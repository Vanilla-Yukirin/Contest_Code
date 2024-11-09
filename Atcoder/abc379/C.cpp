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

#define pii pair<int,int>
#define mk(a,b) make_pair(a,b)

#define N 1000010


int n,m;
pii point[N];
LL ans;
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
		cin>>n>>m;
		LL sum=0;
		for(int i=1;i<=m;i++)
		{
			cin>>point[i].first;
		}
		for(int i=1;i<=m;i++)
		{
			cin>>point[i].second;
		}
		sort(point+1,point+m+1);
		
		for(int i=1;i<=m;i++)
		{
			if(sum<point[i].first-1)
			{
				cout<<"-1";
				return 0;
			}
			sum+=point[i].second;
			if(sum<point[i].first)
			{
				cout<<"-1";
				return 0;
			}
		}
		if(sum!=n)
		{
			cout<<"-1";
			return 0;
		}
		sum=0;
		point[m+1].first=n;
		for(int i=1;i<=m;i++)
		{
			sum+=point[i].second;
			sum--;
//			DEBUG1(sum);
			LL step=point[i+1].first-point[i].first-1;
//			DEBUG2(step);
			ans+=(1+step)*step/2;
			sum-=step;
			ans+=sum*(step+1);
		}
		cout<<ans;
		
		
		
		
		
	}
	return 0;
}
