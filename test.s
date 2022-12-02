
.data
str: .string "hello"

.text
.global main
main: 
PUSHQ %rbp
MOVQ %rsp, %rbp


SUBQ $16, %rsp

PUSHQ %rbx
PUSHQ %r12
PUSHQ %r13
PUSHQ %r14
PUSHQ %r15

MOVQ $5, %r10
MOVQ %r10, -8(%rbp)
MOVQ -8(%rbp), %r11
MOVQ %r11, %rdi
PUSHQ %r10
PUSHQ %r11
CALL print_integer
POPQ %r11
POPQ %r10
MOVQ %rax, %r10
MOVQ $6, %r10
MOVQ %r10, -16(%rbp)
MOVQ -8(%rbp), %r11
MOVQ %r11, %rdi
PUSHQ %r10
PUSHQ %r11
CALL print_integer
POPQ %r11
POPQ %r10
MOVQ %rax, %r10
MOVQ -16(%rbp), %r11
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

