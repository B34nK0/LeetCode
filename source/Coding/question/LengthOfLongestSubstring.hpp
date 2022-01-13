#pragma once

#include <vector>
#include <unordered_set>
/*
��ȡ�ַ���������ظ��ַ��Ӵ��ĳ���
*/

using namespace std;
class LengthOfLongestSubstring {
public:
	static int GetMaxLength(string s) {
		//��ϣ�����ڼ�¼�ַ����ֵ�λ��
		unordered_set<char> occ;
		//�����ַ���
		int li=0, ri=0;
		int maxLength = 0;

		for (int i = 0; i < s.length(); ++i) {
			
			if (i != 0) {
				// ��ָ�������ƶ�һ���Ƴ�һ���ַ�
				occ.erase(s[i - 1]);
			}

			//�ƶ���ָ�룬���hash��û�и��ַ�����ô����ŵ�hash��
			while (ri < s.length() && !occ.count(s[ri])) {
				occ.insert(s[ri]);
				++ri;
			}
			//ri�������ַ���hash���ظ����ַ�����ô���㵱ǰ������ַ�������
			maxLength = max(maxLength, ri - li);		
		}


		return maxLength;
	}
};