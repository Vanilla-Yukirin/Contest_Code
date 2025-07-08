/**************************************************************
 * Problem: A
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


int n,m;
int a[N];
int ans=0;
int cnt[N];
void solve()
{
	cin>>n>>m;
	ans=0;
	for(int i=0;i<=m;i++)
	{
		cnt[i]=0;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		a[i]%=m;
		cnt[a[i]]++;
	}
	if(cnt[0]) ans++;
	for(int i=1,j=m-1;i<=j;i++,j--)
	{
		if(i==j&&cnt[i])
		{
			ans++;
			break;
		}
		if(cnt[i]||cnt[j])
		{
			if(abs(cnt[i]-cnt[j])<=1)
			{
				ans++;
			}
			else
			{
				ans+=abs(cnt[i]-cnt[j]);
			}
		}
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
	cin>>t;
	LOOP(t)
	{
		solve();
	}
	return 0;
}
