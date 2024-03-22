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


int n;
LL k;
LL a[N],sum;
LL p=1000000007;
LL pow2[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cout.precision(10);
	pow2[0]=1;
	for(int i=1;i<=200000;i++)
	{
		pow2[i]=pow2[i-1]*2%p;
	}
	
	
	int t=1;
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		sum=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			sum+=(a[i]%p+p)%p;
			sum%=p;
		}
		
		LL b=0,s=0;
		for(int i=1;i<=n;i++)
		{
			if(b>0) b+=a[i];
			else b=a[i];
			s=max(s,b);
		}
		
		if(s<=0)
		{
			cout<<(sum%p+p)%p<<endl;
		}
		else
		{
			s%=p;
			cout<<(sum%p-s+p+pow2[k]*s)%p<<endl;
			
		}
		
		
		
	}
	return 0;
}
