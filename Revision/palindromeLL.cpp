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

/** basic idea is to reverse the ll and just campare each element
  but do we have to reverse the whole ll
  No we will just campare the half **/
class Solution {
    private:
    ListNode* reverse(ListNode* head){
        ListNode* curr=head;
        ListNode* prev=NULL;
        ListNode* front;
        while(curr!=NULL){
            front=curr->next;
            curr->next=prev;
            prev=curr;
            curr=front;
        }
        return prev;
    }

public:
    bool isPalindrome(ListNode* head) {
       
     ListNode* slow=head;
     ListNode* fast=head;

     while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;

     }

     ListNode* rev=reverse(slow);

     while(rev!=NULL){
        if(head->val!=rev->val){
            return false;
        }
        head=head->next;
        rev=rev->next;
     }
      return true;
    }
};
