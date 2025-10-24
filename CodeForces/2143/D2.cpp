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

const int N = 2010;
const int M = 2000010;



int n;
LL dp[N][N],nxt[N][N],c[N];
int a[N];


namespace seg1
{
	struct Edge{
		LL l,r,sum,add;
#define l(x) tree[x].l
#define r(x) tree[x].r
#define sum(x) tree[x].sum
#define add(x) tree[x].add
	}tree[N*4];
	LL n,m; 
	void build(LL l,LL r,LL p)
	{
		l(p)=l,r(p)=r;
		if(l==r){sum(p)=0;return;}
		LL mid=(l+r)>>1;
		build(l,mid,p<<1);
		build(mid+1,r,p<<1|1);
		sum(p)=sum(p<<1)+sum(p<<1|1);
	}
	void spread(LL p)
	{
		if(add(p))
		{
			sum(p<<1)+=add(p)*(r(p<<1)-l(p<<1)+1);
			sum(p<<1|1)+=add(p)*(r(p<<1|1)-l(p<<1|1)+1);
			add(p<<1)+=add(p);
			add(p<<1|1)+=add(p);
			add(p)=0;
		}
	}
	void change(LL l,LL r,LL p,LL k)
	{
		if(l<=l(p)&&r>=r(p)){add(p)+=k;sum(p)+=k*(r(p)-l(p)+1);return;}
		LL mid=l(p)+r(p)>>1;
		spread(p);
		if(l<=mid) change(l,r,p<<1,k);
		if(r>mid) change(l,r,p<<1|1,k);
		sum(p)=sum(p<<1)+sum(p<<1|1);
	}
	LL ask(LL l,LL r,LL p)
	{
		if(l<=l(p)&&r>=r(p)) return sum(p);
		spread(p);
		LL mid=l(p)+r(p)>>1,val=0;
		if(l<=mid) val+=ask(l,r,p<<1);
		if(r>mid) val+=ask(l,r,p<<1|1);
		return val;
	}
};

namespace seg2
{
	struct Edge{
		LL l,r,sum,add;
#define l(x) tree[x].l
#define r(x) tree[x].r
#define sum(x) tree[x].sum
#define add(x) tree[x].add
	}tree[N*4];
	LL n,m; 
	void build(LL l,LL r,LL p)
	{
		l(p)=l,r(p)=r;
		if(l==r){sum(p)=0;return;}
		LL mid=(l+r)>>1;
		build(l,mid,p<<1);
		build(mid+1,r,p<<1|1);
		sum(p)=sum(p<<1)+sum(p<<1|1);
	}
	void spread(LL p)
	{
		if(add(p))
		{
			sum(p<<1)+=add(p)*(r(p<<1)-l(p<<1)+1);
			sum(p<<1|1)+=add(p)*(r(p<<1|1)-l(p<<1|1)+1);
			add(p<<1)+=add(p);
			add(p<<1|1)+=add(p);
			add(p)=0;
		}
	}
	void change(LL l,LL r,LL p,LL k)
	{
		if(l<=l(p)&&r>=r(p)){add(p)+=k;sum(p)+=k*(r(p)-l(p)+1);return;}
		LL mid=l(p)+r(p)>>1;
		spread(p);
		if(l<=mid) change(l,r,p<<1,k);
		if(r>mid) change(l,r,p<<1|1,k);
		sum(p)=sum(p<<1)+sum(p<<1|1);
	}
	LL ask(LL l,LL r,LL p)
	{
		if(l<=l(p)&&r>=r(p)) return sum(p);
		spread(p);
		LL mid=l(p)+r(p)>>1,val=0;
		if(l<=mid) val+=ask(l,r,p<<1);
		if(r>mid) val+=ask(l,r,p<<1|1);
		return val;
	}
};


void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=n;j++)
		{
			dp[i][j]=0;
		}
	}
	LL ans=0;
	dp[0][0]=1;
	seg1::build(0,n,1);
	seg2::build(0,n,1);
	for(int i=1;i<=n;i++)
	{
		//  clear
		for(int x=0;x<=n;x++)
		{
			for(int y=0;y<=n;y++)
			{
				nxt[x][y]=0;
			}
		}
		for(int x=0;x<=a[i];x++)
		{
			nxt[x][a[i]]=seg1::ask(x,a[i],1);
			if(nxt[x][a[i]])
			{
				
			}
		}
		for(int y=a[i]+1;y<=n;y++)
		{
			LL sum=seg2::ask(0,a[i]-1,1);
			if(sum)
			{
				
			}
		}
		
		
		
		
		// add
		for(int x=0;x<=n;x++)
		{
			for(int y=0;y<=n;y++)
			{
				dp[x][y]+=nxt[x][y];
			}
		}
	}
	for(int x=0;x<=n;x++)
	{
		for(int y=x;y<=n;y++)
		{
			ans+=dp[x][y];
			ans%=p;
		}
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
