#pragma once
/// <summary>
/// leetCode 92��ת������������ͷָ��head���Լ�left��rightֵ����תleft~right��ڵ�
/// 
/// ���룺head = [1,2,3,4,5], left = 2, right = 4
/// �����[1, 4, 3, 2, 5]
/// 
/// 
/// ��Ŀ�����󣬣�����������ģ� �ǽ���left���ڵ㵽right���ڵ������ڵĽڵ���з�ת
/// </summary>
/// 
#include "CommonStruct.h"
class ReverseBetween {
public:
	//�����µı�ͷ
	static void reverseSubList(ListNode* head, ListNode* tail) {
		//��������β�ڵ����һ���ڵ���Ϊ��ǰ��ǰ�ڵ�
		ListNode* prev = tail->next;
		ListNode* curr = head;
		while (prev != tail) {
			ListNode* next = curr->next;
			curr->next = prev;
			prev = curr;
			curr = next;
		}
	}

	//static ListNode* GetReverseRes(ListNode* head, int left, int right) {
	//	if (left > right) return nullptr;
	//	if (!head) return nullptr;

	//	//���ҳ���ѡ�������ͷ�ڵ��β�ڵ�
	//	ListNode* subHead = nullptr, * subTail = nullptr, *subListPre = nullptr;
	//	ListNode* tail = head;
	//	while (tail) {
	//		//���ҳ�������ͷ
	//		if (tail->val == left) {
	//			subHead = tail;
	//		}
	//		else if(!subHead){
	//			subListPre = tail;
	//		}
	//		//������β���������˱�ͷ֮��
	//		if (tail->val == right && subHead) {
	//			subTail = tail;
	//		}
	//		tail = tail->next;
	//	}
	//	//
	//	if (!subHead || !subTail) {
	//		return nullptr;
	//	}
	//	//��ת������,�����µı�ͷ
	//	reverseSubList(subHead, subTail);
	//	if (!subListPre) {
	//		head = subTail;
	//	}
	//	else {
	//		subListPre->next = subTail;
	//	}

	//	return head;
	//}


	static ListNode* GetReverseRes(ListNode* head, int left, int right) {
		//������������ǰһ���ڵ㣬��left���ڵ㣬���߽�Ϊleft-1
		ListNode* pre = head;
		for (int i = 0; i < left - 1; ++i) {
			pre = pre->next;
		}


		//��������һ���ڵ㿪ʼ���滻��ǰcur����һ���ڵ㵽pre���¸��ڵ㣬������ʽѹջ��ʽ
		ListNode* cur = pre->next;
		ListNode* next = nullptr;
		for (int i = 0; i < right - left; ++i) {
			next = cur->next;
			cur->next = next->next;
			next->next = pre->next;
			pre->next = next;
		}

		return head;
	}
};