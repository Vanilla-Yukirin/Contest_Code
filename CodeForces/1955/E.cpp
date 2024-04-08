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



#define N 6000


bool a[N];
int n;
 

struct Edge{
	LL l,r,sum;
	bool add;
#define l(x) tree[x].l
#define r(x) tree[x].r
#define sum(x) tree[x].sum
#define add(x) tree[x].add
}tree[N*4];
void build(LL l,LL r,LL p)
{
	l(p)=l,r(p)=r;
	if(l==r){sum(p)=a[l];return;}
	LL mid=(l+r)>>1;
	build(l,mid,p<<1);
	build(mid+1,r,p<<1|1);
	sum(p)=sum(p<<1)+sum(p<<1|1);
}
void clear(LL p)
{
	sum(p)=0;
	add(p)=0;
	if(l(p)==r(p)){sum(p)=0;return;}
	clear(p<<1);
	clear(p<<1|1);
	sum(p)=0;
}
void spread(LL p)
{
	if(add(p))
	{
		sum(p<<1)=r(p<<1)-l(p<<1)+1-sum(p<<1);
		sum(p<<1|1)=r(p<<1|1)-l(p<<1|1)+1-sum(p<<1|1);
		add(p<<1)=!add(p<<1);
		add(p<<1|1)=!add(p<<1|1);
		add(p)=0;
	}
}
void change(LL l,LL r,LL p)
{
	if(l<=l(p)&&r>=r(p)){add(p)=!add(p);sum(p)=r(p)-l(p)+1-sum(p);return;}
	LL mid=l(p)+r(p)>>1;
	spread(p);
	if(l<=mid) change(l,r,p<<1);
	if(r>mid) change(l,r,p<<1|1);
	sum(p)=sum(p<<1)+sum(p<<1|1);
}
LL ask(LL l,LL r,LL p)
{
	if(l<=l(p)&&r>=r(p)) return sum(p);
	spread(p);
	LL mid=l(p)+r(p)>>1,val=0;
	if(l<=mid) val+=ask(l,r,p<<1);
	if(r>mid) val+=ask(l,r,p<<1|1);
	return val;
}
LL ask(int x,int p)
{
	if(l(p)==r(p))
	{
		return sum(p);
	}
	spread(p);
	LL mid=l(p)+r(p)>>1;
	if(x<=mid) return ask(x,p<<1);
	return ask(x,p<<1|1);
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
		string str;cin>>str;
		for(int i=1;i<=n;i++) a[i]=str[i-1]-'0';
		for(int k=n;k>=1;k--)
		{
			clear(1);
			build(1,n,1);
//			cout<<"try k="<<k<<endl;
			for(int i=1;i+k-1<=n;i++)
			{
//				cout<<"try ask "<<i<<" "<<i+k-1<<endl;
//				cout<<"ask i="<<i<<" = "<<ask(i,1)<<endl;
				if(ask(i,1)==0)
				{
					change(i,i+k-1,1);
//					cout<<"flip "<<i<<" "<<i+k-1<<endl;
				}
				if(ask(1,n,1)==n)
				{
//				cout<<"max_k = ";
					break;
				}
				/*
				int j=n-i+1;
				cout<<"ask "<<j<<endl;
				if(ask(j,j,1)==0)
				{
					change(j-k+1,j,1);
					cout<<"flip "<<j<<" "<<j-k+1<<endl;
				}
				*/
//				cout<<"and now 1-n = "<<ask(1,n,1)<<endl;
//				if(ask(1,n,1)==n)
//				{
//					win=1;
//					cout<<"max_k = ";
//					cout<<k<<endl;
//					break;
//				}
			}
			if(ask(1,n,1)==n)
			{
//				cout<<"max_k = ";
				cout<<k<<endl;
				break;
			}
			
//			clear(1);
		}
		
	}
	return 0;
}
