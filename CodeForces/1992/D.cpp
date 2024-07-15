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



#define N 2000020

int dp[N];
int n,m,k;
#define inf 1000000007

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
		string str;cin>>str;
		str="L"+str;
		for(int i=1;i<=n+1;i++) dp[i]=inf;
		for(int i=0;i<=n;i++)
		{
			if(str[i]=='L') for(int j=1;j<=m;j++) dp[i+j]=min(dp[i+j],dp[i]);
			if(str[i]=='W') dp[i+1]=min(dp[i]+1,dp[i+1]);
		}
		
		if(dp[n+1]<=k) cout<<"yes"<<endl;
		else cout<<"no"<<endl;
		
		
	}
	return 0;
}
