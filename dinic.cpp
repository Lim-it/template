// for max flow problem
struct Edge{
    int v, u;
    int cap, flow;
    Edge(int u, int v, int cap, int flow):u(u), v(v), cap(cap), flow(flow){}
};

class Dinic{
public:
    const int INF = 2e9;
    vector<Edge> e;
    vector<vector<int>> adj;
    int n, m = 0;
    int s, t;
    vector<int> level, ptr;
    queue<int> q;
    Dinic(int, int, int);
    void add_edge(int, int, int);
    void reset()
    bool bfs();
    int dfs(int, int);
    int flow();
};

Dinic::Dinic(int n, int s, int t): n(n), s(s), t(t) {
    adj.resize(n);
    level.resize(n);
    ptr.resize(n);
}

void Dinic::add_edge(int u, int v, int cap){
    e.emplace_back(u, v, cap, 0);
    e.emplace_back(v, u, cap, 0);
    adj[u].push_back(m);
    adj[v].push_back(m + 1);
    m += 2;
}

bool Dinic::bfs(){ //build level
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int i : adj[u]){
            if(e[i].cap - e[i].flow <= 0) continue;
            if(level[e[i].v] != -1) continue;
            level[e[i].v] = level[u] + 1;
            q.push(e[i].v);
        }
    }
    return level[t] != -1; //check
}

int Dinic::dfs(int u, int pushed){
    if(pushed == 0) return 0;
    if(u == t) return pushed; //reach end
    for(int& x = ptr[u]; x < (int)adj[u].size(); x++){
        int i = adj[u][x];
        int v = e[i].v;
        if(level[u] + 1 != level[v] || e[i].cap - e[i].flow < 1) continue;
        int res = dfs(v, min(pushed, e[i].cap - e[i].flow));
        if(res == 0) continue;
        e[i].flow += res;
        e[i ^ 1].flow -= res;
        return res;
    }
    return 0;
}

int Dinic::flow(){
    int f = 0;
    while(1){
        fill(level.begin(), level.end(), -1);
        fill(ptr.begin(), ptr.end(), 0);
        level[s] = 0;
        q.push(s);
        if(!bfs()) break;
        while(int push = dfs(s, INF)){
            f += push;
        }
    }
    return f;
}

void Dinic::reset(){
    for(auto& ei : e){
        ei.flow = 0;
    }
    return;
}

