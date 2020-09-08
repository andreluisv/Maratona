const double eps=1e-12;
 
double determinant(const vector<vector<double>>& A, bool swp){
	int n = A.size();
	double det=1;
	for(int i=0;i<n;i++){
		det*=A[i][i];
	}
	if(swp)det*=-1;
 
	return det;
}
vector<vector<double>> GaussJordan(vector<vector<double>> A){
	int n=A.size();
	vector<vector<double>>inv(n,vector<double>(n));
	for(int i=0;i<n;i++){
		inv[i][i]=1;
	}
	bool swp=0;
	for(int	col=0,row=0;col<n && row<n;col++,row++){
		int sel=row;
		for(int i=row;i<n;i++){
			if(fabs(A[i][col])>fabs(A[sel][col])){
				sel=i;
			}
		}
 
		if(fabs(A[sel][col])<eps){
			//Impossible: det=0
			return {{-1}};
		}
		if(sel!=row)swp^=1;
 
		for(int j=0;j<n;j++){
			swap(A[sel][j],A[row][j]);
			swap(inv[sel][j],inv[row][j]);
		}
 
		for(int i=0;i<n;i++){
			if(i!=row){
				double c=A[i][col]/A[row][col];
 
				for(int j=0;j<n;j++){
					A[i][j]-=c*A[row][j];
					inv[i][j]-=c*inv[row][j];
				}
			}
		}
	}
	
 
	//The determinant is now the main diagonal
	double det=determinant(A,swp);
	
	//Finishing the inversion process:
	for(int i=0;i<n;i++){
		double c=A[i][i];
		for(int j=0;j<n;j++){
			A[i][j]/=c;
			inv[i][j]/=c;
		}
	}
	return inv;
}

void solve(){
	int n; cin >> n;
	vector<vector<double>> mat(n, vector<double>(n)), inv;
	
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> mat[i][j];
	
	inv = GaussJordan(mat);
	
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cout << setprecision(12) << fixed << inv[i][j] << " \n"[j==n-1];
}
