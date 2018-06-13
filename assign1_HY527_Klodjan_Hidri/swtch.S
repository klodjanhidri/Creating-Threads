#function for context switching
# _swtch(thread *from,thread *to){}

.align	
.globl	__swtch
.globl	_swtch
__swtch:
_swtch:
	subl	$16,%esp	#get local storage for 4 words
	movl	%ebx,0(%esp)	#store [(thread)from] args 		to [sp + 0]
	movl	%esi,4(%esp)	#store [(thread)from]     		to [sp + 4]
	movl	%edi,8(%esp)	#store [(thread)from]			to [sp + 8]
	movl	%ebp,12(%esp)	#store [(thread)from] stack frame 	to [sp + 12]
	movl	20(%esp),%eax	#put   [(thread)from] value 		of [sp + 20] to [eax]
	movl	%esp,0(%eax)    #put sp address of [(thread)from] 	to [eax + 0]
	movl	24(%esp),%eax	#put value of [sp+24] of [(thread)from] to [eax]
	movl	0(%eax),%esp	#load value  [eax+ 0] of [(thread)to]   to [sp]
	movl	0(%esp),%ebx	#load value  [sp + 0] of [(thread)to]   to [ebx] 
	movl	4(%esp),%esi	#load value  [sp + 4] of [(thread)to]   to [esi]
	movl	8(%esp),%edi	#load value  [sp + 8] of [(thread)to]   to [edi]
	movl	12(%esp),%ebp   #load value  [sp + 12] of [(thread)to]  to [ebp]
	addl	$16, %esp	#free local storage of 4 words
	ret
.align	4
.globl	__thrstart
.globl	_thrstart
__thrstart:
_thrstart:
	pushl	%edi
	call	%esi
	pushl	%eax
	call	Thread_exit
.globl	__ENDMONITOR
.globl	_ENDMONITOR
__ENDMONITOR:
_ENDMONITOR:
