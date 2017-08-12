template<class K, class V> class Map;
template<class K, class V> class Mapiter;
template<class K, class V> class Link {
	friend class Map<K,V>;
	friend class Mapiter<K,V>;
private:
	const K key;
	V value;
	Link* pre;
	Link* suc;
	Link(const K& k, const V& v) : key(k), value(v) { }
	~Link() { delete suc; } // рекурсивное удаление всех
};

template<class K, class V> class Map {
	friend class Mapiter<K,V>;
	Link<K,V>* head;
	Link<K,V>* current;
	V def_val;
	K def_key;
	int sz;
	void find(const K&);
	void init() { sz = 0; head = 0; current = 0; }
public:
	Map() { init(); }
	Map(const K& k, const V& d) : def_val(d), def_key(k) { init(); }
	~Map() { delete head; } // рекурсивное удаление всех объектов в списке
	Map(const Map&);
	Map& operator= (const Map&);
	V& operator[] (const K&);
	int size() const { return sz; }
	void clear() { delete head; init(); } 
	void remove(const K& k);
	Mapiter<K,V> element(const K& k) // функции для итерации
	{
		(void) operator[](k); // сделать k текущим элементом
		return Mapiter<K,V>(this,current);
	}
	Mapiter<K,V> first();
	Mapiter<K,V> last();
};



template<class K, class V> class Mapiter {
	friend class Map<K,V>;
	Map<K,V>* m;
	Link<K,V>* p;
	Mapiter(Map<K,V>* mm, Link<K,V>* pp) { m = mm; p = pp; }
public:
	Mapiter() { m = 0; p = 0; }
	Mapiter(Map<K,V>& mm);
	operator void*() { return p; }
	const K& key() { return p ? p->key : m->def_key; };
	V& value() { return p ? p->value : m->def_val; } ;
	Mapiter& operator--();  //prefix
	void operator--(int);  //postfix
	Mapiter& operator++(); //pre
	void operator++(int);  //post
};

#include "map.cpp"