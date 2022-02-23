#pragma once


/// <summary>
/// leetCode 1 ������֮��ΪĿ��ֵ���±�
/// </summary>
/// 
#include <vector>
#include <unordered_map>
using namespace std;
class TwoSum {
public:

	static vector<int> GetRes(vector<int>& nums, int target) {
		//ͨ��map����¼����������±�
		unordered_map<int, int> numIndex;

		for (int i = 0; i < nums.size(); ++i) {
			//Ŀ��ֵ - ��ǰ��ֵ = ʣ��ֵ
			int gap = target - nums[i];
			//����ʣ��ֵ�Ƿ��Ѽ�¼
			auto index = numIndex.find(gap);
			//�ҵ�������Ϊtarget
			if (index != numIndex.end()) {
				return { index->second, i };
			}

			numIndex[nums[i]] = i;
		}

		return {};
	}
};
