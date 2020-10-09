vector<int> sufixarray(const string& in) {
  int n = in.size(), c = 0;
  vector<int> temp(n), posBucket(n), bucket(n), bpos(n), out(n);
  for (int i = 0; i < n; i++) out[i] = i; 
  sort(out.begin(), out.end(), [&](int a, int b) { return in[a] < in[b]; });
  for (int i = 0; i < n; i++) {
    bucket[i] = c;
    if (i + 1 == n || in[out[i]] != in[out[i + 1]]) c++;
  }
  for (int h = 1; h < n && c < n; h <<= 1) {
    for (int i = 0; i < n; i++) posBucket[out[i]] = bucket[i];
    for (int i = n - 1; i >= 0; i--) bpos[bucket[i]] = i;
    for (int i = 0; i < n; i++) {
      if (out[i] >= n - h) temp[bpos[bucket[i]]++] = out[i];
    }
    for (int i = 0; i < n; i++) {
      if (out[i] >= h) temp[bpos[posBucket[out[i] - h]]++] = out[i] - h;
    }
    c = 0;
    for (int i = 0; i + 1 < n; i++) {
        int a = (bucket[i] != bucket[i + 1]) || (temp[i] >= n - h)
            || (posBucket[temp[i + 1] + h] != posBucket[temp[i] + h]);
        bucket[i] = c;
        c += a;
    }
    bucket[n - 1] = c++;
    temp.swap(out);
  }
  return out;
}
