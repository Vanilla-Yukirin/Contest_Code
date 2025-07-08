/**************************************************************
 * Problem: 3384 -> CF587C
 * Author: Vanilla_chan
 * Date: 20210306
 **************************************************************/
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<vector>
#include<limits.h>
#define IL inline
#define re register
#define LL long long
#define ULL unsigned long long
#ifdef TH
#define debug printf("Now is %d\n",__LINE__);
#else
#define debug 
#endif
#ifdef ONLINE_JUDGE
char buf[1<<23],* p1=buf,* p2=buf,obuf[1<<23],* O=obuf;
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
#endif
using namespace std;
#define endl '\n'
#define N 200010
int n,m,r;
vector<int>a[N];
int head[N],ver[N<<1],nxt[N<<1],cnt;
void insert(int x,int y)
{
	nxt[++cnt]=head[x];
	head[x]=cnt;
	ver[cnt]=y;
	
	nxt[++cnt]=head[y];
	head[y]=cnt;
	ver[cnt]=x;
}
int f[N],sze[N],son[N],dep[N];
void dfs1(int x)
{
//	debug cout<<"x="<<x<<endl;
	sze[x]=1;
	dep[x]=dep[f[x]]+1;
	for(int i=head[x];i;i=nxt[i])
	{
		if(ver[i]==f[x]) continue;
		f[ver[i]]=x;
		dfs1(ver[i]);
		sze[x]+=sze[ver[i]];
		if(sze[son[x]]<sze[ver[i]]) son[x]=ver[i];
	}
}
int top[N];
int dfn[N],dfncnt,id[N];
void dfs2(int x,int tt)
{
//	debug cout<<"x="<<x<<endl;
	dfn[++dfncnt]=x;
	id[x]=dfncnt;
	top[x]=tt;
	if(!son[x]) return;
	dfs2(son[x],tt);
	for(int i=head[x];i;i=nxt[i])
	{
		if(ver[i]==f[x]||ver[i]==son[x]) continue;
		dfs2(ver[i],ver[i]);
	}
}
struct arr
{
	int a[30];
	int len;
	arr()
	{
		len=0;
		memset(a,0,sizeof(a));
	}
	int size()const
	{
		return len;
	}
	void pb(const int &x)
	{
		a[len]=x;
		len++;
		if(len>10) len=10;
	}
	void clear()
	{
		len=0;
	}
};

arr merge(const arr &a,const arr &b)
{
	arr res;
	int i=0,j=0;
	while(i<a.size()&&j<b.size())
	{
		if(a.a[i]<b.a[j])
		{
			res.pb(a.a[i]);
			i++;
		}
		else
		{
			res.pb(b.a[j]);
			j++;
		}
	}
	while(i<a.size())
	{
		res.pb(a.a[i]);
		i++;
	}
	while(j<b.size())
	{
		res.pb(b.a[j]);
		j++;
	}
	return res;
}

struct node
{
	int l,r;
	arr top;
#define l(x) b[x].l
#define r(x) b[x].r
#define top(x) b[x].top
}b[N<<2];

IL void upd(int p)
{
	top(p).clear();
	top(p)=merge(top(p<<1),top(p<<1|1));
}
void build(int p,int l,int r)
{
	l(p)=l;
	r(p)=r;
	if(l==r)
	{
		sort(a[dfn[l]].begin(),a[dfn[l]].end());
		for(int i=0;i<10&&i<a[dfn[l]].size();i++)
		{
			top(p).pb(a[dfn[l]][i]);
		}
		return;
	}
	int mid=l+r>>1;
	build(p<<1,l,mid);
	build(p<<1|1,mid+1,r);
	upd(p);
}

arr ask(int p,int l,int r)
{
	if(l<=l(p)&&r(p)<=r)
	{
		return top(p);
	}
	int mid=l(p)+r(p)>>1;
	arr res;
	if(l<=mid) res=merge(res,ask(p<<1,l,r));
	if(r>mid) res=merge(res,ask(p<<1|1,l,r));
	return res;
}
LL ans;
int q;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	r=1;
	cin>>n>>m>>q;
	for(int i=1,a,b;i<n;i++)
	{
		cin>>a>>b;
		insert(a,b);
	}
	for(int i=1;i<=m;i++)
	{
		int y;
		cin>>y;
		a[y].push_back(i);
	}
	dep[r]=1;
	dfs1(r);
	dfs2(r,r);
	
	build(1,1,n);
	int u,v,aa;
	while(q--)
	{
		cin>>u>>v>>aa;

		arr ans;
		while(top[u]!=top[v])
		{
			if(dep[top[u]]<dep[top[v]]) swap(u,v);
			ans=merge(ans,ask(1,id[top[u]],id[u]));
			u=f[top[u]];
		}
		if(dep[u]>dep[v]) swap(u,v);
		ans=merge(ans,ask(1,id[u],id[v]));
		cout<<min((int)ans.size(),aa)<<" ";
		for(int i=0;i<min((int)ans.size(),aa);i++)
		{
			cout<<ans.a[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}

