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

int a,b,c;


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
		cin>>a>>b>>c;
		if(a+1!=c)
		{
			cout<<"-1"<<endl;
		}
		else
		{
			if(a==0)
			{
				cout<<b<<endl;
				
				
				
				
			}
			else{
				int ceng=ceil(log2(a+1))-1;
				int ye=((a&1)?(a+1)/2:a/2);
//				int ye2=(1<<ceng)-ye;
				int ye2=(1<<ceng)-(a-((1<<ceng)-1));
//				cout<<
//				cout<<"ye2="<<ye2<<endl;
				b-=ye2;
				if(b>0)
				{
					ceng+=b/(a+1);
					if(b%(a+1)) ceng++;
				}
				cout<<ceng+1<<endl;
			}
		}
		
		
	}
	return 0;
}
