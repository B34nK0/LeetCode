#pragma once

#include <CommonStruct.h>
/// <summary>
/// leetCode 236
/// ����һ��������, �ҵ�����������ָ���ڵ������������ȡ�
/// </summary>
class LowestCommonAncestor {
public:
    TreeNode* GetCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) return nullptr;
        //��ǰ�ڵ����ָ���ڵ��е�ĳһ������ô��ǰ�ڵ�����丸�ڵ㼴Ϊ�����������
        if (root == p || root == q) return root;

        //���������鿴�Ƿ���ָ���ڵ�
        TreeNode* leftNode = GetCommonAncestor(root->left, p, q);
        //���������鿴�Ƿ���ָ���ڵ�
        TreeNode* rightNode = GetCommonAncestor(root->right, p, q);

        //��ǰ�ڵ�Ϊ�����������
        if (leftNode && rightNode ) return root;

        //��������ָ���ڵ�
        if (leftNode != nullptr) return leftNode;
        //��������ָ���ڵ�
        if (rightNode != nullptr) return rightNode;
    }
};