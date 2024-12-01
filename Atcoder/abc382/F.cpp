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


#define N 200010

// 区间赋值，查询区间最大值
struct node
{
	int l,r,mx,lazy;
#define l(x) tree[x].l
#define r(x) tree[x].r
#define mx(x) tree[x].mx
#define lazy(x) tree[x].lazy
}tree[N*4];

void build(int p,int l,int r)
{
	l(p)=l,r(p)=r;
	if(l==r)
	{
		mx(p)=0;
		return;
	}
	int mid=(l+r)/2;
	build(p<<1,l,mid);
	build(p<<1|1,mid+1,r);
	mx(p)=0;
}
void spread(int p)
{
	if(lazy(p))
	{
		mx(p<<1)=mx(p<<1|1)=lazy(p<<1)=lazy(p<<1|1)=lazy(p);
		lazy(p)=0;
	}
}

void change(int p,int l,int r,int k)
{
	if(l<=l(p)&&r(p)<=r)
	{
		lazy(p)=k;
		mx(p)=k;
		return;
	}
	spread(p);
	int mid=(l(p)+r(p))/2;
	if(l<=mid) change(p<<1,l,r,k);
	if(r>mid) change(p<<1|1,l,r,k);
	mx(p)=max(mx(p<<1),mx(p<<1|1));
}

int ask(int p,int l,int r)
{
	if(l<=l(p)&&r(p)<=r)
	{
		return mx(p);
	}
	spread(p);
	int mid=(l(p)+r(p))/2;
	int tmp=0;
	if(l<=mid) tmp=max(tmp,ask(p<<1,l,r));
	if(r>mid) tmp=max(tmp,ask(p<<1|1,l,r));
	return tmp;
}

int h,w,n;
struct Block
{
	int R,C,L;
	int num,ans;
}block[N];

bool cmp1(const Block &x,const Block &y)
{
	return x.R>y.R;
}
bool cmp2(const Block &x,const Block &y)
{
	return x.num<y.num;
}

void solve()
{
	cin>>h>>w>>n;
	build(1,1,w);
	for(int i=1;i<=n;i++)
	{
		cin>>block[i].R>>block[i].C>>block[i].L;
		block[i].num=i;
	}
	sort(block+1,block+n+1,cmp1);
	for(int i=1;i<=n;i++)
	{
		int l=block[i].C,r=block[i].C+block[i].L-1;
		int top=ask(1,l,r);
		top++;
		change(1,l,r,top);
		block[i].ans=top;
	}
	sort(block+1,block+n+1,cmp2);
	for(int i=1;i<=n;i++)
	{
		cout<<h-block[i].ans+1<<endl;
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
