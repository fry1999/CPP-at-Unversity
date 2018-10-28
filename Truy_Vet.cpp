#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;

bool checkSumEqualS(long a, long s){
	while(a){
		s-= (a%10);
		a/=10;
	}
	return s==0;
}
vector<int> creatAVector(long a, int n){
	vector<int> x;
	while(a){
		x.push_back(a%10);
		a/=10;
	}
	reverse(x.begin()+0, x.begin()+ n);
	return x;
}
vector<vector<int> > sieveOfEratothenes(int n, int s){
	long m= pow(10, n);
	bool prime1[m+1];
	vector<vector<int> > arrayPrime;
	memset(prime1, true, m);
	for(long p=2; p<m; ++p){
		if(prime1[p]){
			if(p>=pow(10, n-1)){
				if(checkSumEqualS(p, s))
				arrayPrime.push_back(creatAVector(p,n));
			}
			for(long k=p*2; k<m; k+=p){
				prime1[k]=false;
			}
		}
	}
	return arrayPrime;
}
bool checkDifferenceOf0(vector<int> a){
	for(int i=0; i<a.size();  ++i){
		if(a[i]==0) return false;
	}
	return true;
}
bool fillSquare(int n, vector<vector<int> > arrayPrime, int p, int k, int ans[][100]){
	bool f= false;
	for(int i=p; i<arrayPrime.size(); ++i){
		if(checkDifferenceOf0(arrayPrime[i])){
			f=true;
			for(int z=0; z<n; z++){
				ans[0][z]=arrayPrime[i][z];
			}
			break;
		}
	}
	if(f==false){
		return false;
	}
	f=false;
	for(int i=k; i<arrayPrime.size(); ++i){
		if(checkDifferenceOf0(arrayPrime[i])){
			f=true;
			for(int z=0; z<n; z++){
				ans[z][0]=arrayPrime[i][z];
			}
			break;
		}
	}
	if(f==false){
		return false;
	}
	f=false;
	for(int i=0; i<arrayPrime.size(); ++i){
		if(arrayPrime[i][0]==ans[n-1][0] && arrayPrime[i][n-1]==ans[0][n-1]){
			f=true;
			for(int z=0; z<n; ++z){
				ans[n-z-1][z]=arrayPrime[i][z];
			}
			break;
		}
	}
	if(f==false){
		return false;
	}
	f=false;
	for(int i=0; i<arrayPrime.size(); ++i){
		if(arrayPrime[i][0]==ans[1][0] && arrayPrime[i][n-2]==ans[1][n-2]){
			f=true;
			for(int z=0; z<n; ++z){
				ans[1][z]=arrayPrime[i][z];
			}
			break;
		}
	}
	if(f==false){
		return false;
	}
	f=false;
	for(int i=0; i<arrayPrime.size(); ++i){
		if(arrayPrime[i][0]==ans[0][1] && arrayPrime[i][1]==ans[1][1] && arrayPrime[i][n-2]==ans[n-2][1]){
			f=true;
			for(int z=0; z<n; ++z){
				ans[z][1]=arrayPrime[i][z];
			}
			break;
		}
	}
	if(f==false){
		return false;
	}
	f=false;
	for(int i=0; i<arrayPrime.size(); ++i){
		if(arrayPrime[i][0]==ans[2][0] && arrayPrime[i][1]==ans[2][1] && arrayPrime[i][2]==ans[2][2]){
			f=true;
			for(int z=0; z<n; ++z){
				ans[2][z]=arrayPrime[i][z];
			}
			break;
		}
	}
	if(f==false){
		return false;
	}
	f=false;
	for(int i=0; i<arrayPrime.size(); ++i){
		if(arrayPrime[i][0]==ans[0][2] && arrayPrime[i][1]==ans[1][2] && arrayPrime[i][2]== ans[2][2]){
			f=true;
			for(int z=0; z<n; ++z){
				ans[z][2]=arrayPrime[i][z];
			}
			break;
		}
	}
	if(f==false){
		return false;
	}
	f=false;
	for(int i=0; i<arrayPrime.size(); ++i){
		if(arrayPrime[i][0]==ans[3][0] && arrayPrime[i][1]==ans[3][1] && arrayPrime[i][2]== ans[3][2]){
			f=true;
			for(int z=0; z<n; ++z){
				ans[3][z]=arrayPrime[i][z];
			}
			break;
		}
	}
	if(f==false){
		return false;
	}
	f=false;
	for(int i=0; i<arrayPrime.size(); ++i){
		if(arrayPrime[i][0]==ans[0][3] && arrayPrime[i][1]==ans[1][3] && arrayPrime[i][2]== ans[2][3] && arrayPrime[i][3]==ans[3][3]){
			f=true;
			for(int z=0; z<n; ++z){
				ans[z][3]=arrayPrime[i][z];
			}
			break;
		}
	}
	if(f==false){
		return false;
	}
	f=false;
	for(int i=0; i<arrayPrime.size(); ++i){
		if(arrayPrime[i][0]==ans[0][4] && arrayPrime[i][1]==ans[1][4] && arrayPrime[i][2]== ans[2][4] && arrayPrime[i][3]==ans[3][4]){
			f=true;
			for(int z=0; z<n; ++z){
				ans[z][4]=arrayPrime[i][z];
			}
			break;
		}
	}
	if(f==false){
		return false;
	}
	f=false;
	int sum=0;
	for(int i=0; i<n; ++i){
		sum+=ans[i][i];
	}
	if(sum!=17) return false;
	return true;
}
void output(vector<vector<int> >arrayPrime, int n){
	for(int i=0; i<arrayPrime.size(); ++i){
		for(int j=0; j<arrayPrime[i].size(); ++j){
			cout<<arrayPrime[i][j]<<" ";
		}
		cout<<endl;
	}
}

void printSquare(int ans[][100], vector<vector<int> >arrayPrime, int n){
	int static p=0, k=0;
	for(p=0; p<arrayPrime.size(); ++p){
		for(k=0; k<arrayPrime.size(); ++k){
			if(fillSquare(n, arrayPrime, p, k, ans)){
				for(int i=0; i<n; ++i){
					for(int j=0; j<n; ++j){
						cout<<ans[i][j]<<" ";
					}
					cout<<"\n";
				}
				return;
			}
		}
	}
	cout<<"NO finding!";
	return ;
}
int main(){
	int ans[100][100];
	vector<vector<int> > arrayPrime;
	int n, s;
	cin>>n>>s;
	arrayPrime = sieveOfEratothenes(n, s);
	printSquare(ans, arrayPrime, n);
	//output(arrayPrime, n);
}
