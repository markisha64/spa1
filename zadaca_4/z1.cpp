
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

vector<int> random_brojevi(int duljina) {
  vector<int> arr(duljina);

  for (auto &x : arr) {
    // do 9999
    x = rand() % 10000;
  }

  return arr;
}

template <typename T> class Queue {
  stack<T> insertStack;
  stack<T> reversedStack;
  void reverseStack();

public:
  void push(T element);
  T pop();
  T top();
  size_t size() const { return insertStack.size() + reversedStack.size(); };
  size_t rsize() const { return reversedStack.size(); }
  Queue();
  ~Queue();
};

template <typename T> Queue<T>::Queue() {}

template <typename T> Queue<T>::~Queue() {}

template <typename T> void Queue<T>::push(T element) {
  this->insertStack.push(element);
}

template <typename T> T Queue<T>::pop() {
  T element = this->top();
  this->reversedStack.pop();

  return element;
}

template <typename T> T Queue<T>::top() {
  if (this->reversedStack.empty()) {
    this->reverseStack();
  }

  T element = this->reversedStack.top();

  return element;
}

template <typename T> void Queue<T>::reverseStack() {
  while (!this->insertStack.empty()) {
    this->reversedStack.push(this->insertStack.top());
    this->insertStack.pop();
  }
}

int main() {
  /*
   * queue struktura pomocu stack strukture
   * koristimo 2 stacka
   * -> prilikom push() metode stavljamo elemente u insert stack
   * -> top() metoda provjerava ima li elemenata u reverseStack-u
   *    -> ako nema prebacimo sve elemente iz insert stacka u reverStack
   *    -> to ih odma i reversa order pa imamo zadnji stack element prvi queue
   * element
   *    -> posto nikad necemo ponovo pomicati elemente u revereStack dok nije
   * prazan
   *    -> nikad se nece izgubiti dobar poredak u reverseStacku
   *    -> top() vrati reverseStack.top()
   * -> pop() metoda poziva vlastitu top() metodu, pozove reverseStack.pop() te
   * vrata vraceni element od top() metode
   *
   *
   * c)
   * Aggregate metoda
   * metoda | stack 1 velicina | stack 2 velicina | operacija
   * push   | 1                | 0                | 1
   * push   | 2                | 0                | 1
   * push   | 3                | 0                | 1
   * pop    | 0                | 2                | 4
   * pop    | 0                | 1                | 1
   * push   | 1                | 1                | 1
   * pop    | 1                | 0                | 1
   * pop    | 0                | 0                | 2
   *
   * push = O(1)
   * pop = {
   * -> insertStack.size() + 1, revereStack.size() == 0
   * -> 1, revereStack.size() != 0
   *
   * pop = 1 + n + n + 1 = 2n
   * => pop = O(2n)/n = O(1)
   */

  vector<int> brojevi = random_brojevi(10000);
  std::queue<int> squeue;
  Queue<int> mqueue;

  double vrijeme = clock();
  for (int i = 0; i < 20; i++) {
    if (i % 2 == 0) {
      for (int j = 0; j < 1000; j++) {
        squeue.push(brojevi[(i / 2) * 1000 + j]);
      }
    } else {
      for (int j = 0; j < 1000; j++) {
        squeue.pop();
      }
    }
  }
  double rez = (clock() - vrijeme) / CLOCKS_PER_SEC;

  cout << "10000 standard queue push/popova vrijeme: " << rez << " sekundi"
       << endl;

  vrijeme = clock();
  for (int i = 0; i < 20; i++) {
    if (i % 2 == 0) {
      for (int j = 0; j < 1000; j++) {
        mqueue.push(brojevi[(i / 2) * 1000 + j]);
      }
    } else {
      for (int j = 0; j < 1000; j++) {
        mqueue.pop();
      }
    }
  }
  rez = (clock() - vrijeme) / CLOCKS_PER_SEC;

  cout << "10000 moj queue push/popova vrijeme: " << rez << " sekundi" << endl;
  cout << "\n isti test samo manji razmak izmedju pusheva/popova \n\n";

  vrijeme = clock();
  for (int i = 0; i < 2000; i++) {
    if (i % 2 == 0) {
      for (int j = 0; j < 10; j++) {
        squeue.push(brojevi[(i / 2) * 10 + j]);
      }
    } else {
      for (int j = 0; j < 10; j++) {
        squeue.pop();
      }
    }
  }
  rez = (clock() - vrijeme) / CLOCKS_PER_SEC;

  cout << "10000 standard queue push/popova vrijeme: " << rez << " sekundi"
       << endl;

  vrijeme = clock();
  for (int i = 0; i < 2000; i++) {
    if (i % 2 == 0) {
      for (int j = 0; j < 10; j++) {
        mqueue.push(brojevi[(i / 2) * 10 + j]);
      }
    } else {
      for (int j = 0; j < 10; j++) {
        mqueue.pop();
      }
    }
  }
  rez = (clock() - vrijeme) / CLOCKS_PER_SEC;

  cout << "10000 moj queue push/popova vrijeme: " << rez << " sekundi" << endl;

  // zakljucak: nas queue sa 2 stacka je konzistentno sporiji
}
