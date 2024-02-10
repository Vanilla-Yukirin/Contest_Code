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

#define N 1000010

struct Edge{
	int l,r;
	pair<int,int>mx,mn;
#define l(x) tree[x].l
#define r(x) tree[x].r
#define mx(x) tree[x].mx
#define mn(x) tree[x].mn
}tree[1600010];
int n,m; 
int ans[200010];
void build(LL l,LL r,LL p)
{
	l(p)=l,r(p)=r;
	if(l==r){mx(p)=mn(p)=make_pair(ans[l],l);return;}
	LL mid=(l+r)>>1;
	build(l,mid,p<<1);
	build(mid+1,r,p<<1|1);
	mx(p)=max(mx(p<<1),mx(p<<1|1));
	
	mn(p)=min(mn(p<<1),mn(p<<1|1));
	
	
	
}

pair<int,int> ask_mx(LL l,LL r,LL p)
{
	if(l<=l(p)&&r>=r(p)) return mx(p);
	LL mid=(l(p)+r(p))>>1;
	if(l<=mid&&r>mid)
	{
		pair<int,int>ll=ask_mx(l,r,p<<1),rr=ask_mx(l,r,p<<1|1);
		return max(ll,rr);
	}
	else{
		if(l<=mid) return ask_mx(l,r,p<<1);
		if(r>mid) return ask_mx(l,r,p<<1|1);
	}
	return ask_mx(l,r,p<<1|1);
}


pair<int,int> ask_mn(LL l,LL r,LL p)
{
	if(l<=l(p)&&r>=r(p)) return mn(p);
	LL mid=(l(p)+r(p))>>1;
	if(l<=mid&&r>mid)
	{
		pair<int,int>ll=ask_mn(l,r,p<<1),rr=ask_mn(l,r,p<<1|1);
		return min(ll,rr);
	}
	else{
		if(l<=mid) return ask_mn(l,r,p<<1);
		if(r>mid) return ask_mn(l,r,p<<1|1);
	}
	return ask_mn(l,r,p<<1|1);
}
int t;

int main()
{
	cin>>t;
	while(t--)
	
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>ans[i];
		}
		build(1,n,1);
		cin>>m;
		while(m--)
		{
			int l,r;
			cin>>l>>r;
			pair<int,int>maxmax=ask_mx(l,r,1),minmin=ask_mn(l,r,1);
			if(maxmax.first==minmin.first)
			{
				cout<<"-1 -1"<<endl;
			}
			else{
				cout<<minmin.second<<" "<<maxmax.second<<endl;
			}
		}
		cout<<endl;
		
		
		for(int i=1;i<=n*4;i++)
		{
			l(i)=r(i)=0;
			mx(i)=mn(i)=make_pair(0,0);
		}
	}
	
	
	
	
	
	return 0;
}
