/*
* leetCode 98
* 
�ж����Ƿ�Ϊ���������

�����������Ķ���
������ֻ����С�ڵ�ǰ�ڵ����
������ֻ�������ڵ�ǰ�ڵ����
����������������������Ƕ���������
*/

#include "CommonStruct.h"

class IsValidBSTHelper {
public :
	bool IsValidBST(TreeNode* root) {
		return isValid(root, nullptr, nullptr);
	}
	//����dfs��˼·�������ж�ÿ�������Ƿ���϶���������
	bool isValid(TreeNode* root, TreeNode* leftChild, TreeNode* rightChild) {
		
		if (!root) return true;

		//������ֵ����n�ڵ� ���� ������ֵ����n�ڵ� ʱ��˵�������϶����������Ķ��壬����false
		if ((leftChild && leftChild->val >= root->val) || (rightChild && rightChild->val <= root->val)) {
			return false;
		}

		//���������Ե�ǰ�ڵ�Ϊ���ڵ㣬ԭ���ڵ�ֵӦ�ô��ڸ�ֵ�����ڵ�ĸ��ڵ�ֵӦ��С�ڵ�ǰֵ
		//���������Ե�ǰ�ڵ�Ϊ���ڵ㣬ԭ���ڵ�ֵӦ��С�ڸ�ֵ�����ڵ�ĸ��ڵ�ֵӦ�ô��ڵ�ǰֵ
		return isValid(root->left, leftChild, root) && isValid(root->right, root, rightChild);
	}
};