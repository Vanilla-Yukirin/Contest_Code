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

int n,k;
string str;
int a[N];
void solve()
{
	cin>>n>>k;
	cin>>str;
	int cnt1=0;
	for(int i=1;i<=n;i++) a[i]=str[i-1]-'0',cnt1+=(a[i]==1);
	if(cnt1<=k)
	{
		cout<<"Alice"<<endl;
		return;
	}
	if(k>=n-k+1)
	{
		bool flag=1;
		for(int i=n-k;i<=k;i++)
		{
			if(a[i]) flag=1;
		}
		if(flag) cout<<"Alice"<<endl;
		else cout<<"Bob"<<endl;
	}
	else cout<<"Bob"<<endl;
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
