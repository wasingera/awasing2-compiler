
.data
.global x
x: .quad 5

.text
.global main
main: 
PUSHQ %rbp
MOVQ %rsp, %rbp


SUBQ $8, %rsp

PUSHQ %rbx
PUSHQ %r12
PUSHQ %r13
PUSHQ %r14
PUSHQ %r15

MOVQ $5, %r11
MOVQ $5, %r12
MOVQ %r11, %rdi
MOVQ %r12, %rsi
PUSHQ %r10
PUSHQ %r11
CALL integer_power
POPQ %r11
POPQ %r10
MOVQ %rax, %r10
MOVQ %r10, -8(%rbp)
MOVQ x, %r11
MOVQ -8(%rbp), %r12
ADDQ %r11, %r12
MOVQ %r12, %rdi
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

