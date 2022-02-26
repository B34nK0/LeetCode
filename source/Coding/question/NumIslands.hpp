#pragma once

/// <summary>
/// leetCode 200 �ڶ�ά�����У��ֱ����1��0��ʾ½�ظ�ˮ�����1�γɵĵ�������
/// grid = [
//["1", "1", "1", "1", "0"],
//["1", "1", "0", "1", "0"],
//["1", "1", "0", "0", "0"],
//["0", "0", "0", "0", "0"]
//]
// ��� 1
/// </summary>

#include <vector>
using namespace std;

class NumIslands {
public :
	//��������������ʹ���Ԫ����Ϊ0
	static void dfs(vector<vector<int>>& grid, int r, int c) {
		int nr = grid.size();
		int nc = grid[0].size();

		grid[r][c] = 0;
		//��
		if (r-1 >= 0 && grid[r - 1][c] == 1) {
			dfs(grid, r - 1, c);
		}
		//��
		if (r+1 < nr && grid[r + 1][c] == 1) {
			dfs(grid, r + 1, c);
		}
		//��
		if (c-1 >= 0 &&  grid[r][c-1] == 1) {
			dfs(grid, r, c - 1);
		}
		//��
		if (c+1 < nc && grid[r][c +1] == 1) {
			dfs(grid, r, c + 1);
		}
	}

	static int GetNumsOfIslands(vector<vector<int>>& grid) {
		//������޸�ԭ��ά���ݵ�ֵ����ô���ʹ���Ԫ�ؿ��Ա��Ϊ0�������޸ĵĻ����Բ��ñ������ռ�
		//1��������ά����
		int row = grid.size();
		int column = grid[0].size();
		int nums = 0;
		for (int r = 0; r < row; ++r) {
			for (int c = 0; c < column; ++c) {
				//�ҵ�1��Ԫ�ش�������������������������������Ҳ���Բ��ù��������ʹ�ö����滻�ݹ飩
				if (grid[r][c] == 1) {
					//������+1
					nums++;
					dfs(grid, r, c);
				}
			}
		}

		return nums;
	}
};
