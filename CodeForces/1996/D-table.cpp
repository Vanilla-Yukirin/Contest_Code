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
		for(int n=1;n<=20;n++)
		{
			for(int x=1;x<=20;x++)
			{
				int ans=0;
				for(int a=1;a<=x;a++)
				{
					for(int b=1;b<=x-a-1;b++)
					{
						for(int c=1;a+b+c<=x;c++)
						{
							if(a*b+b*c+a*c<=n) ans++;
						}
					}
				}
				cout<<ans<<"  ";
			}
			cout<<endl;
		}
		
		
		
	}
	return 0;
}
