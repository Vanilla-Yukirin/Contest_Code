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
	return qpow(a,p-2);
}
map<LL,vector<int>>mp;
int ppre[N];
void solve()
{
	DEBUG(8*inv(3)%p,1);
	DEBUG(inv(2),2);
	DEBUG(inv(6),3);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=6;j++)
		{
			cin>>a[i][j];
			mp[-a[i][j]].push_back(i);
		}
		ppre[i]=6;
	}
	LL ans=0;
	LL pre=1;
	for(auto it=mp.begin();it!=mp.end();it++)
	{
		LL x=-it->first;
		LL add=0;
		for(unsigned int i=0;i<it->second.size();i++)
		{
			int pos=it->second[i];
			int cnt=0;
			for(int j=1;j<=6;j++) if(a[pos][j]==x) cnt++;
			add+=x*inv(6)%p*pre%p*inv(ppre[pos]*inv(6)%p)%p;
			add%=p;
		}
		DEBUG(add,1);
		//update pre
		for(unsigned int i=0;i<it->second.size();i++)
		{
			int pos=it->second[i];
			pre=pre*inv(ppre[pos])%p;
			ppre[pos]--;
			pre=pre*ppre[pos]%p;
		}
		ans+=add;
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
