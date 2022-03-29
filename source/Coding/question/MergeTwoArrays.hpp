
/*
leetCode 88�ϲ�������������

nums1���� ����Ϊm + n��ǰ���m�����֣����� n��0,
nums2���� ����Ϊn

��num1��num2�ϲ�����ͬ��˳��ϲ���num1����
*/

#include <vector>

using namespace std;
class MergeTwoArrays {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		//����˫ָ�뷽ʽ��ָ�����������β��
		int p1 = m - 1;
		int p2 = n - 1;
		int tail = m + n - 1;
		//�Ӻ��жϣ��ĸ���ֵ��ʱ�ŵ�������
		while (p1 >= 0 || p2 >= 0) {

			int curValue = 0;
			if (p1 == -1) {
				curValue = nums2[p2];
				p2--;
			}
			else if (p2 == -1) {
				curValue = nums1[p1];
				p1--;
			}
			else if (nums1[p1] > nums2[p2]) {
				curValue = nums1[p1];
				p1--;
			}
			else {
				curValue = nums2[p2];
				p2--;
			}
			nums1[tail] = curValue;
			tail--;
		}
	}
};