/************

Word ladder I

Given are the two distinct words startWord and targetWord, and a list of size N,
denoting wordList of unique words of equal size M. Find the length of the
shortest transformation sequence from startWord to targetWord.



Keep the following conditions in mind:



A word can only consist of lowercase characters.
Only one letter can be changed in each transformation.
Each transformed word must exist in the wordList including the targetWord.
startWord may or may not be part of the wordList


Note: If there’s no possible way to transform the sequence from startWord to
targetWord return 0.


Example 1

Input: wordList = ["des","der","dfr","dgt","dfs"], startWord = "der", targetWord
= "dfs"

Output: 3

Explanation:

The length of the smallest transformation sequence from "der" to "dfs" is 3
i.e. "der" -> (replace ‘e’ by ‘f’) -> "dfr" -> (replace ‘r’ by ‘s’) -> "dfs".
So, it takes 3 different strings for us to reach the targetWord. Each of these
strings are present in the wordList. Example 2

Input: wordList = ["geek", "gefk"], startWord = "gedk", targetWord= "geek"

Output: 2

Explanation:

The length of the smallest transformation sequence from "gedk" to "geek" is 2
i.e. "gedk" -> (replace ‘d’ by ‘e’) -> "geek" .
So, it takes 2 different strings for us to reach the targetWord. Each of these
strings are present in the wordList.
**************/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int wordLadderLength(string startWord, string targetWord,
                       vector<string> &wordList) {
    set<string> sorted_wordList;
    for (int i = 0; i < wordList.size(); i++) {
      sorted_wordList.insert(wordList[i]);
    }
    // cout<<*sorted_wordList.begin();

    // BFS Traversal
    // vector<int> visited(sorted_wordList.size(),0);
    int result = 1;
    queue<pair<string, int>> q;
    pair<string, int> p = make_pair(startWord, result);
    q.push(p);
    // visited[0]=1;
    // while(!q.empty() && q.front().first!=targetWord){
    while (!q.empty()) {
      string top_val = q.front().first;
      int top_time = q.front().second;
      q.pop();

      if (top_val == targetWord) {
        return top_time;
      }

      for (int i = 0; i < top_val.length(); i++) {
        for (int j = 0; j < 26; j++) {
          string new_word = top_val;
          new_word[i] = 'a' + j;

          auto itr = sorted_wordList.find(new_word);
          if ((itr) != sorted_wordList.end()) {

            int index = distance(sorted_wordList.begin(), itr);

            // if(visited[index]==0){
            //     visited[index]=1;
            sorted_wordList.erase(new_word);
            p = make_pair(new_word, top_time + 1);
            q.push(p);
            // }
          }
        }
      }
    }

    return 0;
  }
};

int main() {
  // your code goes here
  vector<string> wordList = {"des", "der", "dfr", "dgt", "dfs"};
  string startWord = "der";
  string targetWord = "dfs";
  Solution sol;
  cout << sol.wordLadderLength(startWord, targetWord, wordList);
}
