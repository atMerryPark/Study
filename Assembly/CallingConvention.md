# Calling Convention ( 함수 호출 규약 )

>## 1. 함수 호출 규약 이란?
>    
>Stack Frame을 사용하는 함수들 간의 대화 방식 ( 스택에 데이터를 read/write 하는 방식 )
>
>```
>   #Stack Frame?
>   -호출된 하나의 Subprogram 이 사용하는 스택영역의 모든 데이터 ( 함수도 Subprogram )
>
>   !Stack Frame의 연속을 CallStack 이라고 한다
>```
***
>## 2. 함수 호출 규약을 구분하는 기준
>
>   * Parameter Passing
>       + StackFrame 사용 / 레지스터 사용   
>       + Argument-passing Order
>   * Return Value
>       + 함수 리턴 값을 어디에 저장해서 돌려주는가?
>   * Stack Cleanup
>       + StackFrame 을 누가 정리 하는가?
***
>## 3. 함수 호출 규약 종류
>  * *__cdecl*
>  * *__stdcall*
>  * *__fastcall*
>
>>   1. __cdecl ( C언어 함수 호출 규약 )
>>   ```
>>      Parameter 전달 방법 : StackFrame 사용하여 전달 ( Parameter 개수 제한이 없다 )
>>      Parameter 전달 순서 : 오른쪽에서 왼쪽으로
>>      리턴값 전달 방법     : 리턴값이 4byte 이하
>>                              -eax 에 저장
>>                             리턴값이 8byte 이하
>>                               -리턴값의 상위 4바이트 edx 에 저장
>>                               -리턴값의 하위 4바이트 eax 에 저장
>>      Stack Cleanup       : caller 가 callee 의 StackFrame 을 정리
>>                            어셈블리코드 - add esp, (total parameter size)
>>      
>>      *Stack Cleanup 이 caller 인 이유
>>          가변인자 함수가 있기 때문이다. ( ex. printf )
>>          가변인자는 Callee 에서 파라미터의 개수를 파악하기 어렵고,
>>          Caller 에서 파라미터의 개수 파악이 용이하기 때문이다.
>>
>>   ```
>>
>>  2. __stdcall ( 윈도우 표준 호출 규약 )
>>  ```
>>      Parameter 전달 방법 : StackFrame 사용하여 전달 ( Parameter 개수 제한이 없다)
>>      Parameter 전달 순서 : 오른쪽에서 왼쪽으로
>>      리턴값 전달 방법     : 리턴값이 4byte 이하
>>                              -eax 에 저장
>>                             리턴값이 8byte 이하
>>                               -리턴값의 상위 4바이트 edx 에 저장
>>                               -리턴값의 하위 4바이트 eax 에 저장
>>      Stack Cleanup       : callee 가 자신의 StackFrame 을 정리
>>                            어셈브리코드 - ret
>>  ```
>> 3. __fastcall
>> ```
>>      Parameter 전달 방법 : Register 에 저장 후, 스택에 Push
>>      Parameter 전달 순서 : 오른쪽에서 왼쪽으로
>>       리턴값 전달 방법     : 리턴값이 4byte 이하
>>                              -eax 에 저장
>>                             리턴값이 8byte 이하
>>                               -리턴값의 상위 4바이트 edx 에 저장
>>                               -리턴값의 하위 4바이트 eax 에 저장
>>      Stack Cleanup      : callee 가 자신의 StackFrame 을 정리
>> ```
***

