void primeFactors(long long N){
    int cc = 0;

    while(!(N%2)){
        N >>= 1;
        cc++;
    }

    if (cc) cout << 2 << " " << cc << endl;

    for (long long i = 3; i <= sqrt(N); i+=2){
        cc = 0;
        while(N%i == 0){
            N /= i;
            cc++;
        }
        if (cc) cout << i << " " << cc << endl;
    }

    if (N>2) cout << N << " " << 1 << endl;
}
