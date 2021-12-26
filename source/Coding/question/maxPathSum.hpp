#include <utility>


/*
��������������·����

�磺
-10
/	\
9	 20
	/	\
	15   7

���·����Ϊ 15->20->7

*/

class TreeNode {
public:
	int value;

	TreeNode* left;

	TreeNode* right;
};

using namespace std;
class MaxPathSum {
private:
	int _maxSum = 0;

public:

	static int MaxSum(TreeNode* treeNode) {
		if (nullptr == treeNode) {
			return 0;
		}


	}

private:
	/// <summary>
	/// ����ÿ���ڵ�Ĺ���ֵ
	/// </summary>
	/// <param name="treeNode"></param>
	/// <returns></returns>
	int maxGain(TreeNode* treeNode) {
		if (nullptr == treeNode) {
			return 0;
		}

		//��ǰ�ڵ�Ĺ���ֵ ���� ���ҽڵ�Ĺ���ֵ��Ϊ���Ľڵ㲻��������
		int curGain = treeNode->value;

		//�ݹ�������ҽڵ�Ĺ���ֵ
		int leftGain = maxGain(treeNode->left);
		if (leftGain > 0) {
			curGain += leftGain;
		}

		int rightGain = maxGain(treeNode->right);
		if (rightGain > 0) {
			curGain += rightGain;
		}

		//���·���� ��ǰ�ڵ�Ϊ���ڵ�ʱ�� �ۼ����ҽڵ���ȻΪ��������������ɼ�������
		_maxSum = max(_maxSum, _maxSum + curGain);

		//�������У� �ɻ��� ���нڵ�
		return treeNode->value + max(leftGain, rightGain);
	}
};