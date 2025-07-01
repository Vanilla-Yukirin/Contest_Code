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


#define N 2000100

int n;
int a[N];
LL cnt[N];
LL more[N];
LL suf[N];
LL k[N];
int mex;
void solve()
{
	cin>>n;
	for(int i=0;i<=n+10;i++)
	{
		cnt[i]=0;
		more[i]=0;
		k[i]=0;
		suf[i]=0;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		cnt[a[i]]++;
	}
	mex=0;
	for(int i=0;i<=n+1;i++)
	{
		if(cnt[i]>1) more[i]=cnt[i]-1;
		if(mex==i&&cnt[i]) mex++;
	}
//	DEBUG(mex,1);
	for(int i=1;i<=n+1;i++)
	{
		more[i]+=more[i-1];
	}
	for(int i=n;i>=0;i--)
	{
		suf[i]=suf[i+1]+cnt[i];
	}
//	DEBUG(mex,1);
	for(int i=0;i<=mex;i++)
	{
//		if(cnt[i]==0) continue;
		LL l,r;
		l=cnt[i];
		//k-cnt[i]<=
		r=cnt[i]+suf[i+1];
		if(i) r+=more[i-1];
//		cout<<"i="<<i<<" L="<<l<<" R="<<r<<endl;
//		cout<<
		if(r>=l)
		{
			k[l]++;
			k[r+1]--;
		}
	}
	int ans=0;
	for(int i=0;i<=n;i++)
	{
		ans+=k[i];
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
