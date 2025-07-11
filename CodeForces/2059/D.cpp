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


#define N 1010

int n,m1,m2,s1,s2;
vector<int>edge1[N],edge2[N];
bool book[N][N];
LL dis[N][N];
#define inf 0x3f3f3f3f3f3f3f3fll
void solve()
{
	cin>>n>>s1>>s2;
	for(int i=1;i<=n;i++)
	{
		edge1[i].clear();
		edge2[i].clear();
	}
	cin>>m1;
	for(int i=1;i<=m1;i++)
	{
		int x,y;
		cin>>x>>y;
		edge1[x].pb(y);
		edge1[y].pb(x);
	}
	cin>>m2;
	for(int i=1;i<=m2;i++)
	{
		int x,y;
		cin>>x>>y;
		edge2[x].pb(y);
		edge2[y].pb(x);
	}
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			dis[i][j]=inf;
			book[i][j]=0;
		}
	}
	dis[s1][s2]=0;
	book[s1][s2]=1;
	priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>q;
	q.push(mk(0,mk(s1,s2)));
	while(q.size())
	{
		int x=q.top().second.first,y=q.top().second.second;
		q.pop();
		book[x][y]=1;
		for(int i=0;i<edge1[x].size();i++)
		{
			for(int j=0;j<edge2[y].size();j++)
			{
				int xx=edge1[x][i],yy=edge2[y][j];
				if(dis[xx][yy]>dis[x][y]+abs(xx-yy))
				{
					dis[xx][yy]=dis[x][y]+abs(xx-yy);
					if(book[xx][yy]==0) q.push(mk(dis[xx][yy],mk(xx,yy)));
				}
			}
		}
	}
	
	LL ans=inf;
	for(int x=1;x<=n;x++)
	{
		vector<int>cnt(n+1);
		for(int i=0;i<edge1[x].size();i++)
		{
			cnt[edge1[x][i]]++;
		}
		for(int i=0;i<edge2[x].size();i++)
		{
			if(cnt[edge2[x][i]])
			{
				ans=min(ans,dis[x][x]);
				break;
			}
		}
	}
	if(ans==inf) cout<<"-1"<<endl;
	else cout<<ans<<endl;
	
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
