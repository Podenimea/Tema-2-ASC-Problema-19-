section .data

_x0:    dq    6900000000000.0
_2:    dq    2.0
_3:    dq    3.0
input:	db	"%lf", 0x0
output:    db    "%lf", 0x0A, 0x0

section    .text
global main

extern printf
extern scanf

main:
    enter    0, 0

	mov	rdi, input
	mov	rsi, _x0
	mov	rax, 0
	call	scanf

	movsd	xmm0, [_x0]
	mov	rcx, 255

_calculate:
    movsd    xmm1, xmm0
    mulsd    xmm1, xmm0

    addsd    xmm1, xmm0
    addsd    xmm1, xmm0

    movsd    xmm2, [_3]
    subsd    xmm1, xmm2

    movsd    xmm2, xmm0
    addsd    xmm2, xmm0

    movsd    xmm3, [_2]
    addsd    xmm2, xmm3    

    divsd    xmm1, xmm2 

    subsd    xmm0, xmm1

    loop    _calculate  

    mov    rax, 1
    mov    rdi, output    
    call    printf

    leave
    ret