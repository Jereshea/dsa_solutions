/******************************************************************************

Interleave Elements of Queue:
Given a queue q[] of even size. Rearrange the elements by interleaving the first
half with the second half. Note: Interleaving means take one element from the
first half, then one element from the second half, then the next element from
the first half, then the next element from the second half, and continue this
process until the queue is fully rearranged. Examples: Input: q[] = [2, 4, 3, 1]
Output: [2, 3, 4, 1]
Explanation: We place the first element of the first half 2 and after that place
the first element of second half 3 and after that repeat the same process one
more time so the resulting queue will be [2, 3, 4, 1]


Constrain:
1. You are not allowed to use extra queues
2. Only one stack is permitted

Approach
we have
queue 11 12 13 14
STEP:1
Create a stack half
stack 11 12

STEP: 2
push it back to queue
13 14 12 11

STEP: 3
Make it as (popping and pushing back)
12 11 13 14

STEP:4
push it to stack again
12 11
So now
queue 13 14

STEP5:
Push stack to queue, then push the p.top(). Do it alternatively

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

void interleave_elements(queue<int> &q) {
  stack<int> half;

  int mid = q.size() / 2;
  int cnt = 0;
  // STEP: 1
  while (cnt != mid) {
    half.push(q.front());
    q.pop();
    cnt++;
  }

  // STEP: 2
  cnt = 0;
  while (cnt != mid) {
    q.push(half.top());
    half.pop();
    cnt++;
  }

  // STEP: 3
  cnt = 0;
  while (cnt != mid) {
    q.push(q.front());
    q.pop();
    cnt++;
  }

  // STEP:4
  cnt = 0;
  while (cnt != mid) {
    half.push(q.front());
    q.pop();
    cnt++;
  }

  // STEP: 5
  cnt = 0;
  while (cnt != mid) {
    q.push(half.top());
    half.pop();
    q.push(q.front());
    q.pop();
    cnt++;
  }
}

int main() {
  cout << "Interleave Elements of Queue" << endl;
  queue<int> q;
  q.push(11);
  q.push(12);
  q.push(13);
  q.push(14);

  interleave_elements(q);

  while (!q.empty()) {
    cout << q.front() << " ";
    q.pop();
  }

  return 0;
}