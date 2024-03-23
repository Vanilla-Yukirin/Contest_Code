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



#define N 200010

int n;
int a[N];
int x[N];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cout.precision(10);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n==2)
	{
		if(a[1]==0) cout<<"0 0"<<endl;
		else if(a[1]==1) cout<<"0 1"<<endl;
		else cout<<"1 1"<<endl;
	}
	else if(n==3)
	{
		x[3]=a[2]-a[1];
		x[1]=a[2]-a[3];
		x[2]=a[2]-x[1]-x[3];
		cout<<x[1]<<" "<<x[2]<<" "<<x[3]<<endl;
	}
	else{
		bool succ=0;
		for(x[1]=0;x[1]<=1&&!succ;x[1]++)
		{
			for(x[2]=0;x[2]<=1&&!succ;x[2]++)
			{
//				cout<<"x1="<<x[1]<<" x2="<<x[2]<<endl;
				x[3]=a[2]-a[1];
				for(int i=4;i<=n;i++)
				{
					x[i]=x[i-3]-a[i-2]+a[i-1];
				}
				
				if(x[n-2]==a[n-1]-a[n]&&x[n-1]+x[n]==a[n])
				{
					bool flag=1;
					for(int i=1;i<=n;i++)
					{
						if(x[i]<0||x[i]>1)
						{
							flag=0;
							break;
						}
					}
					if(flag)
					{
						succ=1;
						for(int i=1;i<=n;i++)
						{
							cout<<x[i]<<" ";
						}
						break;
					}
				}
				
			}
		}
	}
	return 0;
}
