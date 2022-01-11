#pragma once
/*
* leetCode 206
��ת����
*/

#include <CommonStruct.h>

class ReverseList {
public:
	ListNode* Reverse(ListNode* head) {
		
		ListNode* pre = nullptr;
		ListNode* curr= head;
		while (curr) {
			ListNode* next = curr->next;
			curr->next = pre;
			pre = curr;
			curr = next;
		}

		return pre;
	}
};