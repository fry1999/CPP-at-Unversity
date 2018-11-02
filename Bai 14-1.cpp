#include<iostream>
#include<cmath>
using namespace std;

struct Matrix{
	int n;
	float **data;
};
void creatMemory(Matrix &a){
	a.data= new float *[a.n];
	for(int i=0; i<a.n; ++i){
		a.data[i]= new float [a.n];
	}
}
void deleteMemory(Matrix &a){
	for(int i=0; i<a.n; ++i){
		delete[] a.data[i];
	}
	delete [] a.data;
}
void input(Matrix &a){
	cin>>a.n;
	creatMemory(a);
	for(int i=0; i<a.n; ++i){
		for(int j=0; j<a.n; ++j){
			cin>>a.data[i][j];
		}
	}
}
void output(Matrix a){
	for(int i=0; i<a.n; ++i){
		for(int j=0; j<a.n; ++j){
			cout<<a.data[i][j]<<" ";
		}
		cout<<"\n";// x2
	}
}
int findRow(Matrix a){
	int locate=0;
	int max=0, maxR=0;
	for(int i=0; i<a.n; ++i){
		max=0;
		for(int j=0; j<a.n; ++j){
			max+=a.data[i][j];
		}
		if(i==0) maxR=max;
		if(max > maxR) {
			maxR=max;
			locate=i;
		}
	}
	return locate+1;
}
Matrix timMaTranChuyenVi(Matrix a){
	Matrix b;
	b.n= a.n;
	creatMemory(b);
	for(int i=0; i<b.n; i++){
		for(int j=0; j<b.n; ++j){
			b.data[j][i]= a.data[i][j];
		}
	}
	return b;
}
int timDinhThuc(Matrix a){
	if(a.n==1) return a.data[0][0];
	if(a.n==2) return a.data[0][0] *a.data[1][1] - a.data[0][1]*a.data[1][0];
	Matrix temp;
	temp.n= 2*a.n;
	creatMemory(temp);
	int det=0;
	for(int i=0; i<a.n; ++i){
		for(int j=0; j<temp.n; ++j){
			temp.data[i][j]=a.data[i][j%a.n];
		}
	}
	int t=1;
	for(int i=0; i<a.n; ++i){
		for(int j=0; j<a.n; ++j){
			t *= temp.data[j][j+i];
		}
		det +=t;
		t=1;
	}
	for(int i=a.n; i<temp.n; ++i){
		for(int j=0; j<a.n; ++j){
			t*=temp.data[j][i-j];
		}
		det -=t;
		t=1;
	}
	deleteMemory(temp);
	return det;
}
Matrix maTranCon(Matrix b, int row, int col){
	Matrix d;
	int k=0, p=0;
	d.n= b.n-1;
	creatMemory(d);
	for(int i=0; i<b.n; ++i){
		for(int j=0; j<b.n; ++j){
			if(i!=row && j!=col){
				if(p<d.n)
				d.data[k][p++]=b.data[i][j];
				else{
					p=0;
					d.data[++k][p]=b.data[i][j];
					p=1;
				}
			}
		}
	}
	return d;
}
Matrix timMaTranPhuHop(Matrix b){
	Matrix c;
	c.n= b.n;
	creatMemory(c);
	for(int row=0; row<b.n; ++row){
		for(int col=0; col<b.n; ++col){
			c.data[row][col]=pow(-1, row+col+2) * timDinhThuc(maTranCon(b, row, col));
		}
	}
	return c;
}
Matrix timMaTranNghichDao(Matrix c, int det){
	Matrix d;
	d.n= c.n;
	creatMemory(d);
	for(int i=0; i<c.n; ++i){
		for(int j=0; j<c.n; ++j){
			d.data[i][j]= (float)1/det * c.data[i][j];
		}
	}
	return d;
}
void manu(){
	Matrix a, b, c, d;
	int choice;
	cout<<"1. Nhap ma tran a: "<<endl;
	cout<<"2. Xuat ma tran: "<<endl;
	cout<<"3. Hang co tong lon nhat: "<<endl;
	cout<<"4. Dinh thuc cua ma tran: "<<endl;
	cout<<"5. Ma tran chuyen vi cua a: "<<endl;
	cout<<"6. Ma tran phu hop cua a: "<<endl;
	cout<<"7. Ma tran nghich dao cuar a: "<<endl;
	cout<<"0. Ket thuc chuong trinh."<<endl;
	while(1){
		cin>>choice;
		switch(choice){
			case 1: {
				input(a);
				break;
			}
			case 2: {
				output(a);
				break;
			}
			case 3: {
				cout<<"Hang co tong lon nhat: "<<findRow(a)<<endl;
				break;
			}
			case 4:{
				cout<<"Dinh Thuc cua ma tran a: "<<timDinhThuc(a)<<endl;
				break;
			}
			case 5:{
				b = timMaTranChuyenVi(a);
				cout<<"Ma tran chuyen vi cua ma tran a: "<<endl;
				output(b);
				break;
			}
			case 6:{
				c= timMaTranPhuHop(b);
				cout<<"Ma tran phu hop cua ma tran a: "<<endl;
				output(c);
				break;
			}
			case 7:{
				int det = timDinhThuc(a);
				d= timMaTranNghichDao(c, det);
				cout<<"Ma tran nghich dao ma tran a: "<<endl;
				output(d);
				break;
			}
			default: break;
		}
	}
	deleteMemory(a);
	deleteMemory(b);
	deleteMemory(c);
	deleteMemory(d);
}
int main(){
	manu();
	
}
