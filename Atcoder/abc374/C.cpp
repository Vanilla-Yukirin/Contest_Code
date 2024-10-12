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

LL min_ans=100000000ll*1000;
LL k[100],sum;
int n;
void dfs(int x,LL now)
{
	LL now_b=sum-now;
	if(max(now,now_b)<min_ans)
	{
		min_ans=max(now,now_b);
	}
	if(now>min_ans)
	{
		return;
	}
	if(x==n+1) return;
	dfs(x+1,now);
	dfs(x+1,now+k[x]);
}

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
		cin>>n;
		for(int i=1;i<=n;i++) cin>>k[i],sum+=k[i];
		
		dfs(1,0);
		cout<<min_ans<<endl;
		
		
	}
	return 0;
}
