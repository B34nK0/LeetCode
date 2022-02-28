#pragma once

/// <summary>
/// leetCode 101 �Գƶ�����
/// ������ڵ㿪ʼ�������� ��Ϊ����������Ϊ�Գ�ʱ������������Ϊ����
/// root = [1,2,2,3,4,4,3] return true;
/// </summary>

#include "CommonStruct.h"
class IsSymmetric {
public:
	bool isMirrorTree(TreeNode* leftRoot, TreeNode* rightRoot) {
		//��Ϊnullptrʱ�Գ�
		if (!leftRoot && !rightRoot) {
			return true;
		}
		//�ڵ�������һ��Ϊnullptrʱ���Գ�
		if (!leftRoot || !rightRoot) {
			return false;
		}
		//���ڵ㶼��Ϊ�գ���ô��Ҫ�ж�ֵ�Ƿ�һֱ
		if (leftRoot->val != rightRoot->val) {
			return false;
		}
		//������A ��B ��Ϊ����
		//��ʼ�ݹ��ӽڵ㣬��Ϊ��Ϊ����ʱ��Ӧ�öԱ�A���ӽڵ���B���ӽڵ㣬�Ա�A���ӽڵ���B���ӽڵ�
		if (isMirrorTree(leftRoot->left, rightRoot->right) && isMirrorTree(leftRoot->right, rightRoot->left)) {
			return true;
		}

		return false;
	}

	bool isSymmetric(TreeNode* root) {
		if (root == nullptr) {
			return false;
		}

		return isMirrorTree(root, root);
	}
};