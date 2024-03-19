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



#define N 300010

int n;
string str;
bool a[N];
int pre[N],rpre[N];


int ans;

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
		cin>>n;
		cin>>str;
		for(int i=1;i<=n;i++)
		{
			a[i]=str[i-1]-'0';
			pre[i]=pre[i-1]+(a[i]==0);
//			cout<<pre[i]<<" ";
		}
		ans=-1;
//		cout<<endl;
		for(int i=n;i>=1;i--)
		{
			rpre[i]=rpre[i+1]+a[i];
//			cout<<rpre[i]<<" ";
		}
//		cout<<endl;
		for(int i=0;i<=n;i++)
		{
			if(pre[i]>=ceil(i/2.0)&&rpre[i+1]>=ceil((n-i)/2.0))
			{
//				cout<<"now,left0="<<pre[i]<<" and right1="<<rpre[i+1]<<endl;
//				cout<<i<<endl;
				if(abs(n-2*i)<abs(n-2*ans)) ans=i;
//				break;
			}
			
			
		}
		if(ans==-1) ans=0;
//		cout<<"ans="<<endl;
		cout<<ans<<endl;
		
		for(int i=1;i<=n;i++)
		{
			pre[i]=rpre[i]=0;
		}
		
	}
	return 0;
}
