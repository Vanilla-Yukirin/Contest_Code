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


int n;
int a[N];
int cnt1[N],cnt2[N],mex1,mex2;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cout.precision(10);
	int t;cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		memset(cnt1,0,sizeof(cnt1));
		memset(cnt2,0,sizeof(cnt2));
		mex1=mex2=0;
		int k=1;//1~k,k+1~n k_max=n-1
		cnt1[a[1]]++;
		for(int i=2;i<=n;i++) cnt2[a[i]]++;
		while(cnt1[mex1]) mex1++;
		while(cnt2[mex2]) mex2++;
		bool win=0;
		if(mex1==mex2)
		{
			cout<<2<<endl;
			cout<<"1 "<<k<<"\n"<<k+1<<" "<<n<<endl;
			win=1;
			continue;
		}
		for(k=2;k<=n-1;k++)
		{
			cnt1[a[k]]++;
			while(cnt1[mex1]) mex1++;
			cnt2[a[k]]--;
			if(cnt2[a[k]]==0&&a[k]<mex2) mex2=a[k];
			
			if(mex1==mex2)
			{
				cout<<2<<endl;
				cout<<"1 "<<k<<"\n"<<k+1<<" "<<n<<endl;
				win=1;
				break;
			}
		}
		if(!win)
		{
			cout<<"-1"<<endl;
		}
	}
	return 0;
}
