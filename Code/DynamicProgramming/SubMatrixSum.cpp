const int N = 1025, M = 1025;

int mat[N][M], aux[N][M];

void preProcess(){
	for (int j = 0; j < M; i++)
		aux[0][j] = mat[0][j];
		
	for (int i = 1; i < N; i++)
		for (int j = 0; j < M; j++)
			aux[i][j] = mat[i][j] + aux[i-1][j];
	
	for (int i = 0; i < N; i++)
		for (int j = 1; j < M; j++)
			aux[i][j] += aux[i][j-1];
}

int sumQuery(int tli, int tlj, int rbi,  int rbj){
    int res = aux[rbi][rbj]; 

    if (tli > 0)
       res -= aux[tli-1][rbj]; 
    if (tlj > 0)
       res -=  aux[rbi][tlj-1]; 
    if (tli > 0 && tlj > 0)
       res +=  aux[tli-1][tlj-1]; 
       
    return res; 
}
