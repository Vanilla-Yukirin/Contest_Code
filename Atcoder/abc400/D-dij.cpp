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
string str[N];
int n,m;
int sx,sy,ex,ey;
struct node
{
	pair<int,int>p;
	int dis;
	node(pair<int,int>a=mk(0,0),int b=0)
	{
		p=a;
		dis=b;
	}
	bool operator<(const node& z)const
	{
		return dis>z.dis;
	}
};
priority_queue<node>q;
int dt[4][2]={0,1,0,-1,1,0,-1,0};
int dis[N][N];
bool out[N][N];
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>str[i];
		str[i]=" "+str[i];
	}
	cin>>sx>>sy>>ex>>ey;
	q.push(node(mk(sx,sy),0));
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			dis[i][j]=100000;
		}
	}
	dis[sx][sy]=0;
	while(q.size())
	{
		node now=q.top();
		pair<int,int> X=now.p;
		q.pop();
//		cout<<"now="<<now.first<<" "<<now.second<<endl;
		out[X.first][X.second]=1;
		for(int t=0;t<4;t++)
		{
			pair<int,int>Y=mk(X.first+dt[t][0],X.second+dt[t][1]);
			if(Y.first<1||Y.second<1||Y.first>n||Y.second>m)
			{
				continue;
			}
			if(str[Y.first][Y.second]=='.')
			{
				if(dis[Y.first][Y.second]>dis[X.first][X.second])
				{
					dis[Y.first][Y.second]=dis[X.first][X.second];
					if(out[Y.first][Y.second]==0)
					{
						q.push(node(mk(Y.first,Y.second),dis[Y.first][Y.second]));
					}
				}
			}
			
			// ti
			if(dis[Y.first][Y.second]>dis[X.first][X.second]+1)
			{
				dis[Y.first][Y.second]=dis[X.first][X.second]+1;
				if(out[Y.first][Y.second]==0)
				{
					q.push(node(mk(Y.first,Y.second),dis[Y.first][Y.second]));
				}
			}
			
			
			//ti2
			if(str[Y.first][Y.second]=='#')
			{
				Y=mk(Y.first+dt[t][0],Y.second+dt[t][1]);
				if(Y.first<1||Y.second<1||Y.first>n||Y.second>m)
				{
					continue;
				}
				if(dis[Y.first][Y.second]>dis[X.first][X.second]+1)
				{
					dis[Y.first][Y.second]=dis[X.first][X.second]+1;
					if(out[Y.first][Y.second]==0)
					{
						q.push(node(mk(Y.first,Y.second),dis[Y.first][Y.second]));
					}
				}
			}
			
		}
	}
	cout<<dis[ex][ey]<<endl;
	
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
