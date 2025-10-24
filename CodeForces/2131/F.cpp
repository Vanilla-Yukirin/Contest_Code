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


int n;
LL a[N],b[N],a0[N],a1[N],b0[N],b1[N],C[N];
pair<LL,int>D[N];
LL pre[N],suf[N],DD[N];
LL suma0[N],suma1[N];
void solve()
{
	cin>>n;
	string str;cin>>str;
	for(int i=1;i<=n;i++) a[i]=(str[i-1]=='1'),a0[i]=a0[i-1]+(a[i]==1),a1[i]=a1[i-1]+(a[i]==0),C[i]=a0[i]-a1[i];
	cin>>str;
	for(int i=1;i<=n;i++) b[i]=(str[i-1]=='1'),b0[i]=b0[i-1]+(b[i]==1),b1[i]=b1[i-1]+(b[i]==0),D[i]=mk(b1[i]-b0[i],i);
	sort(D+1,D+n+1);
	for(int i=1;i<=n;i++)
	{
		pre[i]=pre[i-1]+b1[D[i].se];
		DD[i]=D[i].fi;
		suma0[i]=suma0[i-1]+a0[i];
		suma1[i]=suma1[i-1]+a1[i];
	}
	suf[n+1]=0;
	for(int i=n;i>=1;i--)
	{
		suf[i]=suf[i+1]+b0[D[i].se];
	}
	LL ans=0;
	for(int i=1;i<=n;i++)
	{
		int left=lower_bound(DD+1,DD+n+1,C[i])-DD;
		left--;
//		ans+=left*a1[i]+(n-left)*a0[i]+pre[left]+suf[n-left+1];
		LL now=left*a1[i]+(n-left)*a0[i]+pre[left]+suf[left+1];
		ans+=now;
	}
	cout<<ans<<endl;
}

int main()
{
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
