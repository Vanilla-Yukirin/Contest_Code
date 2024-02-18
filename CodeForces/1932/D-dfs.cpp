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

#define N 10010


int t;
int n;
string King;
char king;
string card[N];
bool book[N];
bool possible;
vector<int>ans;
void dfs2(int,string);
void dfs1(int depth)
{
	if(possible) return;
	if(depth==n)
	{
		possible=1;
		for(int i=0;i<2*n;i++)
		{
			cout<<card[ans[i]]<<" ";
			if(i&1) cout<<endl;
		}
		cout<<endl;
		return;
	}
	
	
	for(int i=0;i<2*n;i++)
	{
		if(!book[i])
		{
			book[i]=1;
			ans.push_back(i);
			dfs2(depth,card[i]);
			ans.pop_back();
			book[i]=0;
		}
	}
	
}
void dfs2(int depth,string last)
{
	if(possible) return;
	
	for(int i=0;i<2*n;i++)
	{
		if(!book[i])
		{
			bool bigger=0;
			if(card[i][1]==king)
			{
				if(last[1]==king)
				{
					if(card[i][0]>last[0]) bigger=1;
				}
				else{
					bigger=1;
				}
			}
			else
			{
				if(card[i][1]==last[1]&&card[i][0]>last[0])
				{
					bigger=1;
				}
			}
			if(bigger)
			{
				book[i]=1;
				ans.push_back(i);
				dfs1(depth+1);
				ans.pop_back();
				book[i]=0;
			}
		}
	}
	
}

int main()
{
	cin>>t;
	while(t--)
	{
		cin>>n;
		cin>>King;
		king=King[0];
		memset(book,0,sizeof(book));
		possible=0;
		ans.clear();
		
		for(int i=0;i<2*n;i++) cin>>card[i];
		dfs1(0);
		if(!possible)
		{
			cout<<"IMPOSSIBLE"<<endl;
		}
	}
	
	
	
	
	
	
	return 0;
}
