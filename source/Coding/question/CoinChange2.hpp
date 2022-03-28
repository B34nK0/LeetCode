/*
leetCode 518 ��Ǯ�һ�2
��һ����������coins��ʾ��ͬ����Ӳ�ң����һ������amount ��ʾ�ܽ��
��ɴճ��ܽ���Ӳ�������
*/

#include <vector>
using namespace std;

class CoinChange2 {
public:
	int GetRes(int amount, vector<int>& coins) {
		//��¼0��amount���ܽ���Ӳ�������
		vector<int> dp(amount+1, 0);
		//���ܽ��Ϊ0ʱ����ȡ�κ�Ӳ�ң����ֻ��һ�����
		dp[0] = 1;
		//����Ӳ�����
		for (auto& coin : coins) {
			//��coin��amount���
			for (int i = coin; i <= amount; ++i) {
				//���i������� = ��i����ȥcoin�������������
				dp[i] += dp[i - coin];
			}
		}

		return dp[amount];
	}
};