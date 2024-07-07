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



#define N 200010




int cnt;
struct node
{
	int l,r;
	int lson,rson;
	int sum;
#define l(x) b[x].l
#define r(x) b[x].r
#define ls(x) b[x].lson
#define rs(x) b[x].rson
#define sum(x) b[x].sum
}b[N*20];
void upd(int p)
{
	sum(p)=sum(ls(p))+sum(rs(p));
}
void add(int p,int x)
{
	if(l(p)==r(p))
	{
		sum(p)++;
		return;
	}
	int mid=l(p)+r(p)>>1;
	if(x<=mid)
	{
		if(!ls(p)) ls(p)=++cnt,l(ls(p))=l(p),r(ls(p))=mid;
		add(ls(p),x);
	}
	else
	{
		if(!rs(p)) rs(p)=++cnt,l(rs(p))=mid+1,r(rs(p))=r(p);
		add(rs(p),x);
	}
	upd(p);
}
LL ask(int p,int l,int r)
{
//	debug
	if(l<=l(p)&&r(p)<=r)
	{
		return sum(p);
	}
	LL ans=0;
	int mid=l(p)+r(p)>>1;
	if(l<=mid)
	{
		if(ls(p)) ans+=ask(ls(p),l,r);
	}
	if(r>mid)
	{
		if(rs(p)) ans+=ask(rs(p),l,r);
	}
	return ans;
}
int a[N];
set<int>s;
int n,root,mx=200000;

void clear(int p,int l,int r)
{
	
	if(l==r) return;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cout.precision(10);
	int t=1;
	cin>>t;
	while(t--)
	{
		cin>>n;
		
		s.clear();
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			s.insert(a[i]);
		}
		
		root=++cnt;
		LL p1=0;
		l(root)=1;
		r(root)=mx;
		for(int i=1;i<=n;i++)
		{		
			p1+=ask(root,a[i]+1,mx);
			add(root,a[i]);
		}
		
		
		bool flag=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			if(s.find(a[i])==s.end()) flag=1;
		}
		
		if(flag)
		{
			cout<<"NO"<<endl;
			continue;
		}
		root=++cnt;
		LL p2=0;
		l(root)=1;
		r(root)=mx;
		for(int i=1;i<=n;i++)
		{		
			p2+=ask(root,a[i]+1,mx);
			add(root,a[i]);
		}
			
//		cout<<p1<<" "<<p2<<endl;
		if((p1&1)==(p2&1)) cout<<"YES";
		else cout<<"NO";
		cout<<endl;
		
	}
	return 0;
}
