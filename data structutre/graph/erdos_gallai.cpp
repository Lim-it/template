bool er(vector<int>& d,int n){                   //to solve the graph realization problem in nlogn time
    vector<long long> h(n, 0);
    h[0] = d[0];
    for(int i = 1; i < n; i++){
        h[i] = h[i-1] + (long long)d[i];
    }
    long long w = n;
    for(long long i = 1; i <= n; i++) {
        while(w > 0 && d[w - 1] < i) w--;
        long long y = max(i, w);
        if(h[i - 1] > i * (y - 1) + h[n - 1] - h[y - 1])
            return false;
    }
    return true;
}
