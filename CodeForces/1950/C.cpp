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
		string str;cin>>str;
		int a=str[0]-'0';
		a=a*10+str[1]-'0';
		int b=str[3]-'0';
		b=b*10+str[4]-'0';
		
		bool PM=0;
		if(a>=12)
		{
			PM=1;
			a-=12;
		}
		if(a==0)
		{
			a=12;
			
		}
		str[0]=a/10+'0';
		str[1]=a%10+'0';
		cout<<str<<" ";
		if(PM) cout<<"PM";
		else cout<<"AM";
		cout<<endl;
		
	}
	return 0;
}
