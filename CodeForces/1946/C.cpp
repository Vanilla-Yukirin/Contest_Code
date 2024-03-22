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



#define N 400010

int n,k;
vector<int>e[N];

int f[N],son[N];

int l,r,mid,ans;
int kk;

bool dfs1(int x)
{
	son[x]=1;
	
	
	for(int i=0;i<(int)e[x].size();i++)
	{
		int v=e[x][i];
		if(v==f[x]) continue;
		f[v]=x;
		if(dfs1(v)) son[x]+=son[v];
	}
	
	if(x==1)
	{
		if(son[x]<mid) kk--;
		return 0;
	}
	
	
	if(son[x]>=mid) 
	{
		kk++;
//		cout<<"delete "<<x<<" "<<f[x]<<endl;
		return 0;
	}
	return 1;
	
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
		cin>>n>>k;
		for(int i=1;i<=n;i++) e[i].clear(),f[i]=0,son[i]=1;
		for(int i=1,x,y;i<n;i++)
		{
			cin>>x>>y;
			e[x].push_back(y);
			e[y].push_back(x);
		}
		l=1,r=n;
		ans=1;
		while(l<=r)
		{
//			debug
			mid=l+r>>1;
//			cout<<"try: l="<<l<<" r="<<r<<" mid="<<mid<<endl;
			f[1]=0;
			kk=0;
			dfs1(1);
//			cout<<"kk="<<kk<<endl;
			if(kk>=k)//yes!
			{
//				cout<<"yes!"<<endl;
				ans=mid;
				l=mid+1;
			}
			else r=mid-1;
		}
//		cout<<"ans=";
		cout<<ans<<endl;
		
		
	}
	return 0;
}
