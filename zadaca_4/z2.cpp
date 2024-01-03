
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

using namespace std;

// implementirati cu moveToFront u obliku
// LRUCache-a (least recently used)

template <typename K, typename V> class Node {
public:
  Node<K, V> *next;
  Node<K, V> *previous;
  K key;
  V value;
  Node<K, V>() {
    this->next = nullptr;
    this->previous = nullptr;
  }
};

template <typename K, typename V> class LRU {
  Node<K, V> *root;
  void moveToFront(Node<K, V> *);
  void recFree(Node<K, V> *);

public:
  Node<K, V> *search(K key);
  void insert(K key, V value);
  LRU() { this->root = nullptr; }
  ~LRU();
};

template <typename K, typename V> void LRU<K, V>::recFree(Node<K, V> *node) {
  if (node == nullptr)
    return;

  this->recFree(node->next);
  delete node;
}

template <typename K, typename V> LRU<K, V>::~LRU() {
  // this->recFree(this->root);
}

template <typename K, typename V> Node<K, V> *LRU<K, V>::search(K key) {
  Node<K, V> *it = this->root;

  while (it != nullptr && it->next != nullptr) {
    if (it->key == key) {
      break;
    }

    it = it->next;
  }

  if (it == nullptr || it->key != key)
    return nullptr;

  this->moveToFront(it);
  return this->root;
}

template <typename K, typename V>
void LRU<K, V>::moveToFront(Node<K, V> *node) {
  Node<K, V> *previous = node->previous;
  Node<K, V> *next = node->next;

  // vec smo root
  if (node == this->root) {
    return;
  }

  // izbaci node iz lanca
  if (previous != nullptr)
    previous->next = node->next;

  if (next != nullptr)
    next->previous = previous;

  // postavi node na root
  node->next = this->root;
  if (this->root != nullptr) {
    this->root->previous = node;
  }

  this->root = node;
}

template <typename K, typename V> void LRU<K, V>::insert(K key, V value) {
  Node<K, V> *novi = new Node<K, V>;
  novi->key = key;
  novi->value = value;

  this->moveToFront(novi);
}

vector<int> random_brojevi(int duljina) {
  vector<int> arr(duljina);

  for (auto &x : arr) {
    // do 9999
    x = rand() % 10000;
  }

  return arr;
}

int main() {
  // kod mjeri razlicize nacine pristupanja
  // keyevi su promjesani nakon inserta
  // neki primjer moveToFront algoritma je LRUCache (koji sam implementirao)
  LRU<int, int> cache;

  vector<int> randomBrojevi1 = random_brojevi(10000);
  vector<int> randomBrojevi2 = random_brojevi(10000);

  for (int i = 0; i < 10000; i++)
    cache.insert(randomBrojevi1[i], randomBrojevi2[i]);

  // fisher-yaates shuffles
  for (int i = 0; i < 9998; i++) {
    int j = i + rand() % (10000 - i - 1);

    swap(randomBrojevi1[i], randomBrojevi1[j]);
  }

  double vrijeme = clock();
  for (int i = 0; i < 1000; i++) {
    for (int j = 0; j < 10; j++) {
      cache.search(randomBrojevi1[j]);
    }
  }
  double res = (clock() - vrijeme) / (double)CLOCKS_PER_SEC;

  cout << "10 istih keyeva, 10k searcheva: " << res << "sekundi" << endl;

  vrijeme = clock();
  for (int i = 0; i < 100; i++) {
    for (int j = 0; j < 100; j++) {
      cache.search(randomBrojevi1[j]);
    }
  }
  res = (clock() - vrijeme) / (double)CLOCKS_PER_SEC;

  cout << "100 istih keyeva, 10k searcheva: " << res << "sekundi" << endl;

  vrijeme = clock();
  for (int j = 0; j < 10000; j++) {
    cache.search(randomBrojevi1[j]);
  }
  res = (clock() - vrijeme) / (double)CLOCKS_PER_SEC;

  cout << "Svi keyevi: " << res << "sekundi" << endl;
  // zakljucak: sto manji broj keyeva se cesto trazi to brze ide
}
