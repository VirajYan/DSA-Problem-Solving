/*brute force with tc of O(n3);
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> st;
        for (int i = 0; i < nums.size() - 2; i++) {
            for (int j = i + 1; j < nums.size() - 1; j++) {
                for (int k = j + 1; k < nums.size(); k++) {
                    if (nums[i] + nums[j] + nums[k] == 0) {
                        vector<int> temp = {nums[i], nums[j], nums[k]};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                }
            }
        }
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};
*/

// better approach is for hashing LEARN IT
// 3 POINTERS
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();

        for (int i = 0; i < n - 2; ++i) {
            // Skip duplicates for the first element
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int j = i + 1;
            int k = n - 1;

            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum < 0) {
                    ++j;
                } else if (sum > 0) {
                    --k;
                } else {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    ++j;
                    --k;

                    // Skip duplicates for the second element
                    while (j < k && nums[j] == nums[j - 1]) ++j;

                    // Skip duplicates for the third element
                    while (j < k && nums[k] == nums[k + 1]) --k;
                }
            }
        }
        return ans;
    }
};
