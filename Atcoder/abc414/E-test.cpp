/**************************************************************
 * Problem: 
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


int n;


int calc(int n,int l,int r)
{
	int res=0;
	int b=l;
	while(b<=r)
	{
		cout<<"b="<<b<<endl;
		int k=n/b;
//		最大满足 floor(N/x)==k的x
		int max_x=min(n/k,r);
		int cnt=max_x-b+1;
		res+=k*cnt;
		b=max_x+1;
	}
	return res;
}



void solve()
{
	cin>>n;
	int last=0;
	int sum=0;
	for(int b=1;b<=n;b++)
	{
		cout<<n/b<<" ";
		if(n/b!=last) cout<<endl;
		last=n/b;
		sum+=n/b;
	}
	cout<<"sum="<<sum<<endl;
	cout<<calc(n,1,n)<<endl;
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
