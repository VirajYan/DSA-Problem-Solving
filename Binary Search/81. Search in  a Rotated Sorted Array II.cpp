#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

//EK QUSTION AA SAKTA HAI, IDHAR RETURN TYPE INT HOKE BHI WHY ARE WE RETURNING TRUE/FALSE, IT IMPLICITLY GETS CONVERTED TO 1/0 RESPECTIVELY MEANS TRUE OR FALSE
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size()-1;

        while(start <= end)
        {
            int mid = (start+end)/2;

            if(nums[mid] == target)
            {
                return true; 
            }
            if(nums[start] == nums[mid] && nums[mid] == nums[end]) //agar duplicates mile
            {
                start = start + 1; //aage ka index lelo
                end = end - 1; //peeche ka index lelo
                continue; //baaki continue kro
            }

            //left part is sorted
            if(nums[start] <= nums[mid])
            {
                //if target is present on left half
                if(nums[start]<=target && target <= nums[mid])
                {
                    end = mid - 1;
                }
                else //if target is present on right half
                {
                    start = mid + 1;
                }
            }
            else //right half is sorted
            {
                //if target is present on right half
                if(nums[mid] <= target && target <= nums[end])
                {
                    start = mid + 1;
                }
                //target is on left half
                else
                {
                    end = mid - 1;
                }
            }
        }
        return false;
    }
};

int main()
{
  vector<int> nums = {2,5,6,0,0,1,2};
  int target = 1;
    Solution sol;
    cout << "index: " << sol.search(nums, target) << endl;

    return 0;
}