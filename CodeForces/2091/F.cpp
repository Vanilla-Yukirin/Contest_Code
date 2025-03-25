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


#define N 2010
#define p 998244353ll
void cal(LL & x)
{
	x%=p;
	x+=p;
	x%=p;
}
int n,m,d,d2;
double dis(int a,int b)
{
	return sqrt(a*a+b*b);
}
string mp[N];
LL dp[N][N][2];
LL sum[N][2];
void solve()
{
	cin>>n>>m>>d;
	d2=sqrt(d*d-1);
	for(int i=1;i<=n;i++)
	{
		cin>>mp[i];
		mp[i]=" "+mp[i];
	}
	for(int i=n;i>=1;i--)
	{
		if(i==n)
		{
			for(int j=1;j<=m;j++)
			{
				if(mp[i][j]=='X') dp[i][j][0]=1;
				else dp[i][j][0]=0;
			}
		}
		else
		{
			for(int j=1;j<=m;j++)
			{
				dp[i][j][0]=0;
				if(mp[i][j]=='X')
				{
					dp[i][j][0]+=sum[min(j+d2,m)][0]-sum[max(0,j-d2-1)][0];
					dp[i][j][0]+=sum[min(j+d2,m)][1]-sum[max(0,j-d2-1)][1];
					cal(dp[i][j][0]);
				}
			}
		}
		for(int j=1;j<=m;j++) sum[j][0]=sum[j-1][0]+dp[i][j][0];
		for(int j=1;j<=m;j++)
		{
			dp[i][j][1]=0;
			if(mp[i][j]=='X')
			{
				dp[i][j][1]=sum[min(j+d,m)][0]-sum[max(0,j-d-1)][0];
				dp[i][j][1]-=dp[i][j][0];
				cal(dp[i][j][1]);
			}
		}
		for(int j=1;j<=m;j++) sum[j][1]=sum[j-1][1]+dp[i][j][1];
	}
	LL ans=0;
	for(int j=1;j<=m;j++) ans+=dp[1][j][0]+dp[1][j][1];
	cal(ans);
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
