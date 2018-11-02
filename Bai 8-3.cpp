#include<iostream>
#include<cmath>
using namespace std;

class Point{
	protected:
		double x;// khi thuc hien ke thua thi muon class con  tiep can toi thuaoc tinh cau class cha thi  ta can phai dung ham set va get o public
		double y;
	public:
		Point();
		Point(double x1, double y1);
		double getX(){ return x;}//
		double getY(){ return y;}
		void set(double x1, double y1){x= x1;y= y1;}
		void enter();
		void show();
		double distance(Point b);
};
Point::Point(){
	x=0, y=0;
}
Point::Point(double x1, double y1){
	x = x1; y= y1;
}
void Point::enter(){
	cout<<"\nNhap toa do (x, y)= ";
	cin>>x>>y;
}
void Point::show(){
	cout<<x<<" "<<y<<endl;
}
double Point::distance(Point b){
	return sqrt((this->x - b.x)*(this->x - b.x) + (this->y - b.y)*(this->y - b.y));
}
class Polygon:public Point{
	protected:
		int numOfPoint;
		Point point[10];
	public:
		Polygon();
		Polygon(int n, double x1, double y1);
		void enter();
		void show();
		void check();
		bool isTriangle();
		bool isRectangle();
		bool isSquare();
		bool isParallelogram();
		bool isTrapezoidDeu();
		bool istrapezoid();
		
};
Polygon::Polygon(){
	Point();
}
Polygon::Polygon(int n, double x1, double y1):Point(x1, y1){
	numOfPoint = n;
}
void Polygon::enter(){
	cout<<"\nNhap so dinh cua da giac: ";
	cin>>numOfPoint;
	for(int i=0; i<numOfPoint; ++i){
		point[i].enter();
	}
}
void Polygon::show(){
	cout<<numOfPoint<<"\n";
	for(int i=0; i<numOfPoint; ++i){
		point[i].show();
	}
}
bool Polygon::isTriangle(){
	if(point[0].getX()==point[1].getX() &&point[1].getX() ==point[2].getX()|| 
		point[0].getY()== point[1].getY() && point[1].getY() == point[2].getY()){
		return false;
	}
	return true;
}
bool Polygon::isRectangle(){
	Point c;
	double x1=(point[0].getX() + point[1].getX() + point[2].getX() + point[3].getX())/4;
	double y1 = (point[0].getY() + point[1].getY() + point[2].getY() +point[3].getY())/4;
	c.set(x1, y1);
	double dd1 = c.distance(point[0]);
	double dd2 = c.distance(point[1]);
	double dd3 = c.distance(point[2]);
	double dd4 = c.distance(point[3]);
	return dd1 = dd2 && dd2 == dd3 && dd3 ==dd4;
}
bool Polygon::isSquare(){
	if(!isRectangle()) return false;
	double dd1 = point[0].distance(point[1]);
	double dd2 = point[0].distance(point[2]);
	double dd3 = point[0].distance(point[3]);
	return dd1 == dd2 || dd2 == dd3 || dd1 == dd3;
}
void Polygon::check(){
	if(numOfPoint == 3){
		if(isTriangle()){
			cout<<"Day la tam giac.\n";
		}
	}
	else if(numOfPoint == 4){
		if(isRectangle()){
			if(isSquare()) cout<<"Day la hinh vuong.\n";
			else  cout<<"Day la hinh chu nhat.\n";
		}
		else cout<<"\nDay la tu giac";
	}
//	else if(numOfPoint == 5){
//		if(isTrapezoidDeu()) cout<<"Day la ngu giac deu.\n";
//		else cout<<"Day la ngu giac";
//	}
}
int main(){
//	Point a, b;
//	a.enter();
//	b.enter();
//	cout<<"Do dai AB: "<<a.distance(b);
	Polygon P;
	P.enter();
//	P.show();
	//if(P.isTriangle()) cout<<"U thi 3 canh.\n";
	P.check();
	
}
