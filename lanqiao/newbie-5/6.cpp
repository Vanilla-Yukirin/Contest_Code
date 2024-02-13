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

namespace oi
{
	inline bool isdigit(const char& ch)
	{
		return ch<='9'&&ch>='0';
	}
	inline bool isalnum(const char& ch)
	{
		return (ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z')||(ch>='0'&&ch<='9');
	}
	struct istream
	{
		char ch;
		bool fu;
		template<class T>inline istream& operator>>(T& d)
		{
			fu=d=0;
			while(!isdigit(ch)&&ch!='-') ch=getchar();
			if(ch=='-') fu=1,ch=getchar();
			d=ch-'0';ch=getchar();
			while(isdigit(ch))
				d=(d<<3)+(d<<1)+(ch^'0'),ch=getchar();
			if(fu) d=-d;
			return *this;
		}
		inline istream& operator>>(char& ch)
		{
			ch=getchar();
			for(;!isalnum(ch);ch=getchar());
			return *this;
		}
		inline istream& operator>>(string& str)
		{
			str.clear();
			for(;!isalnum(ch);ch=getchar());
			while(isalnum(ch))
				str+=ch,ch=getchar();
			return *this;
		}
	}cin;
	inline int read()
	{
		int x=0,fu=0;char ch=getchar();
		while(!isdigit(ch)&&ch!='-') ch=getchar();
		if(ch=='-') fu=1,ch=getchar();
		while(isdigit(ch)) { x=x*10+ch-'0';ch=getchar(); }
		if(fu) x=-x;
		return x;
	}
	int G[55];
	template<class T>inline void write(T x)
	{
		int g=0;
		if(x<0) x=-x,putchar('-');
		do { G[++g]=x%10;x/=10; } while(x);
		for(int i=g;i>=1;--i) putchar('0'+G[i]);
		putchar('\n');
	}
};
using oi::read;

#define N 1000010

/*
x+1/x=k

x^2+1/x^2=k^2-2

x^4+1/x^4=(k^2-2)^2-2

x^n+1/x^n


x^3+1/x^3=

x^1+1/x^1  *  x^2+1/x^2  =  x^3+x^1+x^-1+x^-3



x^100=x^50*x^50

x^100+x^-100=(x^50+x^-50)^2-2

x^101+x^-101=

(x^50+x^-50)*(x^51+x^-51)=x^101+x^-101+

*/



int t;
LL n,k;

LL p=1000000007;
int n2pow[100];


LL calc(LL kk)
{
	if(kk==1) return k;
	if(kk&1)
	{
		
		LL mid=kk/2;
		LL part1=calc(mid),part2=calc(mid+1);
		part1=part1*part2%p+p-k;
		part1%=p;
		return part1;
		
	}
	else
	{
		LL ret=calc(kk/2);
		ret=ret*ret-2+p;
		ret%=p;
		return ret;
	}
	
	
	
	
}




int main()
{
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		n2pow[0]=k;
		for(int i=1;i<=40;i++)
		{
			n2pow[i]=n2pow[i-1]*n2pow[i-1]%p+p-2;
			n2pow[i]%=p;
		}
		cout<<calc(n)<<endl;
		
		
	}
	
	
	
	
	
	
	return 0;
}
