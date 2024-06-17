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



#define N 1010

int n;
int pow3[100];



bool calc(int x,int y)
{
	int k=10;
	while(pow3[k-1]>=x&&pow3[k-1]>=y&&k>=2) k--;
	//cout<<"size="<<pow3[k]<<endl;
	if(pow3[k-1]+1<=x&&x<=2*pow3[k-1]&&pow3[k-1]+1<=y&&y<=2*pow3[k-1]) return 0;
	if(k==1) return 1;
	return calc(x%pow3[k-1],y%pow3[k-1]);
}

int main()
{
	cin>>n;
	pow3[0]=1;
	for(int i=1;i<16;i++){
		pow3[i]=pow3[i-1]*3;
	}
	
	for(int i=1;i<=pow3[n];i++)
	{
		for(int j=1;j<=pow3[n];j++)
		{
			if(calc(i,j)) cout<<'#';
			else cout<<'.';
		}
		cout<<endl;
	}
	
	return 0;
}
