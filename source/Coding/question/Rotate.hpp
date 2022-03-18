#include <vector>
/*
leetCode 48 ��תͼ��
����n*n�ľ���˳ʱ����ת90�� �����ת��ľ���
*/
using namespace std;
class Rotate {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // ˮƽ��ת
        for (int i = 0; i < n / 2; ++i) {
            for (int j = 0; j < n; ++j) {
                swap(matrix[i][j], matrix[n - i - 1][j]);
            }
        }
        // ���Խ��߷�ת
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }

    //��ת�Ĺ��ɣ�matrix[col][n-row-1] = matrxi[row][col]
    //�е����ݻ���ת����Ӧ�и���λ��
    void rotate2(vector<vector<int>>& matrix) {
        int n = matrix.size();
        //��ת�Ĳ��
        for (int i = 0; i < n / 2; ++i) {
            for (int j = 0; j < (n + 1)/2; ++j) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[n - j - 1][i];
                matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1];
                matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1];
                matrix[j][n - i - 1] = temp;
            }
        }
    }
};