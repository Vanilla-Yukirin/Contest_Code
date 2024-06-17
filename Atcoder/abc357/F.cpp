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


#define P 998244353ll

#define N 800010


struct Edge{
	LL l,r,sumA,sumB,sum,addA,addB;
#define l(x) tree[x].l
#define r(x) tree[x].r
#define sumA(x) tree[x].sumA
#define sumB(x) tree[x].sumB
#define sum(x) tree[x].sum
#define addA(x) tree[x].addA
#define addB(x) tree[x].addB
}tree[N];
LL n,m; 
LL A[N],B[N];
void build(LL l,LL r,LL p)
{
	l(p)=l,r(p)=r;
	if(l==r){sumA(p)=A[l]%P;sumB(p)=B[l]%P;sum(p)=sumA(p)*sumB(p)%P;return;}
	LL mid=(l+r)>>1;
	build(l,mid,p<<1);
	build(mid+1,r,p<<1|1);
	sum(p)=sum(p<<1)+sum(p<<1|1);
	sumA(p)=sumA(p<<1)+sumA(p<<1|1);
	sumB(p)=sumB(p<<1)+sumB(p<<1|1);
	sum(p)%=P;
	sumA(p)%=P;
	sumB(p)%=P;
}
void spread(LL p)
{
	if(addA(p)||addB(p))
	{
		addA(p<<1)+=addA(p);
		addA(p<<1|1)+=addA(p);
		addB(p<<1)+=addB(p);
		addB(p<<1|1)+=addB(p);
		
		sum(p<<1)+=addA(p)*sumB(p<<1)+addB(p)*sumA(p<<1)+addA(p)*addB(p)%P*(r(p<<1)-l(p<<1)+1);
		sum(p<<1|1)+=addA(p)*sumB(p<<1|1)+addB(p)*sumA(p<<1|1)+addA(p)*addB(p)%P*(r(p<<1|1)-l(p<<1|1)+1);
		
		sumA(p<<1)+=addA(p)*(r(p<<1)-l(p<<1)+1);
		sumB(p<<1)+=addB(p)*(r(p<<1)-l(p<<1)+1);
		sumA(p<<1|1)+=addA(p)*(r(p<<1|1)-l(p<<1|1)+1);
		sumB(p<<1|1)+=addB(p)*(r(p<<1|1)-l(p<<1|1)+1);
		
		addA(p)=addB(p)=0;
		
		sum(p<<1)%=P;
		sum(p<<1|1)%=P;
		sumA(p<<1)%=P;
		sumA(p<<1|1)%=P;
		sumB(p<<1)%=P;
		sumB(p<<1|1)%=P;
		
		addA(p<<1)%=P;
		addB(p<<1)%=P;
		addA(p<<1|1)%=P;
		addB(p<<1|1)%=P;
	}
}
void change(LL l,LL r,LL p,LL k,bool isA)
{
	if(l<=l(p)&&r>=r(p)){
		if(isA) addA(p)+=k,sum(p)+=k*sumB(p),sumA(p)+=k*(r(p)-l(p)+1);
		else addB(p)+=k,sum(p)+=k*sumA(p),sumB(p)+=k*(r(p)-l(p)+1);
		sumA(p)%=P;sumB(p)%=P;sum(p)%=P;
		addA(p)%=P;addB(p)%=P;
		return;
	}
	LL mid=l(p)+r(p)>>1;
	spread(p);
	if(l<=mid) change(l,r,p<<1,k,isA);
	if(r>mid) change(l,r,p<<1|1,k,isA);
	sum(p)=sum(p<<1)+sum(p<<1|1);
	sumA(p)=sumA(p<<1)+sumA(p<<1|1);
	sumB(p)=sumB(p<<1)+sumB(p<<1|1);
	sum(p)%=P;
	sumA(p)%=P;
	sumB(p)%=P;
}

LL ask(LL l,LL r,LL p)
{
	if(l<=l(p)&&r>=r(p)) return sum(p);
	spread(p);
	LL mid=l(p)+r(p)>>1,val=0;
	if(l<=mid) val+=ask(l,r,p<<1);
	val%=P;
	if(r>mid) val+=ask(l,r,p<<1|1);
	val%=P;
	return val;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cout.precision(10);
	int q;
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>A[i];
	for(int i=1;i<=n;i++) cin>>B[i];
	build(1,n,1);
	while(q--)
	{
		int op,l,r,x;
		cin>>op>>l>>r;
		if(op!=3) cin>>x,change(l,r,1,x,(op==1));
		else cout<<ask(l,r,1)<<endl;
	}
	return 0;
}
