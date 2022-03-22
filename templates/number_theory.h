//switch between terminal and editor: ctrl + ` 
#define endl '\n'
using namespace std;
typedef long long ll;

//          <---- contents: ----->
//divisors of a number
//factorial
//isPrime
//primes between 1..n sieve
//primeFactor O(sqrt(n))
//primeFactor sieve
//modular power in O(logN)
//modular division

//for testing purpose only as it takes O(sqrt(n))
vector<int> get_divisor(int n){
  int l = sqrt(n);
  vector<int> div;
  loop(i,1,l+1,1){
    if(n%i == 0){
      div.push_back(i);
      if(n/i != i)
        div.push_back(n/i);
    }
  }
  return div;
}

//O(n)
ll factorial(ll n,ll m){
  ll answer = 1;
  for(int i = 1; i < n+1;i++){
    answer = (answer * i) % m;
  }
  return answer;  
}

//O(sqrt(n))
bool isPrime(ll n){
  if(n==2)
    return true;
  else if(!(n&1))
    return false;
  ll limit = sqrt(n);
  for(ll i = 3;i <= limit;i+=2)
    if(n%i == 0)
      return false;
  return true;
}

//O(sqrt(n))
map<ll,ll> factor;//-->this contains all prime factors with their frequencies
void primeFactor(ll n){
  factor.clear();
  while(!(n&1)){
    factor[2]++;
    n >>= 1;
  }
  for(ll i = 3;i <= sqrt(n);i+=2){
    while(n % i == 0){
      factor[i]++;
      n /= i;
    }
  }
    if(n != 1)
      factor[n]++;
}

//prime factor of n <= 1000000
unsigned int sp[1000001] = {0};
//call this method first and then we can find any prime factorization in O(logN)
void sieve(){
  int n = 1000001;
  int limit = sqrt(n);
  for(int i = 2;i <= limit;i++){
    if(sp[i])
      continue;
    sp[i] = i;
    for(int j = i*i;j <= n;j+=i)
      if(!sp[j])
        sp[j] = i;
  }
  for(int i = limit;i < n;i++)
    if(!sp[i])
      sp[i] = i;
}

//O(logN) after sieve precomputation
void primeFactorSieve(int n){
  factor.clear();
  while(n != 1){
    factor[sp[n]]++;
    n /= sp[n];
  }
}

//primes between 1..1000000
bitset<1000001> primeNumber;
vector<int> primeslist;
void sieve(int n){
  primeslist.clear();
  int limit = sqrt(n);
  for(int i = 2;i <= limit;i++){
    if(primeNumber[i])
      continue;
    for(int j = i*i;j <= n;j+=i)
      primeNumber[j] = 1;
  }
  for(int i = 2;i <= n;i++)
    if(!primeNumber[i])
      primeslist.push_back(i);
}

ll power(ll a,ll b,ll m) {
  a %= m;
  ll res = 1;
  while (b > 0) {
    if (b & 1)
        res = res * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return res;
}

ll divmod(ll a,ll b,ll m){
  return (a%m * power(b,m-2,m))%m;
}

long long mult(long long a, long long b, long long m) {
    long long result = 0;
    while (b) {
        if (b & 1)
            result = (result + a) % m;
        a = (a + a) % m;
        b >>= 1;
    }
    return result;
}
long long f(long long x, long long c, long long m) {
    return (mult(x, x, m) + c) % m;
}

long long rho(long long n, long long x0=2, long long c=1) {
    long long x = x0;
    long long y = x0;
    long long g = 1;
    while (g == 1) {
        x = f(x, c, n);
        y = f(y, c, n);
        y = f(y, c, n);
        g = __gcd(abs(x - y), n);
    }
    return g;
}

// ll power(ll a,ll b,ll m){
//   if(b == 0)
//     return 1;
//   ll ans = power(a,b/2,m);
//   ans = ((ans%m) * (ans%m))%m;
//   if(b&1)
//     ans = (ans%m * a%m)%m;
//   return ans;
// }

// int main(){
//   std::ios::sync_with_stdio(false);
//   cin.tie(0);
//   #ifndef ONLINE_JUDGE
//   freopen("input.txt", "r", stdin);
//   freopen("output.txt", "w", stdout);
//   #endif
//   int t = 1;
//   //cin>>t;
//   while(t--){
//     //solve();
//     // ll a,b;
//     // cin>>a>>b;
//     // cout<<power(a,b,mod);
//     ll n;cin>>n;
//     sieve();
//     primeFactorSieve(n);
//     for(auto& i:factor)
//       cout<<i.first<<" "<<i.second<<endl;
//   }
//   return 0;
// }