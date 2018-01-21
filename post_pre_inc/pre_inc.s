	.file	"pre_inc.cpp"
	.section	.text.startup,"ax",@progbits
	.p2align 4,,15
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	movl	$0, -4(%rsp)
	movl	-4(%rsp), %eax
	cmpl	$4, %eax
	jg	.L3
	.p2align 4,,10
	.p2align 3
.L4:
	movl	-4(%rsp), %eax
	movl	%eax, -4(%rsp)
	movl	-4(%rsp), %eax
	addl	$1, %eax
	movl	%eax, -4(%rsp)
	movl	-4(%rsp), %eax
	cmpl	$4, %eax
	jle	.L4
.L3:
	movl	-4(%rsp), %eax
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (GNU) 6.3.1 20161221 (Red Hat 6.3.1-1)"
	.section	.note.GNU-stack,"",@progbits
