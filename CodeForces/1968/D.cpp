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
int n,k;
int p[N],a[N];
LL calc(int s)
{
	set<int>book;
	LL cnt=1,mx=0,sum=0;
	while(1)
	{
		book.insert(s);
		sum+=a[s];
		//cout<<"sum="<<sum+(k-cnt)*a[s]<<endl;
		mx=max(mx,sum+(k-cnt)*a[s]);
		
		
		cnt++;
		
		s=p[s];
		if(book.find(s)!=book.end()) break;
		if(cnt>k) break; 
		
	}
	return mx;
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
		int s1,s2;
		cin>>n>>k>>s1>>s2;
		for(int i=1;i<=n;i++)
		{
			cin>>p[i];
		}
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		LL a1=calc(s1),a2=calc(s2);
		if(a1==a2) cout<<"Draw";
		if(a1>a2) cout<<"Bodya";
		if(a1<a2) cout<<"Sasha";
		cout<<endl;
		//cout<<"1="<<a1<<" 2="<<a2<<endl;
	}
	return 0;
}
