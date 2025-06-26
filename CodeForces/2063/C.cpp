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

vector<int>edge[N];
set<int>near[N];
int d[N];
set<pair<int,int>>s;
int n;
void solve()
{
	cin>>n;
	//clear
	s.clear();
	for(int i=1;i<=n;i++)
	{
		edge[i].clear();
		near[i].clear();
		d[i]=0;
	}
	//read
	for(int i=1;i<n;i++)
	{
		int x,y;
		cin>>x>>y;
		edge[x].push_back(y);
		edge[y].push_back(x);
		near[x].insert(y);
		near[y].insert(x);
		d[x]++;
		d[y]++;
	}
	for(int i=1;i<=n;i++)
	{
		s.insert(make_pair(-d[i],i));
	}
	int ans=0;
	//calc
	for(int i=1;i<=n;i++)
	{
//		set<pair<int,int>>s2=s;
		for(unsigned int j=0;j<edge[i].size();j++)
		{
			s.erase(make_pair(-d[edge[i][j]],edge[i][j]));
			s.insert(make_pair(-d[edge[i][j]]+1,edge[i][j]));
//			DEBUG(s2.size(),2);
		}
		s.erase(make_pair(-d[i],i));
//		DEBUG(s2.size(),3);
		ans=max(ans,d[i]-s.begin()->first-1);
		for(unsigned int j=0;j<edge[i].size();j++)
		{
			s.insert(make_pair(-d[edge[i][j]],edge[i][j]));
			s.erase(make_pair(-d[edge[i][j]]+1,edge[i][j]));
//			DEBUG(s2.size(),2);
		}
		s.insert(make_pair(-d[i],i));
	}
	cout<<ans<<endl;
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
