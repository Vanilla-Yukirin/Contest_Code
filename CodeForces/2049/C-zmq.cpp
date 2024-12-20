// code from zmq
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	ll T;
	cin>>T;
	while(T--){
		ll n,x,y;
		cin>>n>>x>>y;
		ll a[n+1];
		for(ll i=1;i<=n-1;i+=2){
			a[i]=0;
			a[i+1]=1;
		}
		
		if(x%2==y%2&&n%2==0){
			a[y]=2;
		}
		if(n%2==1){
			for(ll i=1;i<=n-1;i++) {
				cout<<a[i]<<" ";
				if(i==x&&x%2==y%2) cout<<2<<" ";
			}
			if(x%2!=y%2) cout<<2<<" ";
		}else{
			for(ll i=1;i<=n;i++) cout<<a[i]<<" ";
		}
		cout<<endl;
	}
}
