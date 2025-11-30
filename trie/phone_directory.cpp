/******************************************************************************
Phone directory

Given a list of contacts contact[] of length n where each contact is a string
which exist in a phone directory and a query string s. The task is to implement
a search query for the phone directory. Run a search query for each prefix p of
the query string s (i.e. from  index 1 to |s|) that prints all the distinct
contacts which have the same prefix as p in lexicographical increasing order.
Please refer the explanation part for better understanding. Note: If there is no
match between query and contacts, print "0".

Example 1:

Input:
n = 3
contact[] = {"geeikistest", "geeksforgeeks",
"geeksfortest"}
s = "geeips"
Output:
geeikistest geeksforgeeks geeksfortest
geeikistest geeksforgeeks geeksfortest
geeikistest geeksforgeeks geeksfortest
geeikistest
0
0
Explaination: By running the search query on
contact list for "g" we get: "geeikistest",
"geeksforgeeks" and "geeksfortest".
By running the search query on contact list
for "ge" we get: "geeikistest" "geeksforgeeks"
and "geeksfortest".
By running the search query on contact list
for "gee" we get: "geeikistest" "geeksforgeeks"
and "geeksfortest".
By running the search query on contact list
for "geei" we get: "geeikistest".
No results found for "geeip", so print "0".
No results found for "geeips", so print "0".


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

  void print_trie_string(Trie *root, string new_word, vector<string> &output,
                         string phone_word) {
    if (root->data != '\0') {
      new_word.push_back(root->data);
    }
    if (root->is_terminal) {
      output.push_back(new_word);
    }

    for (int i = 0; i < 26; i++) {
      if (root->arr[i] != NULL) {
        print_trie_string(root->arr[i], new_word, output, phone_word);
      }
    }
  }
  void print_trie() {
    Trie *root = this;
    string new_word = "";
    string phone_word = "geeips";
    // string phone_word="hellx";
    for (int i = 0; i < phone_word.length(); i++) {
      cout << endl;
      //  new_word.push_back(phone_word[i]);
      int index = phone_word[i] - 'a';
      vector<string> output;
      if (root->arr[index] != NULL) {
        print_trie_string(root->arr[index], new_word, output, phone_word);
        root = root->arr[index];
        new_word.push_back(phone_word[i]);
      } else {
        output.push_back("0");
      }

      for (string &m : output) {
        cout << m << " ";
      }
    }
    // print_trie_string(root, "", output, "hello");
  }
};
int main() {
  cout << "Printing the strings in Trie";
  Trie *t = new Trie('\0');
  t->insert_trie("geeikistest");
  t->insert_trie("geeksforgeeks");
  t->insert_trie("geeksfortest");
  // t->insert_trie("hello");
  // t->insert_trie("hel");
  // t->insert_trie("abcd");
  //     contact[] = {"geeikistest", "geeksforgeeks",
  // "geeksfortest"}
  // s = "geeips"
  cout << endl;
  t->print_trie();
  return 0;
}