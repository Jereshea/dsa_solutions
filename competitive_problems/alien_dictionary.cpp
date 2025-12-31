/******************************************************************************

 Alien dictionary:
 Problem statement
You have been given a sorted (lexical order) dictionary of an alien language.



Write a function that returns the order of characters as a string in the alien
language. This dictionary will be given to you as an array of strings called
'dictionary', of size 'N'.



Example :
If the dictionary consists of the following words:-
["caa", "aaa", "aab"], and 'K' is 3.

Then, the order of the alphabet is -
['c', 'a', 'b']
Note:
If the language consists of four letters, the four letters should be the
starting four letters of the English language.

However, their order might differ in the alien language.
Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1 :
3 1
a aa aaa
Sample Output 1 :
true
Explanation For Sample Output 1 :
The words are 'a', 'aa', and 'aaa'. Since the unique character here is 'a', the
array to be returned will just be ['a'].

The 'true' being printed signifies that the output returned by the function is
valid. Sample Input 2 : 3 3 caa aaa aab Sample Output 2 : true Constraints : 1 ≤
N ≤ 300 1 ≤ K ≤ 26 1 ≤ Length of words ≤ 50

Time Limit: 1 sec

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;
string getAlienLanguage(vector<string> &dictionary, int k) {
  // Write your code here.
  vector<bool> alphabet_visited(26, false);
  string result = "";
  int n = dictionary.size();
  int index = 0;
  int count = 0;

  while (index < n) {
    string str = dictionary[index];
    for (int i = 0; i < str.size(); i++) {
      if (!alphabet_visited[str[i] - 'a'] && count <= k) {
        result += str[i];
        alphabet_visited[str[i] - 'a'] = true;
        count = count + 1;
      }
      if (count > k) {
        return result;
      }
    }
    index = index + 1;
  }

  return result;
}
int main() {
  cout << "Alien dictionary" << endl;
  int k = 3;
  vector<string> dictionary = {"caa", "aaa", "aab"};
  cout << getAlienLanguage(dictionary, k);

  return 0;
}