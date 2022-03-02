#pragma once

/*
leetCode 415 �ַ������
�ַ���'0' ��Ӽ��ɵõ���Ӧ����ֵ
 ��1�� - ��0�� = 1
 1 + ��0�� = ��1��
*/
#include <string>

using namespace std;
class AddStrings {
public:
	string AddTwoString(string& strA, string& strB) {
		if (strA.empty() || strB.empty()) {
			return strA.empty() ? strB : strA;
		}

		int add = 0;
		int i = strA.length() - 1;
		int j = strB.length() - 1;

		//���
		string ans = "";
		//���ַ���β������ֵλ�������н�λʱ
		while (i >= 0 || j >= 0 || add > 0) {
			//�ж��ĸ��ַ�������������
			int a = i >= 0 ? strA[i] - '0' : 0;
			int b = j >= 0 ? strB[j] - '0' : 0;
			int result = a + b + add;
			//��ȡ��λֵ
			add = result / 10;
			//��ǰ��ֵλ��ֵ
			ans.push_back(result % 10 + '0');
			//
			i--;
			j--;
		}

		//��ת��ȡ����ֵ
		reverse(ans.begin(), ans.end());

		return ans;
	}
};