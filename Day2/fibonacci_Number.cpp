 // https://leetcode.com/problems/fibonacci-number/

class Solution {
public:
    int fib(int n) {   // Recursive approach
       if(n<=0) return 0;
       if(n==1 or n==2) return 1;

    return fib(n-1)+fib(n-2);
    }
};

