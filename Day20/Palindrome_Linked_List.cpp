//  https://leetcode.com/problems/palindrome-linked-list/

// approach using vector
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> nums;
        ListNode* curr = head;
        
        while(curr != NULL){ 
            nums.push_back(curr->val);
             curr = curr->next;
        }
        
        for(int i = 0; i < nums.size() / 2; i++){
            if(nums[i] != nums[nums.size() - i - 1]) return false;
        }
        
        return true;
    }
};

//  Stack->Queue Approach

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        stack<int> start;
        queue<int> end;

        ListNode* curr = head;
        
        while(curr != NULL){ 
            start.push(curr->val); 
            end.push(curr->val); 
            curr = curr->next;
        }
        
        while(!start.empty() && !end.empty()){
            if(start.top() != end.front()) 
            return false;
            start.pop(); end.pop();
        }
        
        return true;
    }
};