#pragma once

/// <summary>
/// leetcode 160
/// �ж����������Ƿ����ཻ�����򷵻��ཻ�Ľڵ㣬���򷵻�null
/// </summary>
/// 

#include "CommonStruct.h"
#include <unordered_set>
using namespace std;

class GetIntersectionNode {
public:
	ListNode* GetNode(ListNode* headA, ListNode* headB) {
		//����hashֵ��ʽ�ж�����b�������Ľڵ��Ƿ���������a�д���
		unordered_set<ListNode*> firstListNode;
		while (headA) {
			firstListNode.insert(headA);
			headA = headA->next;
		}

		while (headB) {
			auto itr = firstListNode.find(headB);
			if (itr != firstListNode.end()) {
				return *itr;
			}
			headB = headB->next;
		}
		return nullptr;
	}

	//����˫ָ�뷽ʽ��ԭ������������A��������B��Ϊ��
	ListNode* Func2(ListNode* headA, ListNode* headB) {
		ListNode* ptrA = headA;
		ListNode* ptrB = headB;

		if (ptrA == nullptr || ptrB == nullptr) {
			return nullptr;
		}

		while (ptrA != ptrB) {

			if (ptrA == nullptr) {
				ptrA = headB;
			}
			else {
				ptrA = ptrA->next;

			}

			if (ptrB == nullptr) {
				ptrB = headA;
			}
			else {
				ptrB = ptrB->next;

			}
		}

		return ptrA;
	}
};