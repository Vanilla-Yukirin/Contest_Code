/**************************************************************
 * Problem: bitset！啊？要吃4GB？！
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
int n,m,q;
int a[N],b[N];
vector<int>useful;
int lsh[N],flsh[N];
bitset<200010>pre[200010];
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i]>>b[i];
		useful.push_back(a[i]);
		useful.push_back(b[i]);
	}
	sort(useful.begin(),useful.end());
	for(int i=1;i<=m;i++)
	{
		lsh[a[i]]=lower_bound(useful.begin(),useful.end(),a[i])-useful.begin();
		flsh[lsh[a[i]]]=a[i];
		pre[lsh[a[i]]].set(i);
		lsh[b[i]]=lower_bound(useful.begin(),useful.end(),b[i])-useful.begin();
		flsh[lsh[b[i]]]=b[i];
		pre[lsh[b[i]]].set(i);
	}
	for(int i=1;i<=m*2;i++)
	{
		pre[i]=pre[i-1]^pre[i];
	}
	cin>>q;
	while(q--)
	{
		int c,d;
		cin>>c>>d;
		c=lower_bound(useful.begin(),useful.end(),c)-useful.begin();
		d=lower_bound(useful.begin(),useful.end(),d)-useful.begin();
		d--;
		c--;
		cout<<(pre[d]^pre[c]).count()<<endl;
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
