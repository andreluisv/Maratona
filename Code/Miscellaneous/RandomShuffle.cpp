int rnd[n];

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
iota(rnd, rnd+n, 0);
shuffle(rnd, rnd+n, rng);

//for (int i = 0; i < n; i++) cout << rnd[i] << " \n"[i==n-1];
