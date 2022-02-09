#pragma once

/// <summary>
/// leetCode 42����ˮ
/// 
/// ���� n ���Ǹ�������ʾÿ�����Ϊ 1 �����ӵĸ߶�ͼ�����㰴�����е����ӣ�����֮���ܽӶ�����ˮ��
// ���룺height = [0,1,0,2,1,0,1,3,2,1,2,1]
//�����6
//���ͣ�������������[0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1] ��ʾ�ĸ߶�ͼ
/// </summary>
/// 

#include <vector>

using namespace std;

class Trap {
public:
	static int GetTrapResult(vector<int>& height) {
		//��������˫ָ�뷽ʽ��
		int* leftIndex = &height[0], *rightIndex = &height[height.size()-1];
		int leftMaxHeight = *leftIndex, rightMaxHeight = *rightIndex;

		int ans = 0;
		//����ָ������ʱ�Ѿ������γɵ�����
		while (leftIndex != rightIndex) {
			if (*leftIndex >= leftMaxHeight) {
				leftMaxHeight = *leftIndex;
			}
			else {
				ans += (leftMaxHeight - *leftIndex);
			}


			if (*rightIndex >= rightMaxHeight) {
				rightMaxHeight = *rightIndex;
			}
			else {
				ans += (rightMaxHeight - *rightIndex);
			}

			if (*leftIndex > *rightIndex) {
				rightIndex--;
			}
			else {
				leftIndex++;
			}
		}

		return ans;
	}

	//���ñ�����¼ÿ��λ�õ��������ֵ
	static int GetTrapResult2(vector<int>& nums) {
		int n = nums.size();
		if (n == 0) {
			return 0;
		}
		vector<int> leftMax(n);
		leftMax[0] = nums[0];
		for (int i = 1; i < n; ++i) {
			//��߼�¼��ֵ�뵱ǰ�߶ȱ�
			leftMax[i] = max(leftMax[i - 1], nums[i]);
		}

		//���������¼�ұ����߶�
		vector<int> rightMax(n);
		rightMax[n - 1] = nums[n - 1];
		for (int i = n - 2; i >= 0; --i) {
			//�ұ߼�¼��ֵ�뵱ǰ�߶ȱ�
			rightMax[i] = max(rightMax[i + 1], nums[i]);
		}

		int ans = 0;
		for (int i = 0; i < n; ++i) {
			//���Ҹ߶�ֵ����Сֵ��ȥ��ǰ�߶�
			ans += min(leftMax[i], rightMax[i]) - nums[i];
		}
		return ans;
	}
};