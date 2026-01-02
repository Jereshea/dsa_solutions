/******************************************************************************

Trie Implementation
*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

class Trie {
public:
  bool is_terminal_char;
  Trie *children[26];

  Trie() {
    for (int i = 0; i < 26; i++) {
      children[i] = NULL;
    }
    is_terminal_char = false;
  }
  ~Trie() {
        // Recursive destructor to free memory
        for (int i = 0; i < 26; i++)
            if (children[i])
                delete children[i];
    }
};

void insert_trie(Trie *root, string s1) {
  Trie *curr = root;
  if (s1.size() == 0) {
    curr->is_terminal_char = true;
    return;
  }

  int index = s1[0] - 'a';
  if (curr->children[index] != NULL) {
    curr = curr->children[index];
  } else {
    Trie *temp = new Trie();
    // temp->children[index]=s1[0];
    curr->children[index] = temp;
    curr = curr->children[index];
  }

  insert_trie(curr, s1.substr(1));
}

bool search_trie(Trie *root, string s1) {

  Trie *curr = root;
  if (s1.size() == 0) {
    return curr->is_terminal_char;
  }

  int index = s1[0] - 'a';

  if (curr->children[index] == NULL) {
    return false;
  } else {
    curr = curr->children[index];
  }

  return search_trie(curr, s1.substr(1));
}

bool remove_trie(Trie *root, string s1) {
  Trie *curr = root;

  if (s1.size() == 0) {
    curr->is_terminal_char = false;
    for (int i = 0; i < 26; i++) {
      if (curr->children[i] != NULL) {
        return true;
      }
    }
    return false;
  }
  int index = s1[0] - 'a';

  Trie *child = curr->children[index];
  if (child == NULL) {
    return true;
  }
  bool is_delete = remove_trie(child, s1.substr(1));

  if (!is_delete) {
    delete child;
    curr->children[index] = NULL;
  }

  if (curr->is_terminal_char) {
    return true;
  }
  for (int i = 0; i < 26; i++) {
    if (curr->children[i] != NULL) {
      return true;
    }
  }
  return false;
}
void trie_implementation(vector<string> &strings) {
  Trie *root = new Trie();

  for (int i = 0; i < strings.size(); i++) {
    insert_trie(root, strings[i]);
    cout << endl << "Inserted: " << strings[i];
  }

  cout << endl << "Searched: hello -> " << search_trie(root, "hello");
  cout << endl << "Searched: hell -> " << search_trie(root, "hell");
  cout << endl << "Removed: hello -> " << remove_trie(root, "hello");
  cout << endl << "Removed: computer -> " << remove_trie(root, "computer");
  cout << endl << "Searched: hello -> " << search_trie(root, "hello");
  cout << endl << "Searched: helloworld -> " << search_trie(root, "helloworld");
  cout << endl << "Searched: computer -> " << search_trie(root, "computer");
}

int main() {
  cout << "Trie Implementation";
  vector<string> strings = {"hello", "helloworld", "computer"};
  trie_implementation(strings);

  return 0;
}