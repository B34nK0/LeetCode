#include <vector>
#include <math.h>

using namespace std;

/*
* ������Ʊ�����ʱ��
*/
//������Ʊ�ļ۸����飬�ҳ����������,�ó�����
class FindStockBuySell {
public:
	//leetcode 121
	/*
	* һ�ι�Ʊ���׵��������
	*/
	static int FindResult(vector<int> prices) {
		if (prices.empty()) {
			return 0;
		}
		int result = 0;
		int minPrice = prices[0];
		for (int i = 1; i < prices.size(); ++i) {
			//��ǰλ������Сֵ�ĲΪ����
			result = max(result, prices[i] - minPrice);
			//��¼��������Сֵ��Ϊ���
			minPrice = min(minPrice, prices[i]);
		}

		return result;
	}

	/*
	leetCode 122
	����ͬʱ�����ʽ���
	*/
	//��̬�滮
	static int SumBuySell(vector<int> prices) {
		if (prices.empty()) {
			return 0;
		}

		int n = prices.size();
		int** dp = new int*[n];
		for (int i = 0; i < n; ++i) {
			dp[i] = new int[2];
		}
		//��0��
		//�����й�Ʊʱ������
		dp[0][0] = 0;
		//���й�Ʊʱ������
		dp[0][1] = -prices[0];
		for (int i = 1; i < n; ++i) {
			//��ǰ��λʱ
			// 
			// ������ʱ������  
			// �Ƚ� ǰһ����λ����������  ǰһ��λ����ʱ��ǰ��λ������+price������
			dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
			//����ʱ������
			// �Ƚ� ǰһ����λ��������  ǰһ��λ������ʱ��ǰ��λ���루-price������
			dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
		}
		//������ʱ���������Դ��ڳ���ʱ������
		return dp[n-1][0];
	}

	//̰���㷨
	static int SumBuySell2(vector<int> prices) {
		if (prices.empty()) {
			return 0;
		}

		int result = 0;
		for (int i = 1; i < prices.size(); ++i) {
			if (prices[i] > prices[i - 1]) {
				result += (prices[i] - prices[i - 1]);
			}
		}

		return result;
	}

	//���ף�������ν��ף������������
	static int MaxProfit(vector<int>& prices) {
		int min_so_far = numeric_limits<int>::max();
		vector<int> profit_first_trade(prices.size(), 0);
		int max_profit = 0;

		//˳��
		for (int i = 0; i < prices.size(); ++i) {
			//��ǰλ���ϵ���С�۸���Ե����
			min_so_far = min(min_so_far, prices[i]);
			//��ǰλ���ϵ��������=��ǰ��-֮ǰ����ͼ�
			max_profit = max(max_profit, prices[i] - min_so_far);
			//�洢ÿ��λ�ò������������
			profit_first_trade[i] = max_profit;
		}

		int max_so_far = numeric_limits<int>::min();

		//����
		for (int i = prices.size() - 1; i > 0; --i) {
			//��ǰλ���ϵ����۸���Ϊ����
			max_so_far = max(prices[i], max_so_far);
			//���㵱ǰλ���뵱ǰλ��֮ǰ�������׵���������
			max_profit = max(max_profit, max_so_far - prices[i] + profit_first_trade[i - 1]);
		}

		return max_profit;
	}
};