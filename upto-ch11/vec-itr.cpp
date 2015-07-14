#include <vector>

int main(){
  typedef std::vector<int> Num_list;
  
  Num_list nlist;
  for(Num_list::const_iterator it = nlist.begin(); it != nlist.end(); ++it)
    ;
  
  return 0;
}