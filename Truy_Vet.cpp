#include<iostream>

using namespace std;

void nhapHang(int hang,int vuong[5][5],int a[5][10000],int so)
{
	int h=hang-1;
	for(int j=0;j<5;j++)
	{
		vuong[h][j]=a[j][so];
	}
}
void nhapCot(int cot,int vuong[5][5],int a[5][10000],int so)
{
	int c=cot-1;
	for(int j=0;j<5;j++)
	{
		vuong[j][c]=a[j][so];
	}
}
void nhaptreo(int treo,int vuong[5][5],int a[5][10000],int so)
{
 	if(treo==1)
  	{
  		for(int j=0;j<5;j++)
		{
			vuong[j][j]=a[j][so];
		}
 	}
 	else
 	{
 		 for(int j=0;j<5;j++)
		{
			vuong[4-j][j]=a[j][so];
		}
  	}
}
int main()
{
	int vuong[5][5];
	int a[5][10000],n=0,s;
	int kt=0;
	cout<<"nhap s :";
	cin >>s;
	for(int i=10001;i<=99999;i=i+2)
	{
		int dem=0,xet,so=i; 
		if(i%3==0||i%5==0||i%7==0) continue;
			for(int j=1;j<=5;j++)
			{
				xet=so%10;
				so/=10;
				dem+=xet;
			}
		if(dem!=s) continue;
			dem=0;
		for(int j=1;j<=i;j++)
		{
			if(i%j==0)
			{
				 dem++	;
			} 
		}
		if(dem!=2) continue;
		so=i;
		for(int j=0;j<5;j++)
			{
				a[4-j][n]=so%10;
				so/=10;
			}
			n++;
		}
	for(int i=0;i<n&&kt==0;i++)
	  {
	    /*hang 1
		  cot 1*/
	    if(a[0][i]!=0&&a[1][i]!=0&&a[2][i]!=0&&a[3][i]!=0&&a[4][i]!=0)
	    {
		 nhapHang(1,vuong,a,i);
		 nhapCot(1,vuong,a,i);
		 for(int j=0;j<n&&kt==0;j++)
	    {
	    /*hang 5
		  cot 5*/
	      if(a[0][j]!=0&&a[1][j]!=0&&a[2][j]!=0&&a[3][j]!=0&&a[4][j]!=0&&a[0][j]==vuong[4][0]&&
		    a[0][j]!=2&&a[1][j]!=2&&a[2][j]!=2&&a[3][j]!=2&&a[4][j]!=2&&
			a[0][j]!=4&&a[1][j]!=4&&a[2][j]!=4&&a[3][j]!=4&&a[4][j]!=4&&
			a[0][j]!=5&&a[1][j]!=5&&a[2][j]!=5&&a[3][j]!=5&&a[4][j]!=5&&
			a[0][j]!=6&&a[1][j]!=6&&a[2][j]!=6&&a[3][j]!=6&&a[4][j]!=6&&
			a[0][j]!=8&&a[1][j]!=8&&a[2][j]!=8&&a[3][j]!=8&&a[4][j]!=8)
	     {
		  nhapHang(5,vuong,a,j);
		  nhapCot(5,vuong,a,j);
		  for(int k=0;k<n&&kt==0;k++)
	      {
	    /*treo 1*/
	      if(a[0][k]==vuong[0][0]&&a[4][k]==vuong[4][4])
	      {
		  nhaptreo(1,vuong,a,k);
	       for(int l=0;l<n&&kt==0;l++)
	      {
	    /*treo 2*/
	      if(a[0][l]==vuong[4][0]&&a[4][l]==vuong[0][4]&&a[2][l]==vuong[2][2]&&a[1][l]==a[3][l])
	      {
		  nhaptreo(2,vuong,a,l);
	       for(int m=0;m<n&&kt==0;m++)
	       {
	    /*hang 2
		  cot 2*/
	       if(a[0][m]==vuong[1][0]&&a[1][m]==vuong[1][1]&&a[3][m]==vuong[1][3]&&a[4][m]==vuong[1][4])
	       {
		    nhapHang(2,vuong,a,m);
	        nhapCot(2,vuong,a,m);
	         for(int p=0;p<n&&kt==0;p++)
	        {
	    /*hang 3
		  cot 3*/
	         if(a[0][p]==vuong[2][0]&&a[1][p]==vuong[2][1]&&a[2][p]==vuong[2][2]&&a[4][p]==vuong[2][4])
	        {
		    nhapHang(3,vuong,a,p);
	        nhapCot(3,vuong,a,p);
	         for(int q=0;q<n;q++)
	        { 
	    /*hang 4
		  cot 4*/
	         if(a[0][q]==vuong[3][0]&&a[1][q]==vuong[3][1]&&a[2][q]==vuong[3][2]&&a[3][q]==vuong[3][3]&&a[4][q]==vuong[3][4])
	         {
		     nhapHang(4,vuong,a,q);
	         nhapCot(4,vuong,a,q);
	         cout<<"ket qua";
	         kt=1;
	         break;
		     }
		     }
		    }
		    }
		   }
		   }
		  }
		  }
	     }
		 }
	    }
	    }
	  }
	  }
  	cout <<"\n===========================================================================\n";
  for(int i=0;i<5;i++)
	{
	for(int j=0;j<5;j++)
	{
	cout<<vuong[j][i]<<"\t";
	}
	cout <<"\n";
	}
	cout <<"\n===========================================================================";
	return 0;
	}

