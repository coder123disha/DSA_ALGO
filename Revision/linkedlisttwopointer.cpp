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
    ListNode* middleNode(ListNode* head) {

        
        if(head->next==nullptr || head==nullptr){
            return head;
        }

        ListNode* fast=head;
        ListNode* slow=head;

        while( fast!=nullptr && fast->next!=nullptr){
             //in while it matters what condition to be true first
            slow=slow->next;
            fast = fast->next->next;
        }

        return slow;
        
    }
};

//time complexity O(len) len of the linked list
// space complexity O(1)