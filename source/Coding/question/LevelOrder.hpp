/*
���������������ڵ�
*/

#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int val) :val(val), left(nullptr), right(nullptr) {

	}
};

class LevelOrder {
public:
	vector<vector<int>> ConvertTreeNode(TreeNode* root) {
		vector<vector<int>> result;
		if (nullptr == root) return result;

		//�ֱ���ø��ڵ� ���ӽڵ�
		queue<TreeNode*> q1, q2;
		q1.push(root);
		while (!q1.empty() || !q2.empty()) {
			//�ֱ�ָ��ǰ�����εĶ��С����ö�Ӧ�ӽڵ�Ķ���
			queue<TreeNode*>* putQ, * getQ;
			putQ = q1.empty() ? &q1 : &q2;
			getQ = q1.empty() ? &q2 : &q1;

			//ͬһ��ڵ�
			vector<int> level;
			while (!getQ->empty()) {
				TreeNode* curr = getQ->front();
				level.push_back(curr->val);
				if (curr->left) putQ->push(curr->left);
				if (curr->right) putQ->push(curr->right);
				getQ->pop();
			}
			result.push_back(level);
		}
		return result;
	}

};