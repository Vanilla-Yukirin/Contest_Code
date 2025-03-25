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


#define N 50010

int n;
bool a[N];
int calc_dis(int x,int y)
{
	return x+y+(x%3==2&&y%3==2)*2;
}
struct Point
{
	int x,y;
	Point(int xx=0,int yy=0)
	{
		x=xx;
		y=yy;
	}
	Point(pair<int,int>p)
	{
		x=p.first;
		y=p.second;
	}
	bool operator<(const Point &z)const
	{
		if(calc_dis(x,y)==calc_dis(z.x,z.y))
		{
			if(x==z.x) return y<z.y;
			return x<z.x;
		}
		return calc_dis(x,y)<calc_dis(z.x,z.y);
	}
};
void solve()
{
	cin>>n;
	set<Point>s1,s2;
	int len=sqrt(n)*2+2;
	for(int x=0;x<=len;x++)
	{
		for(int y=0;y<=len;y++)
		{
			s1.insert(mk(3*x+1,3*y+1));
			s2.insert(mk(3*x+1,3*y+1));
			s2.insert(mk(3*x+2,3*y+1));
			s2.insert(mk(3*x+1,3*y+2));
			s2.insert(mk(3*x+2,3*y+2));
		}
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==0)
		{
			//s1
			auto it=s1.begin();
			int x=it->x,y=it->y;
			cout<<x<<" "<<y<<endl;
			s1.erase(it);
			s2.erase(mk(x,y));
		}
		else
		{
			//s2
			auto it=s2.begin();
			int x=it->x,y=it->y;
			cout<<x<<" "<<y<<endl;
			s2.erase(it);
			s1.erase(mk(x/3*3+1,y/3*3+1));
		}
	}
}

int main()
{
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//	cout.precision(10);
	int t=1;
	cin>>t;
	LOOP(t)
	{
		solve();
	}
	return 0;
}
