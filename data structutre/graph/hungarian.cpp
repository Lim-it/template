//O(n^3)
class Hungarian {
    public:
    int n, max_match; //n workers and n jobs
    vector<vector<int>> cost;
    vector<int> lx, ly; //labels of X and Y parts
    vector<int> xy; //xy[x] - vertex that is matched with x,
    vector<int> yx; //yx[y] - vertex that is matched with y
    vector<bool> S, T; //sets S and T in algorithm
    vector<int> slack;
    vector<int> slackx;
    vector<int> prev;

    void init_labels(){
        lx.resize(n, 0);
        ly.resize(n, 0);
        for (int x = 0; x < n; x++)
            for (int y = 0; y < n; y++)
                lx[x] = max(lx[x], cost[x][y]);
    }

    void update_labels(){
        int x, y;
        int delta = 2e9; //init as infinity
        for (y = 0; y < n; y++)
            if (!T[y])
                delta = min(delta, slack[y]);
        for (x = 0; x < n; x++)
            if (S[x])
                lx[x] -= delta;
        for (y = 0; y < n; y++)
            if (T[y])
                ly[y] += delta;
        for (y = 0; y < n; y++)
            if (!T[y])
                slack[y] -= delta;
    }

    void add_to_tree(int x, int prevx) {
        S[x] = true;
        prev[x] = prevx;
        //update slack
        for (int y = 0; y < n; y++) {
            if (lx[x] + ly[y] - cost[x][y] < slack[y]) {
                slack[y] = lx[x] + ly[y] - cost[x][y];
                slackx[y] = x;
            }
        }
    }
 
    void augment(){
        if (max_match == n) return;
        int x, y, root;
        queue<int> qs;
        S.assign(n, false); 
        T.assign(n, false);
        prev.assign(n, -1);
         
        //finding root
        for (x = 0; x < n; x++) {
            if (xy[x] == -1){
                root = x;
                qs.push(x);
                prev[x] = -2;
                S[x] = true;
                break;
            }
        }

        //initialize slack
        for (y = 0; y < n; y++){
            slack[y] = lx[root] + ly[y] - cost[root][y];
            slackx[y] = root;
        }

        //second part
        while (true) {
            while (!qs.empty()) {
                x = qs.front();
                qs.pop();
                for (y = 0; y < n; y++)
                    if (cost[x][y] == lx[x] + ly[y] && !T[y]){
                        if (yx[y] == -1) break;
                            T[y] = true;
                        qs.push(yx[y]);
                        add_to_tree(yx[y], x);
                    }
                if (y < n) break;
            }
            if (y < n) break;
             
            update_labels();

            for (y = 0; y < n; y++){
                if (!T[y] && slack[y] == 0){
                    if (yx[y] == -1) {
                        x = slackx[y];
                        break;
                    }
                    else{
                        T[y] = true;
                        if (!S[yx[y]]){
                            qs.push(yx[y]);
                            add_to_tree(yx[y], slackx[y]);
                        }
                    }
                }
            }
            if (y < n) break;
        }
         
        if (y < n){
            max_match++;
            for (int cx = x, cy = y, ty; cx != -2; cx = prev[cx], cy = ty){
                ty = xy[cx];
                yx[cy] = cx;
                xy[cx] = cy;
            }
            augment();
        }
    }//end of augment() function
      
    void hungarian(){
        int ret = 0;
        max_match = 0;
        init_labels(); //step 0
        augment(); //steps 1-3
         
        for (int x = 0; x < n; x++) 
            ret += cost[x][xy[x]];
     
        cout << -1 * ret << endl;

        for(int x = 0; x < n; x++){
            cout << x << ' ' << xy[x] << endl;
        }
    }
     
    void init_cost() {
        cin >> n;
        cost.assign(n, vector<int>(n, 0));
        xy.resize(n, -1);
        yx.resize(n, -1);
        slack.resize(n);
        slackx.resize(n);
        S.resize(n);
        T.resize(n);
        prev.resize(n);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                int cst;
                cin >> cst;
                cost[i][j] = -1 * cst;
            }
        }
    }
};
