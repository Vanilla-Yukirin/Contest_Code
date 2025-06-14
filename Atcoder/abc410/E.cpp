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

#define inf 0x3f3f3f3f
#define N 3100
int n,h,m;
int a[N],b[N];
int dp[N][N];
/*
击败前i只怪物后，
生命值大于等于j的时候，魔力值的最大值
dp[i][j]
-1表示生命值无法大于j



*/
void solve()
{
	cin>>n>>h>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
	}
	for(int j=0;j<=h;j++)
	{
		dp[0][j]=m;
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=h;j++)
		{
			dp[i][j]=-1;
			if(j>0) dp[i][j]=max(dp[i][j],dp[i][j-1]);
			// use h
			if(j>=a[i]) dp[i][j]=max(dp[i][j],dp[i-1][j-a[i]]);
			// use m
			dp[i][j]=max(dp[i][j],dp[i-1][j]-b[i]);
//			cout<<"i="<<i<<" j="<<j<<" dp="<<dp[i][j]<<endl;
			if(dp[i][j]>=0) ans=max(ans,i);
		}
	}
	cout<<ans<<endl;
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
