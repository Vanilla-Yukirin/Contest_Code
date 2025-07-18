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
string A="Ashishgup";
string B="FastestFinger";
void solve()
{
	cin>>n;
	if(n==1)
	{
		cout<<B<<endl;
		return;
	}
	if(n==2)
	{
		cout<<A<<endl;
		return;
	}
	if(n&1)
	{
		cout<<A<<endl;
		return;
	}
	int m=n;
	int p=0;
	while(m%2==0) p++,m/=2;
	if(m==1)
	{
		cout<<B<<endl;
		return;
	}
	bool isprime=1;
	for(int i=2;i*i<=m;i++)
	{
		if(m%i==0)
		{
			isprime=0;
			break;
		}
	}
	if(!isprime)
	{
		cout<<A<<endl;
		return;
	}
	if(p==1)
	{
		cout<<B<<endl;
		return;
	}
	cout<<A<<endl;
	
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
