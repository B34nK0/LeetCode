#pragma once
/*
leetCode 234 ��������

*/

#include "CommonStruct.h"

class IsPalindrome {
	ListNode* frontPoint;
public:
	bool recursivelyCheck(ListNode* currentNode) {
		//����β�ڵ����������ð
		if (currentNode == nullptr) {
			return true;
		}
		//��һ�ڵ�ֵ�뵱ǰͷ�ڵ�ָ�벻���
		if (!recursivelyCheck(currentNode->next)) {
			return false;
		}
		//��ǰ�ڵ�ֵ����ȣ�ֱ�ӷ��ش���
		if (currentNode->val != frontPoint->val) {
			return false;
		}
		//�ڵ�ֵ��ȣ�ͷָ�����£�βָ������
		frontPoint = frontPoint->next;
		return true;
	}

	//����һ�����õݹ�ķ�ʽ
	bool check1(ListNode* head) {
		//ȫ�ּ�¼ͷ��㣬���ݹ鶼β�ڵ�����ðʱ����ͬʱ�ȶ�ͷβ�ڵ��ֵ
		//frontPoint = frontPoint->next������ͷ��㣬�γ�ͷβ��£
		frontPoint = head;
		return recursivelyCheck(head);
	}


	//����������ת��벿������֮��ȶ�ǰ���������Ƿ�ֵ���
	bool check2(ListNode* head) {
		//���ҳ��м�ڵ�
		ListNode* firstHalfEnd = endOfFirstHalf(head);
		//��ת��벿������
		ListNode* secondHalfStart = reverseList(firstHalfEnd->next);
		ListNode* p1 = head;
		ListNode* p2 = secondHalfStart;
		bool result = true;
		while (result && p2 != nullptr) {
			if (p1->val != p2->val) {
				result = false;
			}
			p1 = p1->next;
			p2 = p2->next;
		}

		//��ת�غ�������
		firstHalfEnd->next = reverseList(secondHalfStart);
		return result;
	}

	//���ÿ���ָ�룬�ҳ�������м�ڵ�
	ListNode* endOfFirstHalf(ListNode* head) {
		ListNode* slow = head;
		ListNode* fast = head;
		while (slow->next != nullptr && fast->next->next != nullptr) {
			slow = slow->next;
			fast = fast->next->next;
		}
		return slow;
	}

	//��ת���������µ�ͷ���
	ListNode* reverseList(ListNode* head) {
		ListNode* pre = nullptr;
		ListNode* cur = head;
		while (cur != nullptr) {
			ListNode* next = cur->next;
			cur->next = pre;
			pre = cur;
			cur = next;
		}
		return pre;
	}
};