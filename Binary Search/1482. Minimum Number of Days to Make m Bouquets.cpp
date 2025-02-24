class Solution {
public:
    bool fun(vector <int> &bloomDay, int mid, int m, int k)
    {
        int possibleBouquets = 0;
        int cnt = 0;
        for(int i = 0; i<bloomDay.size(); i++)
        {
            if(bloomDay[i] <= mid)
            {
                cnt ++;
            }
            else
            {
                possibleBouquets += (cnt/k);
                cnt  = 0;
            }
        }
        possibleBouquets += (cnt/k);
        return possibleBouquets >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        //due to limit of int we are taking long long
        long long val = m * 1LL * k * 1LL; 
        if(val > bloomDay.size()) return -1;
        /* or else if(m * k >bloomDay.size()) return -1; also works
        this is basically to check if it not possible to make bouquets
        */
        int s = *min_element(bloomDay.begin(), bloomDay.end());   
        int e = *max_element(bloomDay.begin(), bloomDay.end());

        while(s <= e)
        {
            int mid = (s + e) / 2;
            if(fun(bloomDay, mid, m, k))
            {
                e = mid - 1;
            }
            else
            {
                s = mid + 1;
            }
        }
        return s;
    }
};