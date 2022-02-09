#pragma once
#include <vector>
#include <algorithm>

using namespace std;

class NextPermutation {
public:
	static void sortNextPermutation(vector<int>& nums) {
		int i = 0;
		//������߽�Сֵ
		for (i = nums.size() - 1; i > 0; --i) {
			if (nums[i] > nums[i - 1]) break;
		}

		if (i == 0) {
			sort(nums.begin(), nums.end());
			return;
		}

		int j = 0;
		//�����ұ߽ϴ�ֵ(���ڻ�ȡ����߽�Сֵ)
		for (j = nums.size() - 1; j > 0; --j) {
			if (nums[j] > nums[i - 1]) break;
		}
		//�������ҽ�Сֵ
		swap(nums[i - 1], nums[j]);

		//���ұ߽������򣬼�Ϊ��ǰ�������һ�����򣨴��ڵ�ǰ����
		sort(nums.begin() + i, nums.end());
	}

	static void sortNextPermutation2(vector<int>& nums) {
		//���ҽ����[i-1]
		int i = 0;
		for (i = nums.size() - 1; i > 0; --i) {
			if (nums[i] > nums[i - 1]) break;
		}

		//Ϊ0˵��Ϊ����ֱ�����򼴿�
		if (i != 0) {
			//�н���ģ���ȡ���ұ߽�С��ֵ���н���
			int j = 0;
			for (j = nums.size() - 1; j > 0; --j) {
				if (nums[j] > nums[i - 1]) break;
			}
			swap(nums[i - 1], nums[j]);
		}

		sort(nums.begin() + i, nums.end());
	}
};