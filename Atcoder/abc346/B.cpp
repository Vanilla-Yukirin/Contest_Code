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

string str="wbwbwwbwbwbw";
int ww[N],bb[N];

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
		while(str.size()<=100) str+=str;
//		cout<<str;
		str=" "+str;
		for(int i=0;i<str.size();i++)
		{
			ww[i]=ww[i-1];
			bb[i]=bb[i-1];
			if(str[i]=='w') ww[i]++;
			else bb[i]++;
		}
		int w,b;
		cin>>w>>b;
		for(int i=0;i<str.size();i++)
		{
			for(int j=i;j<str.size();j++)
			{
				if(ww[j]-ww[i]==w&&bb[j]-bb[i]==b)
				{
					cout<<"Yes"<<endl;
					return 0;
				}
			}
		}
		cout<<"No"<<endl;
		
	}
	return 0;
}
