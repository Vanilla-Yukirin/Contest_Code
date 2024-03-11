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

int n,k,m,d;


LL mp[110][N];
LL ans[110];
deque<int>q;
LL dp[N];
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
		cin>>n>>m>>k>>d;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				cin>>mp[i][j];
			}
		}
		
		for(int i=1;i<=n;i++)
		{
			q.clear();
			memset(dp,0,sizeof(dp));
			dp[1]=1;
			q.push_back(1);
			for(int j=2;j<=m;j++)
			{
				while(q.size()&&q.front()<j-d-1) q.pop_front();
				dp[j]=dp[q.front()]+mp[i][j]+1;
				//cout<<"dp"<<j<<"'s from "<<q.front()<<endl;
				while(q.size()&&dp[j]<=dp[q.back()]) q.pop_back();
				q.push_back(j);
				//cout<<"dp"<<i<<" "<<j<<" = "<<dp[j]<<endl;
			}
			ans[i]=dp[m];
		}
		LL minsum=100000000000000009ll;
		LL sum=0;
		for(int i=1;i<=k;i++) sum+=ans[i];
		minsum=sum;
		for(int i=k+1;i<=n;i++)
		{
			sum-=ans[i-k];
			sum+=ans[i];
			minsum=min(minsum,sum);
		}
		cout<<minsum<<endl;
		
		
	}
	return 0;
}
