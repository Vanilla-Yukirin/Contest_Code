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

int n;
LL a[N];
vector<pair<int,LL>>edge[N];
LL sum[N];
LL dp[N];
void dfs1(int x,int f)
{
	sum[x]=a[x];
	for(unsigned int i=0;i<edge[x].size();i++)
	{
		int y=edge[x][i].first;
		int z=edge[x][i].second;
		if(y==f) continue;
		dfs1(y,x);
		sum[x]+=sum[y];
		dp[x]+=abs(sum[y]*z);
		dp[x]+=dp[y];
	}
}

void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<n;i++)
	{
		int x,y;
		LL z;
		cin>>x>>y>>z;
		edge[x].push_back(mk(y,z));
		edge[y].push_back(mk(x,z));
	}
	dfs1(1,0);
	cout<<dp[1]<<endl;
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
