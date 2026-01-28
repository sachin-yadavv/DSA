class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
         vector<vector<pair<int,int>>> adj(n+1);
        
        for(auto &e : edges){
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }
        
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;
        
        vector<int> dist(n+1,1e9),parent(n+1);
        for(int i=0;i<=n;i++) parent[i]=i;
        dist[1]=0;
        pq.push({0,1});
        
        while(!pq.empty()){
            auto it= pq.top();
            int node=it.second;
            int dis=it.first;
            pq.pop();
            
            if(dis > dist[node]) continue;
            
            for(auto it : adj[node]){
                int adjNode=it.first;
                int edw=it.second;
                if(dis+edw<dist[adjNode]){
                    dist[adjNode]=dis+edw;
                    pq.push({dis+edw,adjNode});
                    parent[adjNode]=node;
                }
            }
        }
        
        if(dist[n]==1e9) return {-1};
        vector<int>ans;
        int node=n;
        while(parent[node]!=node){
            ans.push_back(node);
            node=parent[node];
        }
        ans.push_back(1);
        reverse(ans.begin(),ans.end());
        
        ans.insert(ans.begin(), dist[n]);
        return ans;
    }
};