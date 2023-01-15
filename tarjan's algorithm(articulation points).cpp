//used for finding articulation point(vertex cuts)
vector<bool> visit;
vi ent, low;
set<int> cut;
int t; //time

//initialize
t = 0;
visit.assign(n, false);
ent.assign(n, -1);
low.assign(n, -1);
for(int i = 0; i < n; i++) {
    if(!visit[i])
        dfs(i, -1);
}

//dfs function
void dfs(int u, int par){
    visit[u] = true;
    ent[u] = t;
    low[u] = t;
    t++;
    int child = 0;
    for(auto v : adj[u]){
        if(v == par) continue;
        if(visit[v]) {
            low[u] = min(low[u], ent[v]);
        }
        else{
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] >= ent[u] && par !=-1)
                cut.insert(u);
            child++;
        }
    }
    if(par == -1 && child >= 2){
        cut.insert(u);
    }
}
