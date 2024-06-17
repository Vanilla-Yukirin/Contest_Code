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




#define p 998244353ull

ULL qpow(ULL a,ULL b){
	a%=p;
	ULL ans=1;
	while(b){
		if(b&1) ans=ans*a%p;
		b>>=1;
		a=a*a%p;
	}
	return ans;
}

ULL inv(ULL a){
	return qpow(a%p,p-2)%p;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cout.precision(10);
	int t=1;
//	cin>>t;
	while(t--)
	{
		ULL N,w;
		cin>>N;
		w=to_string(N).size();
		//w=log10(N)+1;
		cout<< N %p *(qpow(qpow(10,w),N)-1+p) %p * inv((qpow(10,w)-1+p)%p) %p;
	}
	return 0;
}
