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


#define N 1000010

int n;
int solo[N],a[N];
int cnt[N];
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		solo[i]=0;
		cnt[i]=0;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		cnt[a[i]]++;
		if(cnt[a[i]]==1) solo[a[i]]=1;
		if(cnt[a[i]]==2) solo[a[i]]=0;
	}
	int l=0,r=0,ans=0;
	int nowl=0;
	for(int i=1;i<=n;i++)
	{
//		DEBUG(solo[a[i]],1);
		if(solo[a[i]]==1)
		{
			if(nowl==0) nowl=i;
			if(i-nowl+1>ans)
			{
				ans=i-nowl+1;
				l=nowl;
				r=i;
			}
		}
		else
		{
			nowl=0;
		}
	}
	if(l==0) cout<<l<<endl;
	else cout<<l<<" "<<r<<endl;
	
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
