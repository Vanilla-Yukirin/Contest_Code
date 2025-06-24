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
int cnt0;
int book[N];
int pre[N],suf[N];
vector<int>vec;
void solve()
{
	cin>>n;
	cnt0=0;
	int first0=0;
	vec.clear();
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==0)
		{
			cnt0++;
			if(first0==0) first0=i;
		}
		book[i]=0;
		pre[i]=0;
		suf[i]=0;
	}
	if(cnt0==0)
	{
		cout<<n<<endl;
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]||i==first0)
		{
			book[i]=1;
			vec.push_back(a[i]);
			if(vec.size()==1) pre[1]=a[i];
			else pre[vec.size()]=min(pre[vec.size()-1],a[i]);
		}
	}
	set<int>s;
	suf[vec.size()+1]=0;
	for(int i=int(vec.size());i>0;i--)
	{
		s.insert(vec[i-1]);
		suf[i]=suf[i+1];
		while(s.find(suf[i])!=s.end()) suf[i]++;
	}
	bool succ=1;
	for(unsigned i=1;i<vec.size();i++)
	{
		if(pre[i]<suf[i+1]) succ=0;
	}
	cout<<n-cnt0+succ<<endl;
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
