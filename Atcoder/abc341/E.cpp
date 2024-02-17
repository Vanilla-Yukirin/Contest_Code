/**************************************************************
 * Problem: 
 * Author: Vanilla_chan
 * Date: 
 * E-Mail: heshaohong2015@outlook.com
 **************************************************************/
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
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

namespace oi
{
	inline bool isdigit(const char& ch)
	{
		return ch<='9'&&ch>='0';
	}
	inline bool isalnum(const char& ch)
	{
		return (ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z')||(ch>='0'&&ch<='9');
	}
	struct istream
	{
		char ch;
		bool fu;
		template<class T>inline istream& operator>>(T& d)
		{
			fu=d=0;
			while(!isdigit(ch)&&ch!='-') ch=getchar();
			if(ch=='-') fu=1,ch=getchar();
			d=ch-'0';ch=getchar();
			while(isdigit(ch))
				d=(d<<3)+(d<<1)+(ch^'0'),ch=getchar();
			if(fu) d=-d;
			return *this;
		}
		inline istream& operator>>(char& ch)
		{
			ch=getchar();
			for(;!isalnum(ch);ch=getchar());
			return *this;
		}
		inline istream& operator>>(string& str)
		{
			str.clear();
			for(;!isalnum(ch);ch=getchar());
			while(isalnum(ch))
				str+=ch,ch=getchar();
			return *this;
		}
	}cin;
	inline int read()
	{
		int x=0,fu=0;char ch=getchar();
		while(!isdigit(ch)&&ch!='-') ch=getchar();
		if(ch=='-') fu=1,ch=getchar();
		while(isdigit(ch)) { x=x*10+ch-'0';ch=getchar(); }
		if(fu) x=-x;
		return x;
	}
	int G[55];
	template<class T>inline void write(T x)
	{
		int g=0;
		if(x<0) x=-x,putchar('-');
		do { G[++g]=x%10;x/=10; } while(x);
		for(int i=g;i>=1;--i) putchar('0'+G[i]);
		putchar('\n');
	}
};
using oi::read;

#define N 500010
int n,q;
string str;
struct node{
	int l,r;
	bool lb,rb;
	bool lazy;
	bool great;
#define l(x) tree[x].l
#define r(x) tree[x].r
#define lb(x) tree[x].lb
#define rb(x) tree[x].rb
#define lazy(x) tree[x].lazy
#define great(x) tree[x].great
}tree[N*4];
void spread(int p)
{
	if(lazy(p))
	{
		lazy(p<<1)^=1;
		lazy(p<<1|1)^=1;
		lb(p<<1)^=1;
		lb(p<<1|1)^=1;
		rb(p<<1)^=1;
		rb(p<<1|1)^=1;
		
		
		lazy(p)=0;
	}
}

void update(int p)
{
	if(l(p)==r(p))
	{
		return;
	}
	lb(p)=lb(p<<1);
	rb(p)=rb(p<<1|1);
	if(great(p<<1)&&great(p<<1|1)&&rb(p<<1)!=lb(p<<1|1)) great(p)=1;
	else great(p)=0;
}

void build(int p,int l,int r)
{
	l(p)=l;
	r(p)=r;
	if(l==r)
	{
		lb(p)=rb(p)=str[l-1]-'0';
		great(p)=1;
		return;
	}
	int mid=l+r>>1;
	build(p<<1,l,mid);
	build(p<<1|1,mid+1,r);
	update(p);
}
void change(int l,int r,int p)
{
	if(l<=l(p)&&r>=r(p))
	{
		lazy(p)^=1;
		lb(p)^=1;
		rb(p)^=1;
		return;
	}
	spread(p);
	int mid=(l(p)+r(p))/2;
	if(l<=mid) change(l,r,p<<1);
	if(r>mid) change(l,r,p<<1|1);
	update(p);
}

node ask(int l,int r,int p)
{
	if(l<=l(p)&&r>=r(p))
	{
		return tree[p];
	}
	spread(p);
	int mid=(l(p)+r(p))/2;
	if(r<=mid) return ask(l,r,p<<1);
	if(l>mid) return ask(l,r,p<<1|1);
	node lnode=ask(l,r,p<<1),rnode=ask(l,r,p<<1|1);
	node fail;fail.great=0;
	if(lnode.great==0||rnode.great==0)
	{
		return fail;
	}
	if(lnode.rb!=rnode.lb)
	{
		fail.lb=lnode.lb;
		fail.rb=rnode.rb;
		fail.great=1;
		return fail;
	}
	return fail;
}
int main()
{
	
	cin>>n>>q;
	cin>>str;
	build(1,1,n);
	while(q--)
	{
		int t,a,b;
		cin>>t>>a>>b;
		if(t==1)
		{
			change(a,b,1);
		}
		else
		{
			node ret=ask(a,b,1);
			if(ret.great) cout<<"Yes"<<endl;
			else cout<<"No"<<endl;
		}
	}
	
	
	
	
	
	return 0;
}
