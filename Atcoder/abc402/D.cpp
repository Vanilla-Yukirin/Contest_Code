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


#define N 10000100


int n,m;
string mp[2000];
string ans[2000];
int dt[4][2]={0,1,0,-1,1,0,-1,0};
char way[5]="<>^v";
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>mp[i];
		mp[i]=" "+mp[i];
//		ans[i].resize(m+1);
	}
	queue<pair<int,int>>q;
	for(int i=1;i<=n;i++)
	{
		ans[i].push_back(' ');
		for(int j=1;j<=m;j++)
		{
			if(mp[i][j]=='E') q.push(make_pair(i,j)),ans[i].push_back('E');
			else ans[i].push_back(mp[i][j]);
		}
	}
	while(q.size())
	{
		pair<int,int>xy=q.front();
		q.pop();
		for(int t=0;t<4;t++)
		{
			pair<int,int>nxy=make_pair(xy.first+dt[t][0],xy.second+dt[t][1]);
			if(nxy.first<=n&&nxy.first>=1&&nxy.second<=m&&nxy.second>=1)
			{
				if(ans[nxy.first][nxy.second]=='.')
				{
					ans[nxy.first][nxy.second]=way[t];
					q.push(nxy);
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cout<<ans[i][j];
		}
		cout<<endl;
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
