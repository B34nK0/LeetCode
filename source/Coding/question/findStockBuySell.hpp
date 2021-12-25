#include <vector>
#include <math.h>

using namespace std;

//������Ʊ�ļ۸����飬�ҳ����������,�ó�����
class findStockBuySell {
public:
	static int findResult(vector<int> prices) {
		if (prices.empty()) {
			return 0;
		}
		int result = 0;
		int minPrice = prices[0];
		for (int i = 1; i < prices.size(); ++i) {
			result = max(result, prices[i] - minPrice);
			minPrice = min(minPrice, prices[i]);
		}

		return result;
	}

	//��̬�滮
	static int sumBuySell(vector<int> prices) {
		if (prices.empty()) {
			return 0;
		}

		int n = prices.size();
		int** dp = new int*[n];
		for (int i = 0; i < n; ++i) {
			dp[i] = new int[2];
		}
		dp[0][0] = 0;
		dp[0][1] = -prices[0];
		for (int i = 1; i < n; ++i) {
			//������ʱ������
			dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
			//����ʱ������
			dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
		}
		//������ʱ������
		return dp[n-1][0];
	}

	//̰���㷨
	static int sumBuySell2(vector<int> prices) {
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
};