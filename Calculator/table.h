struct name {
     char* string;
     name* next;
     double value;
};

class table {
	name** tbl;
	int size;
	public:
		table(int sz = 15);
		~table();
		name* look(const char*, int = 0);
		name* insert(const char* s) { return look(s,1); }
  };

extern table var_names;