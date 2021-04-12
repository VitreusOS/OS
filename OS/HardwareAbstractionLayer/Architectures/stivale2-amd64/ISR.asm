%macro ISRWithoutErrorCode 1

global isr%1
isr%1:

	push 0
	push %1
	jmp CommonISRStub

%endmacro

%macro ISRWithErrorCode 1

global isr%1
isr%1:

	push %1
	jmp CommonISRStub

%endmacro

%macro pushall 0
    push rax
    push rbx
    push rcx
    push rdx
    push rdi
    push rsi
    push rsp
    push rbp
    push r8
    push r9
    push r10
    push r11
    push r12
    push r13
    push r14
    push r15
%endmacro

%macro popall 0
    pop r15
    pop r14
    pop r13
    pop r12
    pop r11
    pop r10
    pop r9
    pop r8
    pop rbp
    pop rsp
    pop rsi
    pop rdi
    pop rdx
    pop rcx
    pop rbx
    pop rax
%endmacro

ISRWithoutErrorCode 0
ISRWithoutErrorCode 1
ISRWithoutErrorCode 2
ISRWithoutErrorCode 3
ISRWithoutErrorCode 4
ISRWithoutErrorCode 5
ISRWithoutErrorCode 6
ISRWithErrorCode 7
ISRWithoutErrorCode 8
ISRWithErrorCode 9
ISRWithErrorCode 10
ISRWithErrorCode 11
ISRWithErrorCode 12
ISRWithErrorCode 13
ISRWithoutErrorCode 14
ISRWithoutErrorCode 15
ISRWithoutErrorCode 16
ISRWithoutErrorCode 17
ISRWithoutErrorCode 18
ISRWithoutErrorCode 19
ISRWithoutErrorCode 20
ISRWithoutErrorCode 21
ISRWithoutErrorCode 22
ISRWithoutErrorCode 23
ISRWithoutErrorCode 24
ISRWithoutErrorCode 25
ISRWithoutErrorCode 26
ISRWithoutErrorCode 27
ISRWithoutErrorCode 28
ISRWithoutErrorCode 29
ISRWithoutErrorCode 30
ISRWithoutErrorCode 31

EXTERN ISRHandler

CommonISRStub:
	cld
	pushall

	mov rdi, rsp

	call ISRHandler

	popall

	add rsp, 16

	iretq
