/*
���Ұ༶���γɺ��ѹ�ϵ������
*/
#include <vector>

using namespace std;
class FindCircleNum {
public:
	static void dfs(vector<vector<int>>& M, vector<bool>& visited, int i) {
		visited[i] = true;
		for (int j = 0; j < M[i].size(); j++) {
			if (M[i][j] == 1 && !visited[j]) dfs(M, visited, j);
		}
	}

	static int findCircleNum(vector<vector<int>> &M) {
		int n = M.size();
		int m = n > 0 ? M[0].size() : 0;
		//�������Ƿ����
		if (n == 0 || m == 0 || n != m) return 0;

		//��ʼ������ڵ�û�з��ʹ�
		vector<bool> visited(n, false);
		int count = 0;
		for (int i = 0; i < n; ++i) {
			if (!visited[i]) {
				dfs(M, visited, i);
				++count;
			}
		}

		return count;
	}
};