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


const LL       p = p1e9p7;
const LL     inf = e9;
const LL     INF = e18;

const int N = 2000010;
const int M = 50;


LL n,k;
LL dp[N],dp2[N];
LL s[N];
LL ans=1;
void init()
{
	dp[1]=1;
	dp2[1]=1;
	for(int i=2;i<=M;i++)
	{
		dp[i]=1;
		dp2[i]=i;
		for(int j=1;j<i;j++) dp[i]+=dp[j],dp2[i]=dp2[i]*dp2[j]%p;
//		DEBUG(i,1);
//		DEBUG(dp[i],2);
//		DEBUG(dp2[i],3);
	}
}

void calc(LL n)
{
	//enter some loop
	if(k==0) return;
	k--;
	ans=ans*n%p;
	for(int i=1;i<=n;i++)
	{
//		DEBUG(k,3);
		if(k==0) break;
		if(dp[i]<=k)
		{
//			debug
			k-=dp[i];
			ans=ans*dp2[i]%p;
		}
		else
		{
//			debug
			calc(i);
			break;
		}
	}
}

void solve()
{
	ans=1;
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>s[i];
	sort(s+1,s+n+1);
	for(int i=1;i<=n;i++)
	{
		if(s[i]>=M)
		{
//			debug
			calc(s[i]);
			break;
		}
		if(dp[s[i]]>k)
		{
//			DEBUG(s[i],1);
			calc(s[i]);
			break;
		}
//		DEBUG(s[i],2);
		k-=dp[s[i]];
		ans=ans*dp2[s[i]]%p;
	}
	cout<<ans<<endl;
	
}

int main()
{
	init();
	fastIO();
	cout.precision(10);
	int t=1;
	cin>>t;
	LOOP(t)
	{
		solve();
	}
	return 0;
}
