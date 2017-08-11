template<class K, class V>
  V& Map<K,V>::operator[] (const K& k) {
	if (head == 0) {
		current = head = new Link<K,V>(k,def_val);
		current->pre = current->suc = 0;
		return current->value;
	}
	Link<K,V>* p = head;
	for (;;) {
		if (p->key == k) { // найдено 
			current = p;
			return current->value;
		}
		if (k < p->key) { // вставить перед p (в начало)
			current = new Link<K,V>(k,def_val);
			current->pre = p->pre;
			current->suc = p;
			if (p == head) // текущий элемент становится начальным
				head = current;
			else
				p->pre->suc = current;
			p->pre = current;
			return current->value;
		}
		Link<K,V>* s = p->suc;
		if (s == 0) { // вставить после p (в конец)
			current = new Link<K,V>(k,def_val);
			current->pre = p;
			current->suc = 0;
			p->suc = current;
			return current->value;
       }
		p = s;
	}
}

template<class K, class V>
  void  Map<K,V>::remove(const K& k) {
  	Link<K,V>* p = head;
	for (;;) {
		if (p == 0)
  			return;
		if (p->key == k) {
			if (p->pre) {
				p->pre->suc = p->suc;
			}
			if (p->suc) {
				p->suc->pre = p->pre;
			}
			delete p;
			return;
		}
		p = p->suc;
	}
  }

template<class K, class V>
  Map<K,V>::Map(const Map<K,V>& m) {
     // копирование таблицы Map и всех ее элементов
}

template<class K, class V>
  Map<K,V>& Map<K,V>::operator=(const Map<K,V>& m) {
     // копирование таблицы Map и всех ее элементов
}

/* ------ Mapiter -------- */

template<class K, class V>
Mapiter<K,V>& Mapiter<K,V>::operator--() {
	if (p) 
		p = p->pre;
	return *this;
}

template<class K, class V>
void Mapiter<K,V>::operator--(int) {
     if (p) 
     	p = p->pre;
}

template<class K, class V>
Mapiter<K,V>& Mapiter<K,V>::operator++() {
	if (p) 
		p = p->suc;
	return *this;
}

template<class K, class V>
void Mapiter<K,V>::operator++(int) {
	if (p) 
		p = p->suc;
}

template<class K, class V> Mapiter<K,V>::Mapiter(Map<K,V>& mm) {
	m = &mm; 
	p = m->head;
}