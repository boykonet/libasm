global		_ft_strcmp

_ft_strcmp:
			xor		rax, rax
			xor		rcx, rcx
			xor		rdx, rdx

_loop:
			mov		cl, byte[rdi + rax]
			mov		dl, byte[rsi + rax]
			cmp		cl, 0
			je		_end
			cmp		dl, 0
			je		_end
			cmp		dl, cl
			jne		_end
			inc		rax
			jmp		_loop

_end:
			sub		rcx, rdx
			mov		rax, rcx
			ret
