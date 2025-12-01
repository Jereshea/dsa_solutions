/******************************************************************************

Given two strings s and t, return true if s is a subsequence of t, or false
otherwise.

A subsequence of a string is a new string that is formed from the original
string by deleting some (can be none) of the characters without disturbing the
relative positions of the remaining characters. (i.e., "ace" is a subsequence of
"abcde" while "aec" is not).



Example 1:

Input: s = "abc", t = "ahbgdc"
Output: true
Example 2:

Input: s = "axc", t = "ahbgdc"
Output: false

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool sequence(int start, int end, string s, string t, string output) {
    if (s == output) {
      return true;
    }
    if (start > t.size()) {
      return false;
    }

    output.push_back(t[start]);
    if (sequence(start + 1, end, s, t, output)) {
      return true;
    }
    output.pop_back();
    if (sequence(start + 1, end, s, t, output)) {
      return true;
    }
    return false;
  }
  bool isSubsequence(string s, string t) {
    string output;
    return sequence(0, t.size(), s, t, output);
  }
};
int main() {
  cout << "Subsequence" << endl;
  string s = "abc";
  string t = "ahbgdc";
  // string s = "axc";
  // string t = "ahbgdc";
  Solution sol;
  cout << sol.isSubsequence(s, t);

  return 0;
}