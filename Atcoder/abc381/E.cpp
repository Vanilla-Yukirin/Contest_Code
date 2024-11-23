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

#define RED cout << "\033[91m"
#define GREEN cout << "\033[92m"
#define YELLOW cout << "\033[93m"
#define BLUE cout << "\033[94m"
#define MAGENTA cout << "\033[95m"
#define CYAN cout << "\033[96m"
#define RESET cout << "\033[0m"

// 红色
#define DEBUG1(x)                     \
RED;                              \
cout << #x << " : " << x << endl; \
RESET;

// 绿色
#define DEBUG2(x)                     \
GREEN;                            \
cout << #x << " : " << x << endl; \
RESET;

// 蓝色
#define DEBUG3(x)                     \
BLUE;                             \
cout << #x << " : " << x << endl; \
RESET;

// 品红
#define DEBUG4(x)                     \
MAGENTA;                          \
cout << #x << " : " << x << endl; \
RESET;

// 青色
#define DEBUG5(x)                     \
CYAN;                             \
cout << #x << " : " << x << endl; \
RESET;

// 黄色
#define DEBUG6(x)                     \
YELLOW;                           \
cout << #x << " : " << x << endl; \
RESET;

#ifdef ONLINE_JUDGE
char buf[1<<23],* p1=buf,* p2=buf,obuf[1<<23],* O=obuf;
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
#endif
using namespace std;



#define N 1000010


int left1[N],left2[N],right1[N],right2[N];
int n,q;
string str;
int pos[N],cnt;
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
		cin>>n>>q;
		cin>>str;
		str=" "+str;
//		pos[++cnt]=0;
		for(int i=1;i<=n;i++)
		{
			if(str[i]=='/')
			{
				pos[++cnt]=i;
			}
		}
		pos[++cnt]=n+1;
		int pre1=0,pre2=0;
		for(int i=1;i<=n;i++)
		{
			left1[i]=pre1;
			left2[i]=pre2;
			if(str[i]=='1') pre1++;
			if(str[i]=='2') pre2++;
		}
		pre1=pre2=0;
		for(int i=n;i>=1;i--)
		{
			right1[i]=pre1;
			right2[i]=pre2;
			if(str[i]=='1') pre1++;
			if(str[i]=='2') pre2++;
		}
		
		while(q--)
		{
			int a,b,ans=0;cin>>a>>b;
			// 确定左右边界，即找到最远的一对杠但是在[a,b]之内
			int l=lower_bound(pos+1,pos+cnt+1,a)-pos;
			int r=upper_bound(pos+1,pos+cnt+1,b)-pos-1;
//			DEBUG1(l);
//			DEBUG1(r);
			while(l+3000<r)
			{
				int mid1=l+(r-l)/3;
				int mid2=r-(r-l)/3;
				int p1=pos[mid1],p2=pos[mid2];
				int s1=min(left1[p1]-left1[a],right2[p1]-right2[b]);
				int s2=min(left1[p2]-left1[a],right2[p2]-right2[b]);
				if(s1<s2)
				{
					l=mid1;
				}
				else{
					r=mid2;
				}
			}
			for(int i=l;i<=r;i++)
			{
				int p=pos[i];
				if(str[p]=='/')
				{
//					cout<<"calc "<<i<<endl;
//					cout<<min(left1[p]-left1[a],right2[p]-right2[b])<<endl;
					ans=max(ans,1+2*min(left1[p]-left1[a],right2[p]-right2[b]));
				}
			}
			cout<<ans<<endl;
		}
		
	}
	return 0;
}
