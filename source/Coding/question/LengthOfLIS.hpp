#pragma once
/// <summary>
/// leetCode 300 �����������
/// 
/// [0,3,1,6,2,2,7] �����������Ϊ [0,1,2,7]
/// [0,1,0,3,2,3] => [0,1,2,3]
/// </summary>
/// 
#include<vector>
#include<algorithm>

using namespace std;

class LengthOfLIS {
public:
	static int GetLengthOfLIS(vector<int>& nums) {
		if (nums.empty()) {
			return 0;
		}
		vector<int> dp(nums.size(), 0);
		//�����ڵ�
		for (int i = 0; i < nums.size(); ++i) {
			dp[i] = 1;
			//��0��ʼ����ǰ�ڵ��������򳤶�
			for (int j = 0; j < i; ++j) {
				if (nums[j] < nums[i]) {
					dp[i] = max(dp[i], dp[j] + 1);
				}
			}
		}
		//�ж����нڵ�������еĽڵ�
		return* max_element(dp.begin(), dp.end());
	}

	//����̰���㷨 + ���ֲ���
	static int GetLengthOfLIS2(vector<int>& nums) {
        int len = 1, n = (int)nums.size();
        if (n == 0) {
            return 0;
        }
        vector<int> d(n + 1, 0);
        d[len] = nums[0];
        for (int i = 1; i < n; ++i) {
            if (nums[i] > d[len]) {
                d[++len] = nums[i];
            }
            else {
                int l = 1, r = len, pos = 0; // ����Ҳ���˵�����е������� nums[i] �󣬴�ʱҪ���� d[1]���������ｫ pos ��Ϊ 0
                //���ֲ��ҵ�ǰ�ڵ�ֵ���Ѳ��ҵ�ֵ��λ��
                while (l <= r) {
                    int mid = (l + r) >> 1;
                    if (d[mid] < nums[i]) {
                        pos = mid;
                        l = mid + 1;
                    }
                    else {
                        r = mid - 1;
                    }
                }
                d[pos + 1] = nums[i];
            }
        }
        return len;
	}
};