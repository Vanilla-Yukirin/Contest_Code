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
string str;
set<char>pre[N];
void solve()
{
	cin>>n;
	cin>>str;
	pre[0].clear();
	pre[0].insert(str[0]);
	for(int i=1;i<n;i++)
	{
		pre[i]=pre[i-1];
		pre[i].insert(str[i]);
	}
	for(int i=1;i<n-1;i++)
	{
		if(pre[i-1].find(str[i])!=pre[i-1].end())
		{
			cout<<"Yes"<<endl;
			return;
		}
	}
	pre[n].clear();
	pre[n-1].clear();
	pre[n-1].insert(str[n-1]);
	for(int i=n-2;i>=0;i--)
	{
		pre[i]=pre[i+1];
		pre[i].insert(str[i]);
	}
	for(int i=1;i<n-1;i++)
	{
		if(pre[i+1].find(str[i])!=pre[i+1].end())
		{
			cout<<"Yes"<<endl;
			return;
		}
	}
	cout<<"No"<<endl;
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
