#include <iostream>
#include <unordered_map>
using namespace std;
  
int main()
{
    // Declaring umap to be of <string, int> type
    // key will be of string type and mapped value will
    // be of int type
    unordered_map<string, int> umap;
  
    umap["GeeksforGeeks"] = 10;
    umap["Practice"] = 20;
    // inserting values by using [] operator

    umap["Contribute"] = 30;
  
    // Traversing an unordered map
    for (auto x : umap)
      cout << x.first << " " << x.second << endl;
  
}
