/*
leetCode 162 Ѱ�ҷ�ֵ

nums[1,2,3,1] ��� 2
nums[2] = 3 3 
*/

#include <vector>

using namespace std;
class FindPeakElement {
public:
	static int GetRes(vector<long long>& nums) {
		int count = nums.size()-1;
		//���ö��ַ�����
		int left = 0, right = count;

		int ans = -1;
		int midValue = 0, midLeftValue = LONG_MIN, midRightValue = LONG_MIN;

		while (left <= right) {
			int mid = (left + right) >> 1;

			//��ȡ�����ֵ,���ڴ��� ע��mid-1Ϊ-1�� mid+1Ϊ size(), ��������
			midValue = nums[mid];
			if (mid - 1 >= 0) {
				midLeftValue = nums[mid - 1];
			}
			if (mid + 1 <= count) {
				midRightValue = nums[mid + 1];
			}
			if (midValue > midLeftValue && midValue > midRightValue) {
				ans = mid;
				break;
			}

			if (midLeftValue >= midValue) {
				right = mid-1;
			}
			else {
				left = mid+1;
			}
		}

		return ans;
	}
};