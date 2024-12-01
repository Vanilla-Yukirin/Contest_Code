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
int p[N];
int test()
{
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(rand()%100<p[i]) cnt++;
	}
	return cnt;
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>p[i];
	int test_time=1000000,test_ans=0;
	for(int i=1;i<=test_time;i++)
	{
		int now=0;
		int times=0;
		for(times=1;;times++)
		{
			now+=test();
			if(now>=m) break;
		}
		test_ans+=times;
	}
	cout<<fixed<<1.0*test_ans/test_time;
	cout.flush();
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cout.precision(10);
	int t=1;
	cin>>t;
	srand(time(0));
	LOOP(t)
	{
		solve();
	}
	return 0;
}
