
/*
leetCode 322 ��Ǯ�һ�
coins�����ʾӲ�ҵĽ�amount��ʾĿ����
�������Ϊamount�����ٸ�Ӳ����
[1,2,5]  amount = 11
���3����ʾ 5 + 5 + 1�� ����Ӳ��������
*/
#include <vector>
using namespace std;

class CoinChange {
public:
	int GetRes(vector<int>& coins, int amount) {
		int max = amount + 1;
		//��¼ÿ�������СӲ����
		vector<int> dp(amount+1, max);
		dp[0] = 0;
		//���1~amount������Ҫ����Ӳ����
		//��ǰӲ�ҽ��idx, amount������Ӳ�������� dp[amount-idx] + 1;
		//idx����ֿɻ���Ϊ�� idx������Ӳ����
		for (int i = 1; i <= amount; ++i) {
			for (int j = 0; j < coins.size(); ++j) {
				//Ӳ�ҽ������amountʱ�������
				if (coins[j] <= i) {
					dp[i] = min(dp[i], dp[i-coins[j]]+1);
				}
			}
		}

		return dp[amount] > amount ? -1 : dp[amount];
	}
};