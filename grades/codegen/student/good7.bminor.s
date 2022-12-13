
.text
.global main
main: 
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
MOVQ $1, %r11
CMPQ %r11, %r10
JG .L0
MOVQ $0, %r11
JMP .L1
.L0:
MOVQ $1, %r11
.L1:
CMP $0, %r11
JE .L2

.data
.L4: .string "args passed\n"

.text
LEA .L4, %r12
MOVQ %r12, %rdi
PUSHQ %r10
PUSHQ %r11
CALL print_string
POPQ %r11
POPQ %r10
MOVQ %rax, %r10
JMP .L3
.L2:

.data
.L5: .string "no args :("

.text
LEA .L5, %r12
MOVQ %r12, %rdi
PUSHQ %r10
PUSHQ %r11
CALL print_string
POPQ %r11
POPQ %r10
MOVQ %rax, %r10
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

