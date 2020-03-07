class minStack{
	public:
	stack<int> pilha;
	int min = INT_MAX;
	
	void push(int x){
		if (pilha.empty()){
			pilha.push(x);
			min = x;
		}else{
			if (x >= min) pilha.push(x);
			else{
				pilha.push(2*x-min);
				min = x;
			}
		}
	}
	
	int pop(){
		if (pilha.empty()){
			return -1;
		}
		int y = pilha.top();
		pilha.pop();
		if (y < min){
			min = 2*min - y;
		}		
		return 1;
	}
	
	int getMin(){
		if (pilha.empty()) return -1;
		return this->min;
	}
		
};
