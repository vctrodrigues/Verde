#include "../include/verde.hpp"

using namespace verde;

Node *AVL::insert(Node *node, int key)
{
  if (node == NULL)
    return new Node(key);

  if (key < node->key)
    node->left = insert(node->left, key);
  else if (key > node->key)
    node->right = insert(node->right, key);
  else
    return node;

  node->height = max(height(node->left), height(node->right)) + 1;

  int balance = getBalance(node);

  if (balance > 1 && key < node->left->key)
    return rightRotate(node);

  if (balance < -1 && key > node->right->key)
    return leftRotate(node);

  if (balance > 1 && key > node->left->key)
  {
    node->left = leftRotate(node->left);
    return rightRotate(node);
  }

  if (balance < -1 && key < node->right->key)
  {
    node->right = rightRotate(node->right);
    return leftRotate(node);
  }

  return node;
}

int AVL::height(Node *N)
{
  if (N == nullptr)
    return 0;

  return N->height;
}

int AVL::max(int a, int b)
{
  return (a > b) ? a : b;
}

Node *AVL::rightRotate(Node *y)
{
  Node *x = y->left;
  Node *T = x->right;

  x->right = y;
  y->left = T;

  y->height = max(height(y->left), height(y->right)) + 1;
  x->height = max(height(x->left), height(x->right)) + 1;

  return x;
}

Node *AVL::leftRotate(Node *x)
{
  Node *y = x->right;
  Node *T = y->left;

  y->left = x;
  x->right = T;

  x->height = max(height(x->left), height(x->right)) + 1;
  y->height = max(height(y->left), height(y->right)) + 1;

  return y;
}

int AVL::getBalance(Node *N)
{
  if (N == nullptr)
    return 0;

  return height(N->left) - height(N->right);
}

std::string AVL::toString()
{
  if (root == nullptr)
    return "";

  std::queue<Node *> q;
  q.push(root);

  std::stringstream stream;

  stream << "\n";
  while (q.empty() == false)
  {
    Node *node = q.front();
    stream << "{" << node->key << "}"
           << "(L" << node->height << ")"
           << " B[" << getBalance(node) << "]\n";
    q.pop();

    if (node->left != nullptr)
      q.push(node->left);

    if (node->right != nullptr)
      q.push(node->right);
  }

  return stream.str();
}

Node *AVL::search(Node *node, int key)
{
  if(node == nullptr)
  {
    return nullptr;
  }

  if(node->key == key)
    return node;
  else if(key > node->key) 
    return search(node->right, key);
  else
    return search(node->left, key);
}