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
LL m;
map<LL,int>mp;

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
		cin>>n>>m;
		mp.clear();
		for(int i=1;i<=n;i++)
		{
			int x;cin>>x;
			mp[x]++;
		}
		ans=0;
		for(auto it=mp.begin();it!=mp.end();it++)
		{
			LL k=it->first;
			int up=it->second;
			ans=max(ans,min(k*up,m/k*k));
		}
		
		for(auto it=mp.begin();it!=mp.end();it++)
		{
			LL k1=it->first;
			LL k2=k1+1;
			if(mp.find(k2)==mp.end()) continue;
			int up1=it->second;
			int up2=mp[k2];
			for(int i=0;i<=up1&&i*k1<=m;i++)
			{
				ans=max(ans,min(i*k1+up2*k2,(m-i*k1)/k2*k2+i*k1));
			}
		}
		
		cout<<ans<<endl;
	}
	return 0;
}
