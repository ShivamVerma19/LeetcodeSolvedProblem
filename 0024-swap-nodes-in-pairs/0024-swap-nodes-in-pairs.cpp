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
    void ans(ListNode*&temp,ListNode*&curr,ListNode*a){
        a=curr;
        if(temp==NULL || temp->next==NULL)return;
        temp->next=NULL;
        temp->next=curr->next;
        curr->next=temp;
        ListNode*prev = temp;

        temp=temp->next;
        if(temp==NULL || temp->next==NULL)return;
        curr=temp->next;
        prev->next=curr;
        ans(temp,curr,a);
    }
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL)return NULL;
        if(head->next==NULL)return head;
        ListNode*temp=head;
        ListNode*curr = head->next;
        ListNode*a=curr;
        ans(temp,curr,a);
        return a;
    }
};