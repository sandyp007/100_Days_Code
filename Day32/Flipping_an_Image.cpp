//  https://leetcode.com/problems/flipping-an-image/

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        for(int i=0;i<image.size();i++){
            reverse(image[i].begin(),image[i].end()); // reverse each row
            for(int j=0; j<image[0].size(); j++){
                image[i][j] = image[i][j] ^ 1;      // flip each number
            }
        }
        return image;
    }
};