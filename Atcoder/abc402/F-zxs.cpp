/**************************************************************
 * Problem: F-主席树！啊！
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
#define M 400010
int n,m,q;
int a[N],b[N];
vector<int>useful;
int lsh[N],flsh[N];

int pos[M];

struct node
{
	int lson,rson,cnt;
#define lson(x) tree[x].lson
#define rson(x) tree[x].rson
#define cnt(x) tree[x].cnt
}tree[M*40];
int cnt;
int root[M];
int new_node(int lp=0)
{
	int p=++cnt;
	tree[p]=tree[lp];
	return p;
}
void change(int &p,int lp,int l,int r,int x)
{
	p=new_node(lp);
	if(l==r)
	{
		cnt(p)^=1;
		return;
	}
	int mid=(l+r)>>1;
	if(x<=mid) change(lson(p),lson(lp),l,mid,x);
	else change(rson(p),rson(lp),mid+1,r,x);
	cnt(p)=
}
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
		pos[lsh[a[i]]]=i;
		lsh[b[i]]=lower_bound(useful.begin(),useful.end(),b[i])-useful.begin();
		flsh[lsh[b[i]]]=b[i];
		pos[lsh[b[i]]]=i;
	}
	for(int i=1;i<=m*2;i++)
	{
		change()
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
	cin>>t;
	LOOP(t)
	{
		solve();
	}
	return 0;
}
