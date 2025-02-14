/**************************************************************
 * Problem: 
 * Author: Vanilla_chan
 * Date: 
 * E-Mail: heshaohong2015@outlook.com
 **************************************************************/
#include<bits/stdc++.h>
#define IL inline
#define re register
#define LL long long
#define ll long long
#define ULL unsigned long long
#define ull unsigned long long
#define mk(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define endl '\n'
#ifdef TH
#define debug cout<<"Now is "<<__LINE__<<endl;
#else
#define debug
#endif

std::string COLORS[]={"\033[0m","\033[91m","\033[92m","\033[93m","\033[94m","\033[95m","\033[96m"};
std::string COLOR_NAMES[]={"RESET","RED","GREEN","YELLOW","BLUE","MAGENTA","CYAN"};

#define DEBUG(x,color)                   \
cout<<COLORS[color];                     \
cout << #x << " : " << x << endl;        \
cout<<COLORS[0];                         \
cout.flush();

#define LOOP(While_times) while(While_times-->0)
using namespace std;


#define N 1000010

double calc(int x1,int y1,int x2,int y2,int x3,int y3)
{
	LL A = (LL)x1*(y2-y3) - (LL)y1*(x2-x3) + (LL)x2*y3 - (LL)x3*y2;
	
	if (A == 0) return 0;  // 三点共线，不能构成圆
	
	LL x1_2 = (LL)x1*x1, y1_2 = (LL)y1*y1;
	LL x2_2 = (LL)x2*x2, y2_2 = (LL)y2*y2;
	LL x3_2 = (LL)x3*x3, y3_2 = (LL)y3*y3;
	
	LL B = (x1_2+y1_2)*(y3-y2) + (x2_2+y2_2)*(y1-y3) + (x3_2+y3_2)*(y2-y1);
	LL C = (x1_2+y1_2)*(x2-x3) + (x2_2+y2_2)*(x3-x1) + (x3_2+y3_2)*(x1-x2);
	LL D = (x1_2+y1_2)*(x3*y2-x2*y3) + (x2_2+y2_2)*(x1*y3-x3*y1) + (x3_2+y3_2)*(x2*y1-x1*y2);
	
	LL B_2 = B * B;
	LL C_2 = C * C;
	LL A_2 = A * A;
	
	double r_squared = (B_2 + C_2 - 4 * A * D) / (4.0 * A_2);
	
	if (r_squared <= 0) return 0;  // 半径为虚数或零，不是有效的圆
	return r_squared;
}

int ansx,ansy;
double ans;
void solve()
{
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	for(int x=a;x<=b;x++)
	{
		for(int y=c;y<=d;y++)
		{
			double now=calc(a,d,b,c,x,y);
			if(now>ans) ansx=x,ansy=y,ans=now;
		}
	}
	cout<<a<<" "<<d<<endl;
	cout<<b<<" "<<c<<endl;
	cout<<ansx<<" "<<ansy<<endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cout.precision(10);
	int t=1;
//	cin>>t;
	LOOP(t)
	{
		solve();
	}
	return 0;
}
