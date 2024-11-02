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

#define RED cout << "\033[91m"
#define GREEN cout << "\033[92m"
#define YELLOW cout << "\033[93m"
#define BLUE cout << "\033[94m"
#define MAGENTA cout << "\033[95m"
#define CYAN cout << "\033[96m"
#define RESET cout << "\033[0m"

// 红色
#define DEBUG1(x)                     \
RED;                              \
cout << #x << " : " << x << endl; \
RESET;

// 绿色
#define DEBUG2(x)                     \
GREEN;                            \
cout << #x << " : " << x << endl; \
RESET;

// 蓝色
#define DEBUG3(x)                     \
BLUE;                             \
cout << #x << " : " << x << endl; \
RESET;

// 品红
#define DEBUG4(x)                     \
MAGENTA;                          \
cout << #x << " : " << x << endl; \
RESET;

// 青色
#define DEBUG5(x)                     \
CYAN;                             \
cout << #x << " : " << x << endl; \
RESET;

// 黄色
#define DEBUG6(x)                     \
YELLOW;                           \
cout << #x << " : " << x << endl; \
RESET;

#ifdef ONLINE_JUDGE
char buf[1<<23],* p1=buf,* p2=buf,obuf[1<<23],* O=obuf;
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
#endif
using namespace std;



#define N 1000010
//#define int LL
int n;
int a[N];


signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cout.precision(10);
	int t=1;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i];
		sort(a+1,a+n+1);
		int ans=0;
		for(int l=1;l<=n;l++)
		{
			int min1=a[l],min2=a[l+1];
			int r=l;
			for(int k=24;k>=0;k--)
			{
				if(r+(1<<k)>n) continue;
				int mx=a[r+(1<<k)];
				if(min1+min2>mx&&mx-min1<min2) r+=(1<<k);
			}
//			cout<<"now l="<<l<<" r="<<r<<endl;
			ans=max(ans,r-l+1);
		}
		cout<<n-ans<<endl;
	}
	return 0;
}





/*

a b c

|a-b|<c<a+b

find min(a+b)=min1+min2
find max(a-b)=max-min

1 2 3 4 5 6 7
7-1=6~1+2=3

1 2 3 4 5 6 7







*/
