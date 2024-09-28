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

LL n,q;
map<LL,LL>k;
int x[N];
int add[N],sub[N];
LL question_k[N];
set<LL>s;

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
		cin>>n>>q;
		k.clear();
		s.clear();
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
		}
		for(int i=1;i<=q;i++)
		{
			cin>>question_k[i];
			k[question_k[i]]=0;
		}
		
		LL len=0,now;
		for(int i=1;i<=n;i++)
		{
			now=(i-1)*(n-i)+n-1;
			if(k.find(now)!=k.end()) k[now]++;
		}
		
		for(int i=1;i<n;i++)
		{
			len=x[i+1]-x[i]-1;
			now=i*(n-i);
			if(k.find(now)!=k.end()) k[now]+=len;
		}
		for(int i=1;i<=q;i++)
		{
			cout<<k[question_k[i]]<<" ";
		}
		cout<<endl;
		
		
		
	}
	return 0;
}
