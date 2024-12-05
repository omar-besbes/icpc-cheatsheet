template <class T>
struct AVL {
  struct Node {
    T key;
    Node *left, *right;
    int h, sz;
    Node(T k) : key(k), left(nullptr), right(nullptr), h(1), sz(1) {}
  };
  Node *root;
  AVL() : root(nullptr) {}
  void insert(T key) { root = insert(root, key); }
  T *find_by_order(int idx, Node *v) {
    if (v == nullptr) return nullptr;
    auto lsz = size(v->left), rsz = size(v->right);
    if (idx < lsz) return find_by_order(idx, v->left);
    if (idx == lsz) return &(v->key);
    if (idx < 1 + lsz + rsz)
      return find_by_order(idx - lsz - 1, v->right);
    return nullptr;
  }
  T *find_by_order(int idx) { return find_by_order(idx, root); }
  int height(Node *v) { return v == nullptr ? 0 : v->h; }
  int size(Node *v) { return v == nullptr ? 0 : v->sz; }
  // right rotate subtree rooted with y
  Node *rightRotate(Node *y) {
    Node *x = y->left;
    Node *T2 = x->right;
    // Perform rotation
    x->right = y;
    y->left = T2;
    // Update heights
    y->h = 1 + max(height(y->left), height(y->right));
    x->h = 1 + max(height(x->left), height(x->right));
    y->sz = 1 + size(y->left) + size(y->right);
    x->sz = 1 + size(x->left) + size(x->right);
    // Return new root
    return x;
  }
  // left rotate subtree rooted with x
  Node *leftRotate(Node *x) {
    Node *y = x->right;
    Node *T2 = y->left;
    // Perform rotation
    y->left = x;
    x->right = T2;
    // Update heights
    x->h = 1 + max(height(x->left), height(x->right));
    y->h = 1 + max(height(y->left), height(y->right));
    x->sz = 1 + size(x->left) + size(x->right);
    y->sz = 1 + size(y->left) + size(y->right);
    // Return new root
    return y;
  }
  // Get balance factor of node N
  int getBalance(Node *v) {
    return v == nullptr ? 0 : height(v->left) - height(v->right);
  }
  // insert a key in the subtree rooted with v
  Node *insert(Node *v, T key) {
    // Perform the normal BST insertion
    if (v == nullptr) return new Node(key);
    if (key < v->key)
      v->left = insert(v->left, key);
    else if (key > v->key)
      v->right = insert(v->right, key);
    else  // Equal keys are not allowed in BST
      return v;
    v->h = 1 + max(height(v->left), height(v->right));
    v->sz = 1 + size(v->left) + size(v->right);
    int balance = getBalance(v);
    // If this node becomes unbalanced,
    // then there are 4 cases
    // Left Left Case
    if (balance > 1 && key < v->left->key) return rightRotate(v);
    // Right Right Case
    if (balance < -1 && key > v->right->key) return leftRotate(v);
    // Left Right Case
    if (balance > 1 && key > v->left->key) {
      v->left = leftRotate(v->left);
      return rightRotate(v);
    }
    // Right Left Case
    if (balance < -1 && key < v->right->key) {
      v->right = rightRotate(v->right);
      return leftRotate(v);
    }
    // Return the (unchanged) node pointer
    return v;
  }
};