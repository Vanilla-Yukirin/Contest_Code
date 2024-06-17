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



#define N 1000010




int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cout.precision(10);
	string str;cin>>str;
	int C=0,c=0;
	for(int i=0;i<str.size();i++)
	{
		if(str[i]<='z'&&str[i]>='a') c++;
		if(str[i]<='Z'&&str[i]>='A') C++;
	}
	if(C>c){
		for(int i=0;i<str.size();i++)
		{
			if(str[i]<='z'&&str[i]>='a') str[i]+='A'-'a';
		}
	}
	else{
		for(int i=0;i<str.size();i++)
		{
			if(str[i]<='Z'&&str[i]>='A') str[i]+=-'A'+'a';
		}
	}
	cout<<str;
	return 0;
}
