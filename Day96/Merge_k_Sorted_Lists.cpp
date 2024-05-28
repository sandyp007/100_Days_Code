// https://leetcode.com/problems/merge-k-sorted-lists/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        if(lists.size() == 0) return nullptr;

        ListNode* dummyNode = new ListNode(-1);
        ListNode* temp = dummyNode;

        priority_queue<pair<int,ListNode*>,
        vector<pair<int,ListNode*>>, greater<pair<int,ListNode*>>> pq;

        for(auto head : lists)
        if(head != nullptr)
            pq.push({head->val, head});


        while(!pq.empty()){
            ListNode* minNode = pq.top().second;
            pq.pop();
            if(minNode->next != nullptr)
                pq.push({minNode->next->val, minNode->next});

            temp->next = minNode;
            temp = temp->next;
        }
        return dummyNode->next;
        
    }
};