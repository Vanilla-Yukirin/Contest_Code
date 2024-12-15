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
int r[N];
bool book[N];
set<int>s;
vector<int>st;
int ans;
bool rnd[N];
bool root[N];
void dfs(int x)
{
	s.insert(x);
	st.push_back(x);
	book[x]=1;
	if(s.find(r[x])!=s.end())
	{
		rnd[r[x]]=1;
		while(st.size()&&st.back()!=r[x]) rnd[st.back()]=1,st.pop_back();
		return;
	}
	if(!book[r[x]]) dfs(r[x]);
}
vector<int>fa[N];
void dfs2(int x)
{
//	DEBUG(x,1);
	for(int i=0;;i++,x=r[x])
	{
//		DEBUG(i,2);
		if(rnd[x])
		{
			ans=max(ans,i);
			return;
		}
	}
}
void solve()
{
	ans=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		root[i]=1;
		book[i]=0;
		rnd[i]=0;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>r[i];
		fa[r[i]].push_back(i);
		root[r[i]]=0;
	}
	for(int i=1;i<=n;i++)
	{
		if(!book[i]) 
		{
			s.clear();
			st.clear();
			dfs(i);
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(root[i])
		{
			dfs2(i);
		}
	}
	cout<<ans+2<<endl;
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
