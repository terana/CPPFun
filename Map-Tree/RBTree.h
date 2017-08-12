template<class K, class V> class RBTree;
template<class K, class V> class Link {
	friend class RBTree<K,V>;
private:
	const K key;
	V value;
	char color;
	int depth;
	Link* left;
	Link* right;
	Link* parent;
	Link(const K& k, const V& v, char col = 'r') : key(k), value(v), color(col) { }
	Link() { }
	~Link() { delete left; delete right; } // рекурсивное удаление всех
};

template<class K, class V> class RBTree {
	Link<K,V>* _root;
	Link<K,V>* _nil;
	V def_val;
	K def_key;
	void _init();
	void _insert(Link<K,V>*);
	void _left_rotate(Link<K,V>*);
	void _right_rotate(Link<K,V>*);
	void _insert_fixup(Link<K,V>*);
	void _remove(Link<K,V>*);
	void _transplant(Link<K,V>* u, Link<K,V>* v);
	void _remove_fixup(Link<K,V>*);
public:
	RBTree(const K& k, const V& d) : def_val(d), def_key(k) { _init(); };
	RBTree(Link<K,V>* root);
	void dump(Link<K,V>* x = 0);
	Link<K,V>* search(const K&);
	void insert(const K& k, const V& v);
	Link<K,V>* minimum(Link<K,V>*);
	Link<K,V>* maximum(Link<K,V>*);
	Link<K,V>* precessor(const K&);
	Link<K,V>* successor(const K&);
	void remove(const K&);
};

#include "RBTree.cpp"