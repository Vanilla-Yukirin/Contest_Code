#include<bits[表情]dc++.h>
using namespace std;
#define ll int


signed main(){
	ll T;
	cin>>T;
	while(T--){
		ll n,x,y;
		cin>>n>>x>>y;
		ll p;
		ll yy=y;
		ll b[x+1];
		ll y1=y;
		for(ll i=1;i<=x;i++){
			scanf("%lld",&p);
			b[i]=p;
		}
		sort(b+1,b+1+x);
		ll ans=0;
		ll c[x+1],d[x+1];
		ll cnt=1,ct=1;
		memset(c,0,sizeof(c));
		for(ll i=1;i<=x-1;i++){
			if((b[i+1]-b[i])%2==0){
				c[cnt++]=b[i+1]-b[i];
			}else if(b[i+1]-b[i]>2){
				d[ct++]=b[i+1]-b[i];
			}
		}
		ll ed=n-b[x]+b[1];
		if(ed%2==0) c[cnt++]=ed;
		else if(ed>2) d[ct++]=ed;
		sort(c+1,c+cnt);
		sort(d+1,d+ct);
		for(ll i=1;i<cnt;i++){
			if(y1>=(c[i]/2-1)){
				y1-=c[i]/2-1;
				ans+=c[i]/2;
			}else{
				ans+=y1;
				y1=0;
				break;
			}
		}
		if(y1>0){
			for(ll i=1;i<ct;i++){
				if(y1>=d[i]/2){
					y1-=d[i]/2;
					ans+=d[i]/2;
				}else{
					ans+=y1;
					y1=0;
					break;
				}
			}
		}
		//	cout<<ans<<endl; 
		yy-=y1;
		if((x+yy)>=3) ans+=x+yy-2;
		
		cout<<ans<<endl;
		
	} 
	return 0;
}
