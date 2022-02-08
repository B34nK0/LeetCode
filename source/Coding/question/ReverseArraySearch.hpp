#pragma once

/// <summary>
/// leetCode 33 ������ת��������Ŀ��ֵ���±�
/// [4,5,6,7,0,1,2] target = 0, �±�Ϊ4,
/// �����ڼ�����-1
/// </summary>

#include <vector>

using namespace std;

class ReverseArraySearch {
public:
	int Search(vector<int>& nums, int target) {
		if (nums.empty()) return -1;

		if (nums.size() == 1) {
			return target == nums[0] ? 0 : -1;
		}

		int left = 0, right = nums.size() - 1;
		while (left <= right) {
			int mid = (left + right) / 2;
			if (target == nums[mid]) return mid;

			//����
			if (nums[0] <= nums[mid]) {
				//Ŀ��ֵ��mid���
				if (nums[0] <= target && target < nums[mid]) {
					right = mid - 1;
				} else{
					left = mid + 1;
				}
			}
			else {
				//Ŀ��ֵ��mid�ұ�
				if (nums[mid] < target && target <= nums[nums.size() - 1]) {
					left = mid + 1;
				}
				else {
					right = mid - 1;
				}
			}
		}

		return -1;
	}
};