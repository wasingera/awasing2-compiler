
.data
.global a
a: .quad 1, 2, 3, 4
.global i
i: .quad 1

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
MOVQ $0, %r11
MOVQ %r11, -8(%rbp)
MOVQ %r11, %r10
.L0:
MOVQ -8(%rbp), %r10
MOVQ $4, %r11
CMPQ %r11, %r10
JL .L2
MOVQ $0, %r11
JMP .L3
.L2:
MOVQ $1, %r11
.L3:
CMP $0, %r11
JE .L1
MOVQ i, %r11
MOVQ $5, %r12
ADDQ %r11, %r12
MOVQ %r12, i
MOVQ %r12, %r10
MOVQ i, %r11
LEA a, %r12
MOVQ -8(%rbp), %r13
MOVQ $8, %r14
MOVQ %r13, %rax
IMULQ %r14
MOVQ %rax, %r14
ADDQ %r14, %r12
MOVQ %r11, (%r12)
MOVQ %r11, %r10
LEA a, %r11
MOVQ -8(%rbp), %r12
MOVQ $8, %r13
MOVQ %r12, %rax
IMULQ %r13
MOVQ %rax, %r13
ADDQ %r13, %r11
MOVQ (%r11), %r11
MOVQ %r11, %rdi
PUSHQ %r10
PUSHQ %r11
CALL print_integer
POPQ %r11
POPQ %r10
MOVQ %rax, %r10
MOVQ $32, %r11
MOVQ %r11, %rdi
PUSHQ %r10
PUSHQ %r11
CALL print_character
POPQ %r11
POPQ %r10
MOVQ %rax, %r10
MOVQ -8(%rbp), %r10
MOVQ %r10, %r11
INCQ %r10
MOVQ %r10, -8(%rbp)
JMP .L0
.L1:
MOVQ $10, %r11
MOVQ %r11, %rdi
PUSHQ %r10
PUSHQ %r11
CALL print_character
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

