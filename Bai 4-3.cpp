#include<iostream>
using namespace std;

class base{
	private:
		int a;
		int b;
		int base_b[30];
		int k;
	public:
		void start(){a=0, b=0, k=0;};
		void init(int , int);
		void enter();
		void convert();
		void showAnswer();
	
};
void base::init(int a1, int b1){
	a=a1; b=b1;
}
void base::enter(){
	cin>>a>>b;
}
void base::convert(){
	string Base="0123456789ABCDEFGHEJKLMNOPQRSTUVWXYZ";
	while(a){
		base_b[k++]=a%b;
		a/=b;
	}
}
void base::showAnswer(){
	for(int i=0; i<k; ++i){
		cout<<base_b[i]<<" ";
	}
}
int main(){
	base obj;
	obj.start();
	obj.init(4, 5);
	obj.enter();
	obj.convert();
	obj.showAnswer();
}
