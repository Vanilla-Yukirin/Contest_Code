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

#define pii pair<int,int>
#define N 2000100
int n,m;
pair<int,pii>pos[N];
void solve()
{
	cin>>n>>m;
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			int t;
			cin>>t;
			pos[++cnt]=mk(t,mk(i,j));
		}
	}
	sort(pos+1,pos+cnt+1);
	int ans=pos[cnt].first;
	int r=0,c=0;
	//choose pos[cnt].x
	r=pos[cnt].second.first;
	for(int i=cnt;i>=1;i--)
	{
		if(pos[i].second.first!=r)
		{
			c=pos[i].second.second;
			break;
		}
	}
//	DEBUG(r,1);
//	DEBUG(c,1);
	if(c==0)
	{
		ans=pos[cnt].first-1;
	}
	else
	for(int i=cnt;i>=1;i--)
	{
		if(pos[i].second.first!=r&&pos[i].second.second!=c)
		{
			ans=min(ans,max(pos[cnt].first-1,pos[i].first));
			break;
		}
	}
//	DEBUG(ans,2);
	//choose pos[cnt].y
	r=0;
	c=0;
	c=pos[cnt].second.second;
	for(int i=cnt;i>=1;i--)
	{
		if(pos[i].second.second!=c)
		{
			r=pos[i].second.first;
			break;
		}
	}
//	DEBUG(r,1);
//	DEBUG(c,1);
	if(r==0)
	{
		ans=pos[cnt].first-1;
	}
	else
	for(int i=cnt;i>=1;i--)
	{
		if(pos[i].second.first!=r&&pos[i].second.second!=c)
		{
			ans=min(ans,max(pos[cnt].first-1,pos[i].first));
			break;
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
	cin>>t;
	LOOP(t)
	{
		solve();
	}
	return 0;
}
