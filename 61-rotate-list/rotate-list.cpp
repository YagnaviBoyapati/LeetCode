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
    ListNode* rotateRight(ListNode* head, int k) 
    {
        ListNode* slow=head;
        ListNode* fast=head;
        int count=1;
        int x=0;
      
        ListNode* temp=head;
        while(temp!=NULL)
        {
            x++;
            temp=temp->next;
        }
          if(x==0 || k==0)
          {
            return head;
          }
        k=k%x;
       
        while(count<=k && fast->next!=NULL)
        {
            fast=fast->next;
            count++;
        }
        cout<<"fast: "<<fast->val<<endl;
        slow=head;
        while(fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next;
        }



        fast->next=head;


        head= slow->next;
        slow->next=NULL;
        
        return head;


        
    }
};