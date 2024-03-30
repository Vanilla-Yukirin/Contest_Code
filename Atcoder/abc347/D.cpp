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
#include<bitset>
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
	int t=1;
//	cin>>t;
	while(t--)
	{
		LL a,b,c;
		LL x=0,y=0;
		cin>>a>>b>>c;
		bitset<100>C(c);
//		cout<<C.count()<<endl;
		if(a+b>=C.count()&&((a+b)%2==C.count()%2)&&(abs(a-b)<=C.count()))
		{
			LL remain=(a+b-C.count())/2;
			a-=remain;
			b-=remain;
			if(remain+C.count()>60)
			{
				cout<<-1<<endl;
				return 0;
			}
//			cout<<remain<<endl;
			for(int i=0;i<100;i++)
			{
				if(C[i]==1)
				{
					if(a>0) x|=(1ll<<i),a--;
					else y|=(1ll<<i),b--;
				}
				else{
					if(remain>0)
					{
						x|=(1ll<<i);
						y|=(1ll<<i);
						remain--;
					}
				}
			}
			if(a!=0||b!=0||remain!=0)
			{
				cout<<-1<<endl;
				return 0;
			}
			cout<<x<<" "<<y<<endl;
		}
		else cout<<"-1";
		
	}
	return 0;
}
