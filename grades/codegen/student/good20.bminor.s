
.data
.global a
a: .quad 0, 0, 0, 0, 0
.text
.global make_array
make_array: 
PUSHQ %rbp
MOVQ %rsp, %rbp

PUSHQ %rdi
PUSHQ %rsi

SUBQ $8, %rsp

PUSHQ %rbx
PUSHQ %r12
PUSHQ %r13
PUSHQ %r14
PUSHQ %r15

MOVQ $0, %r10
MOVQ %r10, -24(%rbp)
MOVQ $0, %r11
MOVQ %r11, -24(%rbp)
MOVQ %r11, %r10
.L0:
MOVQ -24(%rbp), %r10
MOVQ -16(%rbp), %r11
CMPQ %r11, %r10
JL .L2
MOVQ $0, %r11
JMP .L3
.L2:
MOVQ $1, %r11
.L3:
CMP $0, %r11
JE .L1
MOVQ -24(%rbp), %r11
MOVQ -8(%rbp), %r12
MOVQ -24(%rbp), %r13
MOVQ $8, %r14
MOVQ %r13, %rax
IMULQ %r14
MOVQ %rax, %r14
ADDQ %r14, %r12
MOVQ %r11, (%r12)
MOVQ %r11, %r10
MOVQ -24(%rbp), %r10
MOVQ %r10, %r11
INCQ %r10
MOVQ %r10, -24(%rbp)
JMP .L0
.L1:

.make_array_epilogue:
POPQ %r15
POPQ %r14
POPQ %r13
POPQ %r12
POPQ %rbx
MOVQ %rbp, %rsp
POPQ %rbp
RET

.global print_array
print_array: 
PUSHQ %rbp
MOVQ %rsp, %rbp

PUSHQ %rdi
PUSHQ %rsi

SUBQ $8, %rsp

PUSHQ %rbx
PUSHQ %r12
PUSHQ %r13
PUSHQ %r14
PUSHQ %r15

MOVQ $0, %r10
MOVQ %r10, -24(%rbp)
MOVQ $0, %r11
MOVQ %r11, -24(%rbp)
MOVQ %r11, %r10
.L4:
MOVQ -24(%rbp), %r10
MOVQ -16(%rbp), %r11
CMPQ %r11, %r10
JL .L6
MOVQ $0, %r11
JMP .L7
.L6:
MOVQ $1, %r11
.L7:
CMP $0, %r11
JE .L5
MOVQ -8(%rbp), %r11
MOVQ -24(%rbp), %r12
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
MOVQ -24(%rbp), %r10
MOVQ %r10, %r11
INCQ %r10
MOVQ %r10, -24(%rbp)
JMP .L4
.L5:

.print_array_epilogue:
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

LEA a, %r11
MOVQ $5, %r12
MOVQ %r11, %rdi
MOVQ %r12, %rsi
PUSHQ %r10
PUSHQ %r11
CALL make_array
POPQ %r11
POPQ %r10
MOVQ %rax, %r10
LEA a, %r11
MOVQ $5, %r12
MOVQ %r11, %rdi
MOVQ %r12, %rsi
PUSHQ %r10
PUSHQ %r11
CALL print_array
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

