class DSU{
  public:
  int *parent;
  int *height;
  int n = 0;
  DSU(int s = 200005){
    n = s;
    parent = new int[n+5];
    height = new int[n+5];
    loop(i,1,n+1,1){
      parent[i] = i;
      height[i] = 1;
    }
  }

  int find_set(int v){
    if(v == parent[v])
      return v;
    return parent[v] = find_set(parent[v]);//path compression while finding the parent
  }

  //returns true if it was successful in merging the two sets
  bool union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
      if (height[a] < height[b])
          swap(a, b);
      parent[b] = a;
      if(height[a] == height[b]) 
        height[a]++;
      return true;
    }
    else
      return false;
  }

  ~DSU(){
    delete []parent;
    delete []height;
  }
};