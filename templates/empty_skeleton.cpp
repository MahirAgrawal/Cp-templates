//switch between terminal and editor: ctrl + ` 
#include"bits/stdc++.h"
#define endl '\n'
using namespace std;
typedef long long ll;
#define comparator_datatype pair<ll,ll> 
#define loop(i,x,n,u) for(ll i = x;i < n;i+=u)
#define rloop(i,x,n,u) for(ll i = x;i > n;i-=u)
#define mod 1000000007
#define read(X,n) loop(i,0,n,1){cin>>X[i];}
#define __builtin_popcount(x) __builtin_popcountll(x)
// #pragma GCC optimize ("Ofast")
// #pragma GCC target ("avx2")

//check if you missed reading input(Most of the time)
//Check for integer overflow
//Modular subtraction can produce negative numbers. So add mod to get positive
//check user defined comparator, check for segmentation fault

bool comparator_2(comparator_datatype& a,comparator_datatype& b){
  return (a.second < b.second);
}

bool comparator_1(comparator_datatype& a,comparator_datatype& b){
  return (a.first < b.first);
}

void compressArray(vector<ll>& array){
  map<ll,int> rank_;
  for(auto& i:array){
    rank_[i] = 1;
  }
  int r = 1;
  for(auto& i:rank_){
    i.second = r++;
  }
  loop(i,0,array.size(),1){
    array[i] = rank_[array[i]];
  }
}

//void solve(){}
int main(){
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  int t = 1;
  //cin>>t;
  while(t--){
    //solve();
  }
  return 0;
}