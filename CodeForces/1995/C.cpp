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



#define N 200010

int n;
LL a[N];
LL cnt[N];
LL ans;

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
		ans=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		bool fail=0;
		for(int i=2;i<=n;i++)
		{
			if(a[i]==1&&a[i-1]!=1)
			{
				cout<<"-1"<<endl;
				fail=1;
				break;
			}
		}
		if(fail) continue;
		cnt[1]=0;
		for(int i=2;i<=n;i++)
		{
			cnt[i]=max(0.0,cnt[i-1]+ceil(log2(log2(a[i-1])/log2(a[i]))));
//			cout<<"lg/lg="<<log2(a[i-1])/log2(a[i])<<" , cnt="<<cnt[i]<<endl;
			ans+=cnt[i];
		}
		
		cout<<ans<<endl;
		
	}
	return 0;
}
