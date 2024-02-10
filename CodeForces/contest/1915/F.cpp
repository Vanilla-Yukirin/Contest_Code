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


namespace BST
{
	const int N = 400010;
	int f[N],ls[N],rs[N],val[N],cnt[N],sze[N];
	int root,tot;
	IL void init()
	{
		
		root=0;
		for(int i=0;i<tot+10;i++)
		{
			f[i]=ls[i]=rs[i]=val[i]=cnt[i]=sze[i]=0;
		}
		tot=0;
	}
	IL void upd(int x)
	{
		sze[x]=sze[ls[x]]+sze[rs[x]]+cnt[x];
	}
	IL int node(int v)
	{
		tot++;
		sze[tot]=1;
		cnt[tot]=1;
		val[tot]=v;
		return tot;
	}
#define check(x) (rs[f[(x)]]==(x))
	void rotate(int x)
	{
		int y=f[x],z=f[y],b=ls[y]==x?rs[x]:ls[x];
		f[x]=z,f[y]=x,f[b]=y;
		if(z)
		{
			if(y==ls[z]) ls[z]=x;
			else rs[z]=x;
		}
		if(ls[y]==x) ls[y]=b,rs[x]=y;
		else rs[y]=b,ls[x]=y;
		upd(y),upd(x);
	}
	void splay(int x,int tar=0)
	{
		while(f[x]!=tar)
		{
			if(f[f[x]]!=tar)
			{
				if(check(x)==check(f[x])) rotate(f[x]);
				else rotate(x);
			}
			rotate(x);
		}
		if(tar==0) root=x;
	}
	int find(int v)
	{
		int p=root;
		while(1)
		{
			if(val[p]==v) return p;
			if(val[p]<v)
			{
				if(rs[p]) p=rs[p];
				else break;
			}
			else if(ls[p]) p=ls[p];
			else break;
		}
		splay(p);
		return p;
	}
	void insert(int v)
	{
		if(!root)
		{
			root=node(v);
			return;
		}
		int p=root,fa=0;
		while(p&&val[p]!=v)
		{
			fa=p;
			if(val[p]>v) p=ls[p];
			else p=rs[p];
		}
		if(p)
		{
			cnt[p]++;
			upd(p);
		}
		else
		{
			p=node(v);
			f[p]=fa;
			if(v<val[fa]) ls[fa]=p;
			else rs[fa]=p;
		}
		splay(p);
	}
	void del(int v)
	{
		int p=find(v);
		if(val[p]!=v) return;
		if(cnt[p]>=2)
		{
			cnt[p]--;
			upd(p);
			return;
		}
		if(!ls[p]&&!rs[p])
		{
			root=0;
			cnt[p]=sze[p]=0;
			return;
		}
		if(!ls[p])
		{
			root=rs[p];
			return;
		}
		if(!rs[p])
		{
			root=ls[p];
			return;
		}
		int a=ls[p],b=rs[p];
		while(rs[a]) a=rs[a];
		while(ls[b]) b=ls[b];
		splay(a);
		splay(b,a);
		ls[b]=0;
		upd(b);
		upd(a);
	}
	int rnk(int v)
	{
		return sze[ls[find(v)]]+1;
	}
	int kth(int k)
	{
		int p=root;
		while(1)
		{
			if(sze[ls[p]]>=k) p=ls[p];
			else if(sze[ls[p]]+cnt[p]<=k) break;
			else k-=sze[ls[p]]+cnt[p],p=rs[p];
		}
		splay(p);
		return p;
	}
	int pre(int v)
	{
		int p=find(v);
		p=ls[p];
		while(rs[p]) p=rs[p];
		return p;
	}
	int nxt(int v)
	{
		int p=find(v);
		p=rs[p];
		while(ls[p]) p=ls[p];
		return p;
	}
	
	
};




#define N 400010


int t,n;
int T[N];
struct Person
{
	int a,b;
	bool operator<(Person x)
	{
		return a<x.a;
	}
}person[N];
vector<int>m;
int ans;









int main()
{
	cin>>t;
	while(t--)
	{
		cin>>n;
		ans=0;
		m.clear();
		BST::init();
		for(int i=0;i<n;i++)
		{
			cin>>person[i].a>>person[i].b;
			T[i]=person[i].b;
		}
		sort(person,person+n);
		for(int i=n-1;i>=0;i--)
		{
			BST::insert(person[i].b);
			ans+=BST::rnk(person[i].b)-1;
		}
		
		cout<<ans<<endl;
	}
	
	
	
	
	
	
	return 0;
}
