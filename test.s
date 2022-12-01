
.data
s: .string "asdf\n"
x: .quad 0
a: .quad 1, 2, 3, 4, 5

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

MOVQ $0, %r10
MOVQ %r10, -8(%rbp)
.L0:
MOVQ -8(%rbp), %r11
MOVQ $10, %r12
CMPQ %r12, %r11
JL .L2
MOVQ $0, %r12
JMP .L3
.L2:
MOVQ $1, %r12
.L3:
CMP $0, %r12
JE .L1
MOVQ -8(%rbp), %r12
MOVQ $1, %r13
ADDQ %r12, %r13
MOVQ %r13, -8(%rbp)
MOVQ %r13, %r11
MOVQ -8(%rbp), %r12
MOVQ %r12, %rdi
PUSHQ %r10
PUSHQ %r11
CALL print_integer
POPQ %r11
POPQ %r10
MOVQ %rax, %r11
MOVQ $10, %r13
MOVQ %r13, %rdi
PUSHQ %r10
PUSHQ %r11
CALL print_character
POPQ %r11
POPQ %r10
MOVQ %rax, %r12
JMP .L0
.L1:

.main_epilogue:
POPQ %r15
POPQ %r14
POPQ %r13
POPQ %r12
POPQ %rbx
MOVQ %rbp, %rsp
POPQ %rbp
RET
