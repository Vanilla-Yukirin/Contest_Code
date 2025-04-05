/**************************************************************
 * Problem: 
 * Author: Vanilla_chan
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
#define pb(a) push_back(a)
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


#define N 200100
int n,k;
#define p 998244353
LL a[N];
LL sum[N];
LL pw[N][11];
LL C[100][100];
void solve()
{
	for(int i=0;i<=10;i++)
	{
		C[i][0]=1;
	}
	for(int i=1;i<=20;i++)
	{
		for(int j=1;j<=20;j++)
		{
			C[i][j]=C[i-1][j-1]+C[i-1][j];
//			cout<<C[i][j]<<" ";
		}
//		cout<<endl;
	}
	
	
	cin>>n>>k;
	pw[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum[i]=sum[i-1]+a[i];
		sum[i]%=p;
		pw[i][1]=sum[i];
		pw[i][0]=1;
		for(int kk=2;kk<=10;kk++)
		{
			pw[i][kk]=pw[i][kk-1]*sum[i]%p;
		}
	}
	LL ans=0;
	vector<int>prem(n+1);
	for(int kk=0;kk<=k;kk++)
	{
		LL b=C[k][kk];
		if(kk&1) b=-b;
		prem[0]=pw[0][kk];
		for(int i=1;i<=n;i++) prem[i]=prem[i-1]+pw[i][kk],prem[i]%=p;
		LL now=0;
		for(int r=1;r<=n;r++)
		{
			now+=pw[r][k-kk]*(prem[r])%p;
			now%=p;
		}
		ans+=now*b%p;
		ans%=p;
		ans+=p;
		ans%=p;
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
//	cin>>t;
	LOOP(t)
	{
		solve();
	}
	return 0;
}
