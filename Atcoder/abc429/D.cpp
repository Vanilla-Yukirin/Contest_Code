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


LL n,m,c;
map<LL,int>mp,pre;
LL calc(LL l,LL r)
{
	// calc pos[l] to pos[r]
}

LL a[N];
LL pos[N];

LL ans=0;
void solve()
{
	cin>>n>>m>>c;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		mp[a[i]]++;
	}
	
	sort(a+1,a+n+1);
	pre=mp;
	int tmp=0;
	int poscnt=0;
	for(auto it=pre.begin();it!=pre.end();it++)
	{
		tmp+=it->second;
		it->second=tmp;
		
		pos[++poscnt]=it->first;
	}
	
	int l=1,r=1;
	LL now=mp[pos[1]];
	for(;l<=poscnt;l++)
	{
		DEBUG(l,1);
		//l=pos[l],then how far can r run?
		while(now<c)
		{
			r=r%poscnt+1;
			now+=mp[pos[r]];
		}
		DEBUG(r,1);
		
		LL dis=pos[l]-pos[(l-2+poscnt)%poscnt+1];
//		cout<<"pre l = "<<(l-2+poscnt)%poscnt+1<<endl;
		if((l-2+poscnt)%poscnt+1>=l) dis+=m;
		
		
		DEBUG(dis,2);
		
		ans+=(dis)*(now);
		
		//away from l
		now-=mp[pos[l]];
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
