// Input:
// image = [[1,1,1],[1,1,0],[1,0,1]]
// sr = 1, sc = 1, newColor = 2
// Output: [[2,2,2],[2,2,0],[2,0,1]]
// Explanation:
// From the center of the image (with position (sr, sc) = (1, 1)),
// all pixels connected by a path of the same color as the starting
// pixel are colored with the new color.
// Note the bottom corner is not colored 2, because it is not 4-directionally
// connected to the starting pixel.

void DFS(vector<vector<int>> &image, int r, int c, int newColor,int old){
    if(r < 0 || r >= image.size() || c < 0 || c >=image[r].size() || image[r][c] == newColor)
        return;
    if(image[r][c] == old){
        image[r][c] = newColor;
        DFS(image,r-1,c,newColor,old);
        DFS(image,r,c-1,newColor,old);
        DFS(image,r+1,c,newColor,old);
        DFS(image,r,c+1,newColor,old);
    }
}
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int old = image[sr][sc];
        DFS(image,sr,sc,newColor,old);
        return image;
    }
};
