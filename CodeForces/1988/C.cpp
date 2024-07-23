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
#include<bitset>
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
		LL n;
		cin>>n;
		LL x=n;
//		int wei=
		vector<LL>ans;
		ans.push_back(n);
		while(1)
		{
			LL last=0;
			for(LL i=x-1;i>=1;i--)
			{
				if((i|x)==n)
				{
					last=i;
					break;
				}
			}
			if(last)
			{
				ans.push_back(last);
				x=last;
			}
			else break;
		}
		
		cout<<ans.size()<<endl;
		while(ans.size())
		{
			//cout<<ans.back()<<" ";
			cout<< (bitset<sizeof(int) *  10>(ans.back()) )<<endl;
			
			
			
			
			ans.pop_back();
		}
		cout<<endl;
		
	}
	return 0;
}
