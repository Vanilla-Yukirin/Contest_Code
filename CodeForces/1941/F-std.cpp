#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
#define int long long
#define pb push_back
#define s second
#define f first
#define pf push_front
#define inf 100000000000000000
#define bitebi __builtin_popcountll
#define FOR( i , n ) for( int i = 0 ; i < n ; i ++ )
#define YES cout <<"YES\n"
#define NO cout << "NO\n"
#define debug cout << "Here Fine" << endl ;
#define pr pair < int , int >
#define fbo find_by_order // returns iterator
#define ook order_of_key // returns strictly less numbers than key
using namespace std ;
//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
using namespace __gnu_pbds;
using namespace __gnu_cxx;
template<class T> using ordered_set =tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update> ;
const double Pi=acos(-1.0);
const double EPS=1E-8;
const int mod =  1000000007 ;
const int mod1 = 998244353 ;
const int N = 2e5 + 10 ;
mt19937 R(time(0));
map < int , int > ma , ma1 ;

int n , m , k ; 
int a[ N ] , b[ N ] , f[ N ] ;
set < int > se ;

void solve(){
	cin >> n >> m >> k ;
	FOR( i , n ) cin >> a[ i ] ;
	FOR( i , m ) cin >> b[ i ] ;
	FOR( i , k ) cin >> f[ i ] ;
	sort( b , b + m ) ;
	sort( f , f + k ) ;
	sort( a , a + n ) ;
	int mx = 0 ;
	FOR( i , n - 1 ){
		mx = max( mx , a[ i + 1 ] - a[ i ] ) ;
	}
	int l , r , cnt = 0 , ot = 0 ; 
	FOR( i , n - 1 ){
		if( ( a[ i + 1 ] - a[ i ] ) == mx ){
			l = a[ i ] , r = a[ i + 1 ] ;
			cnt ++ ; 
		}
		else ot = max( ot , a[ i + 1 ] - a[ i ] ) ; 
	}
	cout<<"mx="<<mx<<" cnt="<<cnt<<endl;
	if( cnt != 1 ){
		cout << mx << "\n" ;
		return ; 
	}
	se.clear() ;
	FOR( i , m ) se.insert( b[ i ] ) ;
	
//	debug ;
	int mn = mx ; 
	FOR( j , k ){
		int x = f[ j ] ;
		int mid = ( l + r ) / 2 ; 
		int nd = mid - x ;
		//if( nd < 0 ) continue ;
		if( *se.begin() >= nd ){
			int axl = *se.begin() + x ;
			if( axl >= l && axl <= r )
				mn = min( mn , max( axl - l , r - axl ) ) ;
		}
		else{
			int axl = *( --se.upper_bound( nd ) ) + x ;
			if( axl >= l && axl <= r )
				mn = min( mn , max( axl - l , r - axl ) ) ;			
		}
		if( se.lower_bound( nd ) != se.end() ){
			int axl = *se.lower_bound( nd ) + x ;
			if( axl >= l && axl <= r )
				mn = min( mn , max( axl - l , r - axl ) ) ;				
		}
	}
	cout << max( mn , ot ) << "\n" ; 
}
signed main() {
	ios_base::sync_with_stdio(0),cin.tie(NULL),cout.tie(NULL);
	int t = 1 ; cin >> t ;
	while( t -- ){
		solve() ;
	}
	
}





