#include <vector>
#include <math.h>

using namespace std;

//给出股票的价格数组，找出最佳买卖点,得出收益
class FindStockBuySell {
public:
	static int FindResult(vector<int> prices) {
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

	//动态规划
	static int SumBuySell(vector<int> prices) {
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
			//不持有时的收益
			dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
			//持有时的收益
			dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
		}
		//不持有时的收益
		return dp[n-1][0];
	}

	//贪心算法
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

	//进阶，最多两次交易，计算最大收益
	static int MaxProfit(vector<int>& prices) {
		int min_so_far = numeric_limits<int>::max();
		vector<int> profit_first_trade(prices.size(), 0);
		int max_profit = 0;

		//计算每个每个位置上产生的最大收益值
		for (int i = 0; i < prices.size(); ++i) {
			min_so_far = min(min_so_far, prices[i]);
			max_profit = max(max_profit, prices[i] - min_so_far);
			profit_first_trade[i] = max_profit;
		}

		int max_so_far = numeric_limits<int>::min();

		for (int i = prices.size() - 1; i > 0; --i) {
			max_so_far = max(prices[i], max_so_far);
			max_profit = max(max_profit, max_so_far - prices[i] + profit_first_trade[i - 1]);
		}

		return max_profit;
	}
};