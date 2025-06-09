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
struct Seg{
	struct node
	{
		int l,r,sum;
#define l(x) tree[x].l
#define r(x) tree[x].r
#define sum(x) tree[x].sum
	}tree[N*4];
	
	void build(int p,int l,int r)
	{
		l(p)=l;
		r(p)=r;
		sum(p)=0;
		if(l==r)
		{
			sum(p<<1)=sum(p<<1|1)=0;
			return;
		}
		int mid=(l+r)>>1;
		build(p<<1,l,mid);
		build(p<<1|1,mid+1,r);
	}
	void upd(int p)
	{
		sum(p)=sum(p<<1)+sum(p<<1|1);
	}
	void add(int p,int x)
	{
		if(l(p)==r(p))
		{
			sum(p)++;
			return;
		}
		int mid=(l(p)+r(p))>>1;
		if(x<=mid) add(p<<1,x);
		else add(p<<1|1,x);
		upd(p);
	}
	int ask(int p,int l,int r) // ask sum in [l,r]
	{
		if(l<=l(p)&&r(p)<=r)
		{
			return sum(p);
		}
		int mid=(l(p)+r(p))>>1;
		int ans=0;
		if(l<=mid) ans+=ask(p<<1,l,r);
		if(r>mid) ans+=ask(p<<1|1,l,r);
		return ans;
	}
}seg[2];

int n;
int a[N];
LL rev[2];
int ans[N];
void solve()
{
	cin>>n;
	seg[0].build(1,1,n);
	seg[1].build(1,1,n);
	rev[0]=rev[1]=0;
	priority_queue<int,vector<int>,greater<int>>q[2];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		rev[i&1]+=seg[i&1].ask(1,a[i]+1,n);
		seg[i&1].add(1,a[i]);
		q[i&1].push(a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		ans[i]=q[i&1].top();
		q[i&1].pop();
	}
	if((rev[0]%2)!=(rev[1]%2))
	{
		swap(ans[n],ans[n-2]);
	}
	for(int i=1;i<=n;i++)
	{
		cout<<ans[i]<<" ";
	}
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
