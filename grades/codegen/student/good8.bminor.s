
.text
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
.L0: .string "asdf"

.text
LEA .L0, %r10
MOVQ %r10, -8(%rbp)

.data
.L1: .string "asdf"

.text
LEA .L1, %r11
MOVQ -8(%rbp), %r12
MOVQ %r11, %rdi
MOVQ %r12, %rsi
PUSHQ %r10
PUSHQ %r11
CALL string_equals
POPQ %r11
POPQ %r10
MOVQ %rax, %r10
CMP $0, %r10
JE .L2

.data
.L4: .string "good\n"

.text
LEA .L4, %r12
MOVQ %r12, %rdi
PUSHQ %r10
PUSHQ %r11
CALL print_string
POPQ %r11
POPQ %r10
MOVQ %rax, %r11
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

