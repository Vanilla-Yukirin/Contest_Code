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



LL a[20]={10,11,100,101,110,111,1000,1001,1010,1011,1100,1101,1110,1111,100000};//0~14
set<LL>ans;
void dfs(int depth,LL now)
{
	if(now>100000) return;
	if(depth>14) return;
	ans.insert(now);
	dfs(depth,now*a[depth]);
//	dfs(depth+1,now*a[depth]);
	dfs(depth+1,now);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cout.precision(10);
	for(int i=0;i<14;i++)
	{
		ans.insert(a[i]);
		ans.insert(a[i]+10000);
	}
	ans.insert(10000);
	ans.insert(10001);
	dfs(0,1);
	
	
	
	
	
	int t=1;
	cin>>t;
	while(t--)
	{
		LL x;cin>>x;
		if(ans.find(x)!=ans.end()&&x<=100000)
		{
			cout<<"YES"<<endl;
		}
		else
		{
			cout<<"NO"<<endl;
		}
		
		
		
	}
	return 0;
}
