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


#define N 2000100
#define inf 1000000100

LL x,y,k;
LL gcd(LL a,LL b)
{
	if(b) return gcd(b,a%b);
	return a;
}
int dp[N];
void solve()
{
	cin>>x>>y>>k;
	LL g=gcd(x,y);
	LL xx=x/g,yy=y/g;
	//xx check
	LL mx=0;
	LL xx_cp=xx;
	for(int i=2;i*i<=xx_cp;i++)
	{
		if(xx_cp%i==0)
		{
			mx=i;
			while(xx_cp%i==0) xx_cp/=i;
		}
	}
	if(xx_cp!=1) mx=max(mx,xx_cp);
	if(mx>k)
	{
		cout<<"-1"<<endl;
		return;
	}
	//yy check
	mx=0;
	LL yy_cp=yy;
	for(int i=2;i*i<=yy_cp;i++)
	{
		if(yy_cp%i==0)
		{
			mx=i;
			while(yy_cp%i==0) yy_cp/=i;
		}
	}
	if(yy_cp!=1) mx=max(mx,yy_cp);
	if(mx>k)
	{
		cout<<"-1"<<endl;
		return;
	}
	// dp
	int limit=max(xx,yy);
	for(int i=1;i<=limit;i++)
	{
		dp[i]=inf;
	}
	dp[1]=0;
	for(int i=1;i<=limit;i++)
	{
		for(int j=2;i*j<=limit&&j<=k;j++)
		{
			if(dp[i*j]>dp[i]+1)
			{
				dp[i*j]=dp[i]+1;
			}
			else
			{
//				break;
			}
		}
	}
	// try xx
	LL ans=0;
	ans+=dp[xx];
	// try yy
	ans+=dp[yy];
	cout<<ans<<endl;
}

int main()
{
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
