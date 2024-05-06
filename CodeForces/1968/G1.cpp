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

int a[N];


int n,k;
string str;
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
		int l,r,mid,ans=0;
		cin>>n>>l>>r;
		cin>>str;
		k=l;
		
		l=1;r=min(n/k+1,n);
		while(l<=r)
		{
			mid=(l+r)>>1;
			string head=str.substr(0,mid);
			//cout<<"l="<<l<<" r="<<r<<" mid="<<mid<<" head="<<head<<endl;
			int cnt=0;
			int it=0;
			while(1)
			{
				int fd=str.find(head,it);
				if(fd==(int)string::npos) break;
				cnt++;
				it=fd+head.size();
				if(cnt>=k) break;
			}
			if(cnt>=k)
			{
				ans=mid;
				l=mid+1;
			}
			else r=mid-1;
		}
		
		cout<<ans<<endl;
		
		
	}
	return 0;
}
