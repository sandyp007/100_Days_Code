// https://leetcode.com/problems/number-of-changing-keys/

class Solution {
public:
    int countKeyChanges(string str) {

        char previous = str[0];

        int countChanges = 0;

        for( auto ele : str)
        {
            if( ele != previous && ele + 32 != previous && ele - 32 != previous)
            {
                 previous = ele;
                 countChanges += 1;
            }
        }   

        return countChanges;
    }
};