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



#define N 100


vector<int>a;

int main()
{
	srand(time(0));
	cout<<1<<endl;
	int n=rand()%8+5,m=rand()%5+5,k=rand()%5+5;
	cout<<n<<" "<<m<<" "<<k<<endl;
	while(n--)
	{
		a.push_back(rand()%N);
	}
	sort(a.begin(),a.end());
	for(int i=0;i<(a.size());i++) cout<<a[i]<<" ";
	cout<<endl;
	while(m--)
	{
		cout<<rand()%N/2<<" ";
	}
	cout<<endl;
	while(k--)
	{
		cout<<rand()%N/2<<" ";
	}
	cout<<endl;
	
	return 0;
}
