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

bool judge(int x)
{
	for(int i=2;i*i<=x;i++)
	{
		if(x%i==0) return 0;
	}
	return 1;
}
int prime[N];
int cnt;
void init()
{
	for(int i=2;i<=100000;i++) if(judge(i)) prime[++cnt]=i;
}
int n;
int a[N];
void solve()
{
	cin>>n;
	int fd=(n)/2;
	fd=lower_bound(prime+1,prime+cnt+1,fd)-prime;
	fd=prime[fd];
	int l=fd,r=fd;
	cout<<fd<<" ";
	while(1)
	{
		l--;
		r++;
		if(l>=1) cout<<l<<" ";
		if(r<=n) cout<<r<<" ";
		if(l==1)
		{
			r++;
			while(r<=n) cout<<r<<" ",r++;
			cout<<endl;
			return;
		}
		if(r==n)
		{
			l--;
			while(l>=1) cout<<l<<" ",l--;
			cout<<endl;
			return;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cout.precision(10);
	int t=1;
	cin>>t;
	init();
	LOOP(t)
	{
		solve();
	}
	return 0;
}
