#include <iostream>
using namespace std;
class Solution{
    public:
    
    bool helper(string s, int l, int r){
        if(l>=r) return true;
        if(!isalnum(s[l])) return helper(s, l+1, r);
        if(!isalnum(s[r])) return helper(s, l, r+1);

        if(tolower(s[l]!=tolower(s[r]))) return false;
        return helper(s, l+1, r-1);
        
    }
    
    bool isPalindrome(string s){
        return helper(s, 0, s.size()-1);
    }
};
int main() {
    string s ="mom"; 
    Solution obj;
    if(obj.isPalindrome(s)){
        cout<<"true";
    }
    else
    {
        cout<<"false";
    }
    return 0;
}