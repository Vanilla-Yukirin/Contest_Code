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
#define inf 0x3f3f3f3f3f3fll
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



int n,m,l;
LL A[N];
LL mxA[2];
vector<int>edge[N];
LL dis[N][2];
void solve()
{
	cin>>n>>m>>l;
	//clear
	mxA[0]=mxA[1]=0;
	for(int i=1;i<=n;i++)
	{
		edge[i].clear();
		dis[i][0]=dis[i][1]=inf;
	}
	//A
	LL sumA=0;
	for(int i=1;i<=l;i++)
	{
		cin>>A[i];
		sumA+=A[i];
	}
	mxA[sumA&1]=sumA;
	for(int i=1;i<=l;i++)
	{
		mxA[(sumA-A[i])&1]=max(mxA[(sumA-A[i])&1],(sumA-A[i]));
	}
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		edge[x].pb(y);
		edge[y].pb(x);
	}
	queue<pair<int,bool>>q;
	dis[1][0]=0;
	q.push(mk(1,0));
	while(q.size())
	{
		pair<int,bool>x=q.front();
		q.pop();
		for(unsigned int j=0;j<edge[x.first].size();j++)
		{
			int y=edge[x.first][j];
			if(dis[y][x.second^1]>dis[x.first][x.second])
			{
				dis[y][x.second^1]=dis[x.first][x.second]+1;
				q.push(mk(y,x.second^1));
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(dis[i][0]<=mxA[0]||dis[i][1]<=mxA[1]) cout<<"1";
		else cout<<"0";
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
