/******************************************************************************

UnOrdered Mapping -> Time Complexity: O(1)
Ordered Mapping -> Time Complexity: O(log n)
*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;
int main() {
  cout << "HashMaps";
  map<string, int> h_map;
  // unordered_map<string,int> h_map;

  // Insertion
  // Method 1
  h_map["hi"] = 1;
  // Method 2
  pair<string, int> p = make_pair("I", 2);
  h_map.insert(p);
  // Method 3
  pair<string, int> p2("went", 3);
  h_map.insert(p2);

  // Reassignment
  h_map["hi"] = 0;

  // Search
  cout << h_map["hi"] << endl;
  cout << h_map.at("hi") << endl;

  // To get size
  cout << "Size: " << h_map.size() << endl;

  // To check whether the key is present or not [if its present, it gives 1,
  // else it gives 0]
  cout << h_map.count("hi") << endl;  // prints 1
  cout << h_map.count("out") << endl; // prints 0

  // To delete
  h_map.erase("hi");

  // If key which is not inserted is called, then if it is in array format it
  // gives 0. If it is called using "at", then it gives error messgae

  // Comment below 2 lines, and observe the result
  // cout<<h_map.at["hello"];
  // cout<<h_map["hello"];

  // Comment above 2, and observe the results
  cout << h_map["hello"] << endl;
  cout << h_map.at("hello") << endl;
  h_map["hello"]++;
  cout << h_map["hello"] << endl;

  // To print
  // Method 1
  for (auto i : h_map) {
    cout << i.first << " " << i.second << endl;
  }

  // Method 2
  cout << endl;
  map<string, int>::iterator it = h_map.begin();
  // unordered_map<string, int> :: iterator it=h_map.begin();
  while (it != h_map.end()) {
    cout << it->first << " " << it->second << endl;
    it++;
  }

  return 0;
}