global		_ft_strcpy

_ft_strcpy:
			xor		rax, rax

_loop:
			cmp		byte[rsi + rax], 0
			je		_end
			mov		dl, byte[rsi + rax]
			mov		byte[rdi + rax], dl
			inc		rax
			jmp		_loop

_end:
			mov		byte[rdi + rax], 0
			mov		rax, rdi
			ret
