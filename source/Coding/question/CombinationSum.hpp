#pragma once

/*
leetCode 39 ����ܺ�
�����ظ����ֵ����� nums����Ŀ��ֵ target�������Ϊtarget�ĸ�����ϣ��ɶ��ʹ��nums���ֵ
*/

#include <vector>

using namespace std;
class CombinationSum {
public:
	//�����ֵ����ķ�ʽ�ڵ�ǰλ��ȡֵ��������һ��λ��ȡֵ������֧�ϵݹ�

	void dfs(vector<int>& nums, int target, vector<vector<int>>& ans,vector<int> combination, int idx) {
		//��ǰȡһλʱ�����ܳ��������С
		if (idx == nums.size()) {
			return;
		}

		if (target == 0) {
			//��ϵ��ܺ�����target����Ϊһ�ִ�
			ans.emplace_back(combination);
			return;
		}

		dfs(nums, target, ans, combination, idx+1);
		//ȡ��ǰֵ
		int remind = target - nums[idx];
		if (remind >= 0) {
			combination.emplace_back(nums[idx]);
			dfs(nums, remind, ans, combination, idx);
			//
			combination.pop_back();
		}
	}

	vector<vector<int>> GetRes(vector<int> nums, int target) {
		vector<vector<int>> ans;
		//
		vector<int> combination;

		dfs(nums, target, ans, combination, 0);

		return ans;
	}
};