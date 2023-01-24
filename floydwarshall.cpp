vector<vector<int>> g;
int n;
int MAX = 2e9;

void floydwarshall(){
    for(int k = 0; k < n; k++)
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if(g[i][k] != -MAX && g[k][j] != -MAX && (g[i][j] == -MAX || g[i][k] + g[k][j] < g[i][j]))
                    g[i][j] = g[i][k] + g[k][j];
}
