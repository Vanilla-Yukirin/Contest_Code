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


#define N 1000010

int n,m;
map<LL,map<LL,bool>>mp;
map<LL,set<LL>>ij,ji;
int ans=0;
void solve()
{
	LL x,y;
	cin>>n>>m>>x>>y;
	for(int i=1;i<=n;i++)
	{
		LL a,b;cin>>a>>b;
		mp[a][b]=1;
		ij[a].insert(b);
		ji[b].insert(a);
	}
	for(int i=1;i<=m;i++)
	{
		char a;
		LL b;cin>>a>>b;
		if(a=='U'||a=='D')
		{
			LL sy,ey;
			if(a=='U') sy=y,ey=y+b;
			else sy=y-b,ey=y;
			set<LL>::iterator it=ij[x].lower_bound(sy);
			while(it!=ij[x].end())
			{
				if(*it>ey) break;
				if(mp[x].find(*it)!=mp[x].end())
				{
					ans++;
					mp[x].erase(*it);
				}
				it=ij[x].erase(it);
			}
			if(a=='U') y+=b;
			else y-=b;
		}
		else
		{
			LL sx,ex;
			if(a=='R') sx=x,ex=x+b;
			else sx=x-b,ex=x;
			set<LL>::iterator it=ji[y].lower_bound(sx);
			while(it!=ji[y].end())
			{
				if(*it>ex) break;
				if(mp[*it].find(y)!=mp[*it].end())
				{
					ans++;
					mp[*it].erase(y);
				}
				it=ji[y].erase(it);
			}
			if(a=='R') x+=b;
			else x-=b;
		}
	}
	cout<<x<<" "<<y<<" "<<ans<<endl;
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
