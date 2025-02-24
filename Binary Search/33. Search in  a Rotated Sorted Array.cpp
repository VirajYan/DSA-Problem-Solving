#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

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
                return mid;
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
        return -1;
    }
};

int main()
{
  vector<int> nums = {4,5,6,7,0,1,2};
  int target = 0;
    Solution sol;
    cout << "index: " << sol.search(nums, target) << endl;

    return 0;
}