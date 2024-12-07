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
#define pb(a,b) push_back(a,b)
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


#define N 4000010

ll n;
const ll sqinf=4000000;
ll prime[N],cnt;
bool book[N];
void init()
{
	for(int i=2;i<=sqinf;i++)
	{
		if(book[i]==0)
		{
			prime[++cnt]=i;
//			DEBUG(cnt,1);
//			DEBUG(i,2);
			for(int j=2;i*j<=sqinf;j++)
			{
//				debug
				book[i*j]=1;
			}
		}
	}
//	cout<<"init over"<<endl;
//	cout.flush();
}
int ans;
void solve()
{
	cin>>n;
	init();
	for(int i=1;i<=cnt&&prime[i]*prime[i]<=n&&prime[i]*prime[i]<=sqinf;i++)
	{
//		DEBUG(i,1);
		int j=i;
		for(int k=20;k>=0;k--)
		{
			int nxt=j+(1<<k);
			if(nxt<=cnt&&prime[i]*prime[nxt]<=sqinf&&prime[nxt]*prime[nxt]*prime[i]*prime[i]<=n) j=nxt;
		}
		int now=j;
//		DEBUG(now,2);
		now=max(0,j-i);
//		DEBUG(now,33);
		ans+=now;
	}
	for(int i=1;i<=cnt;i++)
	{
		if(prime[i]*prime[i]*prime[i]*prime[i]*prime[i]*prime[i]*prime[i]*prime[i]<=n) ans++;
		else break;
	}
	cout<<ans;
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
