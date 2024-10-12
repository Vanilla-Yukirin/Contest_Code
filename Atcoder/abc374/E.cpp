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



#define N 1010
#define M 10000010

int n;
int A[N],B[N];

namespace bag{
	/*
	解决一个背包问题。如果有两台机器，日生产价值A/B，花费P/Q
	设dp[i]表示日生产价值为i时，最小的花费是多少
	dp[i]=min(dp[i-A/B]+P/Q)
	dp[i+A]=min(dp[i]+P)
	
	对于询问，我们需要处理：要实现生产能力W_mid的最小花费
	即min(dp[W_mid++])
	*/
	
	
	
};



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
		
		
		
		
	}
	return 0;
}
