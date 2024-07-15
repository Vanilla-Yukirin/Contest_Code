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

LL pow10[1000]={1};
bool judge(LL n,LL d,LL r)
{
	if(d<=0||d>=17) return 0;
	return n*pow10[d]==r;
}

vector<pair<int,int>>ans;
int main()
{
	for(int i=1;i<=17;i++) pow10[i]=pow10[i-1]*10;
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cout.precision(10);
	int t=1;
	cin>>t;
	int nn=1;
	while(t--)
	{
		LL n=nn;
		nn++; 
//		cout<<n<<endl;
		ans.clear();
		cin>>n;
		if(n==1)
		{
			cout<<9999<<endl;
			for(int i=2;i<=10000;i++) cout<<i<<" "<<i-1<<endl;
			continue;
		}
		else if(n<=9)
		{
			for(LL a=10000;a>=1;a--)
			{
				for(LL b=max(1ll,a-20);b<=min(a*n,10000ll)&&b<=a+20;b++)
				{
					if(a-b<=0) break;
					if(judge(n,a-b,9*n*a-9*b+n)) ans.push_back(make_pair(a,b));
				}
			}
		}
		else if(n<=99)
		{
			for(LL a=10000;a>=1;a--)
			{
				for(LL b=max(1ll,a*2-20);b<=min(a*n,10000ll)&&b<=a*2+20;b++)
				{
					if(a*2-b<=0) break;
					if(b&1)
					{
						if(judge(n,2*a-b,99*n*a+10*n-99*(n/10)-99*b)) ans.push_back(make_pair(a,b));
					}
					else
					{
						if(judge(n,2*a-b,99*n*a-99*b+n)) ans.push_back(make_pair(a,b));
					}
				}
			}
			
			
		}
		else
		{
			for(LL a=10000;a>=1;a--)
			{
				for(LL b=a*3-20;b<=min(a*n,10000ll)&&b<=a*3+20;b++)
				{
					if(a*3-b<=0) break;
					if(b%3==0)
					{
						if(judge(1,3*a-b+2,999*n*a-999*b+100)) ans.push_back(make_pair(a,b));
					}
					else if(b%3==1)
					{
						if(judge(1,3*a-b+2,999*n*a-999*b-999+10000)) ans.push_back(make_pair(a,b));
					}
					else
					{
						if(judge(1,3*a-b+2,999*n*a-999*b-999+1000)) ans.push_back(make_pair(a,b));
					}
				}
			}
			
			
			
		}
		
		cout<<ans.size()<<endl;
		for(unsigned int i=0;i<ans.size();i++){
			cout<<ans[i].first<<" "<<ans[i].second<<endl;
		}
	}
	return 0;
}
