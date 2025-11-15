/******************************************************************************

Median in a Data Stream:

The median is the middle value in an ordered integer list. If the size of the
list is even, there is no middle value, and the median is the mean of the two
middle values.

For example, for arr = [2,3,4], the median is 3.
For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.
Implement the MedianFinder class:

MedianFinder() initializes the MedianFinder object.
void addNum(int num) adds the integer num from the data stream to the data
structure. double findMedian() returns the median of all elements so far.
Answers within 10-5 of the actual answer will be accepted.


Example 1:

Input
["MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"]
[[], [1], [2], [], [3], []]
Output
[null, null, null, 1.5, null, 2.0]

Explanation
MedianFinder medianFinder = new MedianFinder();
medianFinder.addNum(1);    // arr = [1]
medianFinder.addNum(2);    // arr = [1, 2]
medianFinder.findMedian(); // return 1.5 (i.e., (1 + 2) / 2)
medianFinder.addNum(3);    // arr[1, 2, 3]
medianFinder.findMedian(); // return 2.0

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

class MedianFinder {
public:
  vector<int> arr;
  priority_queue<int> max_heap;
  priority_queue<int, vector<int>, greater<int>> min_heap;
  double median;

  MedianFinder() { median = -1; }

  void addNum(int data) {

    if (max_heap.empty() || data < max_heap.top()) {
      max_heap.push(data);
    } else {
      min_heap.push(data);
    }

    // Balance the tree
    if (max_heap.size() > min_heap.size() &&
        (max_heap.size() - min_heap.size() > 1)) {
      min_heap.push(max_heap.top());
      max_heap.pop();
    }
    if (min_heap.size() > max_heap.size() &&
        (min_heap.size() - max_heap.size() > 1)) {
      max_heap.push(min_heap.top());
      min_heap.pop();
    }
  }

  double findMedian() {
    if (min_heap.size() == max_heap.size() && !min_heap.empty()) {
      median = (min_heap.top() + max_heap.top()) / 2.0;
    } else if (min_heap.size() > max_heap.size()) {
      median = min_heap.top();
    } else if (min_heap.size() < max_heap.size()) {
      median = max_heap.top();
    } else {
      median = -1;
    }
    cout << endl << "Median: " << median;
    return median;
  }
};
int main() {
  cout << "Median in a Data Stream";
  MedianFinder *medianFinder = new MedianFinder();
  medianFinder->addNum(1);    // arr = [1]
  medianFinder->addNum(2);    // arr = [1, 2]
  medianFinder->findMedian(); // return 1.5 (i.e., (1 + 2) / 2)
  medianFinder->addNum(3);    // arr[1, 2, 3]
  medianFinder->findMedian(); // return 2.0

  return 0;
}