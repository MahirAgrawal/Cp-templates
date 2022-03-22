//for unweighted and undirected graph
class Graph{
  public:
  int n;
  vector<vector<int>> adjacency_list;
  vector<bool> visited;
  bool Bipartite = true;
  
  Graph(int n = 100000){
    this -> n = n;
    adjacency_list = vector<vector<int>>(n+1);
    visited = vector<bool>(n+1,0);
    Bipartite = true;
  }

  void insert_edge(int m = 1){
    int a,b;
    loop(i,0,m,1){
      cin>>a>>b;
      adjacency_list[a].push_back(b);
      adjacency_list[b].push_back(a);
    }
  }
  
  //returns the number of connected components
  //also recognizes the graph is bipartite or not by just performing coloring
  //also you can place any calculation while discovering neighbours 
  //O(N+M)
  int BFS(){
    //for tracing purposes maintaining parent of each discovered vertex
    fill(visited.begin(),visited.end(),0);
    int parent[n+1]= {0},count = 0;
    vector<bool> color(n+1,0);
    loop(i,1,n+1,1){
      if(!visited[i]){
        count++;
        visited[i] = 1;
        color[i] = 0;
        parent[i] = -1;
        queue<int> q;q.push(i);
        while(!q.empty()){
          auto focus = q.front();
          for(auto& k: adjacency_list[focus]){
            if(!visited[k]){
              visited[k] = 1;
              color[k] = !color[focus];
              parent[k] = focus;
              q.push(k);
            }
            else if(color[k] == color[focus]){
              Bipartite = false;
            }
          }
          q.pop();
        }
      }
    }
    //it has reached here that means that we can color the vertices into two colors such
    //that every edge has different colors on both of its end point
    //Also it implies that graph doesn't have odd length cycle
    return count;
  }
  
  bool isBipartite(){
    int c = BFS();
    return Bipartite;
  }
};

//for unweighted and directed graph
class Graph{
  public:
  int n;
  vector<vector<int>> adjacency_list;
  vector<int> visited,parent;
  //for tracing purposes maintaining parent of each discovered vertex  
  Graph(int n = 100000){
    this -> n = n;
    adjacency_list = vector<vector<int>>(n+1);
    visited = vector<int>(n+1,0);
    parent = vector<int>(n+1,0);
  }

  void insert_edge(int a,int b){
    adjacency_list[a].push_back(b);
  }
  
  bool hascycle(){
    fill(visited.begin(),visited.end(),0);
    loop(i,1,n+1,1){
      if(visited[i]==0){
        if(DFS(i)) return true;
      }
    }
    return false;
  }

  //returns whether the graph has cycles
  bool DFS(int v = 1){
    visited[v] = 1;
    for(auto& k: adjacency_list[v]){
      if(visited[k] == 0){
        parent[k] = v;
        if(DFS(k)) return true;
      }
      else if(visited[k] == 1){
        return true;
      }
    }
    visited[v] = 2;
    return false;
  }
};

//Euler tour / flattening the tree
//Each node has start time and end time so two occurrences of node and in between
//all nodes which are present in the subtree of that node

 
//just call this function with root node to start dfs with and the adjacency list


// dfs(root,adjacency_list);

int MAX_N = 200001;
vector<pair<int,int>> time_interval(MAX_N);// store the entry and leaving time of every node. Subtracting end-start+1 gives the size of subtree of particular node
vector<bool> visited(MAX_N,0);// keep check on visited nodes for dfs
vector<ll> distance_(MAX_N,0); // distance of every node from root node of dfs

int timer = 0;// for keeping count of time
void dfs(int node,vector<vector<int>>& arr){
  visited[node] = true;
  time_interval[node].first = timer;
  for(auto& i: arr[node]){
    if(!visited[i]){
      timer++;
      distance_[i] = distance_[node]+1;
      dfs(i,arr);
    }
  }
  time_interval[node].second = timer;
}