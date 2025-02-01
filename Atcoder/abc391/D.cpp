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

map<int,int>max_die,cnt;
int n,w,q;
int X[N],Y[N],num[N];
vector<int>vec[N];
void solve()
{
	cin>>n>>w;
	for(int i=1;i<=n;i++) cin>>X[i]>>Y[i],vec[X[i]].push_back(Y[i]);
	for(int i=1;i<=w;i++)
	{
		sort(vec[i].begin(),vec[i].end());
	}
	for(int i=1;i<=n;i++)
	{
		num[i]=lower_bound(vec[X[i]].begin(),vec[X[i]].end(),Y[i])-vec[X[i]].begin()+1;
		cnt[num[i]]++;
		max_die[num[i]]=max(max_die[num[i]],Y[i]);
//		cout<<num[i]<<endl;
	}
	cin>>q;
	while(q--)
	{
		int x,y;cin>>x>>y;
		if(cnt[num[y]]<w||max_die[num[y]]>x) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
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
