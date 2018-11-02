#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string.h>
#include<queue>
#include<fstream>
using namespace std;
class CapSo{
	private:
		int s, t;
		int root[10100];
		bool isPrime[10100];
		int order[10100];
	public:
		CapSo();
		void init();
		void sieve();
		inline void convert(int arr[], int s);
		void duongNguyenTo();
		void writeFile(ofstream &ofs);
};
CapSo::CapSo(){
	s=0, t=0;
}
void CapSo::init(){
	cin>>s>>t;
}
void CapSo::sieve(){
	memset(isPrime, true, sizeof(isPrime));
	for(int p=2; p*p<10000; ++p){
		if(isPrime[p]){
			for(int k=p*2; k<10000; k+=p){
				isPrime[k]= false;
			}
		}
	}
	if(isPrime[s]) cout<<s<<"la so nguyen to. ";
	else cout<<s<<" ko la so nguyen to";
	if(isPrime[t]) cout<<t<<"la so nguyen to. ";
	else cout<<t<<" ko la so nguyen to";
}
inline void CapSo::convert(int arr[], int s){
	arr[4] = s%10;
	arr[3] = (s/10)%10;
	arr[2]= (s/100)%10;
	arr[1]=s/1000;
}
void CapSo::duongNguyenTo(){
	memset(order, -1, sizeof(order));
	order[s]=0;
	queue<int> q;
	q.push(s);
	while(!q.empty()){
		int v= q.front();
		q.pop();
		int arr[5];
		convert(arr, v);
		{
			for(int i=4; i>0; --i){
				int temp1 = v - arr[i]*pow(10, 4-i);
				for(int j=0; j<=9; j++){
					int temp2 = temp1 + j*pow(10, 4-i);
					if(isPrime[temp2] && order[temp2]==-1 && temp2>1000){
						order[temp2] = order[v] +1;
						root[temp2]=v;
						q.push(temp2);
					}
				}
			}
		}
	}
}
void CapSo::writeFile(ofstream &ofs){
	ofs<<order[t]<<"\n";
	ofs<<t<<" ";
	while(root[t]!=s){
		ofs<<root[t]<<" ";
		t= root[t];
	}
	ofs<<s;
}
int main(){
	ofstream ofs("nguyento.in", ios::out);
	CapSo cs;
	cs.init();
	cs.sieve();
	cs.duongNguyenTo();
	cs.writeFile(ofs);
}
