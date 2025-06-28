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
int n,c,m;
LL a[N];
LL big=0;
int small[N];
map<int,vector<int>>mp;
LL dp[N];
#define p 998244353ll
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
	return qpow(a,p-2)%p;
}
void solve()
{
	cin>>n>>c;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		m+=a[i];
	}
	a[c]++;
	for(int i=1;i<=n;i++)
	{
		mp[a[i]].push_back(i);
	}
	int cnt=0;
	for(auto it=mp.begin();it!=mp.end();it++)
	{
//		DEBUG(it->first,1);
		cnt+=it->second.size()*it->first;
		for(unsigned int i=0;i<it->second.size();i++)
		{
			int idx=it->second[i];
			small[idx]=cnt-it->first;
		}
	}
	for(int i=1;i<=n;i++)
	{
//		cout<<small[i]<<endl;
	}
	for(auto it=mp.rbegin();it!=mp.rend();it++)
	{
//		DEBUG(it->first,1);
		for(unsigned int i=0;i<it->second.size();i++)
		{
			int idx=it->second[i];
			dp[idx]=(a[idx]-1+small[idx]+big)%p*inv(m-small[idx])%p;
		}
		for(unsigned int i=0;i<it->second.size();i++)
		{
			int idx=it->second[i];
			big+=a[idx]*(dp[idx]+1);
			big%=p;
		}
	}
	for(int i=1;i<=n;i++)
	{
//		cout<<dp[i]<<endl;
	}
	cout<<dp[c]<<endl;
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
