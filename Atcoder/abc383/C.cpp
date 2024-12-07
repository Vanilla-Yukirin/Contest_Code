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


#define N 1010
int mp[N][N];
int idx[N][N];
int h,w,d;
int dt[4][2]={0,1,0,-1,1,0,-1,0};
int ans;

struct node
{
	int x,y,v;
	bool operator<(const node &z)const
	{
		return v<z.v;
	}
};
priority_queue<node>q;
void dfs(int x,int y)
{
	if(idx[x][y]<=1) return;
	for(int t=0;t<4;t++)
	{
		int nx=x+dt[t][0],ny=y+dt[t][1];
		if(nx<1||nx>h||ny<1||ny>w) continue;
		if(mp[nx][ny]&&idx[nx][ny]<idx[x][y]-1) idx[nx][ny]=idx[x][y]-1,dfs(nx,ny);
	}
}
void solve()
{
	cin>>h>>w>>d;
	d++;
	for(int i=1;i<=h;i++)
	{
		string str;cin>>str;
		for(int j=1;j<=w;j++)
		{
			if(str[j-1]=='.') mp[i][j]=1;
			if(str[j-1]=='H') mp[i][j]=2;
		}
	}
	for(int i=1;i<=h;i++)
	{
		for(int j=1;j<=w;j++)
		{
			if(mp[i][j]==2) q.push(node(i,j,d));
		}
	}
	while(q.size())
	{
		node now=q.top();
		int x=now.x,y=now.y,v=now.v;
		q.pop();
		if(idx[x][y]>=v)
		{
			continue;
		}
		idx[x][y]=v;
		if(idx[x][y]<=1) continue;
		for(int t=0;t<4;t++)
		{
			int nx=x+dt[t][0],ny=y+dt[t][1];
			if(nx<1||nx>h||ny<1||ny>w) continue;
			if(mp[nx][ny]&&idx[nx][ny]<v-1) q.push(node(nx,ny,v-1));
		}
	}
	for(int i=1;i<=h;i++)
	{
		for(int j=1;j<=w;j++)
		{
			if(idx[i][j]) ans++;
		}
	}
	cout<<ans;
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
