class LCA{
  public:
  //0 represents invalid parent which will indicate if reached to root
  int max_jump,N;//user will fill this via declaring class variable
  vector<int> parent,depth;//can be found by edges info
  vector<vector<int>> child,up;
  LCA(int nodes_n = 200000){
  //assuming nodes are numbered from 1,...,N
    N = nodes_n;
    max_jump=20;
    parent = vector<int>(N+1,-1);
    depth = vector<int>(N+1,0);
    child = vector<vector<int>>(N+1);
    up = vector<vector<int>>(N+1,vector<int>(max_jump,0));
    //here define your input reading method inside getEdge() 
    getEdge(/*N-1*/);//give parameter as number of edges to read
    
    //start dfs with 1 node
    parent[1] = 0;dfs(1);
    
    // for(auto& i:depth)
    //   cout<<i<<" ";
    // cout<<endl;
    // print();
  }

  void print(){
    for(auto& i:up){
      for(auto &j:i)
        cout<<j<<" ";
      cout<<endl;
    }
  }

  void getEdge(int edges){
    int a,b;
    loop(i,0,edges,1){
      cin>>a>>b;
      child[a].push_back(b);
      child[b].push_back(a);
    }
  }
  
  //Preprocessing the nodes to get every node mapped with 2^i jumps 
  void dfs(int node){
    if(!parent[node]){//for root as it has no node up above it so zero indicates that
      loop(i,0,max_jump,1)
        up[node][i] = 0;
      depth[node]=0;
      for(auto& c:child[node]){
        if(parent[c] == -1){
          parent[c] = node;
          dfs(c);
        }
      }
      return;
    }
    up[node][0] = parent[node];
    depth[node]=depth[parent[node]]+1;
    //store the node which can be reached with jumps: 2^1,2^2,...
    int jump = 1,curr_node = parent[node];

    while(curr_node && jump < max_jump){
      up[node][jump] = up[curr_node][jump-1];
      curr_node = up[node][jump++];
    }

    //dfs all the childs also
    for(auto& c:child[node]){
      if(parent[c] == -1){
        parent[c] = node;
        dfs(c);
      }
    }
  }

  int jump(int node,int order){
    int mask = 1;
    loop(i,0,max_jump,1){
      if(mask&order){
        node = up[node][i];
      }
      mask<<=1;
      if(node == 0)
        break;
    }
    return node;
  }

  int lca(int a,int b){
    if(depth[a] < depth[b])
      swap(a,b);
    a = jump(a,depth[a]-depth[b]); 
    if(a==b)//one is the ancestor of other
      return a;
    else{
      for(int max_j = max_jump-1;max_j > -1;--max_j){
        if(up[a][max_j]!=up[b][max_j]){
          a=up[a][max_j];
          b=up[b][max_j];
        }
      }
      return up[a][0];
    }
  }
};