#include <string>
#include <vector>
#include <iostream>

using namespace std;

struct node {

  int parent; // Parent index number
  string data;
  
  // Child node index number
  int left;
  int right;  
  
};

vector<node> Tree;
  
int main() {

  int i = 0; // Current node index number
  int sub = 0; // Next node index number
  int lastParent = 0; // Parent node index number
  
  string y_n;
  
  //////////////////////////
  // Root node
  //
  
  Tree.push_back(node());	// Create root node
  Tree[i].parent = -1; // Root node parent
  
  cout << "Enter data: ";
  
  goto FirstTime;
  
  /////////////////////////

  // Loop until the user no longer wants to add nodes
  do {

    lastParent = Tree[i].parent;

    cout << "\nEnter \"" << Tree[lastParent].data << "\" ";

    if( Tree[lastParent].left == i) {	// aesthetic
      cout << "left child data: ";
    } else {
      cout << "right child data: ";
    }

FirstTime:
    cin >> Tree[i].data;

    cout << "Left child? (y/n): ";
    cin >> y_n;

    if(y_n == "y" || y_n == "Y") {
        sub++;
        Tree[i].left = sub;       
        Tree.push_back(node());	// Create new node
        Tree[sub].parent = i;         
     } else {
        Tree[i].left = 0; // No child node
     }

     cout << "Right child? (y/n): ";
     cin >> y_n;

     if(y_n == "y" || y_n == "Y") {
        sub++;
        Tree[i].right = sub;
        Tree.push_back(node());	// Create new node
        Tree[sub].parent = i;
      } else {
        Tree[i].right = 0;  // No child node
     }

    i++;
    
  } while(i < (int)Tree.size());

  ////////////////////////////////
  //
  // Output:
  
  int size = (int)Tree.size();  // Get Tree size
  lastParent = 0; // Reset lastParent
  
  cout << "\n---------Output----------\n\n";
  
  for(int a=0; a<size; a++) {
  
    // Start a new line if it's a different branch (different parent)
    if(Tree[a].parent != lastParent) {
      lastParent = Tree[a].parent;
      cout << endl << endl;
    }
    
    cout << "(" << a << ")" << Tree[a].data << "   " << Tree[a].left << "   " << Tree[a].right << " ";
    
  }

  cout << endl << endl;

  return 0;
}