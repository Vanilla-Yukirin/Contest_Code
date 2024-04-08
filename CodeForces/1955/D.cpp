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

int n,m,k;
int a[N],b[N];
int A[N],B[N];

int ans;
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
		ans=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(int i=1;i<=m;i++)
		{
			cin>>b[i];
		}
		for(int i=1;i<=m;i++)
		{
			B[b[i]]++;
		}
		int l=1;
		int now=0;
		for(l=1;l<=m;l++)
		{
			A[a[l]]++;
//			debug cout<<"add "<<a[l]<<endl;
			if(B[a[l]]>=A[a[l]]) now++;
		}
		if(now>=k) ans++;
		for(l=m+1;l<=n;l++)
		{
			//-(l-m)
			if(B[a[l-m]]>=A[a[l-m]]) now--;
			A[a[l-m]]--;
//			debug cout<<"remove "<<a[l-m]<<endl;
			
			//+(l)
			A[a[l]]++;
			if(B[a[l]]>=A[a[l]]) now++;
//			debug cout<<"add "<<a[l]<<endl;
			
//			cout<<"now="<<now<<endl;
			if(now>=k)
			{
//				cout<<"good at "<<l-m+1<<"--"<<l<<endl;
				ans++;
			}
		}
		
		
		cout<<ans<<endl;
		for(int i=1;i<=n;i++) A[a[i]]=B[a[i]]=0;
		for(int i=1;i<=m;i++) A[b[i]]=B[b[i]]=0;
		
	}
	return 0;
}
