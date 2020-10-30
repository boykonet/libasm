global		_ft_write
extern		___error

_ft_write:
			xor		rax, rax
			mov		rax, 0x02000004
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
