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



#define N 200010


int n;
LL tot;
LL a[3][N];
LL low;



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
		cin>>n;
		tot=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[0][i];
			tot+=a[0][i];
		}
		low=ceil(tot/3.0);
		for(int i=1;i<=n;i++)
		{
			cin>>a[1][i];
		}
		for(int i=1;i<=n;i++)
		{
			cin>>a[2][i];
		}
		bool win=0;
		int ans[3][2];
		for(int ii=0;ii<3;ii++)
		{
			for(int jj=0;jj<3;jj++)
			{
				for(int kk=0;kk<3;kk++)
				{
					if(ii==jj||jj==kk||ii==kk) continue;
					int l=0,r=n;
					LL sum1=0;
					for(int i=1;i<=n;i++)
					{
						sum1+=a[ii][i];
						l=i;
						if(sum1>=low) break;
					}
					
					if(sum1<low) break;
					l++;
					LL sum2=0;
					for(int i=n;i>=1;i--)
					{
						sum2+=a[kk][i];
						r=i;
						if(sum2>=low) break;
					}
					r--;
					if(sum2<low) break;
					
					LL sum3=0;
					for(int i=l;i<=r;i++)
					{
						sum3+=a[jj][i];
						if(sum3>=low) break;
					}
					
					if(sum3<low) break;
					
					win=1;
					ans[ii][0]=1;
					ans[ii][1]=l-1;
					ans[jj][0]=l;
					ans[jj][1]=r;
					ans[kk][0]=r+1;
					ans[kk][1]=n;
				}
			}
		}
//		cout<<"ans!=";
		if(win) 
		for(int i=0;i<3;i++)
		{
			cout<<ans[i][0]<<" "<<ans[i][1]<<" ";
		}
		else cout<<"-1";
		cout<<endl;
		
		
		
	}
	return 0;
}
