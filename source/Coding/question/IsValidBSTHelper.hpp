/*
�ж����Ƿ�Ϊ���������
*/

#include "CommonStruct.h"

class IsValidBSTHelper {
public :
	bool IsValidBST(TreeNode* root) {
		return isValid(root, nullptr, nullptr);
	}

	bool isValid(TreeNode* root, TreeNode* leftChild, TreeNode* rightChild) {
		
		if (!root) return true;

		//������ֵ����n�ڵ� ���� ������ֵ����n�ڵ�
		if ((leftChild && leftChild->val >= root->val) || (rightChild && rightChild->val <= root->val)) {
			return false;
		}

		return isValid(root->left, leftChild, root) && isValid(root->right, root, rightChild);
	}
};