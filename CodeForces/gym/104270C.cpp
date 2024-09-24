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

LL n,sum;
int a[N];
string str;

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
		cin>>n;
		sum=0;
		cin>>str;
		str=" "+str;
		for(int i=1;i<=n;i++)
		{
			a[i]=0;
			a[i]^=(str[i]=='1');
		}
		
		cin>>str;
		str=" "+str;
		for(int i=1;i<=n;i++)
		{
			a[i]^=(str[i]=='1');
			sum+=a[i];
		}
		
		int block=0;
		bool inblock=0;
		for(int i=1;i<=n;i++)
		{
			if(!inblock&&a[i]==1)
			{
				inblock=1;
				block++;
			}
			if(a[i]==0) inblock=0;
		}
		
		if(block==0)
		{
			cout<<n*(n+1)/2<<endl;
		}
		else if(block==1)
		{
			cout<<(n-1)*2<<endl;
		}
		else if(block==2)
		{
			cout<<6<<endl;
		}
		else cout<<0<<endl;
		
		
		
		
		
	}
	return 0;
}
