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
#define int long long
#define N 300010
/*

1. sum a = sum b

2. a_i != b_i

3. 





*/

int t;
int n;
int q;
struct Edge{
	LL l,r,sum,cnt1;
	
#define l(x) tree[x].l
#define r(x) tree[x].r
#define sum(x) tree[x].sum
#define cnt1(x) tree[x].cnt1
}tree[1200010];
int ans[300010];
void build(LL l,LL r,LL p)
{
	l(p)=l,r(p)=r;
	sum(p)=0;
	cnt1(p)=0;
	if(l==r){if(ans[l]==1) cnt1(p)=1;sum(p)=ans[l];return;}
	LL mid=(l+r)>>1;
	build(l,mid,p<<1);
	build(mid+1,r,p<<1|1);
	sum(p)=sum(p<<1)+sum(p<<1|1);
	cnt1(p)=cnt1(p<<1)+cnt1(p<<1|1);
	
}
pair<int,int> pplus(pair<int,int> a,pair<int,int> b)
{
	return make_pair(a.first+b.first,a.second+b.second);
}


pair<int,int> ask(LL l,LL r,LL p)
{
	if(l<=l(p)&&r>=r(p)) return make_pair(sum(p),cnt1(p));
	LL mid=l(p)+r(p)>>1;
	pair<int,int>val={0,0};
	if(l<=mid) val=pplus(val,ask(l,r,p<<1));
	if(r>mid) val=pplus(val,ask(l,r,p<<1|1));
	return val;
}
signed main()
{
	cin>>t;
	while(t--)
	{
		cin>>n>>q;
		for(int i=1;i<=n;i++)
		{
			cin>>ans[i];
		}
		build(1,n,1);
		while(q--)
		{
			int l,r;
			cin>>l>>r;
			
			pair<int,int> temp=ask(l,r,1);
			int sum=temp.first;
			int cnt1=temp.second;
			int down=sum-(r-l+1);
			//cout<<"cnt1="<<cnt1<<" sum="<<sum<<" down="<<down<<endl;
			if(down>=cnt1&&l!=r) cout<<"Yes"<<endl;
			else cout<<"No"<<endl;
			
		}
		
	}
	
	
	
	
	
	
	return 0;
}
