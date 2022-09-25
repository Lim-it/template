    //dijkstra with prioirity queue. time complexity:O(ElogE)
    //N = size
    //adjacency matrix format: vector<vector<pair<int, int>>>
    //store each edge in the index of the source, first is end point, second is weight 
    
    priority_queue<pair<int, int>, vector<pair<ll, int>>, greater<>> pq;
    vector<int> vis(2 * N, 0);
    pq.push({0, 0});
    d[0] = 0;

    while (!pq.empty()) {
        int v = pq.top().second;
        pq.pop();

        if(vis[v]) continue;
	vis[v] = 1;

        for (auto [i, w] : adj[v]){
            d[i] = min(d[i], d[v] + w);
            pq.push({d[i], i});
        }
    }
