#pragma once

#include <CommonStruct.h>

class HasCycle {
public:
    bool ListHasCycle(ListNode* head) {
        if (nullptr == head || head->next == nullptr) {
            return false;
        }

        ListNode* p1 = head;
        ListNode* p2 = head->next->next;
        while (p1 != p2) {
            if (nullptr == p2 || nullptr == p2->next) {
                return false;
            }

            p1 = p1->next;
            p2 = p2->next->next;
        }

        return true;
     
    }
};