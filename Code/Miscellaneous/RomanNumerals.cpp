string AtoR(int num){
	vector<pair<int, string>> cvt = {{1000,"M"},{900,"CM"},{500,"D"},{400,"CD"},{100,"C"},
                                     {90,"XC"},{50,"L"},{40,"XL"},{10,"X"},{9,"IX"},
                                     {5,"V"},{4,"IV"},{1,"I"}};
    string R = "";
    for (int i = 0; i < (int)cvt.size(); i++){
        int val = cvt[i].first; string r = cvt[i].second;
        while(num>=val){
            num -= val;
            R += r;
        }
    }
    return R;
}

int get_id(char c){
	if (c=='I') return 0;
	if (c=='V') return 1;
	if (c=='X') return 2;
	if (c=='L') return 3;
	if (c=='C') return 4;
	if (c=='D') return 5;
	if (c=='M') return 6;
	return -1;
}

int RtoA(string R) {
	vector<int> cvt = {1, 5, 10, 50, 100, 500, 1000};
	int value = 0, n = R.size();
	for (int i = 0; i < n; i++){
		int a = get_id(R[i]), b = ((i+1<n) ? get_id(R[i+1]):-1);
		if (b!=-1 && cvt[a] < cvt[b]){
			value += cvt[b] - cvt[a];
			i++;
		}
		else value += cvt[a];
	}
	return value;
}
