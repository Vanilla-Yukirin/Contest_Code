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
LL c;
LL s[N];
LL ji,ou;
LL ans;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cout.precision(10);
	int t;cin>>t;
	while(t--)
	{
		cin>>n>>c;
		ji=ou=0;
		ans=(c+1)*(c+2)/2;
		for(int i=1;i<=n;i++)
		{
			cin>>s[i];
			if(s[i]&1) ji++;
			else ou++;
			ans-=min((LL)floor(s[i]/2.0),c-(LL)ceil(s[i]/2.0));
			ans-=max(0ll,c-s[i]+1);
		}
		ans+=ou*(ou-1)/2+ji*(ji-1)/2;
		cout<<ans<<endl;
	}
	return 0;
}
