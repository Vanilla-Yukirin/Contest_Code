/**************************************************************
 * Problem: 
 * Author: ArisuVanilla
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


#define N 1000010


int n,K;


vector<int>sta;
vector<int>edge[N],edgeK[N];
void dfs(int x,int f)
{
	for(int i=0;i<edge[x].size();i++)
	{
		int y=edge[x][i];
		if(y==f) continue;
		sta.push_back(y);
		dfs(y,x);
		sta.pop_back();
	}
	//son
	
	
	//fa
	if(sta.size()>=K+1)
	{
		int ff=sta[sta.size()-K-1];
		edgeK[ff].push_back(x);
		edgeK[x].push_back(ff);
	}
}
int dis[N];
#define inf 0x3f3f3f3f
bool book[N];
void solve()
{
	cin>>n>>K;
	for(int i=1;i<=n;i++)
	{
		edge[i].clear();
		edgeK[i].clear();
		dis[i]=inf;
		book[i]=0;
	}
	dis[1]=0;
	sta.clear();
	for(int i=2;i<=n;i++)
	{
		int x,y;
		cin>>x>>y;
		edge[x].push_back(y);
		edge[y].push_back(x);
	}
	sta.push_back(1);
	dfs(1,0);
	sta.pop_back();
	
	priority_queue<pair<int,int>>q;
	q.push(mk(0,1));
	while(q.size())
	{
		int x=q.top().second;
		q.pop();
		book[x]=1;
		for(int i=0;i<edgeK[x].size();i++)
		{
			int y=edgeK[x][i];
			if(dis[y]>dis[x]+1)
			{
				dis[y]=dis[x]+1;
				if(!book[y])
				{
					q.push(mk(-dis[y],y));
				}
			}
		}
	}
	for(int i=2;i<=n;i++)
	{
		if(dis[i]<inf) cout<<dis[i]<<" ";
		else cout<<"-1 ";
	}
	cout<<endl;
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
