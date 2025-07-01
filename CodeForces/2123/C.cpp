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
int mn[N],mx[N];
void solve()
{
	cin>>n;
	mn[0]=100001000;
	mx[n+1]=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		mn[i]=min(mn[i-1],a[i]);
	}
	for(int i=n;i>=1;i--)
	{
		mx[i]=max(a[i],mx[i+1]);
	}
	for(int i=1;i<=n;i++)
	{
		if(i==1||i==n) cout<<"1";
		else
		{
			if((a[i]>mx[i+1]&&a[i]>mn[i-1])||(a[i]<mx[i+1]&&a[i]<mn[i-1])||(a[i]>mx[i+1]&&a[i]<mn[i-1])) cout<<"1";
			else cout<<"0";
		}
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
