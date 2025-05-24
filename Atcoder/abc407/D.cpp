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


#define N 100

LL a[N][N];
LL ans;
int n,m;
bool mp[N][N];
void dfs(int x,int y)
{
	if(y==m+1) x++,y=1;
	if(x==n+1)
	{
		LL now=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(mp[i][j]==0) now^=a[i][j];
			}
		}
		ans=max(ans,now);
		return;
	}
	if(mp[x][y])
	{
		dfs(x,y+1);
		return;
	}
	dfs(x,y+1);
	if(y!=m&&mp[x][y+1]==0)
	{
		mp[x][y]=1;
		mp[x][y+1]=1;
		dfs(x,y+2);
		mp[x][y]=0;
		mp[x][y+1]=0;
	}
	if(x!=n&&mp[x+1][y]==0)
	{
		mp[x][y]=1;
		mp[x+1][y]=1;
		dfs(x,y+1);
		mp[x][y]=0;
		mp[x+1][y]=0;
	}
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>a[i][j];
		}
	}
	dfs(1,1);
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
