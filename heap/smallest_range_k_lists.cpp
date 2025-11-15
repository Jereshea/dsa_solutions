/******************************************************************************

Smallest Range Covering Elements from K Lists

You have k lists of sorted integers in non-decreasing order. Find the smallest
range that includes at least one number from each of the k lists. We define the
range [a, b] is smaller than range [c, d] if b - a < d - c or a < c if b - a ==
d - c.

Example 1:

Input: nums = [[4,10,15,24,26],[0,9,12,20],[5,18,22,30]]
Output: [20,24]
Explanation:
List 1: [4, 10, 15, 24,26], 24 is in range [20,24].
List 2: [0, 9, 12, 20], 20 is in range [20,24].
List 3: [5, 18, 22, 30], 22 is in range [20,24].

Algorithm:
1) First push all the first elements of k lists to the min heap
2) Parallely track the max element among the pushed elememts
3) Store min(ans,max-min) to ans
4) Pop the min element from the min_heap and push the next element from the same
row of the popped element 5) Repeat 2-4 till any of the row becomes completely
pushed to the min_heap 6) Return the ans

[Why only min element is moved forward?
Reason: It is an sorted k_lists, so if we move the max pointer as well, then the
range will be greater. But we need only the min range. So we concentrate only in
moving the min pointers]

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

class linked_list {
public:
  int data;
  linked_list *right;

  linked_list(int data) {
    this->data = data;
    this->right = NULL;
  }
};

class custom_op_greater {
public:
  bool operator()(linked_list *a, linked_list *b) { return a->data > b->data; }
};

vector<int> smallest_range_k_lists(vector<linked_list *> input) {
  int row = input.size();
  priority_queue<linked_list *, vector<linked_list *>, custom_op_greater> pq;
  int mini = INT_MAX;
  int maxi = INT_MIN;
  int min_range = INT_MAX;
  int best_min;
  int best_max;
  for (int i = 0; i < row; i++) {
    maxi = max(maxi, input[i]->data);
    pq.push(input[i]);
  }

  while (pq.size() >= 1) {
    linked_list *temp = pq.top();
    mini = pq.top()->data;
    pq.pop();
    if (min_range > (maxi - mini)) {
      min_range = (maxi - mini);
      best_min = mini;
      best_max = maxi;
    }

    if (temp->right != NULL) {
      maxi = max(maxi, temp->right->data);
      pq.push(temp->right);
    } else {
      break;
    }
  }

  return {best_min, best_max};
}

int main() {
  cout << "Smallest Range Covering Elements from K Lists: ";
  vector<linked_list *> input;
  linked_list *a = new linked_list(4);
  a->right = new linked_list(10);
  a->right->right = new linked_list(15);
  a->right->right->right = new linked_list(24);
  a->right->right->right->right = new linked_list(26);
  input.push_back(a);
  linked_list *b = new linked_list(0);
  b->right = new linked_list(9);
  b->right->right = new linked_list(12);
  b->right->right->right = new linked_list(20);
  input.push_back(b);
  linked_list *c = new linked_list(5);
  c->right = new linked_list(18);
  c->right->right = new linked_list(22);
  c->right->right->right = new linked_list(30);
  input.push_back(c);
  // cout<<"Value of k: "<<input.size()<<endl;
  vector<int> result = smallest_range_k_lists(input);
  cout << result[0] << " " << result[1];

  return 0;
}