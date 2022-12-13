
.data
.global a
a: .quad 97, 98

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

LEA a, %r10
MOVQ $0, %r11
MOVQ $8, %r12
MOVQ %r11, %rax
IMULQ %r12
MOVQ %rax, %r12
ADDQ %r12, %r10
MOVQ (%r10), %r10
MOVQ $97, %r10
CMPQ %r10, %r10
JE .L0
MOVQ $0, %r10
JMP .L1
.L0:
MOVQ $1, %r10
.L1:
CMP $0, %r10
JE .L2
LEA a, %r11
MOVQ $0, %r12
MOVQ $8, %r13
MOVQ %r12, %rax
IMULQ %r13
MOVQ %rax, %r13
ADDQ %r13, %r11
MOVQ (%r11), %r11
MOVQ %r11, %rdi
PUSHQ %r10
PUSHQ %r11
CALL print_character
POPQ %r11
POPQ %r10
MOVQ %rax, %r10
JMP .L3
.L2:
.L3:
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

