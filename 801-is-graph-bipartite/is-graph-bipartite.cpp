class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int v=graph.size();
        vector<int>visited(v,-1);
        queue<pair<int,int>>q;
        for(int i=0;i<v;i++){
            if(visited[i]==-1){
                q.push({i,0});
                visited[i]=0;
            }
            while(!q.empty()){
            int nb=q.front().first;
            int vis=q.front().second;
            q.pop();
            for(int i:graph[nb]){
                if(visited[i]==-1 ){
                    if(vis==0){
                        q.push({i,1});
                        visited[i]=1;
                    }
                    else{
                        q.push({i,0});
                        visited[i]=0;
                    }
                }
                if((visited[i]==1 && visited[nb]==1)||(visited[i]==0 && visited[nb]==0)){
                    return false;
                }

            }
        }}
        return true;
    }
};