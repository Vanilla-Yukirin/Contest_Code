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
string str;
LL Lto[N],Rto[N],Lsum[N],Rsum[N];
void solve()
{
	cin>>n;
	cin>>str;
	str=" "+str;
	for(int i=1;i<=n;i++)
	{
		Lsum[i]=Lsum[i-1];
		Lto[i]=Lto[i-1]+Lsum[i];
		
		if(str[i]=='1') Lsum[i]++;
	}
	for(int i=n;i>=1;i--)
	{
		Rsum[i]=Rsum[i+1];
		Rto[i]=Rto[i+1]+Rsum[i];
		
		if(str[i]=='1') Rsum[i]++;
//		DEBUG(i,1);
//		DEBUG(Rsum[i],2);
//		DEBUG(Rto[i],3);
	}
	LL ans=500000ll*500000;
	for(int i=1;i<=n;i++)
	{
//		DEBUG(i,1);
//		DEBUG(Lto[i]+Rto[i],2);
		ans=min(ans,Lto[i]-(0+Lsum[i]-1ll)*Lsum[i]/2+Rto[i+1]-(0+Rsum[i+1]-1ll)*Rsum[i+1]/2);
	}
	cout<<ans<<endl;
//	cout<<ans-(0+Lsum[n]-1ll)*Lsum[n]/2;
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
