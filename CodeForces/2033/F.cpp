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
#ifdef ONLINE_JUDGE
char buf[1<<23],* p1=buf,* p2=buf,obuf[1<<23],* O=obuf;
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
#endif
using namespace std;



#define N 1000010
#define mod 1000000007ll

LL f[N];

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
		LL n,k;
		cin>>n>>k;
		LL first=0;
		f[1]=f[2]=1;
		if(k==1) first=1;
		else
		for(int i=3;i<=k*10;i++)	
		{
			f[i]=(f[i-1]+f[i-2])%k;
			if(f[i]==0)
			{
				first=i;
				break;
			}
		}
		cout<<n%mod*first%mod<<endl;
	}
	return 0;
}
