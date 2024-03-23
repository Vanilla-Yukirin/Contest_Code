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

LL h,w,m;
LL T[N],a[N],x[N];

map<int,LL>mp;
int hh,ww;
bool hbook[N],wbook[N];


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cout.precision(10);
	cin>>h>>w>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>T[i]>>a[i]>>x[i];
	}
	for(int i=m;i>=1;i--)
	{
		if(T[i]==1)
		{
			if(hbook[a[i]]) continue;
			hbook[a[i]]=1;
			hh++;
			mp[x[i]]+=w-ww;
		}
		else{
			if(wbook[a[i]]) continue;
			wbook[a[i]]=1;
			ww++;
			mp[x[i]]+=h-hh;
		}
	}
	LL zero=h*w;
	for(auto it=mp.begin();it!=mp.end();it++)
	{
		zero-=it->second;
	}
	if(zero) mp[0]+=zero;
	int cnt=0;
	
	
	
	for(auto it=mp.begin();it!=mp.end();it++)
	{
		if(it->second)
		{
			cnt++;
		}
	}
	cout<<cnt<<endl;
	for(auto it=mp.begin();it!=mp.end();it++)
	{
		if(it->second)
		{
			cout<<it->first<<" "<<it->second<<endl;
		}
	}
	return 0;
}
