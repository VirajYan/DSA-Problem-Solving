//2pointers
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int left= 0;
        int right = 0;

        while(right<nums.size()-1)
        {
            if(left>right) return false;
            right  = max(right, left + nums[left]);
            left++;
        }
        return true;
    }
};
/*
WELL TRIED CHAMP
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int jump=0;
        int i=0;
        {
            if(nums[i]==0 && i==nums.size()-1)
            {
                return true;
            }
            if(nums[i]==0)
            {
                return false;
            }
        }
        while(i<nums.size())
        {
            if(nums[i]<=0)
            {
                return false;
            }
            else
            {
                jump=nums[i];
                while(jump)
                {
                    i++;
                    jump--;
                }
            }
        }
        return true;
    }
};
*/