// typename_01.cpp
// �� �� ���� �ĺ��ڰ� type ���� �����Ϸ����� �˷��ش�



// ���ø� ���� �� ���� ��� ������ ��� �����ϴ�.
template<typename T>
class Foo
{
public:
	T* pT_ = nullptr;
	
	typename T::mytype t_;		// mytype �� type �̶�� �˷��ش�.
								// T �� ��������� Ŭ���� �� ���, static ���� �� ���� �����Ƿ�.
};



// �⺻ Ŭ���� �������� ���ø� �Ķ���� �ܿ� ��� �� �� ����
template <class T>
class C1 : typename T::InnerType // Error - typename not allowed.  
{};
template <class T>
class C2 : A<typename T::InnerType>  // typename OK.  
{};




// ���ø� ���� ��, typename �� class �� ����
template<class T>
template<typename T>