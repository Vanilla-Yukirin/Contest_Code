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


#define N 200100
#define M 30
int n,m;
vector<int>edge[N];
int f[N][M];
int dep[N];


void dfs(int x)
{
	for(int i=0;i<edge[x].size();i++)
	{
		int y=edge[x][i];
		if(y!=f[x][0])
		{
			f[y][0]=x;
			dep[y]=dep[x]+1;
			for(int k=1;k<=25;k++)
			{
				f[y][k]=f[f[y][k-1]][k-1];
			}
			dfs(y);
		}
	}
}

int lca(int a,int b)
{
	if(dep[a]<dep[b]) swap(a,b);
	for(int k=20;k>=0;k--)
	{
		if(dep[f[a][k]]>=dep[b]) a=f[a][k];
	}
	for(int k=20;k>=0;k--)
	{
		if(f[a][k]!=f[b][k])
		{
			a=f[a][k];
			b=f[b][k];
		}
	}
	if(a==b) return a;
	return f[a][0];
}

int dis(int a,int b)
{
	int c=lca(a,b);
	return dep[a]+dep[b]-dep[c]*2;
}

bool cmp(int a,int b)
{
	return dep[a]>dep[b];
}

int dis(int a1,int b1,int a2,int b2)
{
	int c1=lca(a1,b1),c2=lca(a2,b2);
	int d[4];
	d[0]=lca(a1,a2);
	d[1]=lca(b1,b2);
	d[2]=lca(a1,b2);
	d[3]=lca(a2,b1);
	sort(d,d+4,cmp);
//	DEBUG(c1,1);
//	DEBUG(c2,1);
	if(dep[c1]<dep[c2]) swap(c1,c2);
	if(dep[d[0]]>=dep[c1]&&dep[d[1]]>=dep[c2]) return dis(d[0],d[1]);
	return 0;
}

int dis(int a,int b,int c)
{
	return (dis(a,c)+dis(b,c)-dis(a,b))/2;
}

void solve()
{
	cin>>n>>m;
	for(int i=2;i<=n;i++)
	{
		int y;cin>>y;
		edge[i].push_back(y);
		edge[y].push_back(i);
	}
	dep[1]=1;
	dfs(1);
//	cout<<"f2="<<f[2][0]<<endl;
//	cout<<"lca(2,3)="<<lca(2,3)<<endl;
	while(m--)
	{
		int x[3];
		for(int i=0;i<3;i++) cin>>x[i];
		int ans=0;
		int tt=3;
		LOOP(tt)
		{
//			ans=max(ans,dis(x[0],x[1],x[0],x[2]));
			ans=max(ans,dis(x[0],x[1],x[2]));
			int temp=x[0];
			x[0]=x[1];
			x[1]=x[2];
			x[2]=temp;
		}
		cout<<ans+1<<endl;
	}
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
