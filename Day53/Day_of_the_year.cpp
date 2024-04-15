//  https://leetcode.com/problems/day-of-the-year/

class Solution {
public:

    // checking if leap year
    bool isLeap(int yy){
        if(yy%400==0 || (yy%4==0 && yy%100!=0)) 
        return true;
        return false;
    }

    int dayOfYear(string date) {
        // converting to number as per formate
        int yy = stoi(date.substr(0,4));
        int mm = stoi(date.substr(5,7));
        int dd = stoi(date.substr(8,10));

        // array of total number of days in months
        vector<int> month = {31,28,31,30,31,30,31,31,30,31,30,31};

        if(isLeap(yy)) month[1] = 29;

        int ans=0;
        for(int i=0;i<mm-1;i++) {
            ans += month[i];
        }
        ans += dd;
        return ans;
    }
};