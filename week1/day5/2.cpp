class Solution {
public:
    void dfs(int node,vector<vector<int>> &adj,vector<int> &vis, vector<int> &parent,int &cycleStart){
        vis[node] = 1;
        for(auto it: adj[node]){
            if(!vis[it]){
                parent[it] = node;
                dfs(it,adj,vis,parent,cycleStart);
            }
            else{
                if(it!=parent[node] && cycleStart==-1){
                    cycleStart = it;
                    parent[it] = node;
                }
            }
            
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int size = edges.size();
        vector<vector<int>> adj(size+1);
        for(int i=0;i<size;i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> vis(size+1,0);
        vector<int> ans;
        vector<int> parent(size+1,0);
        unordered_map<int,int> mp;
        int cycleStart = -1;
        for(int i=1;i<=size;i++){
            if(vis[i]==0){
                dfs(i,adj,vis,parent,cycleStart);
            }
        }
        int node = cycleStart;
        while(mp.find(node)==mp.end()){
            mp[node]= 1;
            cout << parent[node] << " " << node << "\n";
            node = parent[node];
        }

        for(int i=size-1;i>=0;i--){
            if(mp.find(edges[i][0])!=mp.end() && mp.find(edges[i][1])!=mp.end()){
                return edges[i];
            }
        }
        return {};
    }
};