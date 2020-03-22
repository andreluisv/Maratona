class minStack{
	public:
	stack<long long> pilha;
	long long min = INT_MAX;
	
	void push(int x){
		if (pilha.empty()){
			pilha.push(x);
			min = x;
		}else{
			if (x >= min) pilha.push(x);
			else{
				pilha.push(2LL*x-min);
				min = x;
			}
		}
	}
	
	int pop(){
		if (pilha.empty()){
			return -1;//fail flag
		}
		int y = pilha.top();
		pilha.pop();
		if (y < min){
			min = 2LL*min - y;
		}		
		return 1;//success
	}
	
	int top(){
		if (pilha.empty()) return -1;//fail flag
		if (pilha.top() > min) return pilha.top();
		return min;
	}
	
	int getMin(){
		if (pilha.empty()) return -1;//fail flag
		return this->min;
	}
		
};
