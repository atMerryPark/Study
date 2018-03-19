# using

+ typedef 와 기본적으로 동일하지만, template 을 추가지원 한다
+ Sample Code
    ```c++
    // general
    using MyInt = int
    typedef int MyInt


    // function pointer
    using Func = void(*)(int)
    typedef void (*Func)(int)


    // template
    template<typename T>
    using ptr = T*;

    template <typename T>
    using my_make_shared = std::shared_ptr<T>(T*);

    template <typename T>
    using my_vector = std::vector<T>;
    ```
