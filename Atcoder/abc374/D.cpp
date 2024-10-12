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



#define N 110

LL S,T;
int n;
double A[N],B[N],C[N],D[N];

bool book[N];
double ans=1e40;


double dis(double x1,double y1,double x2,double y2)
{
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

void dfs(double sum,int cnt,double X,double Y)
{
//	cout<<"cnt="<<cnt<<endl;
	if(cnt==n)
	{
//		debug
		ans=min(ans,sum);
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(book[i]) continue;
		book[i]=1;
		
		dfs(sum+dis(X,Y,A[i],B[i])/S+dis(A[i],B[i],C[i],D[i])/T,cnt+1,C[i],D[i]);
		dfs(sum+dis(X,Y,C[i],D[i])/S+dis(C[i],D[i],A[i],B[i])/T,cnt+1,A[i],B[i]);
		
		
		book[i]=0;
	}
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
		cin>>n>>S>>T;
		for(int i=1;i<=n;i++)
		{
			cin>>A[i]>>B[i]>>C[i]>>D[i];
		}
		
		dfs(0,0,0,0);
		
		cout<<fixed<<ans<<endl;
		
	}
	return 0;
}
