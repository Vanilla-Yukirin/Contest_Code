/**************************************************************
 * Problem: 
 * Author: Vanilla_Yukirin
 * Date: 
 * E-Mail: Vanilla_Yukirin@outlook.com
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

/*

k=1
5 2 1 2
1 2 2 5
2 1 2 5
2 2 1 5

1 2 2 5
1 2 3 1

k=1
1 2 3 5
2 1 3 5
1 3 2 5

k=2
1 2 3 5 6 7
dp[1]=1
dp[2]=
dp[3]=dp[0]*3






*/



int n,d;
int a[N];


LL qpow(LL a,LL b)
{
	a%=p;
	LL ans=1;
	while(b)
	{
		if(b&1) ans=ans*a%p;
		b>>=1;
		a=a*a%p;
	}
	return ans%p;
}

LL inv(LL x)
{
	return qpow(x,p-2);
}

LL fac[N];

void solve()
{
	fac[0]=1;
	for(int i=1;i<=200000;i++)
	{
		fac[i]=fac[i-1]*i%p;
	}
	
	
	cin>>n>>d;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	
	LL ans=1;
	for(int i=1;i<=n;i++)
	{
		int pos=lower_bound(a+1,a+n+1,a[i]-d)-a;
		int head=i-pos+1;
//		cout<<a[i]<<"\t"<<head<<endl;
		ans=ans*head%p;
	}
	
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==a[i-1]) cnt++;
		else
		{
			ans=ans*inv(fac[cnt])%p;
			cnt=1;
		}
	}
	if(cnt)
	{
		ans=ans*inv(fac[cnt])%p;
	}
	
	cout<<ans<<endl;
	
	return;
	
	ans=0;
	vector<int>b(n+1);
//	for(int i=1;i<=n;i++) b[i]=i;
	do
	{
		bool succ=1;
		for(int i=2;i<=n;i++)
		{
			if(a[i]>=a[i-1]-d) continue;
			succ=0;
		}
		if(succ) ans++;
	}while(next_permutation(a+1,a+n+1));
	
	
	cout<<ans<<endl;
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
