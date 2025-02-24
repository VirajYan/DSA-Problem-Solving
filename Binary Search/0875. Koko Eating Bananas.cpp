//here we have changed the data types from int to long long, as it exceeds the limit of int
class Solution {
public:
    long long fun(vector<int> &piles, int mid)
    {
        long long totalH = 0;
        for(int i = 0; i < piles.size(); i++)
        {
            totalH += ceil((double)piles[i] / (double) mid);
        }
        return totalH;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());

        while(low <= high)
        {
            long long mid = (low + high)/2;
            long long totalH = fun(piles, mid);

            if(totalH <= h)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return low;
    }
};