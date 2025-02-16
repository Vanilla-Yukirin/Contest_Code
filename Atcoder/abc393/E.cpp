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


#define N 1200010

int mp[N];
int prime[N];
bool book[N];
int sze;
void init()
{
	book[1]=1;
	for(int i=2,j;i<=1000000;i++)
	{
		if(!book[i]) prime[++sze]=i;
		for(j=1;j<=sze&&i*prime[j]<=1000000;j++)
		{
			book[i*prime[j]]=1;
			if(i%prime[j]==0) break;
		}
	}
}
int n;
int a[N];
vector<int>yinzi[N];
void dfs(vector<pair<int,int> >&p,int dep,int now,const int &ord,const int &c)
{
	if(dep==p.size())
	{
		mp[now]+=c;
//		DEBUG(now,2);
		yinzi[ord].push_back(now);
		return;
	}
	for(int i=0;i<=p[dep].second;i++)
	{
		dfs(p,dep+1,now,ord,c);
		now*=p[dep].first;
	}
}
int ans;
int K;
void dfs2(vector<pair<int,int> >&p,int dep,int now)
{
	if(dep==p.size())
	{
//		DEBUG(now,3);
//		DEBUG(mp[now],3);
		if(mp[now]>=K)
		{
//			DEBUG(now,4);
			ans=max(ans,now);
		}
		return;
	}
	for(int i=0;i<=p[dep].second;i++)
	{
		dfs2(p,dep+1,now);
		now*=p[dep].first;
	}
}
void solve()
{
	init();
	cin>>n>>K;
	map<int,int>cnt;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		cnt[a[i]]++;
	}
	for(auto it=cnt.begin();it!=cnt.end();it++)
	{
		int x=it->first;
		vector<pair<int,int>>p;
		for(int j=1;j<=sze;j++)
		{
			if(x%prime[j]==0)
			{
				p.push_back(make_pair(prime[j],0));
				while(x%prime[j]==0) x/=prime[j],p.back().second++;
			}
			if(book[x]==0)
			{
				p.push_back(make_pair(x,1));
				x=1;
				break;
			}
			if(x==1) break;
		}
		if(x!=1)
		{
			//不可能触发
			DEBUG(it->first,1);
			cout<<"!!!!!";
			return;
		}
		dfs(p,0,1,it->first,it->second);
	}
	for(int i=1;i<=n;i++)
	{
		ans=1;
		int x=a[i];
		for(int i=0;i<yinzi[x].size();i++)
		{
			if(mp[yinzi[x][i]]>=K) ans=max(ans,yinzi[x][i]);
		}
		cout<<ans<<endl;
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
