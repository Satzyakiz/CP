// An image is represented by a 2-D array of integers, each integer representing
// the pixel value of the image (from 0 to 65535).
//
// Given a coordinate (sr, sc) representing the starting pixel (row and column)
// of the flood fill, and a pixel value newColor, "flood fill" the image.
//
// To perform a "flood fill", consider the starting pixel, plus any pixels
// connected 4-directionally to the starting pixel of the same color as the
// starting pixel, plus any pixels connected 4-directionally to those pixels
// (also with the same color as the starting pixel), and so on. Replace the color
// of all of the aforementioned pixels with the newColor.
//
// At the end, return the modified image.

// 1) DFS traversal in 4 directions and change subsequent values if it is
// equivalent to old value.

void dfs(vector<vector<int>> &image,int r,int c,int newColor,int oldColor){
  if(r < 0 || c < 0 || r >= image.size() || c >= image[r].size() || image[r][c] == newColor){
    return;
  }
  if(image[r][c] == oldColor){
    image[r][c] = newColor;
    DFS(image,r-1,c,newColor,oldColor);
    DFS(image,r+1,c,newColor,oldColor);
    DFS(image,r,c-1,newColor,oldColor);
    DFS(image,r,c+1,newColor,oldColor);
  }
}

vector<vector<int>> floodFill(vector<vector<int>> &images, int sr,int sc, int newColor){
  DFS(images,sr,sc,newColor);
  return images;
}
