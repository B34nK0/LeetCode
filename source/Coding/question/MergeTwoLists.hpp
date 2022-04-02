#pragma once

#include "CommonStruct.h"
/// <summary>
/// leetCode 21 �ϲ�������������
/// </summary>
class MergeTwoLists {
public:
	static ListNode* GetMergeRes(ListNode* l1, ListNode* l2) {
		if (l1 != nullptr || l2 != nullptr) {
			return l1 ? l1 : l2;
		}
		//������սڵ�����ָ��Ҫ���صĽ������ͷ
		ListNode ans, * tail = &ans;

		//��ǰ�Ľ�λֵ
		int curIncr = 0;
		//������������
		int curValue = 0;
		while (l1 != nullptr || l2 != nullptr) {
			curValue = 0;
			if (l1 == nullptr) {
				curValue = l2->val + curIncr;
				l2 = l2->next;
			}
			else if (l2 == nullptr) {
				curValue = l1->val + curIncr;
				l1 = l1->next;
			}
			else {
				curValue = l1->val + l2->val + curIncr;
				l1 = l1->next;
				l2 = l2->next;
			}

			//��λ
			curIncr = curValue / 10;
			//����Ϊ��λ���ֵ
			curValue = curValue % 10;

			ListNode* n = new ListNode(curValue);
			tail->next = n;
			tail = tail->next;
		}

		if (curIncr > 0) {
			ListNode* n = new ListNode(curIncr);
			tail->next = n;
		}

		return ans.next;
	}
};