class bit_array {
public:
	explicit bit_array(int size);
	~bit_array() { delete arr_; };
	int size() { return size_; };
	void set(int i);
	void clr(int i);
	int test(int i);
	void print();
private:
	int size_;
	int *arr_;
};