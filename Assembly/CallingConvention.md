# Calling Convention ( 함수 호출 규약 )

## 1. 함수 호출 규약 이란?
    
Stack Frame을 사용하는 함수들 간의 대화 방식 ( 스택에 데이터를 read/write 하는 방식 )

```
   #Stack Frame?
   -호출된 하나의 Subprogram 이 사용하는 스택영역의 모든 데이터 ( 함수도 Subprogram )

   !Stack Frame의 연속을 CallStack 이라고 한다
```

## 2. 함수 호출 규약을 구분하는 기준

   * Parameter Passing
       + StackFrame 사용 / 레지스터 사용   
       + Argument-passing Order
   * Return Value
       + 함수 리턴 값을 어디에 저장해서 돌려주는가?
   * Stack Cleanup
       + StackFrame 을 누가 정리 하는가?

## 3. 함수 호출 규약 종류
  * *__cdecl*
  * *__stdcall*
  * *__fastcall*


1. __cdecl ( C언어 함수 호출 규약 )
   ```
      Parameter 전달 방법 : StackFrame 사용하여 전달 ( Parameter 개수 제한이 없다 )
      Parameter 전달 순서 : 오른쪽에서 왼쪽으로
      리턴값 전달 방법     : 리턴값이 4byte 이하
                              -eax 에 저장
                             리턴값이 8byte 이하
                               -리턴값의 상위 4바이트 edx 에 저장
                               -리턴값의 하위 4바이트 eax 에 저장
      Stack Cleanup       : caller 가 callee 의 StackFrame 을 정리
                            어셈블리코드 - add esp, (total parameter size)
      
      *Stack Cleanup 이 caller 인 이유
          가변인자 함수가 있기 때문이다. ( ex. printf )
          가변인자는 Callee 에서 파라미터의 개수를 파악하기 어렵고,
          Caller 에서 파라미터의 개수 파악이 용이하기 때문이다.

   ```


2. __stdcall ( 윈도우 표준 호출 규약 )
    ```
      Parameter 전달 방법 : StackFrame 사용하여 전달 ( Parameter 개수 제한이 없다)
      Parameter 전달 순서 : 오른쪽에서 왼쪽으로
      리턴값 전달 방법     : 리턴값이 4byte 이하
                              -eax 에 저장
                             리턴값이 8byte 이하
                               -리턴값의 상위 4바이트 edx 에 저장
                               -리턴값의 하위 4바이트 eax 에 저장
      Stack Cleanup       : callee 가 자신의 StackFrame 을 정리
                            어셈브리코드 - ret
    ```

3. __fastcall
    ```
      Parameter 전달 방법 : Register 에 저장 후, 스택에 Push
      Parameter 전달 순서 : 오른쪽에서 왼쪽으로
       리턴값 전달 방법     : 리턴값이 4byte 이하
                              -eax 에 저장
                             리턴값이 8byte 이하
                               -리턴값의 상위 4바이트 edx 에 저장
                               -리턴값의 하위 4바이트 eax 에 저장
      Stack Cleanup      : callee 가 자신의 StackFrame 을 정리
    ```

## 4. 범용 레지스터 ( general register )

* x86 프로세서는 8개 이다
* EAX, EBX, ECX, EDX, ESI, EDI, ESP, EBP
* ESP - stack pointer EBP - base pointer

-ESP register

* 스택프레임에 push,pop 될 때 마다 자동으로 값이 증가/감소 한다
* 다음에 스택에 값을 넣을 위치를 가리키고 있다

-EBP register

* 현재 스택프레임의 시작을 가리키는 레지스터

    + 지역변수를 가리킬 때 사용한다
    + 돌아갈 Routine 의 주소를 백업할 때 사용한다

* 이 값은 Subroutine 을 진입할 때 외에 바뀌지 않는다

## 5. Caller/Callee-Saved-Register ?

* Caller, Callee 가 각각 사용하기 전에 백업해두어야 하는 Register

    > Caller-Saved-Register
    >+ EAX, ECX, EDX
    >+ Caller 는 Subroutine 을 호출하기 전에 이 레지스터 값들을 백업해두어야 한다 ( 무조건이 아니고 백업할 필요가 없을 경우엔 안 한다)
    >+ Callee 가 위 레지스터를 마음껏 사용할 수 있게 하기 위해서 이다 ex) 함수 리턴값은 eax 에 저장되는데, caller 에서 eax 를 사용 중이였다면 이 값이 덮어씌워지므로 백업해두는 것이다

    > Callee-Saved-Register
    >+ EBX, ESI, EDI
    >+ Callee 는 이 레지스터 값들을 백업해두고 시작해야한다

    ```c++
        int foo(int a,int b)
        {
            000E2120  push        ebp  
            000E2121  mov         ebp,esp  
            000E2123  sub         esp,0CCh  
            000E2129  push        ebx           // 스택에 백업
            000E212A  push        esi           // 스택에 백업
            000E212B  push        edi           // 스택에 백업
            ...
            000E214A  pop         edi           // 복원
            000E214B  pop         esi           // 복원
            000E214C  pop         ebx           // 복원
            000E214D  mov         esp,ebp  
            000E214F  pop         ebp  
            000E2150  ret                       // Stack CleanUp
        }
    ```    

## 참고 사이트:

* [Guide to x86 Assembly - Calling Convention](http://www.cs.virginia.edu/~evans/cs216/guides/x86.html)
* [msdn.microsoft - Calling Conventions](https://msdn.microsoft.com/en-us/library/k2b2ssfy.aspx)

