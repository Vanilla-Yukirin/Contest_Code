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
#define p 1000000007
LL dp[N][3];
int n,l,r;

void solve()
{
	cin>>n>>l>>r;
	dp[0][0]=1;
	LL cnt[3];
	cnt[0]=(r+3)/3-(l+2)/3;
	cnt[1]=(r+2)/3-(l+1)/3;
	cnt[2]=(r+1)/3-l/3;
	for(int i=1;i<=n;i++)
	{
		for(int now=0;now<3;now++)
		{
			for(int pre=0;pre<3;pre++)
			{
				dp[i][now]+=dp[i-1][pre]*cnt[(now-pre+3)%3];
				dp[i][now]%=p;
			}
		}
	}
	cout<<dp[n][0]<<endl;
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
