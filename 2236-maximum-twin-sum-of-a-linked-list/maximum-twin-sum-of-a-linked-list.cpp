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

    ListNode* evenMid(ListNode * head)
    {
        if(head==NULL)
        {
            return head;
        }
        ListNode* slow=head;
        ListNode* fast=head->next->next;
        while(fast!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        cout<<slow->val<<endl;
        return slow;
    }
    ListNode* reverse(ListNode * head)
    {
        if(head==NULL || head->next==NULL)
        {
            return head;
        }
        ListNode *small=reverse(head->next);
        head->next->next=head;
        head->next=NULL;
        return small;
    }
    int pairSum(ListNode* head) 
    {
        ListNode * mid=evenMid(head);
        ListNode * ptr2=reverse(mid->next);
        mid->next=ptr2;
        ListNode * ptr1=head;
        int maxSum=INT_MIN;
        while(ptr2!=NULL)
        {
            int sum= ptr1->val+ptr2->val;
            if(maxSum<sum)
            {
                maxSum=sum;
            }
           // cout<<"ptr1 Value:   "<<ptr1->val<<endl;
            
           // cout<<"ptr2 Value:   "<<ptr2->val<<endl;

            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }

        return maxSum;
        
    }
};