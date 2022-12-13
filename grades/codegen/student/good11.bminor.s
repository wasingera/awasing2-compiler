
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

MOVQ $8, %r12
MOVQ $5, %r13
MOVQ $3, %r14
MOVQ %r13, %rax
IMULQ %r14
MOVQ %rax, %r14
MOVQ $4, %r13
MOVQ $6, %r15
ADDQ %r13, %r15
SUBQ %r15, %r14
MOVQ %r12, %rdi
MOVQ %r14, %rsi
PUSHQ %r10
PUSHQ %r11
CALL integer_power
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

