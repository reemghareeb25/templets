#include <iostream>
#include <array>
#include <algorithm>
#include <cmath>
#include <vector>
#include <iomanip>
#include <stack>
#include <deque>
#include <map>
#include<cstdio>
#include <queue>
#include<cstring>
using namespace std;
#define endl '\n'
#define loop(i,k,n) for(ll i=k;i<n;i++)
#define loopr(i,k,n) for(ll i=k;i>=n;i--)
#define clr(v,d) memset(v, d, sizeof(v))
#define fx(x) fixed<<setprecision(x)
#define sz(s) (ll)s.size()
#define all(v) (v).begin(),(v).end()
#define F first
#define S second
#define test int test; cin>>test; while(test--)
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
template<typename T=int>ostream&operator<<(ostream&out,const vector<T>&v){
    for(const T&x:v)out<<x<<" "; return out;}
void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
}
ll gcd(ll x,ll y){
    return(!y?x:gcd(y,x%y));
}
ll lcm(ll x,ll y){
    return x/gcd(x,y)*y;
}
int N = 1e6;
vector<int>is_prime(N,1);
ll fixMod(ll a, ll b){
    return (a % b + b) % b;
}
vector <int> getDiv (int n){
    vector<int>div;
    int i;
    for(i=1;i*i<n;i++){
        if(n%i==0)
            div.push_back(i),div.push_back(n/i);
    }
    if(i*i==n)
        div.push_back(i);
    return div;
} // O(sqrt(n))
vector<int> getMul (int x, int n){
    vector<int>mul;
    for(int i=x;i<=n;i+=x){
        mul.push_back(i);
    }
    return mul;
} // O(n/x)
bool isPrime(int n){
    for(int i=2;i*i<=n;i++){
        if(n%i==0)
            return 0;
    }
    return 1;
} // O(sqrt(n))
void sieve (){
    is_prime[0] = 0, is_prime[1] = 0;
    for(int i = 2; i * i < N; i++){// Nlog(log(N)) ~= N
        if(is_prime[i]){// Nlog(log(N))
            for(int j = i * i; j < N; j += i){// Nlog(N)
                is_prime[j] = 0;
            }
        }
    }
} // O(N)
void print(vector<int>v){
    for(int i=0;i<sz(v);i++)
        cout<<v[i]<<" ";
}
vector<pair<ll,ll>> getPrime_factor(ll n){
    vector<pair<ll,ll>>primeF;
    for(ll i=2;i*i<=n;i++){
        ll c=0;
        while(n%i==0){
            n/=i;
            c++;
        }
        if(c>0){
            primeF.push_back({c,i});
            c=0;
        }
    }
    if(n>1){
        primeF.push_back({1,n});
    }
    return primeF;
} // O(sqrt(n))
int main() {
    init();
    
    return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////

#include <bits/stdc++.h>
using namespace std;


#define ll long long
#define el '\n'


const ll N = 1e5 + 5, M = 1e6 + 5, mod = 1e9 + 7, INF  = 1e9;
ll fact[N], invFact[N];

ll gcd(ll a, ll b){
    if(!b) return a;
    return gcd(b, a % b);
}
ll lcm(ll a, ll b){
    return  a * b / __gcd(a, b);
}
ll add(ll a, ll b, ll m){
    return ((a % m) + (b % m)) % m;
}
ll sub(ll a, ll b, ll m){
    return ((a % m) - (b % m) + m) % m;
}
 
ll mul(ll a, ll b, ll m) {
    return ((a % m) * (b % m)) % m;
}
 
ll fp(ll b, ll p, ll m) { // O(log(p))
    // base case
    if (!p) return 1;
 
    // transition
    ll ret = fp(b, p >> 1, m);
    ret = mul(ret, ret, m);
    if (p & 1) ret = mul(ret, b, m);
    return ret;
}
 
void pre(int m) {
    fact[0] = fact[1] = 1;
    for (int i = 2; i < N; i++)
        fact[i] = mul(fact[i - 1], i, m);
 
    invFact[N - 1] = fp(fact[N - 1], m - 2, m); 
    for (int i = N - 2; i >= 0; i--)
        invFact[i] = mul(invFact[i + 1], i + 1, m);
}
 
ll ncr(ll n, ll r, ll m) { // n! / (r! * (n - r)!)
    if (n < r) return 0;
    return mul(fact[n], mul(invFact[r], invFact[n - r], m), m);
}

ll npr(ll n, ll r, ll m){ // n! / (n - r)!
    if(n < r) return 0;
    return mul(fact[n], modInv(fact[n - r], m), m);
}
void go() {
    pre(mod);
    cout << npr(4, 2, mod) << el;
}
int32_t main() {
    go();
}
