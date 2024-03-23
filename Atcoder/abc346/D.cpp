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

int n;
LL ans=10000000000000000ll;
bool a[N];
bool goal[N];
LL c[N];


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
		cin>>n;
		string s;cin>>s;s=" "+s;
		for(int i=1;i<=n;i++)
		{
			a[i]=s[i]-'0';
		}
		for(int i=1;i<=n;i++)
		{
			cin>>c[i];
		}
		LL now=0;
		for(int i=1;i<=n;i++)
		{
			goal[i]=i&1;
			if(a[i]!=goal[i]) now+=c[i]; 
		}
		for(int i=1;i<=n-1;i++)
		{
			goal[i]^=1;
			if(a[i]==goal[i]) now-=c[i];
			else now+=c[i];
			ans=min(ans,now);
		}
		now=0;
		for(int i=1;i<=n;i++)
		{
			goal[i]=!(i&1);
			if(a[i]!=goal[i]) now+=c[i]; 
		}
		for(int i=1;i<=n-1;i++)
		{
			goal[i]^=1;
			if(a[i]==goal[i]) now-=c[i];
			else now+=c[i];
			ans=min(ans,now);
		}
		cout<<ans;
	}
	return 0;
}
