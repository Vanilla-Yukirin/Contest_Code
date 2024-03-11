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

int l[N],r[N];
char val[N];

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
		int n;cin>>n;
		string str;cin>>str;str=" "+str;
		for(int i=1;i<=n;i++)
		{
			val[i]=str[i];
			l[i]=i-1;
			r[i]=i+1;
		}
		r[n]=0;
		int x=1,ans=0;
		while(x)
		{
//			cout<<"x="<<x<<endl;
//			cout<<"l="<<l[x]<<" "<<"r="<<r[x]<<endl;
			if(val[x]=='m'&&val[r[x]]=='a'&&val[r[r[x]]]=='p'&&val[r[r[r[x]]]]=='i'&&val[r[r[r[r[x]]]]]=='e')
			{
				x=r[r[x]];
				l[r[x]]=l[x];
				r[l[x]]=r[x];
				x=r[x];
				ans++;
				continue;
			}
			if(val[x]=='m'&&val[r[x]]=='a'&&val[r[r[x]]]=='p')
			{
				x=r[x];
				l[r[x]]=l[x];
				r[l[x]]=r[x];
				x=r[x];
				ans++;
				continue;
			}
			if(val[x]=='p'&&val[r[x]]=='i'&&val[r[r[x]]]=='e')
			{
				x=r[x];
				l[r[x]]=l[x];
				r[l[x]]=r[x];
				x=r[x];
				ans++;
				continue;
			}
			x=r[x];
		}
		
		cout<<ans<<endl;
		for(int i=0;i<=n+10;i++) l[i]=r[i]=val[i]=0;
		
	}
	return 0;
}
