/*using inbuilt stl function, this is important to do in an interview, so that interviewer gets to know that,
you know stl very well
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        next_permutation(nums.begin(), nums.end());
    }
};

*/
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return;  // Handle empty or single-element cases
        //STEP 1
        int index = -1;
        for(int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                index = i;
                break;
            }
        }
        
        if (index == -1) {
            reverse(nums.begin(), nums.end());
            return;  // Avoid running the next part of the code
        }
        //STEP 2
        for(int i = n - 1; i > index; i--) {
            if (nums[i] > nums[index]) {
                swap(nums[i], nums[index]);
                break;
            }
        }
        //STEP 3
        reverse(nums.begin() + index + 1, nums.end());
    }
};
