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
#define p 998244353
int n;
LL a[N][7];
LL qpow(LL a,LL b)
{
	LL ans=1;
	while(b)
	{
		if(b&1) ans=ans*a%p;
		a=a*a%p;
		b>>=1;
	}
	return ans;
}

LL inv(LL a)
{
	if(a==0) return 1;
	return qpow(a,p-2);
}
vector<pair<LL,int>>vec;
int ppre[N];
void solve()
{
//	DEBUG(8*inv(3)%p,1);
//	DEBUG(inv(2),2);
//	DEBUG(inv(6),3);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=6;j++)
		{
			cin>>a[i][j];
			vec.push_back(mk(a[i][j],i));
		}
		ppre[i]=0;
	}
	sort(vec.begin(),vec.end());
	LL ans=0;
	LL pre=1;
	int cnt=0;
	for(int i=0;i<vec.size();i++)
	{
		LL x=vec[i].first;
		int pos=vec[i].second;
		if(ppre[pos]==0) cnt++;
		if(cnt==n)
		{
			ans+=x*pre%p*inv(ppre[pos])%p;
			ans%=p;
		}
		// upd
		pre=pre*inv(ppre[pos])%p;
		ppre[pos]++;
		pre=pre*ppre[pos]%p;
	}
	cout<<ans*qpow(inv(6),n)%p<<endl;
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
