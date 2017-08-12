#include <iostream>
#include <queue>

template<class K, class V> 
	void RBTree<K,V>::_init() {
		_nil = new Link<K,V>(def_key, def_val, 'b');
		_root = _nil;
	}

template<class K, class V> 
	RBTree<K,V>::RBTree(Link<K,V>* root) {
		_init();
		_root = root;
		_root->parent = _root->left = _root->right = _nil;
	}

template<class K, class V> 
	void RBTree<K,V>::dump(Link<K,V>* x) {
		if (x == 0) 
			x = _root;
		x->depth = 0;
		std::queue<Link<K,V>*> q;
		q.push(x);
		int cur_dep = 0;
		while (q.size() ) {
			x = q.front();
			if (x->depth > cur_dep) {
				std::cout << '\n';
				cur_dep = x->depth;
			} else if (cur_dep != 0) {
				std::cout << "  ***  ";
			}
			std::cout << x->key << ", " << x->color<< ": " << x->value;
			if (x->left != _nil) {
				q.push(x->left);
				x->left->depth = x->depth + 1;
			}
			if (x->right != _nil) {
				q.push(x->right);
				x->right->depth = x->depth + 1;
			}
			q.pop();
		}
		std::cout << '\n';
	}

template<class K, class V> 
	Link<K,V>* RBTree<K,V>::search(const K& k) {
		Link<K,V>* curr = _root;
		while (curr != _nil &&  k != curr->key) {
			if (k < curr->key) {
				curr = curr->left;
			} else {
				curr = curr->right;
			}
		}
		return curr;
	}

template<class K, class V> 
	Link<K,V>* RBTree<K,V>::minimum(Link<K,V>* x) {
		while(x->left != _nil) {
			x = x->left;
		}
		return x;
	}

template<class K, class V> 
	Link<K,V>* RBTree<K,V>::maximum(Link<K,V>* x) {
		while(x->right != _nil) {
			x = x->right;
		}
		return x;
	}

template<class K, class V> 
	void RBTree<K,V>::insert(const K& k, const V& v) {
		Link<K,V>* z = new Link<K,V>(k, v);
		_insert(z);
	}

template<class K, class V> 
	void RBTree<K,V>::_insert(Link<K,V>* z) {
		Link<K,V>* pre = _nil;
		Link<K,V>* curr = _root;
		while (curr != _nil) {
			pre = curr;
			if (z->key < curr->key) {
				curr = curr->left;
			} else {
				curr = curr->right;
			}
		}
		z->parent = pre;
		z->left = z->right =_nil;
		if (pre == _nil) {
			_root = z;
			z->color = 'b';
			return;
		} else if (z->key < pre->key) {
			pre->left = z;
		} else {
			pre->right = z;
		}
		z->color = 'r';
		_insert_fixup(z);
	}

template<class K, class V> 
	void RBTree<K,V>::_insert_fixup(Link<K,V>* z) {
		Link<K,V>* y;
		while (z->parent->color == 'r') {
			if (z->parent == z->parent->parent->left) {
				y = z->parent->parent->right;
				if (y->color == 'r') {
					z->parent->color = 'b';
					y->color = 'b';
					z->parent->parent->color = 'r';
					z = z->parent->parent;
				} else {
					if (z == z->parent->right) {
						z = z->parent;
						_left_rotate(z);
					}
					z->parent->color = 'b';
					z->parent->parent->color ='r';
					_right_rotate(z->parent->parent);
				}
			} else {
				y = z->parent->parent->left;
				if (y->color == 'r') {
					z->parent->color = 'b';
					y->color = 'b';
					z->parent->parent->color = 'r';
					z = z->parent->parent;
				} else {
					if (z == z->parent->left) {
						z = z->parent;
						_right_rotate(z);
					}
					z->parent->color = 'b';
					z->parent->parent->color ='r';
					_left_rotate(z->parent->parent);
				}
			}

		}
		_root->color = 'b';
	}

