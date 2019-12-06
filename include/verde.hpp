#ifndef VERDE_H
#define VERDE_H

#include <iostream>
#include <string>
#include <queue>
#include <sstream>

namespace verde
{

struct Node
{
public:
  int key;
  Node *left;
  Node *right;
  int height;

  Node(int k, Node *l = nullptr, Node *r = nullptr, int h = 1) : key{k}, left{l}, right{r}, height{h} {};

  Node &operator=(const Node &other)
  {
    key = other.key;
    left = other.left;
    right = other.right;
    height = other.height;

    return *this;
  }
};

class AVL
{
private:
  Node *root;

  int max(int a, int b);
  int height(Node *N);

  Node *rightRotate(Node *y);
  Node *leftRotate(Node *x);
  int getBalance(Node *N);

  Node *insert(Node *node, int key);
  Node *search(Node *node, int key);

public:
  AVL(Node *r = nullptr) : root{r} {}
  void add(int key) { root = insert(root, key); }
  std::string toString();
  Node *find(int key) { return search(root, key); }
};

} // namespace verde

#endif