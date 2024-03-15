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



#define N 10010


int a[N];
vector<int>vec;
int L[N],R[N],val[N];
int cnt;
bool win=1;
int tot;

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
		int n;cin>>n;tot=0;
		vec.clear();
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			vec.push_back(a[i]);
		}
		win=0;
		bool flag=1;
		for(int j=1;j<(int)vec.size();j++)
		{
			if(vec[j-1]>vec[j]) flag=0;
		}
		if(flag) win=1;
		for(int i=0;i<(int)vec.size();i++)
		{
			if(vec[i]>=10)
			{
				int y=vec[i]%10;
				vec[i]/=10;
				vec.insert(vec.begin()+i+1,y);
			}
			
			bool flag=1;
			for(int j=1;j<(int)vec.size();j++)
			{
				if(vec[j-1]>vec[j]) flag=0;
			}
			if(flag) win=1;
		}
		
		
		if(win) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
		
	}
	return 0;
}
