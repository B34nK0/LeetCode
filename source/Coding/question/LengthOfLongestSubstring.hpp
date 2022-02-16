#pragma once

#include <vector>
#include <unordered_set>
/*
* leetCode 3 
��ȡ�ַ���������ظ��ַ��Ӵ��ĳ���
����: s = "abcabcbb"
���: 3
*/

using namespace std;
class LengthOfLongestSubstring {
public:
	static int GetMaxLength(string s) {
		//��ϣ�����ڼ�¼�ַ����ֵ�λ��
		unordered_set<char> occ;
		//�����ַ���
		int ri=0;
		int maxLength = 0;

		for (int i = 0; i < s.length(); ++i) {
			
			if (i != 0) {
				// ��ָ�������ƶ�һ���Ƴ�һ���ַ�
				occ.erase(s[i-1]);
			}

			//�ƶ���ָ�룬���hash��û�и��ַ�����ô����ŵ�hash��
			//�и��ַ��Ļ���������ǰ�ַ��봰���ڵ��Ӵ�������ͬ�ַ�����Ҫ����ѭ�����㴰���Ӵ��ĳ���
			while (ri < s.length() && !occ.count(s[ri])) {
				occ.insert(s[ri]);
				++ri;
			}
			//ri�������ַ���hash���ظ����ַ�����ô���㵱ǰ������ַ�������
			maxLength = max(maxLength, ri - i);		
		}


		return maxLength;
	}
};