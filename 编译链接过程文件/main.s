	.file	"main.c"
.globl data1
	.data
	.align 4
	.type	data1, @object
	.size	data1, 4
data1:
	.long	10
.globl data2
	.bss
	.align 4
	.type	data2, @object
	.size	data2, 4
data2:
	.zero	4
	.comm	data3,4,4
	.data
	.align 4
	.type	data4, @object
	.size	data4, 4
data4:
	.long	20
	.local	data5
	.comm	data5,4,4
	.local	data6
	.comm	data6,4,4
	.text
.globl main
	.type	main, @function
main:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$16, %esp
	movl	$30, -12(%ebp)
	movl	$0, -8(%ebp)
	movl	$0, %eax
	leave
	ret
	.size	main, .-main
	.local	data9.1246
	.comm	data9.1246,4,4
	.local	data8.1245
	.comm	data8.1245,4,4
	.data
	.align 4
	.type	data7.1244, @object
	.size	data7.1244, 4
data7.1244:
	.long	40
	.ident	"GCC: (GNU) 4.4.6 20120305 (Red Hat 4.4.6-4)"
	.section	.note.GNU-stack,"",@progbits
