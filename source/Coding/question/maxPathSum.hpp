#include <utility>

#include "CommonStruct.h"
/*
* 
* leetCode 124
��������������·����

�磺
-10
/	\
9	 20
	/	\
	15   7

���·����Ϊ 15->20->7

*/


using namespace std;
class MaxPathSum {

public:
	static int maxSum;


	static int MaxSum(TreeNode* treeNode) {
		maxGain(treeNode);
		return maxSum;
	}

	static int maxGain(TreeNode* treeNode) {
		if (nullptr == treeNode) {
			return 0;
		}

		//��ǰ�ڵ��·��ֵ ���� ��ǰֵ + ���ҽڵ�Ĺ���ֵ��Ϊ���Ľڵ㲻��������
		int curGain = treeNode->val;

		//�ݹ�������ҽڵ�Ĺ���ֵ
		int leftGain = max(maxGain(treeNode->left), 0);
		curGain += leftGain;

		int rightGain = max(maxGain(treeNode->right), 0);
		curGain += rightGain;

		//���¼�����·��ֵ�Ƚ�
		maxSum = max(maxSum, curGain);

		//��ǰ�ڵ�Ĺ���ֵ���ڵ�ǰֵ+�����ӽڵ�������ֵ
		//����ǰ���л������е�·���ṩ�����ڵ�
		return treeNode->val + max(leftGain, rightGain);
	}
};

int MaxPathSum::maxSum = INT_MIN;;