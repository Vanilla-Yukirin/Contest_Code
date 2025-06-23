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
int dep[N];
vector<int>edge[N];
vector<int>point[N];
void dfs(int x,int f)
{
	dep[x]=dep[f]+1;
	point[dep[x]].push_back(x);
	for(unsigned int i=0;i<edge[x].size();i++)
	{
		int y=edge[x][i];
		if(f==y) continue;
		dfs(y,x);
	}
}
int st,ed;
void solve()
{
	cin>>n>>st>>ed;
	for(int i=1;i<=n;i++)
	{
		edge[i].clear();
		point[i].clear();
	}
	for(int i=2;i<=n;i++)
	{
		int x,y;
		cin>>x>>y;
		edge[x].push_back(y);
		edge[y].push_back(x);
	}
	dfs(ed,0);
	for(int d=n;d>=1;d--)
	{
		for(unsigned int i=0;i<point[d].size();i++)
		{
			cout<<point[d][i]<<" ";
		}
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
