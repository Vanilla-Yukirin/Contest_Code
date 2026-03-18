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

const int N = 550;






/*
对于前i个零件，身体比头重delta重量时，最大的幸福度
dp[i][delta]=max(dp[i-1][delta-W[i]]+H,dp[i-1][delta+W[i]]+B)
*/
int n,W[N];
LL H[N],B[N];
int delta=500*500;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>W[i]>>H[i]>>B[i];
	}
	
	vector<LL>m1(500*500*2+10,-INF),m2(500*500*2+10,-INF);
	m1[0+delta]=0;
	for(int i=1;i<=n;i++)
	{
//		DEBUG(i,1);
		for(int j=0;j<500*500*2+10;j++)
		{
			if(m1[j]<0) continue;
			if(j-W[i]>=0) m2[j-W[i]]=max(m2[j-W[i]],m1[j]+H[i]);
			if(j+W[i]<500*500*2+10) m2[j+W[i]]=max(m2[j+W[i]],m1[j]+B[i]);
		}
		m1=m2;
//		m2.clear();
		for(int i=0;i<500*500*2+10;i++)
		{
			m2[i]=-INF;
		}
	}
	
	
	LL ans=0;
	for(int i=0;i<500*500*2+10;i++)
	{
		if(i-delta>=0) ans=max(ans,m1[i]);
	}
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
