#pragma once

/// <summary>
/// leetCode 199
/// ���������������ͼ
/// 
/// </summary>

#include <vector>
#include <queue>
#include "CommonStruct.h"

using namespace std;

class RightSideView {
public:
	static vector<int> GetRightSideView(TreeNode* root) {
		vector<int> ans = {};
		if (nullptr == root) {
			return ans;
		}

		queue<TreeNode*> levelQueue;
		levelQueue.push(root);
		while (!levelQueue.empty()) {

			int count = levelQueue.size();
			for (int i = 0; i < count; ++i) {

				TreeNode* node = levelQueue.front();
				levelQueue.pop();

				if (node->left) levelQueue.push(node->left);
				if (node->right) levelQueue.push(node->right);

				//���һ���ڵ㼴Ϊ��ǰ�����ҽڵ�
				if (i == count - 1) {
					ans.push_back(node->val);
				}


			}
		}

		return ans;
	}
};