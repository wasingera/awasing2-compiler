
.data
.global a
a: .quad 1, 2, 3

.text
.global f
f: 
PUSHQ %rbp
MOVQ %rsp, %rbp

PUSHQ %rdi
PUSHQ %rsi

SUBQ $0, %rsp

PUSHQ %rbx
PUSHQ %r12
PUSHQ %r13
PUSHQ %r14
PUSHQ %r15

MOVQ -8(%rbp), %r10
MOVQ -16(%rbp), %r11
MOVQ $8, %r12
MOVQ %r11, %rax
IMULQ %r12
MOVQ %rax, %r12
ADDQ %r12, %r10
MOVQ (%r10), %r10
MOVQ %r10, %rax
JMP .f_epilogue

.f_epilogue:
POPQ %r15
POPQ %r14
POPQ %r13
POPQ %r12
POPQ %rbx
MOVQ %rbp, %rsp
POPQ %rbp
RET

.global main
main: 
PUSHQ %rbp
MOVQ %rsp, %rbp


SUBQ $0, %rsp

PUSHQ %rbx
PUSHQ %r12
PUSHQ %r13
PUSHQ %r14
PUSHQ %r15

LEA a, %r12
MOVQ $1, %r13
MOVQ %r12, %rdi
MOVQ %r13, %rsi
PUSHQ %r10
PUSHQ %r11
CALL f
POPQ %r11
POPQ %r10
MOVQ %rax, %r11
MOVQ %r11, %rdi
PUSHQ %r10
PUSHQ %r11
CALL print_integer
POPQ %r11
POPQ %r10
MOVQ %rax, %r10
MOVQ $0, %r10
MOVQ %r10, %rax
JMP .main_epilogue

.main_epilogue:
POPQ %r15
POPQ %r14
POPQ %r13
POPQ %r12
POPQ %rbx
MOVQ %rbp, %rsp
POPQ %rbp
RET

