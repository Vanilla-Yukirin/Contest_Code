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
vector<int>edge[N];
bool ans[N];
void solve()
{
	cin>>n;
	//clear
	for(int i=1;i<=n;i++) edge[i].clear(),ans[i]=0;
	//read
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<n;i++)
	{
		int x,y;cin>>x>>y;
		edge[x].push_back(y);
		edge[y].push_back(x);
	}
	//a==b
	for(int i=1;i<=n;i++)
	{
		for(unsigned int j=0;j<edge[i].size();j++)
		{
			if(a[i]==a[edge[i][j]]) ans[a[i]]=1;
		}
	}
	//a==c
	for(int i=1;i<=n;i++)
	{
//		for(unsigned int j1=0;j1<edge[i].size();j1++)
//		{
//			for(unsigned int j2=j1+1;j2<edge[i].size();j2++)
//			{
//				if(a[edge[i][j1]]==a[edge[i][j2]]) ans[a[edge[i][j1]]]=1;
//			}
//		}
		set<int>s;
		for(unsigned int j=0;j<edge[i].size();j++)
		{
			if(s.find(a[edge[i][j]])==s.end()) s.insert(a[edge[i][j]]);
			else ans[a[edge[i][j]]]=1;
		}
	}
	for(int i=1;i<=n;i++) cout<<ans[i];
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
