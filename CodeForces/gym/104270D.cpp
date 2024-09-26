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

int n,m;

bool succ;
vector<int>min_a,min_b,c;

int to_int(vector<int>x)
{
	int y=0;
	for(unsigned int i=0;i<x.size();i++)
	{
		y=y*10+x[i];
	}
	return y;
}

bool le(vector<int>x,vector<int>y)
{
	if(x.size()!=y.size())
	{
		return x.size()<y.size();
	}
	for(unsigned int i=0;i<x.size();i++)
	{
		if(x[i]<y[i]) return 1;
		if(x[i]>y[i]) return 0;
	}
	return 0;
}
bool eq(vector<int>x,vector<int>y)
{
	if(x.size()!=y.size())
	{
		return 0;
	}
	for(unsigned int i=0;i<x.size();i++)
	{
		if(x[i]!=y[i]) return 0;
	}
	return 1;
}


void check(int a1,vector<int>b,int used)
{
//	cout<<"check:";
//	cout<<"a1="<<a1<<"\t";
//	for(unsigned int j=0;j<b.size();j++)
//	{
//		cout<<b[j]<<" ";
//	}
//	cout<<endl;
	
	vector<int>a;
	a.push_back(a1);
	for(int i=1;i<n;i++)
	{
		if((unsigned int)used==c.size()) return;
		vector<int>headc;
		headc.push_back(c[used]);
		int temp=c[used];
		used++;
		
		if(temp%b[0]==0&&temp/b[0]<10)
		{
			a.push_back(temp/b[0]);
		}
		else
		{
			if((unsigned int)used==c.size()) return;
			headc.push_back(c[used]);
			temp=temp*10+c[used];
			used++;
			if(temp%b[0]==0&&temp/b[0]<10)
			{
				a.push_back(temp/b[0]);
			}
			else return;
		}
//		cout<<"a_"<<i+1<<"="<<a.back()<<endl;
		for(int j=1;j<m;j++)
		{
			bool flag=0;
			if((unsigned int)used==c.size()) return;
			vector<int>headc;
			headc.push_back(c[used]);
			int temp=c[used];
			used++;
			
			if(a[i]*b[j]==temp)
			{
				flag=1;
			}
			else
			{
				if((unsigned int)used==c.size()) return;
				headc.push_back(c[used]);
				temp=temp*10+c[used];
				used++;
				if(a[i]*b[j]==temp)
				{
					flag=1;
				}
				else return;
			}
			if(!flag) return;
		}
	}
	if(used==c.size()&&a.size()==n)
	{
//		cout<<"get ans"<<endl;
		succ=1;
//		for(unsigned int i=0;i<a.size();i++)
//		{
//			cout<<a[i]<<" ";
//		}
//		for(unsigned int j=0;j<b.size();j++)
//		{
//			cout<<b[j]<<" ";
//		}
//		cout<<endl;
		if(min_a.size()==0||le(a,min_a)||(eq(a,min_a)&&le(b,min_b)))
		{
			min_a=a;
			min_b=b;
		}
	}
}

void dfs(int a1,vector<int>b,int used)
{
	if(b.size()==(unsigned int)m)
	{
		check(a1,b,used);
		return;
	}
	
	if((unsigned int)used==c.size()) return;
	vector<int>headc;
	headc.push_back(c[used]);
	int temp=c[used];
	used++;
	
	if(temp%a1==0&&temp/a1<10)
	{
		b.push_back(temp/a1);
		dfs(a1,b,used);
		b.pop_back();
		return;
	}
	
	
	if((unsigned int)used==c.size()) return;
	headc.push_back(c[used]);
	temp=temp*10+c[used];
	used++;
	if(temp==0) return;
	
	if(temp%a1==0&&temp/a1<10)
	{
		b.push_back(temp/a1);
		dfs(a1,b,used);
		b.pop_back();
	}
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
		cin>>n>>m;
		c.clear();
		min_a.clear();
		min_b.clear();
		succ=0;
		string str;cin>>str;
		for(unsigned int i=0;i<str.size();i++)
		{
			c.push_back(str[i]-'0');
		}
		for(int i=1;i<=9;i++)
		{
			vector<int>temp;
			dfs(i,temp,0);
		}
		
		if(succ)
		{
//			cout<<"output ans"<<endl;
			for(unsigned int i=0;i<min_a.size();i++)
			{
				cout<<min_a[i];
			}
			cout<<" ";
			for(unsigned int i=0;i<min_b.size();i++)
			{
				cout<<min_b[i];
			}
			cout<<endl;
		}
		else
		{
			cout<<"Impossible"<<endl;
		}
		
	}
	return 0;
}
