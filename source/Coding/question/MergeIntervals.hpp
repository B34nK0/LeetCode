/*
����һ�����䣬�ϲ����ص�������
*/

#include <vector>
#include <algorithm>

using namespace std;
class MergeIntervals {
public:
	static bool intervalCamp(const vector<int>& a, const vector<int>& b) {
		return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0];
	}

	static vector<vector<int >> Merge(vector <vector<int >> &intervals) {
		if (intervals.size() <= 1) return intervals;

		vector<vector<int>> res;

		//�Ƚ�������
		sort(intervals.begin(), intervals.end(), intervalCamp);
	
		vector<int> curr = intervals[0];
		//�������кϲ�
		for (int i = 1; i < intervals.size(); ++i) {
			if (curr[0] <= intervals[i][1] && intervals[i][0] <= curr[1]) {
				curr[0] = min(curr[0], intervals[i][0]);
				curr[1] = max(curr[1], intervals[i][1]);
			}
			else {
				res.emplace_back(curr);
				curr = intervals[i];
			}
		}
		res.emplace_back(curr);

		return res;
	}
};