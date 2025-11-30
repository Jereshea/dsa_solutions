/******************************************************************************

Printing the string in Trie:


*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

class Trie {
public:
  char data;
  Trie *arr[26];
  bool is_terminal;

  Trie(char data) {
    this->data = data;
    for (int i = 0; i < 26; i++) {
      arr[i] = NULL;
    }
    is_terminal = false;
  }

  void insert_trie_char(Trie *root, string word) {
    if (word.length() == 0) {
      root->is_terminal = true;
      return;
    }
    // hello
    //  hel
    int index = word[0] - 'a';
    Trie *new_root;

    if (root->arr[index] == NULL) {
      root->arr[index] = new Trie(word[0]);
      new_root = root->arr[index];
    } else {
      new_root = root->arr[index];
    }
    insert_trie_char(new_root, word.substr(1));
  }

  void insert_trie(string word) {
    Trie *root = this;
    insert_trie_char(root, word);
  }

  void print_trie_string(Trie *root, string new_word, vector<string> &output) {
    if (root->data != '\0') {
      new_word.push_back(root->data);
    }
    if (root->is_terminal) {
      output.push_back(new_word);
    }

    for (int i = 0; i < 26; i++) {
      if (root->arr[i] != NULL) {
        print_trie_string(root->arr[i], new_word, output);
      }
    }
  }
  void print_trie() {
    Trie *root = this;
    vector<string> output;

    print_trie_string(root, "", output);
    for (string &m : output) {
      cout << m << endl;
    }
  }
};
int main() {
  cout << "Printing the strings in Trie";
  Trie *t = new Trie('\0');
  t->insert_trie("hello");
  t->insert_trie("hel");
  t->insert_trie("abcd");
  cout << endl;
  t->print_trie();
  return 0;
}