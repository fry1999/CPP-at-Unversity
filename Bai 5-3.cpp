#include<iostream>
using namespace std;

class Factor{
	private:
		int k;
		int integer;
		int A[100];
	public:
		void init(){integer =0, k=0;};
		void enter();
		void analyze();
		void showAnswer();
};

void Factor::enter(){
	cin>>integer;
}
void Factor::analyze(){
	int p=2;
	while(integer%p==0){
		A[k++]=p;
		integer/=p;
	}
	p++;
	while(p<=11){
		while(integer%p==0){
			A[k++]=p;
			integer/=p;
		}
		p+=2;
	}
	if(integer!=1) A[k++]=integer;
}
void Factor::showAnswer(){
	for(int i=0; i<k; ++i){
		if(i!=k-1) cout<<A[i]<<" * ";
		else cout<<A[i];
	}
	return ;
}
int main(){
	Factor obj;
	obj.init();
	obj.enter();
	obj.analyze();
	obj.showAnswer();
	return 0;
}
