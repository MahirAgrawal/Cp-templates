//n is the number of rows and m is the numbers of columns
void rotate_90_degree_clockwise(pair<int,int>& coord,int n,int m){
  swap(coord.first,coord.second);
  coord.second = n+1-coord.second;
}

void rotate_90_degree_counter_clockwise(pair<int,int>& coord,int n,int m){
  swap(coord.first,coord.second);
  coord.first = m+1-coord.first;
}