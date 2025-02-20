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

const LL p = 998244353;
#define N 200010
int n;
int a[N];
LL ans;

/*
1 2 2 2 2 2 3


1 2 3 : R3，L2，以及每个3要先知道L2，则该3的贡献为2^(L2-L2)，总贡献为sum 2^(L2-L2)
将1的L2提取出来，用逆元，即求2^L2及前缀和，再除以2^(1的L2)

*/
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
int R3[N],R3L2[N],L2[N],powL2[N],sumL2[N];
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		L2[i]=L2[i-1]+(a[i]==2);
		powL2[i]=qpow(2,L2[i]);
	}
	R3[n+1]=R3L2[n+1]=0;
	for(int i=n;i>=1;i--)
	{
//		R2[i]=R2[i+1]+(a[i]==2);
		R3L2[i]=R3L2[i+1]+(a[i]==3?powL2[i]:0);
		R3[i]=R3[i+1]+(a[i]==3);
	}
	ans=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==1)
		{
			ans+=R3L2[i]*qpow(qpow(2,p-2),L2[i])%p+p-R3[i];
			ans%=p;
		}
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
