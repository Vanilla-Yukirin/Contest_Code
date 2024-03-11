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

int n,m,k;
int a[N],d[N],f[N];
int goal,mx;
int L,R;
int minans;
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
		cin>>n>>m>>k;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(int i=1;i<=m;i++)
		{
			cin>>d[i];
		}
		for(int i=1;i<=k;i++)
		{
			cin>>f[i];
		}
		mx=0;
		for(int i=2;i<=n;i++)
		{
			if(a[i]-a[i-1]>mx) mx=a[i]-a[i-1],goal=a[i]+a[i-1],L=i-1,R=i;
		}
		minans=mx;
		sort(f+1,f+k+1);
		for(int i=1;i<=m;i++)
		{
			int l=1,r=k,mid,ans=0;
			while(l<=r)
			{
				mid=l+r>>1;
				if((d[i]+f[mid])*2<=goal) ans=mid,l=mid+1;
				else r=mid-1;
			}
			
			minans=min(minans,max(d[i]+f[ans]-a[L],a[R]-d[i]-f[ans]));
//			minans=min(minans,);
			
			
		}
		
		cout<<minans<<endl;
		
		
	}
	return 0;
}
