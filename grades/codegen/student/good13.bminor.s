
.data
.global nd
nd: .quad 104, 101, 108, 108, 111, 10

.text
.global print_char_array
print_char_array: 
PUSHQ %rbp
MOVQ %rsp, %rbp

PUSHQ %rdi

SUBQ $8, %rsp

PUSHQ %rbx
PUSHQ %r12
PUSHQ %r13
PUSHQ %r14
PUSHQ %r15

MOVQ $0, %r10
MOVQ %r10, -16(%rbp)
MOVQ $0, %r11
MOVQ %r11, -16(%rbp)
MOVQ %r11, %r10
.L0:
MOVQ -16(%rbp), %r10
MOVQ $6, %r11
CMPQ %r11, %r10
JL .L2
MOVQ $0, %r11
JMP .L3
.L2:
MOVQ $1, %r11
.L3:
CMP $0, %r11
JE .L1
MOVQ -8(%rbp), %r11
MOVQ -16(%rbp), %r12
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
MOVQ -16(%rbp), %r10
MOVQ %r10, %r11
INCQ %r10
MOVQ %r10, -16(%rbp)
JMP .L0
.L1:

.print_char_array_epilogue:
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

LEA nd, %r11
MOVQ %r11, %rdi
PUSHQ %r10
PUSHQ %r11
CALL print_char_array
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

