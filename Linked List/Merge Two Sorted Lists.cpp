ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* t1 = list1;
    ListNode* t2 = list2;

    ListNode* dummy = new ListNode(-1);
    ListNode* temp = dummy;
    
    while (t1 != NULL && t2 != NULL) {
        if (t1->val <= t2->val) {
            temp->next = t1;
            t1 = t1->next;
        } else {
            temp->next = t2;
            t2 = t2->next;
        }
        temp = temp->next;
    }
    
    if (t1 != NULL) {
        temp->next = t1;
        temp = temp->next;
        t1 = t1->next;
    }
    
    if (t2 != NULL) {
        temp->next = t2;
        temp = temp->next;
        t2 = t2->next;
    }
    
    return dummy->next;
}

// Input: list1 = 1, 2, 4 list2 = 1, 3, 4
// Output: 1, 1, 2, 3, 4, 4
