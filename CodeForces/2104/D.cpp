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


#define N 10000100

LL prime[N];
bool book[N];
int cnt;
LL sum[N];
void init()
{
	for(int i=2;i<=10000000;i++)
	{
		if(book[i]==0)
		{
			prime[++cnt]=i;
			for(int j=i*2;j<=10000000;j+=i)
			{
				book[j]=1;
			}
		}
	}
//	DEBUG(cnt,1);
	for(int i=1;i<=cnt;i++) sum[i]=sum[i-1]+prime[i];
}

int n;
LL a[N];
LL preA[N];
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1,greater<int>());
//	DEBUG(a[1],1);
	for(int i=1;i<=n;i++) preA[i]=preA[i-1]+a[i];
	int ans=1;
	int l,r,mid;
	l=1;
	r=n;
	while(l<=r)
	{
		mid=(l+r)>>1;
//		DEBUG(mid,1);
//		DEBUG(preA[mid],2);
//		DEBUG(sum[mid],3);
		if(preA[mid]>=sum[mid])
		{
			ans=mid;
			l=mid+1;
		}
		else r=mid-1;
	}
	cout<<n-ans<<endl;
}

int main()
{
	init();
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
