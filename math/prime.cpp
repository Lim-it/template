//prime related funcitons

//check prime
bool prime_check(int n){  //check if n prime
    if((n>2 && n%2 == 0) || n==1 || n==0) return false;
    vector<bool> isprime(n+1, true);
    isprime[0] = isprime[1] = false;
    for (int i = 3; i <= n; i+=2) {
        if (isprime[i] && (long long)i * i <= n) {
            for (int j = i * i; j <= n; j += i)
                isprime[j] = false;
        }
    }
    return isprime[n];
}

//list primes from range
void prime_range(int l, int r){  //list
    vector<bool> isprime(r+1, true);
    isprime[0] = isprime[1] = false;
    for (int i = 3; i <= r; i+=2) {
        if (isprime[i] && (long long)i * i <= r) {
            for (int j = i * i; j <= r; j += i)
                isprime[j] = false;
        }
    }
    if(l <= 2 && r >= 2){
        l = 3;
        cout << "2 ";
    }
    for(int i=l ;i<=r; i+=2) if(isprime[i]) cout << i << ' ';
    cout << '\n';
    return;
}

//count prime from range
int prime_count(int l, int r){  //list
    int cnt = 0;
    vector<bool> isprime(r+1, true);
    isprime[0] = isprime[1] = false;
    for (int i = 3; i <= r; i+=2) {
        if (isprime[i] && (long long)i * i <= r) {
            for (int j = i * i; j <= r; j += i)
                isprime[j] = false;
        }
    }
    if(l <= 2 && r >= 2){
        l = 3;
        cnt++;
    }
    for(int i=l ;i<=r; i+=2) if(isprime[i]) cnt++;
    return cnt;
}
