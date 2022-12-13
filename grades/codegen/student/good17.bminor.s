
.data
.global s1
s1: .quad .L0

.L0: .string " fun and good\n"

.text
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


.data
.L1: .string "I'm printing "

.text
LEA .L1, %r11
MOVQ %r11, %rdi
PUSHQ %r10
PUSHQ %r11
CALL print_string
POPQ %r11
POPQ %r10
MOVQ %rax, %r10
MOVQ -8(%rbp), %r11
MOVQ %r11, %rdi
PUSHQ %r10
PUSHQ %r11
CALL print_string
POPQ %r11
POPQ %r10
MOVQ %rax, %r10

.data
.L2: .string "!\n"

.text
LEA .L2, %r11
MOVQ %r11, %rdi
PUSHQ %r10
PUSHQ %r11
CALL print_string
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


.data
.L3: .string " money "

.text
LEA .L3, %r10
MOVQ %r10, -8(%rbp)

.data
.L4: .string "Big"

.text
LEA .L4, %r11
MOVQ %r11, %rdi
PUSHQ %r10
PUSHQ %r11
CALL print_string
POPQ %r11
POPQ %r10
MOVQ %rax, %r10
MOVQ -8(%rbp), %r11
MOVQ %r11, %rdi
PUSHQ %r10
PUSHQ %r11
CALL print_string
POPQ %r11
POPQ %r10
MOVQ %rax, %r10
MOVQ s1, %r11
MOVQ %r11, %rdi
PUSHQ %r10
PUSHQ %r11
CALL print_string
POPQ %r11
POPQ %r10
MOVQ %rax, %r10
MOVQ s1, %r11
MOVQ %r11, %rdi
PUSHQ %r10
PUSHQ %r11
CALL f
POPQ %r11
POPQ %r10
MOVQ %rax, %r10
MOVQ -8(%rbp), %r11
MOVQ %r11, %rdi
PUSHQ %r10
PUSHQ %r11
CALL f
POPQ %r11
POPQ %r10
MOVQ %rax, %r10

.data
.L5: .string "Fun!"

.text
LEA .L5, %r11
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

