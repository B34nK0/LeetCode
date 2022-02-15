#pragma once

#include "CommonStruct.h"
/// <summary>
/// leetCode 21 �ϲ�������������
/// </summary>
class MergeTwoLists {
public:
	static ListNode* GetMergeRes(ListNode* listA, ListNode* listB) {
		if (!listA || !listB) {
			return listA ? listA : listB;
		}
		//����һ���սڵ�
		ListNode ans, *tail = &ans;

		//����������������ж�
		while (listA && listB) {
			if (listA->val < listB->val) {
				tail->next = listA;
				listA = listA->next;
			}
			else {
				tail->next = listB;
				listB = listB->next;
			}
			tail = tail->next;
		}

		listA ? tail->next = listA : tail->next = listB;
		return ans.next;
	}
};