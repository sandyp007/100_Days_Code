//  https://leetcode.com/problems/arranging-coins/

class Solution {
public:
    int arrangeCoins(int n) {
        int start=1;
        int end=n;
        int ans;
        long long mid=start+(end-start)/2;
        while(start<=end){
            long long calc=mid*(mid+1)/2; //Total number of coin needed 
                            //for complete 'mid' no. of stairs
            if(calc<=n){
                ans=mid;
                start=mid+1;// Check for another possible no. of 
                            //complete which could be made using the  
                            //given coin
            }else if(calc>n){
                end=mid-1;// If total number of coin needed for
                        //complete 'mid' no. of stairs is greater
                    //than given n coins then the possible number 
                    //of complete stairs which could be made using
                //given coins is less than 'mid'
            }
            mid=start+(end-start)/2;
        }
        return  ans;
    }
};