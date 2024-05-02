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


#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
#define N 1000010


int n;
int dis(pii a,pii b)
{
	return abs(a.first-b.first)+abs(a.second-b.second);
}
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
		set<int>s;
		int n;
		vector<pii>vec;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			int x,y;cin>>x>>y;
			vec.push_back(mp(x,y));
		}
		for(int i=0;i<vec.size();i++)
		{
			for(int j=0;j<vec.size();j++)
			{
				s.insert(dis(vec[i],vec[j]));
			}
		}
		cout<<s.size()<<endl;
		
	}
	return 0;
}