template<class K, class V> 
	void RBTree<K,V>::_left_rotate(Link<K,V>* x) {
		Link<K,V>* y = x->right;
		x->right = y->left;
		if (y->left != _nil) {
			y->left->parent = x;
		}
		y->parent = x->parent;
		if (x->parent == _nil) {
			_root = y;
		} else if (x == x->parent->left) {
			x->parent->left = y;
		} else {
			x->parent->right = y;
		}
		y->left = x;
		x->parent = y;
}

template<class K, class V> 
	void RBTree<K,V>::_right_rotate(Link<K,V>* y) {
		Link<K,V>* x = y->left;
		y->left = x->right;
		if (x->right != _nil) {
			x->right->parent = y;
		}
		x->parent = y->parent;
		if (y->parent == _nil) {
			_root = x;
		} else if (y == y->parent->left) {
			y->parent->left = x;
		} else {
			y->parent->right = x;
		}
		x->right = y;
		y->parent = x;
}

template<class K, class V> 
	void RBTree<K,V>::remove(const K& k) {
		Link<K,V>* z = search(k);
		if (z != _nil) {
			_remove(z);
		}
	}

template<class K, class V> 
	void RBTree<K,V>::_remove(Link<K,V>* z) {
		Link<K,V>* y = z;
		Link<K,V>* x;
		char y_orig_col = y->color;
		if (z->left == _nil) {
			x = z->right;
			_transplant(z, z->right);
		} else if (z->right == _nil) {
			x = z->left;
			_transplant(z, z->left);
		} else {
			y = minimum(z->right);
			y_orig_col = y->color;
			x = y->right;
			if (y->parent == z) {
				x->parent = y;
			} else {
				_transplant(y, y->right);
				y->right = z->right;
				y->right->parent = y;
			}
			_transplant(z, y);
			y->left = z->left;
			y->left->parent = y;
			y->color = z->color;
		}
		if (y_orig_col == 'b') {
			_remove_fixup(x);
		}
	}

template<class K, class V> 
	void RBTree<K,V>::_transplant(Link<K,V>* u, Link<K,V>* v) {
		if (u->parent == _nil) {
			_root = v;
		} else if (u == u->parent->left) {
			u->parent->left = v;
		} else {
			u->parent->right = v;
		}
		v->parent =  u->parent;
	}

template<class K, class V> 
	void RBTree<K,V>::_remove_fixup(Link<K,V>* x) {
		Link<K,V>* w;
		while((x != _root) && (x->color == 'b')) {
			if (x == x->parent->left) {
				w = x->parent->right;
				if (w->color== 'r') {
					w->color = 'b';
					x->parent->color = 'r';
					_left_rotate(x->parent);
					w = x->parent->right;
				}
				if ((w->left->color =='b') && (w->right->color =='b')) {
					w->color = 'r';
					x = x->parent;
				} else {
					if (w->right->color == 'b') {
						w->left->color = 'b';
						w->color = 'r';
						_right_rotate(w);
						w = x->parent->right;
					}
					w->color = x->parent->color;
					x->parent->color = 'b';
					w->right->color = 'b';
					_left_rotate(x->parent);
					x = _root;
				}
			} else {
				w = x->parent->left;
				if (w->color== 'r') {
					w->color = 'b';
					x->parent->color = 'r';
					_right_rotate(x->parent);
					w = x->parent->left;
				}
				if ((w->left->color =='b') && (w->right->color =='b')) {
					w->color = 'r';
					x = x->parent;
				} else {
					if (w->left->color == 'b') {
						w->right->color = 'b';
						w->color = 'r';
						_left_rotate(w);
						w = x->parent->left;
					}
					w->color = x->parent->color;
					x->parent->color = 'b';
					w->left->color = 'b';
					_right_rotate(x->parent);
					x = _root;
				}
			}
		}
		x->color = 'b';
	}
