bool palindrome(string& str){
  bool flag=true;
  loop(i,0,str.size()/2,1)
    flag &= (str[i]==str[str.size()-1-i]);
  return flag;
}
