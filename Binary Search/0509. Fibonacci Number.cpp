//FIBONACCI SERIES : 0,1,1,2,3,5,8
class Solution {
public:
    int fib(int n) {
        if(n==0) return 0; //BASE CONDITION
        if(n<=2) return 1; //BASE CONDITION
        return fib(n-1)+fib(n-2); //RECRSIVE CALL
    }
};