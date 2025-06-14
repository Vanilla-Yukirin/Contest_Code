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


#define N 300010
int h,w;
#define mov 300010
string mp[N];
void solve()
{
	cin>>h>>w;
	for(int i=1;i<=h;i++)
	{
		cin>>mp[i];
		mp[i]=" "+mp[i];
	}
	vector<vector<int>>dp(h+1,vector<int>(w+1));
	for(int i=1;i<=h;i++)
	{
		for(int j=1;j<=w;j++)
		{
			dp[i][j]=dp[i][j-1]+dp[i-1][j]-dp[i-1][j-1];
			if(mp[i][j]=='#') dp[i][j]++;
			else dp[i][j]--;
		}
	}
	LL ans=0;
	if(h<=w)
	{
		vector<int>cnt(mov*2+10);
		for(int up=1;up<=h;up++)
		{
			for(int down=0;down<up;down++)
			{
				for(int j=0;j<=w;j++)
				{
					cnt[dp[up][j]-dp[down][j]+mov]++;
				}
				for(int j=0;j<=w;j++)
				{
					ans+=cnt[dp[up][j]-dp[down][j]+mov]-1;
				}
				for(int j=0;j<=w;j++)
				{
					cnt[dp[up][j]-dp[down][j]+mov]=0;
				}
			}
		}
	}
	else
	{
		vector<int>cnt(mov*2+10);
		for(int up=1;up<=w;up++)
		{
			for(int down=0;down<up;down++)
			{
				
				for(int j=0;j<=h;j++)
				{
					cnt[dp[j][up]-dp[j][down]+mov]++;
				}
				for(int j=0;j<=h;j++)
				{
					ans+=cnt[dp[j][up]-dp[j][down]+mov]-1;
				}
				for(int j=0;j<=h;j++)
				{
					cnt[dp[j][up]-dp[j][down]+mov]=0;
				}
			}
		}
	}
	ans/=2;
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
