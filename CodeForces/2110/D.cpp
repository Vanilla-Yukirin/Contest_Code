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
#define inf 0x3f3f3f3f
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

vector<pair<int,LL>>edge[N];
int n,m;
LL b[N];
LL calc(LL mid)
{
	vector<LL>dp(n+1);
	for(int i=2;i<=n;i++)
	{
//		dp[i]=-inf;
		dp[i]=0;
	}
	dp[1]=b[1];
	dp[1]=min(dp[1],mid);
	for(int i=1;i<=n;i++)
	{
		if(dp[i]==0) continue;
		for(unsigned int j=0;j<edge[i].size();j++)
		{
			int y=edge[i][j].first;
			LL w=edge[i][j].second;
			if(w<=dp[i])
			{
				dp[y]=max(dp[y],dp[i]+b[y]);
				dp[y]=min(dp[y],mid);
			}
		}
	}
	return dp[n];
}

void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		edge[i].clear();
	}
	for(int i=1;i<=n;i++) cin>>b[i];
	for(int i=1;i<=m;i++)
	{
		int x,y;
		LL z;cin>>x>>y>>z;
		edge[x].push_back(mk(y,z));
	}
	if(calc(inf)<=0)
	{
		cout<<"-1"<<endl;
		return;
	}
	LL l,r,mid,ans;
	l=0;
	r=inf;
	ans=inf;
	while(l<=r)
	{
		mid=(l+r)>>1;
		if(calc(mid)>0)
		{
			ans=min(ans,mid);
			r=mid-1;
		}
		else
		{
			l=mid+1;
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
	cin>>t;
	LOOP(t)
	{
		solve();
	}
	return 0;
}
