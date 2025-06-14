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
int n,m;
vector<pair<int,int>>edge[N];
bool arr[N][1<<11];
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int x,y,z;
		cin>>x>>y>>z;
		edge[x].push_back(mk(y,z));
	}
	queue<pair<int,int>>q;
	q.push(mk(1,0));
	arr[1][0]=1;
	while(q.size())
	{
		pair<int,int>now=q.front();
		q.pop();
		int x=now.first;
		int dis=now.second;
		for(unsigned int j=0;j<edge[x].size();j++)
		{
			int y=edge[x][j].first;
			int ww=(dis^edge[x][j].second);
			if(arr[y][ww]) continue;
			arr[y][ww]=1;
			q.push(mk(y,ww));
		}
	}
	int ans=(1<<11);
	for(int i=0;i<(1<<11);i++)
	{
		if(arr[n][i])
		{
			ans=i;
			break;
		}
	}
	if(ans==(1<<11)) cout<<"-1"<<endl;
	else cout<<ans<<endl;
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
