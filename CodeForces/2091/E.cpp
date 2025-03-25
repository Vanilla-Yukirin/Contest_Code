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


#define N 10000100
int prime[2000000];
bool book[N];
int cnt;
int ansa[N];
void init()
{
	book[1]=1;
	int i,j;
	for(i=2;i<=10000000;i++)
	{
		if(!book[i]) prime[++cnt]=i;
		for(j=1;j<=cnt&&i*prime[j]<=10000000;j++)
		{
			book[i*prime[j]]=1;
			if(i%prime[j]==0) break;
		}
	}
}
int n;
void solve()
{
	cin>>n;
	int b=cnt;
	LL ans=0;
	for(int a=1;a<=n;a++)
	{
		while(a*prime[b]>n) b--;
		ans+=b;
	}
	cout<<ans<<endl;
}

int main()
{
	init();
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cout.precision(10);
	int t=1;
	cin>>t;
	LOOP(t)
	{
		solve();
	}
	return 0;
}
