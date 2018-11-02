#include<bits/stdc++.h>
using namespace std;

class UCBC {
	private:
		int a, b;
	public:
		void init(){a=0, b=0;};
		void enter();
		int get_digit_1(){
			return a;
		}
		int get_digit_2(){
			return b;
		}
		int greatestCommonDivisor(int, int);
		int leastCommonMultiple();
};

void UCBC::enter(){
	cin>>a>>b;
}
int UCBC::greatestCommonDivisor(int a1, int b1){
	if(b1==0) return a1;
	return greatestCommonDivisor(b1, a1%b1);
}
int UCBC::leastCommonMultiple(){
	return (a*b)/greatestCommonDivisor(a, b);
}
int main(){
	UCBC obj;
	obj.init();
	obj.enter();
	int a1= obj.get_digit_1();
	int b1= obj.get_digit_2();
	cout<<"Uoc chung lon nhat: "<<obj.greatestCommonDivisor(a1, b1)<<endl;
	cout<<"Boi chung nho nhat: "<<obj.leastCommonMultiple()<<endl;
}
