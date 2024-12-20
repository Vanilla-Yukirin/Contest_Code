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
#define inf 1000000010;
int n,m;
void solve()
{
	cin>>n>>m;
	vector<int>a(n),b(m),c(m);
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		a[i]=max(a[i],a[0]);
	}
	sort(a.begin(),a.end());
	for(int i=0;i<m;i++)
	{
		cin>>b[i];
		if(b[i]<=a[0]) b[i]=inf;
	}
	sort(b.begin(),b.end());
	for(int i=0;i<m;i++)
	{
		c[i]=a.end()-lower_bound(a.begin(),a.end(),b[i]);
		// 能够解出第i题的人数有多少，贡献即为c[i]+1
	}
	for(int k=1;k<=m;k++)
	{
		ll ans=0;
		for(int i=m-k;i>=0;i-=k)
		{
			ans+=c[i]+1;
		}
		cout<<ans<<" ";
	}
	cout<<endl;
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
