class Solution {
public:
 
    void dfs(vector<vector<int>>& image,int sr,int sc,int oldc,int newc){
       int row=image.size();
       int col=image[0].size();
       if(sr<0||sr>=row||sc<0||sc>=col)return;
       if(image[sr][sc]!=oldc)return;
       image[sr][sc]=newc;
       dfs(image,sr-1,sc,oldc,newc);
       dfs(image,sr+1,sc,oldc,newc);
       dfs(image,sr,sc-1,oldc,newc);
       dfs(image,sr,sc+1,oldc,newc);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int oldc=image[sr][sc];
        if(oldc==color)return image;
        dfs(image,sr,sc,oldc,color);
        return image;
        }
};