.data

.global x
x:
	.quad 5
.text

.global main
main:
	pushq %rbp
	movq  %rsp, %rbp
	subq $8,%rsp
	pushq %rbx
	pushq %r12
	pushq %r13
	pushq %r14
	pushq %r15
	movq $5,%rbx
	movq $5,%r10
	movq %rbx, %rdi
	movq %r10, %rsi
	pushq %r10
	pushq %r11
	call integer_power
	popq %r11
	popq %r10
	movq %rax, %rbx
	movq %rbx, -8(%rbp)
	movq x,%rbx
	movq -8(%rbp),%r10
	add %rbx, %r10
	pushq %r10
	pushq %r11
	mov %r10, %rdi
	call print_integer
	popq %r11
	popq %r10
	movq $0,%rbx
	movq %rbx,%rax
	popq %r15
	popq %r14
	popq %r13
	popq %r12
	popq %rbx
	movq %rbp, %rsp
	popq %rbp
	ret
	popq %r15
	popq %r14
	popq %r13
	popq %r12
	popq %rbx
	movq  %rbp, %rsp
	popq %rbp
	ret
