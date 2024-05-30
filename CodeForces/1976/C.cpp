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



#define N 2000010
int n,m;
map<pair<int,int>,LL>mp;
LL a[N],b[N];
LL sum;
LL dfs(int now,int x,int y)
{
	if(now>n+m+1) return 0;
	if(mp.find(make_pair(x,y))!=mp.end()) return mp[make_pair(x,y)];
	if(x==0) return mp[make_pair(x,y)]=dfs(now+1,x,y-1)+b[now];
	if(y==0) return mp[make_pair(x,y)]=dfs(now+1,x-1,y)+a[now];
	if(a[now]>b[now]) return mp[make_pair(x,y)]=dfs(now+1,x-1,y)+a[now];
	return mp[make_pair(x,y)]=dfs(now+1,x,y-1)+b[now];
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
		cin>>n>>m;
//		for(int i=1;i<=n+m+1;i++) cin>>a[i];
		for(int i=1;i<=n+m+1;i++) a[i]=rand();
//		for(int i=1;i<=n+m+1;i++) cin>>b[i];
		for(int i=1;i<=n+m+1;i++) b[i]=rand();
		int x=n,y=m;
		sum=0;
		mp.clear();
		for(int i=1;i<=n+m+1;i++)
		{
			//delete
			
			LL ans=sum;
			ans+=dfs(i+1,x,y);
			cout<<ans<<" ";
			
			//calc
			if(x==0) sum+=b[i],y--;
			else if(y==0) sum+=a[i],x--;
			else if(a[i]>b[i]) sum+=a[i],x--;
			else sum+=b[i],y--;
		}
		cout<<endl;
		
		
		
		
	}
	return 0;
}
