#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution
{
public:
    int fun(vector<int> &weights, int capacity)
    {
        int days = 1, load = 0;
        for (int weight : weights)
        {
            if (load + weight > capacity)
            {
                days++;
                load = weight;
            }
            else
            {
                load += weight;
            }
        }
        return days;
    }

    int shipWithinDays(vector<int> &weights, int days)
    {
        int start = *max_element(weights.begin(), weights.end());
        int end = accumulate(weights.begin(), weights.end(), 0);

        while (start <= end)
        {
            int mid = (start + end) / 2;
            int requiredDays = fun(weights, mid);

            if (requiredDays <= days)
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        return start;
    }
};

int main()
{
    // Predefined weights array
    vector<int> weights = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int days = 5; // Predefined number of days

    Solution sol;
    cout << "Minimum capacity needed: " << sol.shipWithinDays(weights, days) << endl;

    return 0;
}
