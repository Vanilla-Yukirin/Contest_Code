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

int n,k,q;
string s,t;
int dp[N];
int nxt[100];
void solve()
{
	cin>>n>>k;
	cin>>s;
	s=" "+s;
	for(int i=0;i<26;i++) nxt[i]=n+1;
	dp[n+1]=0;
	for(int i=n;i>=1;i--)
	{
		dp[i]=n-i+1;
		for(int ch=0;ch<k;ch++)
		{
			dp[i]=min(dp[i],dp[nxt[ch]]+1);
		}
//		DEBUG(i,1);
//		DEBUG(dp[i],2);
		nxt[s[i]-'a']=i;
	}
	cin>>q;
	while(q--)
	{
		cin>>t;
		int pos=0;
		for(int j=0;j<t.size();j++)
		{
			pos++;
			while(s[pos]!=t[j]&&pos<=n) pos++;
//			DEBUG(j,1);
//			DEBUG(pos,2);
			if(pos>n)
			{
				break;
			}
			
		}
		if(pos>n)
		{
			cout<<"0"<<endl;
			continue;
		}
		cout<<dp[pos]<<endl;
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
