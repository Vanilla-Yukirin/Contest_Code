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


/*
p
2 3 1 5 6 7 4
i
1 2 3 4 5 6 7
ppi
3 1 2 6 7 4 5
*/

int f[N],sze[N];
int getf(int x)
{
	if(x==f[x]) return x;
	return f[x]=getf(f[x]);
}
void merge(int x,int y){
	x=getf(x);
	y=getf(y);
	if(x==y) return;
	f[x]=y;
	sze[y]+=sze[x];
}
int n;

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
		cin>>n;for(int i=1;i<=n;i++) f[i]=i,sze[i]=1;
		for(int i=1;i<=n;i++)
		{
			int x;cin>>x;
			merge(i,x);
		}
		int ans=0;
		for(int i=1;i<=n;i++)
		{
//			cout<<"i="<<i<<endl;
			if(getf(i)==i)
			{
				ans+=(sze[i]-1)/2;
			}
		}
		cout<<ans<<endl;
		
	}
	return 0;
}
