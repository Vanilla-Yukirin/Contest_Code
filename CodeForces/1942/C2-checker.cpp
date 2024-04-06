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
#include<ctime>
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
#include<fstream>
using namespace std;



#define N 1000010


vector<int>a;

int main()
{
	ofstream fout;
	srand(time(0));
	fout.open("c2.txt",ios::out);
	int n=8;
	int x=0,y=3;
	for(int i=1;i<=n;i++)
	{
		if(rand()%100>60) a.push_back(i),x++;
	}
	cout<<"1"<<endl;
	fout<<"1"<<endl;
	cout<<n<<" "<<x<<" "<<y<<endl;
	fout<<n<<" "<<x<<" "<<y<<endl;
	for(int i=0;i<x;i++)
	{
		cout<<a[i]<<" ";
		fout<<a[i]<<" ";
	}
	cout<<endl;
	fout<<endl;
	system("C2-3.exe < c2.txt >my.txt");
	system("C2-zmq.exe <c2.txt >std.txt");
	
	
	return 0;
}
