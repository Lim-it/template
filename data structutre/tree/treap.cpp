//treap 
//search/find/insert/delete in logn
struct Node {
	int val;
	int pri;
	Node *left, *right;
	Node(int val) : val(val), pri(rand()), left(NULL), right(NULL){};
};

void split(Node *root, int x, Node *&left, Node *&right) {
	if (!root) {
		left = right = NULL;
		return;
	}
	if (!(root->val > x)) {
		split(root->right, x, root->right, right);
		left = root;
	} else {
		split(root->left, x, left, root->left);
		right = root;
	}
}

void merge(Node *&root, Node *left, Node *right) {
	if (!left || !right) {
		root = left ? left : right;
	}
	else if (left->pri > right->pri) {
		merge(left->right, left->right, right);
		root = left;
	}
	else {
		merge(right->left, left, right->left);
		root = right;
	}
}

void insert (Node *&t, Node* it) {
    if (!t)
        t = it;
    else if (it->pri > t->pri)
        split (t, it->val, it->left, it->right),  t = it;
    else
        insert (t->val > it->val ? t->left : t->right, it);
}

void erase (Node *&t, int key) {
    if (t->val == key) {
        merge (t, t->left, t->right);
    }
    else
        erase (t->val > key ? t->left : t->right, key);
}

void inorder(Node* t){
    if(t == NULL) return;
    inorder(t->left);
    cout << t->val << '\n';
    inorder(t->right);
}

Node* findmin(Node* t){
    if(t->left == NULL) return t;
    return findmin(t->left);
}