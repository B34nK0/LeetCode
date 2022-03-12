/*
* leetCode 102
����������������������ڵ㵽�ҽڵ����һ��������һ��ķ�����˳���ҵ���
[3, 9, null,null, 20, 15, 7]
[3,[20, 9],[15, 7]]

���ù��������������������������������root���ڵ�Ϊ�����㣬�������ң�ż���㼴���ҵ���˳������ڵ�
*/

#include "CommonStruct.h"
#include <vector>
#include <queue>

using namespace std;
class ZigzagLevelOrder {
public:
	vector<vector<int>> revert(TreeNode* root) {
		//��ά����洢ÿ��ڵ�ֵ
		vector<vector<int>> ans;
		if (!root) {
			return ans;
		}

		//������ڵ����ڹ����������
		queue<TreeNode*> nodeQueue;
		nodeQueue.push(root);
		//��ʼ����������ô�����˳��
		bool isLeftNode = true;
		
		//�ó�ÿ��Ľڵ�������
		while (!nodeQueue.empty()) {
			int levelSize = nodeQueue.size();
			//˫�˶������ڴ��ÿ��ڵ�˳��
			deque<int> nodeValues;
			//�ȱ�����ǰ��ڵ�
			for (int i = 0; i < levelSize; ++i) {
				TreeNode* node = nodeQueue.front();
				nodeQueue.pop();
				//���ݵ�ǰ��ż������ýڵ�
				if (isLeftNode) {
					nodeValues.push_back(node->val);
				}
				else {
					nodeValues.push_front(node->val);
				}
				//�ѽڵ���ӽڵ�ŵ��ڵ����������һ�����
				if (node->left) {
					nodeQueue.push(node->left);
				}
				if (node->right) {
					nodeQueue.push(node->right);
				}
			}
			//�����ǰ��
			ans.emplace_back(vector<int>{nodeValues.begin(), nodeValues.end() });
			isLeftNode = !isLeftNode;
		}

		return ans;
	}
};