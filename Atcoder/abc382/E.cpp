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


#define N 6010

int n,m;
double p[N];
double dp[N][N];
double E[N];
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>p[i],p[i]/=100;
	dp[0][0]=1; //起始条件，抽前0张牌的时候得到0张稀有牌的概率是100%
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=i;j++)
		{
			//抽前i张卡牌，正好得到j张稀有牌的概率是dp[i][j]
			if(j==0) dp[i][j]=dp[i-1][j]*(1-p[i]); //防止越界
			else dp[i][j]=dp[i-1][j-1]*p[i]+dp[i-1][j]*(1-p[i]);
		}
	}
	//此时得到了开一次包的概率分布表（得到j张稀有牌）为dp[n][j]
	for(int j=0;j<=n;j++)
	{
//		DEBUG(j,1);
//		DEBUG(dp[n][j],2);
	}
	for(int i=1;i<=m;i++)
	{
		//得到i张稀有牌的期望开包次数是E[i]
		for(int j=1;j<=n;j++)
		{
			if(i-j>=0) E[i]+=(E[i-j])*dp[n][j];
			else E[i]+=(0)*dp[n][j];
		}
		E[i]=(1+E[i])/(1-dp[n][0]);
	}
	cout<<E[m]<<endl;
	
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
