
.data
.global f

.text
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

MOVQ $5, %r11
MOVQ %r11, %rdi
PUSHQ %r10
PUSHQ %r11
CALL f
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

.global f
f: 
PUSHQ %rbp
MOVQ %rsp, %rbp

PUSHQ %rdi

SUBQ $0, %rsp

PUSHQ %rbx
PUSHQ %r12
PUSHQ %r13
PUSHQ %r14
PUSHQ %r15

MOVQ -8(%rbp), %r10
MOVQ $0, %r11
CMPQ %r11, %r10
JL .L0
MOVQ $0, %r11
JMP .L1
.L0:
MOVQ $1, %r11
.L1:
CMP $0, %r11
JE .L2
JMP .f_epilogue
JMP .L3
.L2:
.L3:
MOVQ -8(%rbp), %r11
MOVQ %r11, %rdi
PUSHQ %r10
PUSHQ %r11
CALL print_integer
POPQ %r11
POPQ %r10
MOVQ %rax, %r10
MOVQ $10, %r11
MOVQ %r11, %rdi
PUSHQ %r10
PUSHQ %r11
CALL print_character
POPQ %r11
POPQ %r10
MOVQ %rax, %r10
MOVQ -8(%rbp), %r11
MOVQ $1, %r12
SUBQ %r12, %r11
MOVQ %r11, %rdi
PUSHQ %r10
PUSHQ %r11
CALL f
POPQ %r11
POPQ %r10
MOVQ %rax, %r10

.f_epilogue:
POPQ %r15
POPQ %r14
POPQ %r13
POPQ %r12
POPQ %rbx
MOVQ %rbp, %rsp
POPQ %rbp
RET

