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


int a[N];

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
		int n;
		cin>>n;
		string str;cin>>str;
		for(int i=1;i<=n;i++)
		{
			a[i]=str[i-1]-'0';
		}
		int one=0,zero=0;
		if(a[1]==1) one++;
		else zero++;
		
		for(int i=2;i<=n;i++)
		{
			if(a[i]==1) one++;
			else{
				if(a[i-1]==1) zero++;
			}
		}
		
		if(one>zero) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
		
	}
	return 0;
}
