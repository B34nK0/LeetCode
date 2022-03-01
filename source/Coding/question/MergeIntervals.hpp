/*
* leetCode 56 �ϲ�����
* ���룺intervals = [[1,3],[2,6],[8,10],[15,18]]
�����[[1,6],[8,10],[15,18]]

���룺intervals = [[1,4],[4,5]]
�����[[1,5]]
* 
����һ�����䣬�ϲ����ص�������
*/

#include <vector>
#include <algorithm>

using namespace std;
class MergeIntervals {
public:
	static bool intervalCamp(const vector<int>& a, const vector<int>& b) {
		//������һ��ʱ�Ƚ�������
		return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0];
	}

	static vector<vector<int >> Merge(vector <vector<int >> &intervals) {
		if (intervals.size() <= 1) return intervals;

		vector<vector<int>> res;

		//�Ƚ������� �Զ���Ƚ���
		sort(intervals.begin(), intervals.end(), intervalCamp);
		/*
		java lambda���ʽ �Ƚ�������������С:
		  Arrays.sort(intervals, new Comparator<int[]>() {
            public int compare(int[] interval1, int[] interval2) {
                return interval1[0] - interval2[0];
            }
        });
		*/

	
		vector<int> curr = intervals[0];
		//�������кϲ�
		for (int i = 1; i < intervals.size(); ++i) {
			//�������һ�����������һ�����ڵ��ڵ�ǰ����������䣬��ô�������������һ�����ڵ�ǰ�����������
			//�����ǰ�������������ڵ�����һ����������䣬��ô˵�������н���
			if (curr[0] <= intervals[i][1] && intervals[i][0] <= curr[1]) {
				curr[0] = min(curr[0], intervals[i][0]);
				curr[1] = max(curr[1], intervals[i][1]);
			}
			else {
				//��ǰ����û���ص�
				res.emplace_back(curr);
				curr = intervals[i];
			}
		}
		res.emplace_back(curr);

		return res;
	}
};