#include "../ft_printf.h"
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	int		r1;
	int		r2;
	char	*nil;
	void	*p_nil;

	nil = NULL;
	p_nil = NULL;
	printf("--- TESTS CRITICOS ---\n");

	/* 1. Strings nulos y precisión límite */
	r1 = printf("ORIGINAL: [%.3s] [%.6s] [%10s]\n", nil, nil, nil);
	r2 = ft_printf("MI PRINT: [%.3s] [%.6s] [%10s]\n", nil, nil, nil);
	printf("Retorno: orig=%d, mio=%d\n\n", r1, r2);

	/* 2. Límites de enteros */
	r1 = printf("ORIGINAL: [%d] [%+d] [%012d] [%.0d]\n", INT_MIN, 42, -42, 0);
	r2 = ft_printf("MI PRINT: [%d] [%+d] [%012d] [%.0d]\n", INT_MIN, 42, -42, 0);
	printf("Retorno: orig=%d, mio=%d\n\n", r1, r2);

	/* 3. Unsigned y Hexadecimal con flag # */
	r1 = printf("ORIGINAL: [%u] [%#x] [%#X] [%#x]\n", 4294967295U, 255, 255, 0);
	r2 = ft_printf("MI PRINT: [%u] [%#x] [%#X] [%#x]\n", 4294967295U, 255, 255, 0);
	printf("Retorno: orig=%d, mio=%d\n\n", r1, r2);

	/* 4. Puntero nulo y direcciones */
	r1 = printf("ORIGINAL: [%p] [%20p]\n", p_nil, (void *)&r1);
	r2 = ft_printf("MI PRINT: [%p] [%20p]\n", p_nil, (void *)&r1);
	printf("Retorno: orig=%d, mio=%d\n\n", r1, r2);

	return (0);
}
