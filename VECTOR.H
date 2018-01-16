
template<typename T>
class vector {
private:
	T* m_pData;
	int m_count;
	int m_capacity;
	
public:
	vector()
	{
		m_pData = 0;
		m_count = 0;
		m_capacity = 0;
	}
	vector(int capacity)
	{
		m_pData = new t[capacity];
		m_count = 0;
		m_capacity = capacity;
	}
	
	virtual ~vector()
	{
		if(m_pData)
			delete [] m_pData;
	}
	
	void push_back(const T& t)
	{
		if(m_count + 1 < m_capacity) {
			m_pData[++m_count] = t;
			return;
		}
		
		int newCapacity = (int)((float)m_capacity * 1.7);
		T* newArray = new T[newCapacity];
		
		for(int x = 0; x < m_count; x++){
			// Does this call a copy
			newArray[x] = m_pData[x];
		}
		
		
	}
	T pop_back()
	{
		
	}
	
};
