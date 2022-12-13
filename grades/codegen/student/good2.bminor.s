
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

MOVQ $1, %r10
CMP $0, %r10
JE .L0

.data
.L2: .string "good"

.text
LEA .L2, %r12
MOVQ %r12, %rdi
PUSHQ %r10
PUSHQ %r11
CALL print_string
POPQ %r11
POPQ %r10
MOVQ %rax, %r11
JMP .L1
.L0:

.data
.L3: .string "false"

.text
LEA .L3, %r12
MOVQ %r12, %rdi
PUSHQ %r10
PUSHQ %r11
CALL print_string
POPQ %r11
POPQ %r10
MOVQ %rax, %r11
.L1:
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

