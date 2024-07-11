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



#define N 1000010
#define p 1000000007ll

LL n,k;
LL a[N];

LL qpow(LL a,LL b)
{
	LL ans=1;
	while(b)
	{
		if(b&1) ans=ans*a%p;
		a=a*a%p;
		b>>=1;
	}
	return ans%p;
}

LL inv(LL x)
{
	return qpow(x,p-2);
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
		cin>>n>>k;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		LL ans1=0,ans2=0,inv1=inv(n-k),inv2=inv(n-k+1);
		for(int i=k+1;i<=n;i++)
		{
			ans1=(ans1+(n-k+1)/2*a[i]%p*inv1)%p;
			ans2=(ans2+(n-k)/2*a[i]%p*inv1)%p;
		}
		for(int i=1;i<=k;i++)
		{
			ans1=(ans1+(n-k+2)/2*a[i]%p*inv2)%p;
			ans2=(ans2+(n-k+1)/2*a[i]%p*inv2)%p;
		}
		
		cout<<ans1<<" "<<ans2<<endl;
		
	}
	return 0;
}
