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



#define N 100010

vector<pair<int,int>>ans;
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
		ans.clear();
		cin>>n;
		string nn=to_string(n);
		for(LL a=1;a<=10000;a++)
		{
			for(LL b=max(1ll,nn.size()*a-6);b<=nn.size()*a-1;b++)
			{
				string x;
				int wei=nn.size()*a-b;
				for(int i=0;i<wei;i++)
				{
					x.push_back(nn[i%nn.size()]);
				}
				if(x==to_string(n*a-b)) ans.push_back(make_pair(a,b));
			}
		}
		
		cout<<ans.size()<<endl;
		for(unsigned int i=0;i<ans.size();i++){
			cout<<ans[i].first<<" "<<ans[i].second<<endl;
		}
	}
	return 0;
}
