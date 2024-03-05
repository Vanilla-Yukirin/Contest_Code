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



#define N 2010

int n,l;
pair<LL,LL>mess[N];
priority_queue<LL,vector<LL> ,greater<LL> >q2;
priority_queue<LL>q1;//small
int ans;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cout.precision(10);
	int t;cin>>t;
	while(t--)
	{
		cin>>n>>l;
		ans=0;
		for(int i=1;i<=n;i++)
		{
			cin>>mess[i].second>>mess[i].first;
		}
		sort(mess+1,mess+1+n);
		LL sum=0;
		for(int i=1;i<=n;i++)
		{
			while(q1.size()) q1.pop();
			while(q2.size()) q2.pop();
			sum=0;
			for(int j=i;j<=n;j++)
			{
				debug
				if(q1.empty()||mess[j].second>q1.top())
				{
					q2.push(mess[j].second);
				}
				else q1.push(mess[j].second),sum+=mess[j].second;
				
				while(q2.size()&&sum+mess[j].first-mess[i].first+q2.top()<=l) sum+=q2.top(),q1.push(q2.top()),q2.pop();
				while(q1.size()&&sum+mess[j].first-mess[i].first>l) sum-=q1.top(),q2.push(q1.top()),q1.pop();
				
				ans=max(ans,(int)q1.size());
			}
		}
		cout<<ans<<endl;
		
	}
	return 0;
}
