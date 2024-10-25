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

int n;
int a[N];


int check(int x)
{
	int ans=0;
	if(x-1) if(a[x-1]==a[x]) ans++;
	if(x+1<=n) if(a[x+1]==a[x]) ans++;
	return ans;
}


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
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(int i=2;i<=n/2;i++)
		{
			int j=i;
			if(a[j-1]==a[j]) swap(a[j],a[n-j+1]);
			
			j=n-i+1;
			if(a[j+1]==a[j]) swap(a[j],a[n-j+1]);
		}
		int ans=0;
		for(int i=1;i<n;i++)
		{
			ans+=(a[i]==a[i+1]);
		}
		cout<<ans<<endl;
	}
	return 0;
}
