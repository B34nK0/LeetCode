/*
����������ϳ���Ԫ�飬��Ԫ���Ϊ�㣬��ÿ����Ԫ�鲻���ظ�
*/

#include <vector>
#include <algorithm>

using namespace std;

class TreeNum {
public:
	static vector<vector<int>> FindTreeNum(vector<int>& nums) {
		sort(nums.begin(), nums.end());
	
		vector<vector<int>> res;

		for (int i = 0; i < nums.size(); ++i) {
			//�����ǰһ��ֵ�ظ�����ô��ϳ��������ݼ������ظ���Ԫ������
			if (i > 0 && nums[i] == nums[i - 1]) continue;
			//����ָ��ָ����Ԫ��ĵڶ���������ֵ
			int lo = i + 1, hi = nums.size() - 1;
			//�ڶ�������ֵ��Ҫ���һֵ�ķ�ֵ��ȣ���ô��ӲŻ����0
			int t = -nums[i];

			while (lo < hi) {
				if (nums[lo] + nums[hi] == t) {
					vector<int> tmp({ nums[i],nums[lo],nums[hi] });
					res.emplace_back(tmp);
					//������ֵͬ
					while (lo < hi && nums[lo] == nums[lo + 1])++lo;
					while (lo < hi && nums[hi] == nums[hi - 1])--hi;
					++lo;
					--hi;
				}
				else if (t > nums[lo] + nums[hi]) ++lo;
				else --hi;
			}
		}

		return res;
	}
};