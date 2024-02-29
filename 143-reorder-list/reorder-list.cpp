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

    ListNode* BeforeMiddle(ListNode *head)
    {
        if(head==NULL ||head->next==NULL)
        {
            return head;
        }
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* bm=slow;

        while(fast!=NULL && fast->next!=NULL)
        {
            bm=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        return bm;

    }

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
    void reorderList(ListNode* head) 
    {
        if(head==NULL || head->next==NULL)
        {
            return ;
        }
        ListNode* bm=BeforeMiddle(head);
        ListNode* head2=reverse(bm->next);
        //cout<<head2->next->val<<endl;
        bm->next=NULL;
       // cout<<head->val;
        ListNode* ptr1=head;

        ListNode* ptr2=head2;
        ListNode* curr1=ptr1;
        ListNode* curr2=ptr2;

        while(ptr1!=NULL && ptr2!=NULL)
        {
            ptr1=ptr1->next;
            curr1->next=ptr2;
            ptr2=ptr2->next;
            curr2->next=ptr1;
            curr1=ptr1;
            curr2=ptr2;
        } 
        ListNode* temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        if(ptr1==NULL && ptr2!=NULL)  
        {
            temp->next=ptr2;
        }  
        if(ptr2==NULL && ptr1!=NULL)
        {
            temp->next=ptr1;
        }
       
    }
};