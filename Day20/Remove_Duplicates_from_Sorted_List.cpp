//  https://leetcode.com/problems/remove-duplicates-from-sorted-list/description/


class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head)
        return head;
        ListNode* tmp = head;

        while (tmp && tmp -> next){
            if (tmp -> val == tmp -> next -> val)
                tmp -> next = tmp ->next->next;

            else
                tmp = tmp -> next;
        }
        return head;
    }
};