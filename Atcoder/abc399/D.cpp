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
map<pair<int,int>,int>mp,ans;
set<int>no;
int n;
int a[N];
vector<int>pos[2];
void solve()
{
	mp.clear();
	no.clear();
	pos[0].clear();
	pos[1].clear();
	ans.clear();
	cin>>n;
	n*=2;
	pos[0].resize(n+1);
	pos[1].resize(n+1);
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		pos[1][a[i]]=pos[0][a[i]];
		pos[0][a[i]]=i;
	}
	set<pair<int,int>>s;
	for(int i=1;i<n;i++)
	{
		s.insert(make_pair(min(a[i],a[i+1]),max(a[i],a[i+1])));
	}
	int ans=0;
	for(auto it=s.begin();it!=s.end();it++)
	{
		int x=(*it).first,y=(*it).second;
		if(abs(pos[0][x]-pos[1][x])!=1&&abs(pos[0][y]-pos[1][y])!=1)
		{
//			swap(pos[0][x],pos[0][y]);
			if(abs(pos[0][y]-pos[1][x])==1&&abs(pos[0][x]-pos[1][y])==1)
			{
				ans++;
				continue;
			}
//			swap(pos[0][x],pos[1][y]);
			if(abs(pos[1][y]-pos[1][x])==1&&abs(pos[0][y]-pos[0][x])==1)
			{
				ans++;
				continue;
			}
//			swap(pos[1][x],pos[0][y]);
			if(abs(pos[0][x]-pos[0][y])==1&&abs(pos[1][x]-pos[1][y])==1)
			{
				ans++;
				continue;
			}
//			swap(pos[1][x],pos[1][y]);
			if(abs(pos[0][x]-pos[1][y])==1&&abs(pos[0][y]-pos[1][x])==1)
			{
				ans++;
				continue;
			}
		}
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
