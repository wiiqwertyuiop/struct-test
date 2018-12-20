// Todo: https://www.programiz.com/dsa/trees
//
// Scale down whole tree path
// Value | Pointer or NULL | Pointer or Null

#include <string>
#include <iostream>

using namespace std;

struct node {
  int parent;
  string data;
  int left;
  int right;
  
};

node Tree[3] = { {0, "root", 1, 2},
                 {1, "left", 0, 0},
                 {1, "right", 0, 0}
  
};
  
int main() {
  
  int lastParent = -1;
  
  for(int i=0; i!=3; i++) {
  
    if(Tree[i].parent != lastParent) {
      lastParent = Tree[i].parent;
      cout << endl << endl;
    }
    
    cout << Tree[i].data << "   ";
    
  }

  cout << endl << endl;
  
  return 0;
}