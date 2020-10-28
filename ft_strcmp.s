global		_ft_strcmp

_ft_strcmp:
			xor		rax, rax
_loop:
			mov		dl, byte[rdi + rax]
			mov		dh, byte[rsi + rax]
			cmp		dl, dh
			jne		_end
			inc		rax
			jmp		_loop

_end:
			sub		dl, dh
			mov		rax, dl
			ret
