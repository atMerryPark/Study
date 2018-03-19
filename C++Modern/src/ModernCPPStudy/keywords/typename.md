# typename


+ treat undefined identifyer as a type ( type 임을 컴파일러에게 알려준다 )
       
    > typename identifier;  

+ 템플릿 선언 및 정의 시 사용 할 수 있다
    ```c++
    template<typename T>
    class Foo
    {
    public:
        T* pT_ = nullptr;
        typename T::mytype var_;    // mytype 이 type 이라고 컴파일러에게 알려준다
                                    // T 가 사용자정의 클래스 일 경우, static value 와 구별하기 위함.
    }
    ```

+ class 와 같다
    ```c++
    template<class T>
    template<typename T>
    ```