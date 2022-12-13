.data

.global nd
nd:
	.quad 104
	.quad 101
	.quad 108
	.quad 108
	.quad 111
	.quad 10
.text

.global print_char_array
print_char_array:
	pushq %rbp
	movq  %rsp, %rbp
	pushq %rdi
	subq $8,%rsp
	pushq %rbx
	pushq %r12
	pushq %r13
	pushq %r14
	pushq %r15
	movq $0,%rbx
	mov %rbx, -16(%rbp)
.L1:
	movq -16(%rbp),%rbx
	movq $6,%r10
	cmp %r10, %rbx
	jl .L3
	mov $0, %rbx
	jmp .L4
.L3:
	mov $1, %rbx
.L4:
	cmp $0, %rbx
	jz .L2
	movq -8(%rbp),%rbx
	movq -16(%rbp),%r10
	mov (%rbx,%r10,8), %r11
	pushq %r10
	pushq %r11
	mov %r11, %rdi
	call print_character
	popq %r11
	popq %r10
	leaq -16(%rbp), %rbx
	mov (%rbx), %r10
	mov %r10, %r11
	add $1, %r10
	mov %r10, (%rbx)
	jmp .L1
.L2:
	popq %r15
	popq %r14
	popq %r13
	popq %r12
	popq %rbx
	movq  %rbp, %rsp
	popq %rbp
	ret
.text

.global main
main:
	pushq %rbp
	movq  %rsp, %rbp
	subq $0,%rsp
	pushq %rbx
	pushq %r12
	pushq %r13
	pushq %r14
	pushq %r15
	leaq nd,%rbx
	mov %rbx, %rdi
	pushq %r10
	pushq %r11
	call print_char_array
	popq %r11
	popq %r10
	movq %rax, %rbx
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
