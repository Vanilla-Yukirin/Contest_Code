/**************************************************************
 * Problem: 
 * Author: Vanilla_chan
 * Date: 
 * E-Mail: heshaohong2015@outlook.com
 **************************************************************/
#include<bits/stdc++.h>
#define IL inline
#define re register
#define LL long long
#define ll long long
#define ULL unsigned long long
#define ull unsigned long long
#define mk(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define endl '\n'
#ifdef TH
#define debug cout<<"Now is "<<__LINE__<<endl;
#else
#define debug
#endif

std::string COLORS[]={"\033[0m","\033[91m","\033[92m","\033[93m","\033[94m","\033[95m","\033[96m"};
std::string COLOR_NAMES[]={"RESET","RED","GREEN","YELLOW","BLUE","MAGENTA","CYAN"};

#define DEBUG(x,color)                   \
cout<<COLORS[color];                     \
cout << #x << " : " << x << endl;        \
cout<<COLORS[0];                         \
cout.flush();

#define LOOP(While_times) while(While_times-->0)
using namespace std;


#define N 10000100
#define inf 1000000010ll
int n;
int xy[N][2];
int xx[N],yy[N];
bool cmpx(int x,int y)
{
	return xy[x][0]<xy[y][0];
}
bool cmpy(int x,int y)
{
	return xy[x][1]<xy[y][1];
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>xy[i][0]>>xy[i][1];
		xx[i]=i;
		yy[i]=i;
	}
	if(n==1)
	{
		cout<<"1"<<endl;
		return;
	}
	sort(xx+1,xx+n+1,cmpx);
	sort(yy+1,yy+n+1,cmpy);
	
	
	int x1=xy[xx[1]][0],x2=xy[xx[1]][1];
	int y1=xy[yy[1]][0],y2=xy[yy[1]][1];
	LL nowx,nowy;
	LL ans=inf*inf;
	//xmin
	nowx=xy[xx[n]][0]-xy[xx[2]][0]+1;
	nowy=xy[yy[n]==xx[1]?yy[n-1]:yy[n]][1]-xy[yy[1]==xx[1]?yy[2]:yy[1]][1]+1;
	if(nowx*nowy==n-1)
	{
		if(nowx<nowy) nowy++;
		else nowx++;
	}
//	cout<<"del xmin,ans="<<nowx*nowy<<endl;
	ans=min(ans,nowx*nowy);
	//xmax
	nowx=xy[xx[n-1]][0]-xy[xx[1]][0]+1;
	nowy=xy[yy[n]==xx[n]?yy[n-1]:yy[n]][1]-xy[yy[1]==xx[n]?yy[2]:yy[1]][1]+1;
	if(nowx*nowy==n-1)
	{
		if(nowx<nowy) nowy++;
		else nowx++;
	}
//	cout<<"del xmax,ans="<<nowx*nowy<<endl;
	ans=min(ans,nowx*nowy);
	//ymin
	nowx=xy[xx[n]==yy[1]?xx[n-1]:xx[n]][0]-xy[xx[1]==yy[1]?xx[2]:xx[1]][0]+1;
	nowy=xy[yy[n]][1]-xy[yy[2]][1]+1;
	if(nowx*nowy==n-1)
	{
		if(nowx<nowy) nowy++;
		else nowx++;
	}
//	cout<<"del ymin,ans="<<nowx*nowy<<endl;
	ans=min(ans,nowx*nowy);
	//ymax
	nowx=xy[xx[n]==yy[n]?xx[n-1]:xx[n]][0]-xy[xx[1]==yy[n]?xx[2]:xx[1]][0]+1;
	nowy=xy[yy[n-1]][1]-xy[yy[1]][1]+1;
	if(nowx*nowy==n-1)
	{
		if(nowx<nowy) nowy++;
		else nowx++;
	}
//	cout<<"del ymax,ans="<<nowx*nowy<<endl;
	ans=min(ans,nowx*nowy);
	cout<<ans<<endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cout.precision(10);
	int t=1;
	cin>>t;
	LOOP(t)
	{
		solve();
	}
	return 0;
}
