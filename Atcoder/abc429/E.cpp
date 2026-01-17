/**************************************************************
 * Problem: 
 * Author: Neko_Yukirin
 * Date: 
 * E-Mail: Neko_Yukirin@outlook.com
 **************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define IL inline
#define re register

typedef long long LL;
typedef long long ll;
typedef unsigned long long ULL;
typedef unsigned long long ull;
#define mk(a,b) make_pair(a,b)
#define pb(x) push_back(x)

typedef pair<int,int> pii;
typedef pair<LL,LL> pll;
typedef pair<double,double> pdd;
typedef pair<int,int> pii;

typedef pair<pii,int> ppiii;
typedef pair<int,pii> pipii;

#define fi first
#define se second
#define YES cout<<"Yes"<<endl
#define NO cout<<"No"<<endl
#define ALICE cout<<"Alice"<<endl
#define BOB cout<<"Bob"<<endl
#define ALL(x) (x).begin(),(x).end()
#define endl '\n'



#ifdef TH

std::string COLORS[]={"\033[0m","\033[91m","\033[92m","\033[93m","\033[94m","\033[95m","\033[96m"};
std::string COLOR_NAMES[]={"RESET","RED","GREEN","YELLOW","BLUE","MAGENTA","CYAN"};

#define debug cout<<COLORS[6]<<"Now is "<<__LINE__<<COLORS[0]<<endl;

#define DEBUG(x,color)                   \
cout<<COLORS[color];                     \
cout <<"LINE"<<__LINE__<< "\t: " << #x << " : " << x << endl;        \
cout<<COLORS[0];                         \
cout.flush();

void fastIO()
{
	return;
}


#else

#define debug
#define DEBUG(x,color)

void fastIO()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	return;
}

#endif


#define LOOP(While_times) while(While_times-->0)
#define FOR(x,y) for(auto III=(x);III<=(y);III++)

const LL   p9982 = 998244353;
const LL  p1e9p7 = 1000000007;
const LL  p1e9p9 = 1000000009;
const LL   p1926 = 19260817;
const double eps = 1e-6;
const double  pi = acos(-1);
const LL     e18 = 1000000000000000000ll;
const LL     e17 = 100000000000000000ll;
const LL      e9 = 1000000000ll;


const LL       p = p9982;
const LL     inf = e9;
const LL     INF = e18;

const int N = 2000010;
const int M = 2000010;

int n,m;
vector<int>edge[N];
void insert(int x,int y)
{
	edge[x].pb(y);
	edge[y].pb(x);
}
bool saf[N];
map<int,LL>dis[N]; //from, dis
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		insert(x,y);
	}
	string s;cin>>s;
	for(int i=1;i<=n;i++)
	{
		saf[i]=(s[i-1]=='S');
	}
	
	queue<pair<int,pair<int,LL>>>q;
	// now,(start,dis)
	
	for(int i=1;i<=n;i++)
	{
		if(saf[i]==1) q.push(mk(i,mk(i,0)));
	}
	
	while(q.size())
	{
		pair<int,pair<int,LL>> x=q.front();
		q.pop();
		int now=x.first;
		int from=x.second.first;
		LL d=x.second.second;
		
		
		
		for(unsigned int i=0;i<edge[now].size();i++)
		{
			int y=edge[now][i];
			if(dis[y].size()>=2) continue;
			
			if(dis[y].find(from)==dis[y].end())
			{
				dis[y][from]=d+1;
				q.push(mk(y,mk(from,d+1)));
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(saf[i]==0)
		{
			LL ans=0;
			for(auto it=dis[i].begin();it!=dis[i].end();it++)
			{
				ans+=it->second;
			}
			cout<<ans<<endl;
		}
	}
}

int main()
{
	fastIO();
	cout.precision(10);
	int t=1;
//	cin>>t;
	LOOP(t)
	{
		solve();
	}
	return 0;
}
