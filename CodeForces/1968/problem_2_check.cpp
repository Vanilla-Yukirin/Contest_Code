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

int dis[N][N]={{0,},
	{0,0,8,5,9,12,14,12,16,17,22},
	{0,8,0,9,15,17,8,11,18,14,22},
	{0,5,9,0,7,9,11,7,12,12,17},
	{0,9,15,7,0,3,17,10,7,15,18},
	{0,12,17,9,3,0,8,10,6,15,15},
	{0,14,8,11,17,8,0,9,14,8,16},
	{0,12,11,7,10,10,9,0,8,6,11},
	{0,16,18,12,7,6,14,8,0,11,11},
	{0,17,14,12,15,15,8,6,11,0,10},
	{0,22,22,17,18,15,16,11,11,10,0}
};

int calc(vector<int>s)
{
	int sum=0;
	sum+=dis[1][s[0]];
	sum+=dis[s.back()][1];
	for(int i=1;i<s.size();i++)
	{
		sum+=dis[s[i]][s[i-1]];
	}
	return sum;
}




int main()
{
	for(int i=1;i<=10;i++)
	{
		for(int j=i+1;j<=10;j++)
		{
			for(int w=1;w<=10;w++)
			{
				if(i!=w&&j!=w)
				{
					if(dis[i][w]+dis[w][j]<dis[i][j]){
						cout<<i<<" "<<j<<" use "<<w<<endl;
					}
				}
			}
		}
	}
	
	return 0;
}
