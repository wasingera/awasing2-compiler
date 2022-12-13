
.text
.global main
main: 
PUSHQ %rbp
MOVQ %rsp, %rbp


SUBQ $16, %rsp

PUSHQ %rbx
PUSHQ %r12
PUSHQ %r13
PUSHQ %r14
PUSHQ %r15

MOVQ $0, %r10
MOVQ %r10, -8(%rbp)
MOVQ $0, %r10
MOVQ %r10, -16(%rbp)
MOVQ $0, %r11
MOVQ %r11, -16(%rbp)
MOVQ %r11, %r10
.L0:
MOVQ -8(%rbp), %r10
MOVQ $20, %r11
CMPQ %r11, %r10
JL .L2
MOVQ $0, %r11
JMP .L3
.L2:
MOVQ $1, %r11
.L3:
CMP $0, %r11
JE .L1
MOVQ -16(%rbp), %r10
MOVQ $3, %r11
MOVQ %r10, %rax
CQO
IDIVQ %r11
MOVQ %rdx, %r11
MOVQ $0, %r10
CMPQ %r10, %r11
JE .L4
MOVQ $0, %r10
JMP .L5
.L4:
MOVQ $1, %r10
.L5:
MOVQ -16(%rbp), %r11
MOVQ $5, %r12
MOVQ %r11, %rax
CQO
IDIVQ %r12
MOVQ %rdx, %r12
MOVQ $0, %r11
CMPQ %r11, %r12
JE .L6
MOVQ $0, %r11
JMP .L7
.L6:
MOVQ $1, %r11
.L7:
ANDQ %r10, %r11
CMP $0, %r11
JE .L8
MOVQ -16(%rbp), %r12
MOVQ %r12, %rdi
PUSHQ %r10
PUSHQ %r11
CALL print_integer
POPQ %r11
POPQ %r10
MOVQ %rax, %r10

.data
.L10: .string " FizzBuzz\n"

.text
LEA .L10, %r12
MOVQ %r12, %rdi
PUSHQ %r10
PUSHQ %r11
CALL print_string
POPQ %r11
POPQ %r10
MOVQ %rax, %r10
MOVQ -8(%rbp), %r10
MOVQ %r10, %r12
INCQ %r10
MOVQ %r10, -8(%rbp)
JMP .L9
.L8:
MOVQ -16(%rbp), %r10
MOVQ $5, %r12
MOVQ %r10, %rax
CQO
IDIVQ %r12
MOVQ %rdx, %r12
MOVQ $0, %r10
CMPQ %r10, %r12
JE .L11
MOVQ $0, %r10
JMP .L12
.L11:
MOVQ $1, %r10
.L12:
CMP $0, %r10
JE .L13
MOVQ -16(%rbp), %r13
MOVQ %r13, %rdi
PUSHQ %r10
PUSHQ %r11
CALL print_integer
POPQ %r11
POPQ %r10
MOVQ %rax, %r12

.data
.L15: .string " Buzz\n"

.text
LEA .L15, %r13
MOVQ %r13, %rdi
PUSHQ %r10
PUSHQ %r11
CALL print_string
POPQ %r11
POPQ %r10
MOVQ %rax, %r12
MOVQ -8(%rbp), %r12
MOVQ %r12, %r13
INCQ %r12
MOVQ %r12, -8(%rbp)
JMP .L14
.L13:
MOVQ -16(%rbp), %r12
MOVQ $3, %r13
MOVQ %r12, %rax
CQO
IDIVQ %r13
MOVQ %rdx, %r13
MOVQ $0, %r12
CMPQ %r12, %r13
JE .L16
MOVQ $0, %r12
JMP .L17
.L16:
MOVQ $1, %r12
.L17:
CMP $0, %r12
JE .L18
MOVQ -16(%rbp), %r14
MOVQ %r14, %rdi
PUSHQ %r10
PUSHQ %r11
CALL print_integer
POPQ %r11
POPQ %r10
MOVQ %rax, %r13

.data
.L20: .string " Fizz\n"

.text
LEA .L20, %r14
MOVQ %r14, %rdi
PUSHQ %r10
PUSHQ %r11
CALL print_string
POPQ %r11
POPQ %r10
MOVQ %rax, %r13
MOVQ -8(%rbp), %r13
MOVQ %r13, %r14
INCQ %r13
MOVQ %r13, -8(%rbp)
JMP .L19
.L18:
.L19:
.L14:
.L9:
MOVQ -16(%rbp), %r10
MOVQ %r10, %r11
INCQ %r10
MOVQ %r10, -16(%rbp)
JMP .L0
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

