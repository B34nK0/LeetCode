#pragma once
#include <vector>
#include <time.h>


/*
������������ nums ������ k���뷵�������е� k ������Ԫ�ء�
*/

using namespace std;
class FindKthLargest {
public:
	int quickSelect(vector<int>& nums, int left, int right, int k) {
		//������ֵ��λ��
		int kindex = findKindex(nums, left, right);
		if (kindex == k) {
			return nums[kindex];
		}
		//ʹ�ÿ���ȷ����ֵ��k�Ĺ�ϵ�������ֵ�ڵ�ǰ�����λ��С��k��ֵ��˵����k���ֵ����ֵ�ұ�
	//���λ�ô���kֵ��˵����k���ֵ����ֵ���
		return kindex < k ? quickSelect(nums, kindex + 1, right, k) : quickSelect(nums, left, kindex - 1, k);
	}

	int partition_select_index(vector<int>& nums, int left, int right) {
		//��ǰ��ֵ
		int pivot = nums[right];

		int i = left;
		for (int j = left; j < right; ++j) {
			if (nums[j] <= pivot) {
				std::swap(nums[i], nums[j]);
				i = i + 1;
			}
		}
		std::swap(nums[i], nums[right]);
		return i;
	}

	int findKindex(vector<int>& nums, int left, int right) {
		int index = rand() % (right - left + 1) + left;
		swap(nums[index], nums[right]);
		return partition_select_index(nums, left, right);
	}

	int FindKthLargestNum(vector<int>& nums, int k) {
	
		srand((unsigned int)time(NULL));
		return quickSelect(nums, 0, nums.size() - 1, nums.size() - k);
	}
};