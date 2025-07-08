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

int n,m,q;
vector<int>edge[N];
int degree[N],small[N];

int ans=0;

void solve()
{
	cin>>n>>m;
	while(m--)
	{
		int x,y;
		cin>>x>>y;
//		edge[x].push_back(y);
//		edge[y].push_back(x);
		degree[x]++;
		degree[y]++;
		small[max(x,y)]++;
	}
	ans=0;
	for(int i=1;i<=n;i++)
	{
		if(small[i]==degree[i]||degree[i]==0) ans++;
	}
	cin>>q;
	while(q--)
	{
		int op;
		cin>>op;
		if(op==1)
		{
			int x,y;
			cin>>x>>y;
//			edge[x].push_back(y);
//			edge[y].push_back(x);
			if(small[x]==degree[x]||degree[x]==0) ans--;
			if(small[y]==degree[y]||degree[y]==0) ans--;
			degree[x]++;
			degree[y]++;
			small[max(x,y)]++;
			if(small[x]==degree[x]||degree[x]==0) ans++;
			if(small[y]==degree[y]||degree[y]==0) ans++;
		}
		else if(op==2)
		{
			int x,y;
			cin>>x>>y;
			if(small[x]==degree[x]||degree[x]==0) ans--;
			if(small[y]==degree[y]||degree[y]==0) ans--;
			degree[x]--;
			degree[y]--;
			small[max(x,y)]--;
			if(small[x]==degree[x]||degree[x]==0) ans++;
			if(small[y]==degree[y]||degree[y]==0) ans++;
		}
		else
		{
			cout<<ans<<endl;
		}
	}
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
