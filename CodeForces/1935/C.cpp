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



#define N 2010
const LL inf = 1000000009;
LL dp[N][N];
LL last[N][N];
int n,l;
pair<LL,LL>mess[N];

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
		memset(last,0,sizeof(last));
		for(int i=1;i<=n;i++)
		{
			cin>>mess[i].second>>mess[i].first;
		}
		sort(mess+1,mess+1+n);
		
//		for(int i=1;i<=n;i++)
//		{
//			cout<<mess[i].second<<" "<<mess[i].first<<endl;
//		}
		
		
		for(int i=1;i<=n;i++)
		{
			last[i][1]=mess[i].second;
			for(int k=2;k<=n;k++) last[i][k]=inf;
		}
		
		
		for(int len=2;len<=n;len++)
		{
			for(int i=1;i+len-1<=n;i++)
			{
				for(int k=1;k<=len;k++)
				{
					dp[i][k]=last[i][k];
					dp[i][k]=min(dp[i][k],last[i][k-1]+mess[i+len-1].second);
					dp[i][k]=min(dp[i][k],last[i+1][k]);
					dp[i][k]=min(dp[i][k],last[i+1][k-1]+mess[i].second);
//					if(dp[i][k]>l) break;
					int calc=dp[i][k]+mess[i+len-1].first-mess[i].first;
					if(calc<=l)
					{
						
						ans=max(ans,k);
					}
					
					cout<<"dp "<<i<<"-"<<i+len-1<<" k="<<k<<" == "<<dp[i][k]<<endl;
				}
			}
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++)
					last[i][j]=dp[i][j];
			
			
		}
		cout<<ans<<endl;
		
		
	}
	return 0;
}
