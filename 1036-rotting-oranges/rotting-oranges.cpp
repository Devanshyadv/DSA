class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows=grid.size(), cols=grid[0].size();
    queue<pair<int,int>> q;
    int fresh=0, time=0;
    int dr[]={1,-1,0,0}, dc[]={0,0,1,-1};
    
    // Step 1: Sab rotten oranges queue mein ek saath daalo
    for(int r=0;r<rows;r++) for(int c=0;c<cols;c++) {
        if(grid[r][c]==2) q.push({r,c});  // multi-source!
        if(grid[r][c]==1) fresh++;
    }
    // Step 2: BFS — ek level = 1 minute
    while(!q.empty()&&fresh>0) {
        int sz=q.size(); time++;           // is minute mein sab process karo
        for(int i=0;i<sz;i++) {
            auto [r,c]=q.front(); q.pop();
            for(int d=0;d<4;d++) {
                int nr=r+dr[d], nc=c+dc[d];
                if(nr>=0&&nr<rows&&nc>=0&&nc<cols&&grid[nr][nc]==1) {
                    grid[nr][nc]=2; fresh--; q.push({nr,nc});
                }
            }
        }
    }
    return (fresh==0) ? time : -1;  // -1 = impossible (isolated fresh orange)
    }
};