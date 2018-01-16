
template<typename T>
class vector {
private:
	T* m_pData;
	int m_count;
	int m_capacity;
	
public:
	vector();
	vector(int capacity);
	virtual ~vector():
	
	void push_back(T);
	T pop_back();
	
};