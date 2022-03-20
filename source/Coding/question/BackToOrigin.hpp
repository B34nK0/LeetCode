/*
leetCode Բ������10���㣨0~9�� ������˳ʱ�������ʱ������һ����
����n��������ж����ַ������Իص�ԭ��
����2
���2�� ��ʾ 0->1->0, 0->9->0

��������leetCode 70 ��¥�ݷ�ʽ:��n����0�ķ�����=��n-1����1�ķ�����+��n-1����9�ķ�������
*/
#include <vector>
using namespace std;

class BackToOrigin {
public:
	static int GetNums(int n) {
		//Բ������
		int length = 10;
		vector<vector<int>> dp(n + 1, vector<int>(length, 0));
		dp[0][0] = 1;
		//
		for (int i = 1; i <= n; ++i) {
			for (int j = 0; j < length; ++j) {
				//dp[i][j]��ʾ��0��������i����j�ķ�����
				dp[i][j] = dp[i - 1][(j - 1 + length) % length] + dp[i - 1][(j + 1) % length];
			}
		}

		return dp[n][0];
	}
};