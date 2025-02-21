/*this is a brute force approach where we are making vector ret, 
then compairing i with every possible j if sum is target and then pushing back in new vec and returning it

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ret;
        int size=nums.size();
        for(int i=0;i<size-1;i++)
        {
            for(int j=i+1;j<size;j++)
            {
                if(nums[i]+nums[j]==target){
                    ret.push_back(i);
                    ret.push_back(j);
                }
            }
        }
        return ret;
    }
    //there is a better approach where we use hash map and complexity is reduced, above one is brute force
};
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target){
    unordered_map<int, int> ans; //unordered isliye liya kyuki woh fast hai, and we just need to return index so no need of ordered
    int n=nums.size();
    for(int i=0;i<n;i++) //traverse kro nums me
    {
        int currentElement = nums[i]; //current element store karwao jo bhi i ka index pe hai
        int moreNeeded = target - currentElement; //bacha hua nikal lo
        if(ans.find(moreNeeded)!=ans.end()) //agar element mile
        {
            return {ans[moreNeeded],i}; //return krdo 
        }
        ans[currentElement]=i; //nahi mile agar, to atleast i ko to store krlo next iteration ke liye
    }  
    return {-1,-1};
}
};