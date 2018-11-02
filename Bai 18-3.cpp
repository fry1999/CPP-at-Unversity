#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

class HugeInteger{
//	friend ostream &operator<<(ostream&, const HugeInteger &);
//	friend istream &operator>>(istream&, HugeInteger &) ;
	private:
		string arr;
	public:
		HugeInteger(){ arr="";};
		void enter();
		void show();
		HugeInteger operator+(HugeInteger);
		HugeInteger operator-(HugeInteger);
		HugeInteger operator*(HugeInteger);
//		HugeInteger operator\(HugeInteger);
//		HugeInteger operator==(HugeInteger);
//		HugeInteger operator!=(HugeInteger);
//		HugeInteger operator>(HugeInteger);
//		HugeInteger operator<(HugeInteger);
//		HugeInteger operator>=(HugeInteger);
//		HugeInteger operator<=(HugeInteger);
};

void HugeInteger::enter(){
	cin>>arr;
}
void HugeInteger::show(){
	cout<<arr;
}
HugeInteger HugeInteger::operator+(HugeInteger h){
	HugeInteger ans;
	ans.arr="";
	string temp1 = this->arr;
	string temp2 = h.arr;
	if(temp1.size() > temp2.size()) swap(temp1, temp2);
	int n1 = temp1.size();
	int n2 = temp2.size();
	reverse(temp1.begin(), temp1.end());
	reverse(temp2.begin(), temp2.end());
	int re=0;
	for(int i=0; i<n1; ++i){
		int t = (temp1[i] -'0') + (temp2[i]-'0') + re;
		re = t/10;
		ans.arr+= (t %10 +'0');
	}
	for(int j=n1; j<n2; ++j){
		ans.arr+= ((temp2[j] -'0')+ re)+'0';
		re=0;
	}
	if(re!=0) ans.arr= ans.arr + char(re+'0');
	reverse(ans.arr.begin(), ans.arr.end());
	return ans;
}
HugeInteger HugeInteger::operator-(HugeInteger h){
	HugeInteger ans;
	ans.arr="";
	string temp1 = this->arr;
	string temp2 = h.arr;
	string negative="";
	if(temp1.size() < temp2.size()){
		swap(temp1, temp2);//ep cho temp1 > temp2
		negative+='-';
	}
	else if(temp1.size()==temp2.size()){//
		for(int i=0; i<temp1.size(); ++i){//
			if(temp1[i] < temp2[i]){//
				swap(temp1, temp2);//
				negative+="-";
				break;//
			}
		}
	}
	int n1 = temp1.size();
	int n2 = temp2.size();
	reverse(temp1.begin(), temp1.end());
	reverse(temp2.begin(), temp2.end());
	int re=0;
	for(int i=0; i<n2; ++i){
		int t = (temp1[i] -'0') - (temp2[i]-'0')-re;
		if(t<0){
			t = (temp1[i]-'0')*10 - (temp2[i]-'0') - re;
			re=1;
		}
		else re=0;
		ans.arr+= (t %10 +'0');
	}
	for(int j=n2; j<n1; ++j){
		ans.arr+= ((temp1[j] -'0')- re)+'0';
		re=0;
	}
	reverse(ans.arr.begin(), ans.arr.end());
	ans.arr = negative + ans.arr;
	return ans;
}
HugeInteger HugeInteger::operator*(HugeInteger h){
	HugeInteger ans1[40];
	HugeInteger ans;
	ans.arr="";
	string temp1 = this->arr;
	string temp2 = h.arr;
	if(temp1.size() < temp2.size()) swap(temp1, temp2);// ep temp1 > temp2
	int n1 = temp1.size();//
	int n2 = temp2.size();//
	reverse(temp1.begin(), temp1.end());
	reverse(temp2.begin(), temp2.end());
	for(int i=0; i<n2; ++i){
		int re=0;
		for(int j=0; j<n1; ++j){
			int t= (temp2[i]-'0')*(temp1[j]-'0')+ re;
			re = t/10;
			ans1[i].arr+=(t%10)+'0';
		}
		if(re!=0) ans1[i].arr+=(re+'0');
		reverse(ans1[i].arr.begin(), ans1[i].arr.end());
//		ans1[i].show();
//		cout<<"\n";
	}
	for(int i=0; i<n2; ++i){
		for(int j=0; j<i; ++j){
			ans1[i].arr+='0';
		}
		ans = ans + ans1[i];
	}
	return ans;
}
int main(){
	HugeInteger a, b, sum, diff, mul, di;
	a.enter(); b.enter();
	sum = a + b;
	a.show(); cout<<" + "; b.show();
	cout<<" = "; sum.show();
	cout<<"\n";
	diff= a- b;
	a.show(); cout<<" - "; b.show(); cout<<" = "; diff.show(); cout<<"\n";
	mul = a * b;
	a.show(); cout<<" * "; b.show(); cout<<" = "; mul.show();
// 	diff = a/ b;
// 	a.show(); cout<<" / "; b.show(); cout<<" = "; di.show();
	
}
