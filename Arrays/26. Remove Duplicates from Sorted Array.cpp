/*BRUTE FORCE SOLUTION
basically we are storing all te elements into the set
and after wards taking it back into a ans2 vector so that
type covversion is done and then again taking the ans2
values back into nums that is our og vector which we are passing
as reference.

at the end why are we returning the size of array?
this is because the return type is int so we can only return the size
but if the return type was vector we could just return the vector nums directly

class Solution {
public:
    int removeDuplicates(vector<int>& nums){
        set <int> ans1;
        for(int i=0;i<nums.size();i++)
        {
            ans1.insert(nums[i]);
        }
        vector <int> ans2;
        for(auto it: ans1)
        {
            ans2.push_back(it);
        }
        nums=ans2;
        return nums.size();
    }
};

*/

/*
this is a better approach where we are using less space
*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums){
        vector <int> ans;
        ans.push_back(nums[0]);

        for(int i=1;i<nums.size();i++)
        {
            if(nums[i] == nums[i-1])
            {
                continue;
            }
            else
            {
                ans.push_back(nums[i]);
            }
        }
        nums=ans;
        return ans.size();
    }
};