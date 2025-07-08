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


#define N 800010





int n,m;
map<int,int>lsh;
int cnt;
int op[N];

struct node
{
	int l,r,sz;
	LL sum[5];
#define l(x) tree[x].l
#define r(x) tree[x].r
#define sz(x) tree[x].sz
#define sum(x) tree[x].sum
}tree[N*4];

void build(int p,int l,int r)
{
	l(p)=l;
	r(p)=r;
	if(l>=r)
	{
		return;
	}
	int mid=(l+r)>>1;
	build(p<<1,l,mid);
	build(p<<1|1,mid+1,r);
}
void upd(int p)
{
	sz(p)=sz(p<<1)+sz(p<<1|1);
	for(int i=0;i<5;i++)
	{
		sum(p)[i]=sum(p<<1)[i]+sum(p<<1|1)[((i-sz(p<<1)%5)%5+5)%5];
	}
}
void add(int p,int x,int v)
{
	if(l(p)==r(p))
	{
		if(sz(p)==0||1)
		{
			sz(p)++;
			sum(p)[sz(p)%5]+=v;
		}
		return;
	}
	int mid=(l(p)+r(p))>>1;
	if(x<=mid) add(p<<1,x,v);
	else add(p<<1|1,x,v);
	upd(p);
}
void del(int p,int x,int v)
{
	if(l(p)==r(p))
	{
		if(sz(p)||1)
		{
			sum(p)[sz(p)%5]-=v;
			sz(p)--;
		}
		return;
	}
	int mid=(l(p)+r(p))>>1;
	if(x<=mid) del(p<<1,x,v);
	else del(p<<1|1,x,v);
	upd(p);
}
LL ask()
{
	return sum(1)[3];
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		string str;cin>>str;
		if(str=="add") 
		{
			cin>>op[i];
			lsh[op[i]]=1;
		}
		else if(str=="del")
		{
			cin>>op[i];
			lsh[op[i]]=1;
			op[i]=-op[i];
		}
	}
	for(auto it=lsh.begin();it!=lsh.end();it++)
	{
		it->second=++cnt;
	}
	
	build(1,1,cnt);
	
	for(int i=1;i<=n;i++)
	{
		if(op[i]==0)
		{
			cout<<ask()<<endl;
		}
		else if(op[i]<0)
		{
			del(1,lsh[-op[i]],-op[i]);
		}
		else
		{
			add(1,lsh[op[i]],op[i]);
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
