//  https://leetcode.com/problems/count-integers-with-even-digit-sum/

class Solution {
public:
    int digitSum(int num)
    {
        int ans=0;
        while( num )
        {
            ans = ans + num % 10 ;
            num = num / 10 ;
        }
        return ans ;
    }
    int countEven(int num) 
    {
        int count = 0 ;
        for ( int i = 1 ; i <= num ; i++ )
        {
            if ( digitSum(i) % 2 == 0 )
                count++ ;
        }
        return count ;
    }
};