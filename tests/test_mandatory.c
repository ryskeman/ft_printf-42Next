#include "../ft_printf.h"
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	int		r1;
	int		r2;
	char	*nil;
	void	*p_nil;
	int		var;

	nil = NULL;
	p_nil = NULL;
	var = 42;
	printf("=== TEST MANDATORY 42 ===\n\n");

	// 1. Caracteres y Strings
	r1 = printf("ORIGINAL: [%c] [%s] [%s] [%%]\n", 'A', "Hola 42", nil);
	r2 = ft_printf("MI PRINT: [%c] [%s] [%s] [%%]\n", 'A', "Hola 42", nil);
	printf("Retorno: orig=%d, mio=%d\n\n", r1, r2);

	// 2. Enteros (int y unsigned)
	r1 = printf("ORIGINAL: [%d] [%i] [%d] [%u] [%u]\n", 0, -42, INT_MIN, 0, UINT_MAX);
	r2 = ft_printf("MI PRINT: [%d] [%i] [%d] [%u] [%u]\n", 0, -42, INT_MIN, 0, UINT_MAX);
	printf("Retorno: orig=%d, mio=%d\n\n", r1, r2);

	// 3. Hexadecimales (x y X)
	r1 = printf("ORIGINAL: [%x] [%X] [%x] [%X]\n", 0, 0, 255, 3735928559U);
	r2 = ft_printf("MI PRINT: [%x] [%X] [%x] [%X]\n", 0, 0, 255, 3735928559U);
	printf("Retorno: orig=%d, mio=%d\n\n", r1, r2);

	// 4. Punteros (p)
	r1 = printf("ORIGINAL: [%p] [%p]\n", p_nil, (void *)&var);
	r2 = ft_printf("MI PRINT: [%p] [%p]\n", p_nil, (void *)&var);
	printf("Retorno: orig=%d, mio=%d\n\n", r1, r2);

	return (0);
}