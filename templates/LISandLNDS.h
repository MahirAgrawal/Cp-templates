//cp template for longest increasing subsequence
int lis(vector<int>& arr){
  map<int,int> m;//to get the mapping of end element of sequence with its length
  for(auto& i: arr){
    if(m.empty()){
      m[i] = 1;
      continue;
    }
    auto it = m.lower_bound(i);
    if(it!=m.end()){
      if(it->first>i){
        if(it!=m.begin()){
          it--;
          m[i]=it->second+1;
        }
        else{
          m[i] = 1;
        }
      }
      else{
        continue;
      }
      it = m.upper_bound(i);
      for(;it!=m.end();){
        if(it->second<=m[i]){
          it = m.erase(it);
        }
        else{
          break;
        }
      }
    }
    else{
      int temp = m.rbegin()->second+1; 
      m[i] = temp;
    }
  }
  int len = 1;
  for(auto& i: m){
    // cout<<i.first<<" "<<i.second<<endl;
    len = max(len,i.second);
  }
  return len;
}

//cp template for longest non decreasing subsequence
int lnds(vector<int>& arr){
  map<int,int> m;//to get the mapping of end element of sequence with its length
  for(auto& i: arr){
    if(m.empty()){
      m[i] = 1;
      continue;
    }
    auto it = m.lower_bound(i);
    if(it!=m.end()){
      if(it->first>i){
        if(it!=m.begin()){
          it--;
          m[i]=it->second+1;
        }
        else{
          m[i] = 1;
        }
      }
      else{
        m[i]=it->second+1;
      }
      it = m.upper_bound(i);
      for(;it!=m.end();){
        if(it->second<=m[i]){
          it = m.erase(it);
        }
        else{
          break;
        }
      }
    }
    else{
      int temp = m.rbegin()->second+1; 
      m[i] = temp;
    }
  }
  int len = 1;
  for(auto& i: m){
    // cout<<i.first<<" "<<i.second<<endl;
    len = max(len,i.second);
  }
  return len;
}
