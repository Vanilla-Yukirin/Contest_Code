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
string str;
int n,k;
void solve()
{
	cin>>n>>k;
	cin>>str;
	int cnt1=0;
	for(int i=0;i<n;i++)
	{
		if(str[i]=='1') cnt1++;
	}
	int mx=0;
	if(cnt1&1) mx=n/2-1;
	else mx=n/2;
	int mn=n/2-min(cnt1,n-cnt1);
	
//	DEBUG(mn,1);
//	DEBUG(mx,2);
	int cnt=0;
	for(int i=0;i<n/2;i++)
	{
		if(str[i]==str[n-i-1]) cnt++;
	}
	if(k>=mn&&k<=mx&&cnt%2==k%2)
	{
		cout<<"YES"<<endl;
	}
	else
	{
		cout<<"NO"<<endl;
	}
}

int main()
{
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
	cout.precision(10);
	int t=1;
	cin>>t;
	LOOP(t)
	{
		solve();
	}
	return 0;
}
