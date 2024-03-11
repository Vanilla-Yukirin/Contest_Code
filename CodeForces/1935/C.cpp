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



#define N 20010

int n,l;
pair<LL,LL>mess[N];
const int inf = 1000000009;
LL dp[N];
int ans;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cout.precision(10);
	int t;cin>>t;
	while(t--)
	{
		cin>>n>>l;
		ans=0;
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++)
		{
			cin>>mess[i].second>>mess[i].first;
		}
		sort(mess+1,mess+1+n);
		LL a,b;
		for(int i=1;i<=n;i++) if(mess[i].second<=l) ans=1;
		
		for(int i=1;i<=n;i++) dp[i]=inf;
		for(int i=1;i<=n;i++)
		{
			a=mess[i].second;
			b=mess[i].first;
			
			for(int j=0;j<=n;j++)
			{
				if(a+b+dp[j]<=l) ans=max(ans,j+1);
			}
			
			for(int j=n;j>=1;j--)
			{
				dp[j]=min(dp[j],dp[j-1]+a);
			}
			dp[1]=min(dp[1],a-b);
			
			//for(int j=1;j<=n;j++) cout<<dp[j]<<" ";
			//cout<<endl;
			
		}
		cout<<ans<<endl;
		
	}
	return 0;
}
