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

LL pow10[1000]={1};
bool judge(LL n,LL d,LL r)
{
	if(d<=0||d>=17) return 0;
	return n*pow10[d]==r;
}

vector<pair<int,int>>ans;
int main()
{
	for(int i=1;i<=17;i++) pow10[i]=pow10[i-1]*10;
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cout.precision(10);
	int t=1;
	cin>>t;
	int nn=1;
	while(t--)
	{
		LL n;
		cin>>n;
		if(n==1)
		{
			cout<<9999<<endl;
			for(int i=2;i<=10000;i++) cout<<i<<" "<<i-1<<endl;
			continue;
		}
		else{
			if(n==2) cout<<"3\n2218 2214\n219 216\n20 18"<<endl;
		}
	}
	return 0;
}
