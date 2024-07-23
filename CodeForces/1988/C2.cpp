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
		vector<int>one;
		vector<LL>ans;
		int t=0;
		while(x)
		{
			if(x&1) one.push_back(t);
			x>>=1;
			t++;
		}
		
		if(one.size()==1)
		{
			cout<<1<<endl<<n<<endl;
			continue;
		}
		
		
		for(int i=one.size()-1;i>=0;i--)
		{
			x=n;
			x-=(1ll<<one[i]);
//			cout<<x<<" ";
			ans.push_back(x);
		}
		
		
		cout<<ans.size()+1<<endl;
		for(unsigned int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
		cout<<n<<endl;
		
	}
	return 0;
}
