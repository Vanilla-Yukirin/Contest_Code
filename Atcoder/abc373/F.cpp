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



#define N 4000

int n,W;
LL w[N],v[N];

LL dp[N][N];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cout.precision(10);
	int t=1;
//	cin>>t;
	while(t--)
	{
		cin>>n>>W;
		for(int i=1;i<=n;i++)
		{
			cin>>w[i]>>v[i];
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=W;j++)
			{
				for(int k=0;k<=v[i];k++)
				{
					if(j-k*w[i]>=0)
						dp[i][j]=max(dp[i][j],dp[i-1][j-k*w[i]]+k*v[i]-k*k);
					else break;
				}
			}
		}
		LL ans=0;
		for(int i=1;i<=W;i++)
		{
			ans=max(ans,dp[n][i]);
		}
		
		cout<<ans;
		
	}
	return 0;
}
