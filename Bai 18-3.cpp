#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

class HugeInteger{
	friend ostream &operator<<(ostream&, const HugeInteger &);
	friend istream &operator>>(istream&, HugeInteger &) ;
	private:
		string arr;
	public:
		HugeInteger(){ arr="";};
		HugeInteger operator+(HugeInteger);
		HugeInteger operator-(HugeInteger);
		HugeInteger operator*(HugeInteger);
		HugeInteger operator/(HugeInteger);
		bool operator==(HugeInteger);
		bool operator!=(HugeInteger);
		bool operator>(HugeInteger);
		bool operator<(HugeInteger);
		bool operator>=(HugeInteger);
		bool operator<=(HugeInteger);
};

ostream &operator<<(ostream& out, const HugeInteger &h){
	out<<h.arr;
	return out;
}
istream &operator>>(istream& inp, HugeInteger &h){
	inp>>h.arr;
	return inp;
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

//HugeInteger HugeInteger::operator%(HugeInteger h){
//	HugeInteger ans;
//	ans.arr= this->arr;
//	
//}
bool HugeInteger::operator>(HugeInteger h){
	if(this->arr.size() < h.arr.size()) return false;
	else if(this->arr.size()== h.arr.size()) {
		for(int i=0; i<this->arr.size(); ++i){
			if(this->arr[i] > h.arr[i]) return true;
			else if(this->arr[i] < h.arr[i]) return false;
		}
	}
	else return true;
}
bool HugeInteger::operator==(HugeInteger h){
	if(this->arr.size()== h.arr.size()) {
		for(int i=0; i<h.arr.size(); ++i){
			if(this->arr[i]!=h.arr[i]) return false;
		}
		return true;
	}
	else return false;
	
}
bool HugeInteger::operator!=(HugeInteger h){
	HugeInteger temp;
	temp.arr=this->arr;
	return (((temp==h)==true)? false: true);
}
bool HugeInteger::operator<(HugeInteger h){
	HugeInteger temp;
	temp.arr= this->arr;
	return (((temp > h)==false && (temp!=h)==true)? true:false);
}
bool HugeInteger::operator>=(HugeInteger h){
	HugeInteger temp;
	temp.arr=this->arr;
	return (((temp>h)== true || (temp==h)==true)? true: false);
}
bool HugeInteger::operator<=(HugeInteger h){
	HugeInteger temp;
	temp.arr=this->arr;
	return ((temp >= h)==false)? true: false;
}
HugeInteger HugeInteger::operator/(HugeInteger h){
	HugeInteger ans;
	ans.arr="";
	HugeInteger temp1;
	HugeInteger temp2;
	temp1.arr=this->arr;
	temp2.arr= h.arr;
	if((temp1 < temp2) ==true) return ans;
	while((temp1 >= temp2) == true){
		HugeInteger t;
		t.arr="";
		t.arr+= (((temp1.arr[0]-'0')/ (temp2.arr[0]-'0')) +'0');
		ans.arr+=t.arr;
		temp1 = temp1 - (t * temp2);
	}
	return ans;
}
int main(){
	HugeInteger a, b, sum, diff, mul, di;
	cin>>a>>b;
	//cout<<a<<" "<<b<<
	cout<<a<<" + "<<b<<" = "<<a+b<<"\n";
	cout<<a<<" - "<<b<<" = "<<a- b<<"\n";
	cout<<a<<" > "<<b<<" is "<<((a>b==true)?"true\n":"false\n");
	cout<<a<<" * "<<b<<" = "<<a*b<<"\n";
	cout<<a<<" / "<<b<<" = "<<a/b<<"\n";
//	cout<<a<<" % "<<b<<" = "<<a%b<<"\n";
	cout<<a<<" < "<<b<<" is "<<((a<b)==true)?"true\n":"false\n";
	cout<<a<<" == "<<b<<" is "<<((a==b)==true)?"true\n": "false\n";
	cout<<a<<" >= "<<b<<" is "<<((a>=b)==true)? "true\n":"false\n";
	cout<<a<<" <= "<<b<<" is "<<((a<=b)==true)? "true\n": "false\n";
	cout<<a<<" != "<<b<<" is "<<((a!=b)==true)? "true\n": "false\n";
	
}
