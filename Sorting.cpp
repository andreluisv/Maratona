#include <bits/stdc++.h>

using namespace std;

 bool compareInterval(pair<int, int> i1, pair<int, int> i2) 
 { 
     return (i1.second < i2.second); 
 } 

int main() {
    vector<pair<int, int> > arr;

    for (int i = 8; i >= 0; i --) arr.push_back(make_pair(i, ceil(random()/500000000)));

    cout << "Not Sorted:\n";
    for (int i = 0; i < 9; i ++) cout << "(" << arr[i].first << ", " << arr[i].second << ") ";
        cout << endl;

    sort(arr.begin(), arr.end(), compareInterval);

        cout << "Sorted:\n";
    for (int i = 0; i < 9; i ++) cout << "(" << arr[i].first << ", " << arr[i].second << ") ";
        cout << endl;
   return 0;
}
//sudo g++ -o main mar.cpp
// ./main