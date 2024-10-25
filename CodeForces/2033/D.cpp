/**************************************************************
 * Problem: 
 * Author: Allinaw
 * Date: 
 * E-Mail: Allinaw@outlook.com
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



/*
2 1 -3 2 1
2 3 0 2 3
2 4
1 3
3 5



*/
int n;

int a[N];
map<int,int>pre;//pre[i]=值为i的前缀的最后的位置
map<int,int>close;
int dp[N];
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
		pre.clear();
		close.clear();
		cin>>n;LL sum=0;
		pre[sum]=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];sum+=a[i];
			if(pre.find(sum)!=pre.end())
			{
				close[i]=pre[sum]+1;
//				cout<<pre[sum]+1<<" "<<i<<endl;
			}
			pre[sum]=i;
		}
		//前i个，最多可以选择多少个？
		for(int i=1;i<=n;i++)
		{
			dp[i]=dp[i-1];
			if(close.find(i)!=close.end())
			{
				dp[i]=max(dp[i-1],dp[close[i]-1]+1);
			}
		}
//		cout<<"ans=";
		cout<<dp[n]<<endl;
		for(int i=1;i<=n;i++) dp[i]=0;
	}
	return 0;
}
