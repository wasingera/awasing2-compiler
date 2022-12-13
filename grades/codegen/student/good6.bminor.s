
.data
.global s
s: .quad .L0

.L0: .string "asdf"

.text
.global f
f: 
PUSHQ %rbp
MOVQ %rsp, %rbp

PUSHQ %rdi
PUSHQ %rsi
PUSHQ %rdx

SUBQ $0, %rsp

PUSHQ %rbx
PUSHQ %r12
PUSHQ %r13
PUSHQ %r14
PUSHQ %r15

MOVQ -8(%rbp), %r11
MOVQ %r11, %rdi
PUSHQ %r10
PUSHQ %r11
CALL print_string
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
MOVQ -16(%rbp), %r11
MOVQ %r11, %rdi
PUSHQ %r10
PUSHQ %r11
CALL print_string
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
MOVQ -24(%rbp), %r11
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

PUSHQ %rdi

SUBQ $8, %rsp

PUSHQ %rbx
PUSHQ %r12
PUSHQ %r13
PUSHQ %r14
PUSHQ %r15


.data
.L1: .string "fda"

.text
LEA .L1, %r10
MOVQ %r10, -16(%rbp)
MOVQ s, %r11
MOVQ -16(%rbp), %r12

.data
.L2: .string "big\n"

.text
LEA .L2, %r13
MOVQ %r11, %rdi
MOVQ %r12, %rsi
MOVQ %r13, %rdx
PUSHQ %r10
PUSHQ %r11
CALL f
POPQ %r11
POPQ %r10
MOVQ %rax, %r10

.main_epilogue:
POPQ %r15
POPQ %r14
POPQ %r13
POPQ %r12
POPQ %rbx
MOVQ %rbp, %rsp
POPQ %rbp
RET

