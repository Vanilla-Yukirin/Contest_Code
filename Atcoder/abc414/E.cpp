/**************************************************************
 * Problem: 
 * Author: ArisuVanilla
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
#define pb(a,b) push_back(a,b)
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


#define N 1000010

#define p 998244353

int calc(LL n,LL l,LL r)
{
	LL res=0;
	LL b=l;
	while(b<=r)
	{
//		cout<<"b="<<b<<endl;
		LL k=n/b;
//		cout<<"k="<<k<<endl;
//		最大满足 floor(N/x)==k的x
		LL max_x=min(n/k,r);
		LL cnt=max_x-b+1;
		res+=(k-1)%p*(cnt)%p;
		res%=p;
//		cout<<"cnt="<<cnt<<endl;
		b=max_x+1;
	}
	return res;
}

LL n;
LL ans=0;

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

void solve()
{
	cin>>n;
	ans=(n-1)%p*((n-2)%p)%p*inv(2)%p;
//	cout<<"ans1="<<ans<<endl;
	LL sub=calc(n,2,n-1);
//	cout<<"sub="<<sub<<endl;
	cout<<((ans-sub)%p+p)%p<<endl;
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
