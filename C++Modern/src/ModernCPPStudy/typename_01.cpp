// typename_01.cpp
// 알 수 없는 식별자가 type 임을 컴파일러에게 알려준다



// 템플릿 선언 및 정의 어느 곳에나 사용 가능하다.
template<typename T>
class Foo
{
public:
	T* pT_ = nullptr;
	
	typename T::mytype t_;		// mytype 이 type 이라고 알려준다.
								// T 가 사용자정의 클래스 인 경우, static 변수 일 수도 있으므로.
};



// 기본 클래스 구문에서 템플릿 파라미터 외에 사용 할 수 없다
template <class T>
class C1 : typename T::InnerType // Error - typename not allowed.  
{};
template <class T>
class C2 : A<typename T::InnerType>  // typename OK.  
{};




// 템플릿 선언 시, typename 과 class 는 같다
template<class T>
template<typename T>