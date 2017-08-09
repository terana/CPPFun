struct dlink {
     dlink* next;
     dlink* prev;
     dlink() { next = 0; prev = 0; }
     dlink(dlink* p) { next = p; prev = p->prev; p->prev = this; prev->next = this; }
};

class dlist_base {
	dlink *tail; // tail->next == head
  public:
     void insert(dlink*); //insert to head
     void append(dlink*); //insert to tail
     dlink* get(); //remove and return head
     void clear() { tail = 0; }
     dlist_base() { tail = 0; }
     dlist_base(dlink* a) { tail = a->next = a->prev = a; }
     friend class dlist_base_iter;
};

class dlist_base_iter {
	dlink* ce; // current element
	dlist_base* cd; // current dlist
public:
	dlist_base_iter(dlist_base& d);
	dlink* operator()();
};


/*    Inherited from dlist_base.    */

template<class T> class Idlist_iter;

template<class T>
class Idlist : private dlist_base {
  public:
	void insert(T* a) { dlist_base::insert(a); }
	T* get() { return (T*) dlist_base::get(); }
	friend class Idlist_iter<T>;
};

template<class T>
	class Idlist_iter : private dlist_base_iter {
	public:
       Idlist_iter(Idlist<T>& d) : dlist_base_iter(d) { }
       T* operator()()
          { return (T*) dlist_base_iter::operator()(); }
};

template<class T>
  struct Tlink : public dlink {
	T info;
	Tlink(const T& a) : info(a) { }
  };

template<class T> class Dlist_iter;

template<class T>
  class Dlist : private dlist_base {
	public:
		void insert(const T& a) { dlist_base::insert(new Tlink<T>(a)); }
		void append(const T& a) { dlist_base::append(new Tlink<T>(a)); }
		T get();
		friend class Dlist_iter<T>;
};

template<class T>
  T Dlist<T>::get() {
     Tlink<T>* lnk = (Tlink<T>*) dlist_base::get();
     T i = lnk->info;
     delete lnk;
     return i;
}

template<class T>
	class Dlist_iter : private dlist_base_iter {
	public:
       Dlist_iter(Dlist<T>& d) : dlist_base_iter(d) { }
       inline T* operator()() 
       { Tlink<T>* tl = (Tlink<T>*) dlist_base_iter::operator()();
       	return tl ? &(tl->info) : 0; };
};

template<class T>
  class Dplist : private Dlist<void*> {
     public:
       void insert(T* p) { Dlist<void*>::insert(p); }
       void append(T* p) { Dlist<void*>::append(p); }
       T* get() { return (T*) Dlist<void*>::get(); }
};

template<class T>
class Idplist : private dlist_base {
     public:
       void insert(T* p) { dlist_base::insert(p); }
       void append(T* p) { dlist_base::append(p); }
       T* get() { return (T*) dlist_base::get(); }
};