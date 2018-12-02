#include<bits/stdc++.h>

#define M 100000
using namespace std;

bool stop = true;
long sum;
vector<long> Prime;
long table[5][5];
int x[M];
bool checkSum(long a, long sum);
void sieve(int sum);
bool isDiff_0(long a);
inline void split(int arr[5], long a);
void init();
bool fill_R1C1();
bool fill_Cheo_Xuoi();
bool fill_R2();
bool fill_C2();
bool fill_R3();
bool fill_C3();
bool fill_R4();
bool fill_C4();
bool fill_C5();
bool check_Cheo_Nguoc();
void print();
void init(){
	cin>>sum;
}
bool checkSum(long a){
	return (a%10 + (a/10)%10 + (a/100)%10 + (a/1000)%10+ a/10000) == sum;
}
void sieve(){
	for(long p=2; p<M; ++p){
		if(!x[p]){
			for(long k=p*2; k<M; k+=p){
				x[k]=1;
			}
		}
	}
	for(long i= 10000; i<M; ++i){
		if(!x[i] && checkSum(i)){
			Prime.push_back(i);
		}
	}
}
bool isDiff_0(long a){
	return (a%10!=0) && (a/10)%10 !=0 && (a/100)%10 !=0 && (a/1000)%10 !=0 && (a/10000)!=0;
}
inline void split(int arr[5], long a){
	arr[0]=a/10000;
	arr[1]=(a/1000)%10;
	arr[2]=(a/100)%10;
	arr[3]=(a/10)%10;
	arr[4]=a%10;
}
bool fill_R1C1(int p, int k){
	for(int i=p; i<Prime.size(); ++i){
		if(isDiff_0(Prime[i])){
			int arr[5];
			split(arr, Prime[i]);
			for(int it=0; it<5; ++it){
				table[0][it] = arr[it];
			}
			for(int j=k; j<Prime.size(); ++j){
				if(isDiff_0(Prime[j]) && Prime[j]/10000 == table[0][0]){
					split(arr, Prime[j]);
					for(int jt=0; jt<5; ++jt){
						table [jt][0]= arr[jt];
					}
					return true;
				}
			}
		}
	}
	return false;
}
bool fill_Cheo_Xuoi(){
	for(int i=0; i<Prime.size(); ++i){
		if(Prime[i]/10000 == table[4][0] && Prime[i]%10 == table[0][4]){
			int arr[5];
			split(arr, Prime[i]);
			for(int i=0; i<5; ++i){
				table[5-i-1][i]= arr[i];
			}
			return true;
		}
		
	}
	return false;
}
bool fill_R2(){
	for(int i=0; i<Prime.size(); ++i){
		if(Prime[i]/10000 == table[1][0] && (Prime[i]/10)%10 == table[1][3]){
			int arr[5];
			split(arr, Prime[i]);
			for(int i=0; i<5; ++i){
				table[1][i]= arr[i];
			}
			//print();
			return true;
		}
	}
	return false;
}
bool fill_C2(){
	for(int i=0; i<Prime.size(); ++i){
		if(Prime[i]/10000 == table[0][1] && (Prime[i]/1000)%10 == table[1][1] && (Prime[i]/10)%10 == table[3][1] ){
			int arr[5];
			split(arr, Prime[i]);
			for(int i=0; i<5; ++i){
				table[i][1]= arr[i];
			}
			return true;
		}
	}
	return false;
}
bool fill_C3(){
	for(int i=0; i<Prime.size(); ++i){
		if(Prime[i]/10000 == table[0][2] && (Prime[i]/1000)%10 == table[1][2] && (Prime[i]/100)%10 == table[2][2] ){
			int arr[5];
			split(arr, Prime[i]);
			for(int i=0; i<5; ++i){
				table[i][2]= arr[i];
			}
			//print();
			return true;
		}
	}
	return false;
}
bool fill_R3(){
	for(int i=0; i<Prime.size(); ++i){
		if(Prime[i]/10000 == table[2][0] && (Prime[i]/1000)%10 == table[2][1] 
		&& (Prime[i]/100)%10 == table[2][2] ){
			int arr[5];
			split(arr, Prime[i]);
			for(int i=0; i<5; ++i){
				table[2][i]= arr[i];
			}
			//print();
			return true;
		}
	}
	return false;
}
bool fill_R4(){
	for(int i=0; i<Prime.size(); ++i){
		if(Prime[i]/10000 == table[3][0] && (Prime[i]/1000)%10 == table[3][1] 
		&& (Prime[i]/100)%10 == table[3][2] ){
			int arr[5];
			split(arr, Prime[i]);
			for(int i=0; i<5; ++i){
				table[3][i]= arr[i];
			}
			return true;
		}
	}
	return false;
}
bool fill_C4(){
	for(int i=0; i<Prime.size(); ++i){
		if(Prime[i]/10000 == table[0][3] && (Prime[i]/1000)%10 == table[1][3] 
		&& (Prime[i]/100)%10 == table[2][3] && (Prime[i]/10)%10 == table[3][3] ){
			int arr[5];
			split(arr, Prime[i]);
			for(int i=0; i<5; ++i){
				table[i][3]= arr[i];
			}
			return true;
		}
	}
	return false;
}
bool fill_C5(){
	for(int i=0; i<Prime.size(); ++i){
		if(Prime[i]/10000 == table[0][4] && (Prime[i]/1000)%10 == table[1][4]
		 && (Prime[i]/100)%10 == table[2][4] && (Prime[i]/10)%10 == table[3][4] ){
			int arr[5];
			split(arr, Prime[i]);
			for(int i=0; i<5; ++i){
				table[i][4]= arr[i];
			}
			return true;
		}
	}
	return false;
}
bool check_Cheo_Nguoc(){
	int number = 0;
	for(int i=0; i<5; ++i){
		number = number * 10 + table[i][i];
	}
	if(!x[number] && checkSum(number)) return true;
	return false;
}
void print(){
	for(int i=0; i<5; ++i){
		for(int j=0; j<5; ++j){
			cout<<table[i][j]<<" ";
		}
		cout<<"\n";
	}
	cout<<endl;
}
int main(){
	init();
	sieve();
	while(stop){
		for(int p = 0; p<Prime.size(); ++p){
			for(int k = 0;k<Prime.size(); ++k){
				if(fill_R1C1(p, k) && fill_Cheo_Xuoi() && fill_R2() && fill_C2() && fill_C3()
				 && fill_R3() && fill_R4() && fill_C4() && fill_C5() && check_Cheo_Nguoc())
				 {
					print();
				}
			}
		}
		stop = false;
	}
}
