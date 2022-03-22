//1 based indexing
class BIT{
  int *arr;
  int n = 0;
  public:
  BIT(int s = 1000000){
    arr = new int[s+1];
    for(int i = 0; i < s+1;i++)
      arr[i] = 0;
    n = s;
  }

  void update(int pos,int value){
    for(;pos <= n;pos += (pos&-pos)){
      arr[pos]+=value;
    }
  }
  
  int sum(int pos){
    if(pos==0 || pos > n)
      return 0;
    int sum = 0;
    for(;pos > 0;pos -= (pos&-pos)){
      sum += arr[pos];
    }
    return sum;
  }

  int sum(int a,int b){
    return (sum(b)-sum(a-1));
  }

  ~BIT(){
    delete []arr;
  }
};

//1 based indexing
template<class X>
class COMPRESSEDBIT{
  X *arr;
  int n = 0;
  map<ll,int> rank;
  public:
  COMPRESSEDBIT(vector<X>& number){
    n = init(number);
    arr = new int[n+1];
    memset(arr,0,sizeof(arr));
  }

  int init(vector<X>& arr){
    for(int i = 0;i < arr.size();i++){
      rank[arr[i]] = 1;
    }
    int k = 1;
    for(auto& i:rank)
      i.second = k++;
    return k-1;
  }

  void update(int pos,ll value){
    pos = rank[pos];
    for(;pos <= n;pos += (pos&-pos)){
      arr[pos]+=value;
    }
  }
  
  ll sum(int pos){
    if(pos==0)
      return 0;
    ll answer = 0;
    int big = n;
    for(;big > 0;big -= (big&-big)){
      answer += arr[big];
    }
    pos = rank[pos];
    for(;pos > 0;pos -= (pos&-pos)){
      answer -= arr[pos];
    }
    return answer;
  }
  
  // void print(){
  //   cout<<"size: "<<rank.size()<<endl;
  //   for(auto& i:rank)
  //     cout<<i.first<<" "<<i.second<<endl;
  // }

  // void printArray(){
  //   loop(i,1,n+1,1)
  //     cout<<arr[i]<<" ";
  //   cout<<endl;
  // }

  ~COMPRESSEDBIT(){
    rank.clear();
    delete []arr;
  }
};