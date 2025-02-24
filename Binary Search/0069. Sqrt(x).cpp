#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution {
public:
	int mySqrt(int x) {
        if(x == 0|| x == 1 )
        {
            return x;
        }
        int low=0;
        int high=x;
        while(low<=high)
        {
            long long mid=(low+high)/2;  
            long long val=mid*mid;
            if(val<=x)
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        return high;

    }
};

int main()
{
    int x;
    cin>>x;

    Solution sol;
    cout << "sqrt: " << sol.mySqrt(x) << endl;

    return 0;
}
