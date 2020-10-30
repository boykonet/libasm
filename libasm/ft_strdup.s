global		_ft_strdup
extern		_malloc
extern		_ft_strlen
extern		_ft_strcpy

_ft_strdup:
			push	rdi
			call	_ft_strlen
			mov		rdi, rax
			inc		rdi
			call	_malloc
			pop		rsi
			cmp		rax, 0
			je		_error
			mov		rdi, rax
			call	_ft_strcpy

_error:
			ret
