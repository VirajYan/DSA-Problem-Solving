class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans = {-1, -1};  // Default result if target is not found
        int s = 0, e = nums.size() - 1;

        // First binary search to find the first occurrence
        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (nums[mid] < target) {
                s = mid + 1;
            } else if (nums[mid] > target) {
                e = mid - 1;
            } else {  
                ans[0] = mid;  // Possible first occurrence
                e = mid - 1;   // Keep searching on the left
            }
        }

        // Reset variables for second binary search
        s = 0, e = nums.size() - 1;

        // Second binary search to find the last occurrence
        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (nums[mid] < target) {
                s = mid + 1;
            } else if (nums[mid] > target) {
                e = mid - 1;
            } else {
                ans[1] = mid;  // Possible last occurrence
                s = mid + 1;   // Keep searching on the right
            }
        }

        return ans;
    }
};
