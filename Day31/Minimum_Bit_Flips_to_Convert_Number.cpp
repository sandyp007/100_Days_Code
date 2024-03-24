//  https://leetcode.com/problems/minimum-bit-flips-to-convert-number/

class Solution {
public:
    int minBitFlips(int start, int goal) {
        
        int a = (start ^ goal); // this will do xor of given numbers
           //now count set bits
        int count = 0; 
        while(a){
            if(a&1){
                count++;
            }
        a = a>>1;  // this is right shift operator
        }
        return count;
    }
};