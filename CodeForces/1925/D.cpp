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

#define mod 1000000007
LL n,m,k;
int a[N],b[N];
LL f[N];
LL sum,p;

LL qpow(LL a,LL b)
{
	LL ans=1;
	while(b)
	{
		if(b&1) ans=ans*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ans%mod;
}
LL inv(LL a)
{
	return qpow(a,mod-2);
}
void solve()
{
	cin>>n>>m>>k;
	sum=0;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i]>>b[i]>>f[i];
		sum+=f[i];
		sum%=mod;
	}
	p=2*inv(n*(n-1)%mod)%mod;
	//选中的是朋友的概率
	LL choose_friend=p*m%mod;
	LL ans=0;
	
	while(k--)
	{
		ans+=choose_friend*sum%mod*inv(m)%mod;
		ans%=mod;
		sum+=choose_friend;
		sum%=mod;
	}
	cout<<ans<<endl;
	
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cout.precision(10);
	int t=1;
	cin>>t;
	LOOP(t)
	{
		solve();
	}
	return 0;
}
