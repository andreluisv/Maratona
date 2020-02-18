bool check(int m){
	//check here arr[m]
	
}

//smallest solution
int bsmin(int l, int r){
	while(l<r){
		int m = (l+r)/2;
		if(check(m)) r=m;
		else l=m+1;
	}
	return l;
}

//biggest solution
int bsmax(int l, int r){
	while(l<r){
		int m = (l+r+1)/2;
		if(check(m)) l=m;
		else r=m-1;
	}
	return r;
}

//find element in sorted array
vector<int> arr;

//find(num, 0, arr.size()-1);
bool find(int num, int l, int r){
	while(l<r){
		int m = (l+r)/2;
		if (arr[m] == num)return true;
		else if(arr[m] > num) r=m;
		else l=m+1;
	}
	return (arr[l] == num);
}
