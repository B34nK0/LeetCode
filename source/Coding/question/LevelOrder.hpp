/*
* leetCode 102
���������������ڵ�
*/

#include <vector>
#include <queue>
#include <CommonStruct.h>

using namespace std;

class LevelOrder {
public:
	vector<vector<int>> GetRes(TreeNode* root) {
		vector<vector<int>> result;
		if (nullptr == root) return result;

		queue<TreeNode*> levelNode;
		levelNode.push(root);
		while (!levelNode.empty()) {
			//��ǰ��εĽڵ���
			int levelNodeNum = levelNode.size();
			//ֻ��ȡ�������n���ڵ㣬ʣ����ǵ�ǰ��νڵ���ӽڵ�
			vector<int> level = {};
			for (int i = 0; i < levelNodeNum; ++i) {
				TreeNode* node = levelNode.front();
				levelNode.pop();
				level.push_back(node->val);
				if (node->left) {
					levelNode.push(node->left);
				}
				if (node->right) {
					levelNode.push(node->right);
				}
			}
			result.push_back(level);
		}
		return result;
	}

	vector<vector<int>> ConvertTreeNode(TreeNode* root) {
		vector<vector<int>> result;
		if (nullptr == root) return result;

		//�ֱ���ø��ڵ� ���ӽڵ�
		queue<TreeNode*> parentQ, childrenQ;
		parentQ.push(root);
		while (!parentQ.empty() || !childrenQ.empty()) {
			//�ֱ�ָ��ǰ�����εĶ��С����ö�Ӧ�ӽڵ�Ķ���
			queue<TreeNode*>* putQ, * getQ;
			//
			putQ = parentQ.empty() ? &parentQ : &childrenQ;
			getQ = parentQ.empty() ? &childrenQ : &parentQ;

			//ͬһ��ڵ�
			vector<int> level;
			while (!getQ->empty()) {
				//getQ�Ľڵ�Ϊ��ǰ��һ��ڵ�����
				TreeNode* curr = getQ->front();
				level.push_back(curr->val);
				//�ڵ������ӽڵ�ʱ���õ�put����
				if (curr->left) putQ->push(curr->left);
				if (curr->right) putQ->push(curr->right);
				getQ->pop();
			}
			result.push_back(level);
		}

		queue<TreeNode*> putQ, getQ;
		putQ.push(root);

		vector<int> level;
		while (!putQ.empty() || !getQ.empty()) {
			while (!putQ.empty()) {
				TreeNode* curr = putQ.front();
				level.push_back(curr->val);
				if (curr->left) getQ.push(curr->left);
				if (curr->right) getQ.push(curr->right);
				putQ.pop();
			}
			level.clear();
			result.push_back(level);

			while (!getQ.empty()) {
				TreeNode* curr = getQ.front();
				level.push_back(curr->val);
				if (curr->left) putQ.push(curr->left);
				if (curr->right) putQ.push(curr->right);
				getQ.pop();
			}
			level.clear();
			result.push_back(level);
		}

		return result;
	}

};