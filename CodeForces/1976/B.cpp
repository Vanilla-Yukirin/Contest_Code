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



#define N 2000010


int n;
LL a[N],b[N];

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
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n+1;i++) cin>>b[i];
		LL ans=0;
		for(int i=1;i<=n;i++) ans+=abs(a[i]-b[i]);
		LL ew=10000000000000007ll;
		for(int i=1;i<=n;i++)
		{
			if(a[i]<=b[n+1]&&b[n+1]<=b[i]) ew=0;
			if(a[i]>=b[n+1]&&b[n+1]>=b[i]) ew=0;
			ew=min(ew,abs(a[i]-b[n+1]));
			ew=min(ew,abs(b[i]-b[n+1]));
		}
		cout<<ans+ew+1<<endl;
		
		
	}
	return 0;
}
