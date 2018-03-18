// using_01.cpp
// C++11


/*------------------------------------------------------------*/
using MyInt = int;
// typedef int MyInt;


/*------------------------------------------------------------*/
using Func = void( *)(int);
// typedef void (*Func)(int);  

// 함수 포인터
void actual_function( int arg ) {}
Func fp = &actual_function;


/*------------------------------------------------------------*/
template<typename T>
using ptr = T*;

ptr<int> ptr_int;

template <typename T>
using my_make_shared = std::shared_ptr<T>( T* );

template <typename T>
using my_vector = std::vector<T>;