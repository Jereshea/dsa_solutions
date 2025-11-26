/******************************************************************************

Trie and Its Implementation
*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

class Trie {
public:
  char data;
  Trie *children[26];
  bool is_terminal_char;

  Trie(char ch) {
    this->data = ch;
    for (int i = 0; i < 26; i++) {
      children[i] = NULL;
    }
    is_terminal_char = false;
  }

  void insert_trie_tree(Trie *root, string word) {
    // base condition
    if (word.length() == 0) {
      root->is_terminal_char = true;
      return;
    }

    // Check if the current char is present
    int index = word[0] - 'a';
    Trie *child;
    // If present, move one node forward
    if (root->children[index] != NULL) {
      child = root->children[index];
    }

    // If not, create a new children
    else {
      child = new Trie(word[0]);
      root->children[index] = child;
    }

    // Recursion
    insert_trie_tree(child, word.substr(1));
  }
  void insert_trie(string word) {
    Trie *root = this;
    insert_trie_tree(root, word);
  }

  bool search_trie_tree(Trie *root, string word) {
    if (word.length() == 0) {
      return root->is_terminal_char;
    }

    // Check if the current char is present
    int index = word[0] - 'a';
    Trie *child;
    // If present, move one node forward
    if (root->children[index] != NULL) {
      child = root->children[index];
    }

    // If not, then the string is not present, so return false
    else {
      return false;
    }

    // Recursion
    return search_trie_tree(child, word.substr(1));
  }

  bool search_trie(string word) {
    Trie *root = this;
    return search_trie_tree(root, word);
  }

  void remove_trie_tree(Trie *root, string word) {
    if (word.length() == 0) {
      root->is_terminal_char = false;
      return;
    }

    int index = word[0] - 'a';
    Trie *child;
    if (root->children[index] != NULL) {
      child = root->children[index];
    } else {
      cout << endl << "The element is not present";
      return;
    }

    // Recursion
    remove_trie_tree(child, word.substr(1));
  }

  void remove_trie(string word) {
    Trie *root = this;
    remove_trie_tree(root, word);
  }
};
int main() {
  cout << "Trie And Its Implementation";
  Trie *t = new Trie('\0');
  t->insert_trie("abcd");
  t->insert_trie("hello");
  t->insert_trie("world");
  cout << endl << "Output: " << t->search_trie("abcd");
  cout << endl << "Output: " << t->search_trie("abc");
  cout << endl << "Output: " << t->search_trie("abcdw");
  cout << endl << "Output: " << t->search_trie("hello");
  t->remove_trie("hello");
  cout << endl << "Output: " << t->search_trie("hello");

  return 0;
}