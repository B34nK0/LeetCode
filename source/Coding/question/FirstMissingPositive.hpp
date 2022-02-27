#pragma once

/// <summary>
/// leetCode 41ȱʧ�ĵ�һ��������
/// ��һ��δ�������������nums���ҳ�����û�г��ֵ���С������
/// �磺 [1,2,0] -> 3
/// [3,4,-1,1] -> 2
/// 
/// </summary>
/// 
/// 
#include <vector>
#include <algorithm>
using namespace std;

class FirstMissingPositive {
public:

	static int GetNum(vector<int>& nums) {
		//������Ϊ1~n��ֵ
		int n = nums.size();
		//�ȱ�����������ֵ�û���Ӧ�ڵ�λ��
		for (int i = 0; i < n; ++i) {
			//������nums[i]�����ж���ֵ�Ƿ�Ϊi+1��������ǣ���ô�����û���nums[i-1]��λ��
			while (nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i] - 1]) {
				swap(nums[i], nums[nums[i] - 1]);
			}
		}
		//�ٴα������飬Ѱ�����±겻���ϵ�Ԫ�أ���ȱʧ��ֵΪ�±�i+1
		for (int i = 0; i < n; ++i) {
			if (nums[i] != i + 1) {
				return i + 1;
			}
		}
		return n + 1;
	}
};