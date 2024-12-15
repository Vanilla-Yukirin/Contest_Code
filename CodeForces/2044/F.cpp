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

int n,m,q;
ll a[N],b[N];
ll suma,sumb;
set<ll>s;
void solve()
{
	cin>>n>>m>>q;
	suma=0;
	sumb=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		suma+=a[i];
	}
	sort(a+1,a+n+1);
	s.clear();
	for(int i=1;i<=m;i++)
	{
		cin>>b[i];
		sumb+=b[i];
		s.insert(b[i]);
	}
	sort(b+1,b+m+1);
	ll sum=suma*sumb;
	DEBUG(sum,3)
	while(q--)
	{
		ll tar;cin>>tar;
		ll need=sum-tar;
//		DEBUG(need,2);
		bool succ=0;
		for(int i=1;i<=n;i++)
		{
			if(mymod((need-a[i]*sumb),(suma-a[i]))==0)
			int j=0;
			for(int k=30;k>=0;k--)
			{
				if(j+(1<<k)<=n&&b[j+(1<<k)])
			}
		}
		if(succ)
		{
			cout<<"YES"<<endl;
		}
		else
		{
			cout<<"NO"<<endl;
		}
	}
	
	
	
	
	
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
