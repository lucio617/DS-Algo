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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int l=0;
       
        if( head->next==nullptr)
            return nullptr;
        ListNode* t=head;
        while(t!=nullptr)
        {
            l++;
            t=t->next;
        }
        cout<<l;
        t=head;
        int del_index=l-n+1;
        if(del_index==1)
            return head->next;
        ListNode* prev=nullptr;
        int count=1;
        while(count!=del_index){
            prev=t;
            t=t->next;
            count++;
        }
        prev->next=t->next;
        t->next=nullptr;
        return head;
    }
};