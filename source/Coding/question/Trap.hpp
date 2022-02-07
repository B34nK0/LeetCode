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
};