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

int n,a[N];
int mx,maxcnt;
int mn,mincnt;

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
		mx=maxcnt=mincnt=0;
		mn=100000;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			if(a[i]>mx) mx=a[i],maxcnt=1;
			else if(a[i]==mx) maxcnt++;
			if(a[i]<mn) mn=a[i],mincnt=1;
			else if(a[i]==mn) mincnt++;
		}
		if(mx==mn)
		{
			cout<<"0"<<endl;
		}
		else if(maxcnt>=2&&mincnt>=2)
		{
			cout<<"0"<<endl;
		}
		else{
			if(maxcnt>=2||mincnt>=2)
			{
				cout<<"1"<<endl;
			}
			else{
				cout<<2<<endl;
			}
		}
		
		
		
		
		
		
	}
	return 0;
}
