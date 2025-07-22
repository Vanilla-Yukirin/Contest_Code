/**************************************************************
 * Problem: 
 * Author: Vanilla_chan
 * Date: 
 * E-Mail: heshaohong2015@outlook.com
 **************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define IL inline
#define re register

typedef long long LL;
typedef long long ll;
typedef unsigned long long ULL;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<LL,LL> pLL;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;

#define mk(a,b) make_pair(a,b)
#define pb(x) push_back(x)
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



LL qpow(LL a,LL b)
{
	LL ans=1;
	while(b)
	{
		if(b&1) ans=ans*a%p;
		a=a*a%p;
		b>>=1;
	}
	return ans%p;
}

LL inv(LL a)
{
	return qpow(a,p-2);
}


int n,m;
vector<pair<int,LL>>edge[N];
LL dp[N];
void solve()
{
	cin>>n>>m;
//	cout<<qpow(n,m)*inv(m)%p<<endl;
	for(int i=0;i<=m;i++)
	{
		dp[i]=0;
		edge[i].clear();
	}
	dp[0]=1;
	for(int i=1;i<=n;i++)
	{
		LL l,r,x,y;
		cin>>l>>r>>x>>y;
		x=x*inv(y)%p;
		edge[r].push_back(mk(l,x));
		dp[0]=dp[0]*(1+p-x)%p;
	}
	DEBUG(dp[0],1);
	for(int i=1;i<=m;i++)
	{
		DEBUG(i,1);
		for(unsigned int j=0;j<edge[i].size();j++)
		{
			int l=edge[i][j].fi;
			LL pp=edge[i][j].se;
			LL res=dp[l-1]*pp%p*inv(1+p-pp)%p;
			DEBUG(res,3);
			dp[i]+=dp[l-1]*pp%p*inv(1+p-pp)%p;
			dp[i]%=p;
			DEBUG(l,3);
			DEBUG(dp[l-1],3);
		}
		DEBUG(dp[i],2);
	}
	cout<<dp[m]<<endl;
	
	
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
