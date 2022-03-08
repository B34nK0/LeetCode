#pragma once

/*
leetCode 221 ���������

Ԫ��Ϊ0,1�Ķ�ά���飬���ȫ��1��ɵ������� ������
*/

#include <vector>

using namespace std;

class MaximalSquare {
public:
	int GetSquare(vector<vector<int>>& matrix) {
		if (matrix.empty() || matrix[0].empty()) {
			return 0;
		}

		int rows = matrix.size();
		int columns = matrix[0].size();
		int maxSide = 0;

		//��¼ÿ��Ԫ�����ڱ��ڵ�ǰλ���ϵ�ֵ
		vector<vector<int>> eleSide(rows, vector<int>(columns, 0));
		//������ά����
		for (int i = 0; i < rows; ++i) {
			for (int j = 0; j < columns; ++j) {
				if (matrix[i][j] == 1) {
					//Ԫ��λ�������������ϲ�
					if (i == 0 || j == 0) {
						eleSide[i][j] = 1;
					}
					else {
						//�ӵ�ǰԪ��λ��Ϊ�����ε����½ǣ���ǰԪ��Ϊ1ʱ����˵�������������������ĵ�
							//�󷽡��Ϸ������Ϸ�Ԫ�ر߳��ӳ�1��λ��
						eleSide[i][j] = min(eleSide[i - 1][j], min(eleSide[i][j - 1], eleSide[i - 1][j - 1])) + 1;
					}
					maxSide = max(maxSide, eleSide[i][j]);
				}
			}
		}


		return maxSide * maxSide;
	}
};