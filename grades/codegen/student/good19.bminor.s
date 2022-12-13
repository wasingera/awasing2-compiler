
.data
.global g
g: .quad .L0

.L0: .string "global\n"

.text
.global f2
f2: 
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
.L1: .string "second\n"

.text
LEA .L1, %r11
MOVQ %r11, %rdi
PUSHQ %r10
PUSHQ %r11
CALL print_string
POPQ %r11
POPQ %r10
MOVQ %rax, %r10
MOVQ -8(%rbp), %r10
MOVQ %r10, %rax
JMP .f2_epilogue

.f2_epilogue:
POPQ %r15
POPQ %r14
POPQ %r13
POPQ %r12
POPQ %rbx
MOVQ %rbp, %rsp
POPQ %rbp
RET

.global f1
f1: 
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
.L2: .string "first\n"

.text
LEA .L2, %r11
MOVQ %r11, %rdi
PUSHQ %r10
PUSHQ %r11
CALL print_string
POPQ %r11
POPQ %r10
MOVQ %rax, %r10
MOVQ -8(%rbp), %r12
MOVQ %r12, %rdi
PUSHQ %r10
PUSHQ %r11
CALL f2
POPQ %r11
POPQ %r10
MOVQ %rax, %r11
MOVQ %r11, %rdi
PUSHQ %r10
PUSHQ %r11
CALL print_string
POPQ %r11
POPQ %r10
MOVQ %rax, %r10

.data
.L3: .string "done"

.text
LEA .L3, %r10
MOVQ %r10, %rax
JMP .f1_epilogue

.f1_epilogue:
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


.data
.L4: .string "test string\n"

.text
LEA .L4, %r11
MOVQ %r11, %rdi
PUSHQ %r10
PUSHQ %r11
CALL f1
POPQ %r11
POPQ %r10
MOVQ %rax, %r10
MOVQ g, %r11
MOVQ %r11, %rdi
PUSHQ %r10
PUSHQ %r11
CALL f1
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

