#pragma once
/*
* leetCode 206
��ת����

���鹹pre�ڵ�Ϊnullptr����ʼ��������
1������next��¼��ǰ�ڵ��next
2����ǰ�ڵ�nextָ��pre
3��preָ��ǰ�ڵ�
4����ɵ�ǰ�ڵ�ĶϿ��󣬵�ǰ�ڵ�ָ��next����ѭ������

���preΪ��ת���ͷ�ڵ�
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