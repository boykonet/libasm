global		_ft_read
extern		___error

_ft_read:
			xor		rax, rax
			mov		rax, 0x02000003
			syscall
			push	rax
			jnc		_no_error
			call	___error
			pop		rbx
			mov		[rax], rbx
			mov		rax, -1
			ret

_no_error:
			pop		rax
			ret
