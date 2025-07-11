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


#define N 1100
#define pii pair<int,int>
#define inf 0x3f3f3f3f
int n,m;
int dt[4][2]={1,0,-1,0,0,1,0,-1};
int dis[N][N];
string str[N];
pii st,ed;
bool book[N][N];
LL ans;
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>str[i];
		str[i]=" "+str[i];
		for(int j=1;j<=m;j++)
		{
			if(str[i][j]=='E') ed=mk(i,j);
			else if(str[i][j]=='S') st=mk(i,j);
			dis[i][j]=inf;
		}
	}
	dis[ed.first][ed.second]=0;
	queue<pii>q;
	q.push(ed);
	while(q.size())
	{
		pii x=q.front();
		q.pop();
		book[x.first][x.second]=1;
		for(int t=0;t<4;t++)
		{
			pii y=mk(x.first+dt[t][0],x.second+dt[t][1]);
			if(y.first>=1&&y.first<=n&&y.second>=1&&y.second<=m)
			if(str[y.first][y.second]!='T')
			if(book[y.first][y.second]==0)
			{
				dis[y.first][y.second]=dis[x.first][x.second]+1;
				book[y.first][y.second]=1;
				q.push(y);
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(str[i][j]<='9'&&str[i][j]>='0'&&dis[i][j]<=dis[st.first][st.second])
			{
				ans+=str[i][j]-'0';
			}
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
//	cin>>t;
	LOOP(t)
	{
		solve();
	}
	return 0;
}
