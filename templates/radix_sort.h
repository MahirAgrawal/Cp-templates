#include<bits/stdc++.h>
#include<chrono>
using namespace std;

//subroutine: sorting by a particular position or base of numbers
template<class X>
void sort_by_base(X *array,int N,long long& to_divide){
  int frequency[10] = {0};
  int *arr = new int[N];
  for(int i = 0;i < N;i++)
    arr[i] = array[i];
  for(int i = 0;i < N;i++)
    frequency[(array[i]/to_divide) % 10]++;
  for(int i = 1;i < 10;i++)
    frequency[i] += frequency[i-1];
  for(int i = N-1;i >= 0;i--)
    array[--frequency[(arr[i]/to_divide) % 10]] = arr[i];
  delete []arr;
}

template<class X>
void RadixSort(X *array,int N){
  X max_element = array[0];
  for(int i = 1;i < N;i++)
    if(array[i] > max_element)
      max_element = array[i];
  
  long long to_divide = 1;
  while(max_element != 0){
    sort_by_base(array,N,to_divide);
    to_divide *= 10;
    max_element /= 10;
    //cout<<"sorting by base: "<<to_divide<<endl;
  }
}