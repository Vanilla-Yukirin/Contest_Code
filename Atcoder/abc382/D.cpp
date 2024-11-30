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


int n,m;
vector<vector<ll>>ans;

void dfs(vector<ll>now)
{
	if((int)now.size()==n)
	{
		ans.pb(now);
		return;
	}
	for(int i=now.back()+10;i<=m&&i+10*(n-(int)now.size()-1)<=m;i++)
	{
		vector<ll>temp=now;
		temp.pb(i);
		dfs(temp);
	}
}

void solve()
{
	cin>>n>>m;
	for(int i=1;i<=m&&i+10*(n-1)<=m;i++)
	{
		vector<ll>now;
		now.pb(i);
		dfs(now);
	}
	cout<<ans.size()<<endl;
	for(int i=0;i<(int)ans.size();i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}
//	DEBUG(ans.size(),1)
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
