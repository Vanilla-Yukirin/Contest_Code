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


const LL       p = p9982;
const LL     inf = e9;
const LL     INF = e18;

const int N = 2000010;
const int M = 2000010;


LL qpow(LL a,LL b)
{
	a%=p;
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

LL fac[N];
LL n,sum0,sum1,ans,c[100];
LL dp[N];
void solve()
{
	sum0=sum1=0;
	ans=1;
	n=0;
	for(int i=0;i<26;i++)
	{
		cin>>c[i];
		n+=c[i];
		if(c[i]) ans=ans*inv(fac[c[i]])%p;
	}
	ans=ans*fac[(n+1)/2]%p*fac[n/2]%p;
	DEBUG(ans,1);
	for(int i=1;i<=n;i++) dp[i]=0;
	dp[0]=1;
	for(int i=0;i<26;i++)
	{
		if(c[i]==0) continue;
		for(int j=n;j>=0;j--)
		{
			if(j+c[i]>n) continue;
			dp[j+c[i]]=(dp[j+c[i]]+dp[j])%p;
		}
	}
	cout<<dp[(n+1)/2]*ans%p<<endl;
	
}

int main()
{
	fac[0]=1;
	for(int i=1;i<=500000;i++)
	{
		fac[i]=fac[i-1]*i%p;
	}
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
