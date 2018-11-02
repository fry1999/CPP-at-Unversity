#include<iostream>
#include<algorithm>
using namespace std;

class DanhSach{
	private:
		float A[100];
		int n;
	public:
		DanhSach();
		void enter();
		void getMaxMin();
		void sortArray();
		void insert(int x);
		void deleteX(int x);
		void show();
		//~DanhSach();
		
};
DanhSach::DanhSach(){
	n=0;
}
void DanhSach::enter(){
	cout<<"Nhap kich thuoc mang: ";
	cin>>n;
	for(int i=0; i<n; ++i) cin>>A[i];
}
void DanhSach::getMaxMin(){
	int max1=A[0], max2=A[1], index1=0, index2=1;
	for(int i=1; i<n; ++i){
		if(A[i]>max1) {
			max2=max1;
			index2=index1;
			max1=A[i];
			index1=i;
		}
		else if(A[i]>max2){
			max2= A[i];
			index2=i;
		}
	}
	cout<<"Phan tu lon nhat trong mang: "<<max1<<", chi so: "<<index1<<endl;
	cout<<"Phan tu lon nhi trong mang: "<<max2<<", chi so: "<<index2<<endl;
}
void DanhSach::sortArray(){
	sort(A, A+n, greater<int>()	);
}
void DanhSach::insert(int x){
	for(int i=0; i<n; ++i){
		if(A[i] < x){
			n++;
			for(int j=n-1; j>i; j--){
				A[j]=A[j-1];
			}
			A[i]=x;
			break;
		}
	}
}
void DanhSach::deleteX(int x){
	for(int i=0; i<n; ++i){
		if(A[i]==x){
			for(int j=i+1; j<n; ++j){
				A[j-1]=A[j];
			}
			n--;
			break;
		}
	}
}
void DanhSach::show(){
	for(int i=0; i<n; ++i) cout<<A[i]<<" ";
	cout<<"\n";
}
int main(){
	DanhSach a;
	a.enter();
	a.getMaxMin();
	a.sortArray();
	cout<<"Mang sau khi sap xep: "<<endl;
	a.show();
	int x; 
	cout<<"Nhap so x can chen: ";
	cin>>x;
	a.insert(x);
	cout<<"Mang sau khi chen: ";
	a.show();
	a.deleteX(x);
	cout<<"Mang sau khi xoa: ";
	a.show();
}
