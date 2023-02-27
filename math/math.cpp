
//need MOD
int mulmod(int a, int b){return (1LL * a * b)%MOD;}
int powmod(int a, int b){
    int res = 1;
    a %= MOD;
    while(b){
        if(b&1)
            res = mulmod(a, res);
        b = b >> 1;
        a = mulmod(a, a);
    }
    return res;
}

//inverse factorial
ll inv(ll a){
    return powmod(a, MOD - 2);
}
