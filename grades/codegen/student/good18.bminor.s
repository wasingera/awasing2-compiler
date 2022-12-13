
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

MOVQ -8(%rbp), %r10
MOVQ $1, %r11
CMPQ %r11, %r10
JLE .L0
MOVQ $0, %r11
JMP .L1
.L0:
MOVQ $1, %r11
.L1:
CMP $0, %r11
JE .L2
MOVQ $1, %r10
MOVQ %r10, %rax
JMP .f2_epilogue
JMP .L3
.L2:
.L3:
MOVQ -8(%rbp), %r11
MOVQ $1, %r12
SUBQ %r12, %r11
MOVQ %r11, %rdi
PUSHQ %r10
PUSHQ %r11
CALL f2
POPQ %r11
POPQ %r10
MOVQ %rax, %r10
MOVQ -8(%rbp), %r11
MOVQ %r10, %rax
IMULQ %r11
MOVQ %rax, %r11
MOVQ %r11, %rax
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

.global f
f: 
PUSHQ %rbp
MOVQ %rsp, %rbp


SUBQ $0, %rsp

PUSHQ %rbx
PUSHQ %r12
PUSHQ %r13
PUSHQ %r14
PUSHQ %r15

MOVQ $6, %r11
MOVQ %r11, %rdi
PUSHQ %r10
PUSHQ %r11
CALL f2
POPQ %r11
POPQ %r10
MOVQ %rax, %r10
MOVQ %r10, %rax
JMP .f_epilogue

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


SUBQ $0, %rsp

PUSHQ %rbx
PUSHQ %r12
PUSHQ %r13
PUSHQ %r14
PUSHQ %r15

PUSHQ %r10
PUSHQ %r11
CALL f
POPQ %r11
POPQ %r10
MOVQ %rax, %r11
MOVQ %r11, %rdi
PUSHQ %r10
PUSHQ %r11
CALL print_integer
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

