/*
Good Resources : aquarchitect.github.com, Youtube Utkarsh Gupta Sparse Table
Sparse Table takes use of dynamic Table and property of binary segments
Any segment of query can be broken into powers of 2 because any length can be
represented in binary number and we can have specific jump to reach from Left to Right
of query segment.

Hence we use this fact to build sparse Table. We don't precompute all
N^2 segments i.e. Dense Table(funny name huh?) but store only the important 
NLogN segments which is why the name "Sparse Table".

Also if function is idempotent then we can achieve O(1) for queries and this is why
sparse table is used.
Moreover it is not a ONLINE DATASTRUCTURE that is we cannot update the table. Because
the all intervals are built on already computed smaller intervals so if a element is
changed we have to update all segments in which it is coming as element and also
recompute all segment which makes use of that element. Overall NLogN updates which is
equivalent to rebuild the table.

Hence there we use SEGMENT TREE as it has lazy propogation but still who knows someone
discovers sparse table which is updatable(it can be me!! ;) )


                          ZERO VALUE OF FUNCTION
Here initialise with function's zero value that is the value which will never 
interfere with the ans.
For e.g if min(L,R) then we initialize with INT_MAX which eventually
fades out. 
For AND we can used 1 as initialization etc
*/



//changes to be made before using: 
//1)N if space is limited
//2)Function in build() and query() as per the requirement
//3)Zero value of function in initialization of ans variable in LogN query

//Change the max size and max jump of dp table by macro N
#define N 1000000 // ***change
int dp[N][__lg(N)+5];
int MAXJUMP = 0;
//@TestingPurpose
void print(int n){
  for(int i = 0;i < n;i++){
    for(int j = 0;i + (1<<j) - 1 < n;j++){
      cout<<dp[i][j]<<" ";
    }
    cout<<endl;
  }
}

void build(vector<int>& arr){
  int n = (int)arr.size();
  MAXJUMP = __lg(n);
  for(int i = 0;i < n;i++){
    dp[i][0] = arr[i];
  }
  for(int j = 1;j <= MAXJUMP;j++){
    for(int i = 0;i+(1<<j)-1 < n;i++){
      dp[i][j] = min(dp[i][j-1],dp[i+(1<<(j-1))][j-1]);  /* ***change operation here to build sparse table*/
    }
  }
  print(n);
}

/*
O(LogN*OPERATION) because we merge the segments with operator given
to find the operation answer all over range [L,R]

for all kinds of functions but generally for non idempotent
like sum,subtraction,xor etc because idempotent can be done in ~O(1)
*/
int query(int l,int r){
  int ans = ;//__FUNCTION'S__ ZERO VALUE READ ABOVE ***change
  for(int i = MAXJUMP;i >= 0 && l <= r;i--){
    if(l+(1<<i)-1 <= r){
      ans = min(dp[l][i],ans);// ***change
      l += (1<<i);
    }
  }
  return ans;
}

/*
O(OPERATION) because we merge two segments with operator given
to find the operation answer all over range [L,R]
Only for idempotent functions like min,max,And,Or,GCD for range [L,R]
*/
int fquery(int l,int r){
  int jump = __lg(r-l+1);
  return (min(dp[l][jump],dp[r-(1<<jump)+1][jump])); //***change
}