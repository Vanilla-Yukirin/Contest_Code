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


#define N 20

int n,m;
bool mp[N][N];
bool now[N][N];
int ans;
int check()
{
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(mp[i][j]!=now[i][j]) cnt++;
		}
	}
	return cnt;
}
bool book[N];
void dfs(int x,vector<int>link)
{
	if(x==n+1)
	{
		if(link.size()==0)
		{
//			mp[link.front()][link.back()]=mp[link.back()][link.front()]=1;
			ans=min(ans,check());
//			mp[link.front()][link.back()]=mp[link.back()][link.front()]=0;
		}
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(!book[i])
		{
			book[i]=1;
			if(link.size())
			{
				now[i][link.back()]=1;
				now[link.back()][i]=1;
			}
			link.push_back(i);
			if(link.size()>=3)
			{
				now[link.back()][link.front()]=1;
				now[link.front()][link.back()]=1;
				vector<int>empty;
				dfs(x+1,empty);
				now[link.back()][link.front()]=0;
				now[link.front()][link.back()]=0;
			}
			dfs(x+1,link);
			link.pop_back();
			if(link.size())
			{
				now[i][link.back()]=0;
				now[link.back()][i]=0;
			}
			book[i]=0;
		}
	}
}
void solve()
{
	cin>>n>>m;
	ans=n*n;
	for(int i=1;i<=m;i++)
	{
		int a,b;cin>>a>>b;
		mp[a][b]=mp[b][a]=1;
	}
	vector<int>empty;
	dfs(1,empty);
	cout<<ans/2<<endl;
	
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
