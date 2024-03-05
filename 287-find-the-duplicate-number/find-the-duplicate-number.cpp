class Solution {
public:
    int findDuplicate(vector<int>& nums) 
    {
       int slow=nums[0];
       int fast=nums[0];
       while(true)
       {
           slow=nums[slow];
           fast=nums[nums[fast]];
        cout<<slow<<"  fast  "<<fast<<endl;

           if(slow==fast)
           {
               break;
           }
       }
       int slow2=nums[0];
       while(slow2!=slow)
       {
           slow2=nums[slow2];
           slow=nums[slow];
       }

       return slow;
        
    }
};