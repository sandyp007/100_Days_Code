//  https://leetcode.com/problems/rank-teams-by-votes/description/

class Solution {
public:
    string rankTeams(vector<string>& votes) {
         
         set<char>st;
         
         vector<char>arr;
         
         map<pair<char,int>,int>mpp;
          
         // storing the unique characters in the vector (arr) and  counting the votes for each character for a particular position         

         for(int i = 0 ; i < votes.size() ; i++)
         {   
             int cnt = 1;

             for( auto ele : votes[i])
             {
                 if(st.find(ele) == st.end())
                 {
                    arr.push_back(ele);
                    st.insert(ele);
                 }

                 mpp[{ele,cnt}] += 1;

                 cnt++;    
             }
         }

         int size = votes[0].size();
         
        // sort on the basis of the count of votes for a particular position and thereafter on the basis of alphabetical order
       
         sort( arr.begin() , arr.end(),[&mpp,&size](char a , char b)
         {
             for( int i = 1 ; i <= size; i++)
             {
                 if(mpp[{a,i}] != mpp[{b,i}])
                 {
                     return mpp[{a,i}] > mpp[{b,i}];
                 }
             }

             return a < b;
         });

        // Finally append the characters of the arr into a string and return answer 

         string ans = "";

         for( auto ele : arr)
         {
             ans += ele;
         }

         return ans;
    }
};