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

    ListNode* reverse(ListNode * head)
    {
        if(head==NULL || head->next==NULL)
        {
            return head;
        }
        ListNode* smallHead=reverse(head->next);
        head->next->next=head;
        head->next=NULL;
        return smallHead;

    }
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        ListNode * newHead=reverse(head);
        ListNode * prev=NULL;
        ListNode * curr=newHead;
        if(n==1)
        {
            return reverse(curr->next);
        }
        int count=0;
        while(curr!=NULL)
        {
            count++;
            if(count==n)
            {
                prev->next=curr->next;
                curr=curr->next;
                break;
            }
            prev=curr;
            curr=curr->next;
        }
        return reverse(newHead);
        
    }
};