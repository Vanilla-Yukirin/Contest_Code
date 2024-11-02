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

int n,k;



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
		cin>>n>>k;
		
		if(n==1)
		{
			cout<<1<<endl<<1<<endl;
			continue;
		}
		
		if(k==1||k==n)
		{
			cout<<-1<<endl;
		}
		else
		{
			if(k%2==0)
			{
				cout<<3<<endl;
				cout<<1<<" "<<k<<" "<<k+1<<endl;
			}
			else
			{
				cout<<3<<endl;
				cout<<1<<" "<<k-1<<" "<<k+2<<endl;
			}
		}
		
		
	}
	return 0;
}



/*

m个区间，那么答案肯定在中间那个去年里面。
偏的话，前面的数，k这个数，后面的数

但是必须保证，k是偶数。
那么k是奇数呢？
1 2 3 4 5，k=3,
1 234 5



*/
