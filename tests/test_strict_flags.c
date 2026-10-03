#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

static void	compare(const char *desc, int r1, int r2)
{
	if (r1 == r2)
		printf("   └─ [OK] %s (ret: %d)\n\n", desc, r1);
	else
		printf("   └─ [FAIL] %s (Orig: %d | Mio: %d)\n\n", desc, r1, r2);
}

int	main(void)
{
	int			r1;
	int			r2;
	const char	*f1;
	const char	*f2;

	printf("=== TESTS: COLISIONES DE FLAGS Y LIMITES ===\n\n");

	/* 1. '-' anula al flag '0' */
	f1 = "ORIG: [%0-10d]\n";
	f2 = "MIO : [%0-10d]\n";
	r1 = printf(f1, 42);
	r2 = ft_printf(f2, 42);
	compare("minus vs zero", r1, r2);

	/* 2. '+' anula al flag ' ' */
	f1 = "ORIG: [%+ d]\n";
	f2 = "MIO : [%+ d]\n";
	r1 = printf(f1, 42);
	r2 = ft_printf(f2, 42);
	compare("plus vs space", r1, r2);

	/* 3. Cero con precision cero y ancho */
	f1 = "ORIG: [%5.0d] [%5.0u] [%#.0x]\n";
	f2 = "MIO : [%5.0d] [%5.0u] [%#.0x]\n";
	r1 = printf(f1, 0, 0, 0);
	r2 = ft_printf(f2, 0, 0, 0);
	compare("zero value with precision 0", r1, r2);

	/* 4. String con precision 0 y ancho */
	f1 = "ORIG: [%10.0s]\n";
	f2 = "MIO : [%10.0s]\n";
	r1 = printf(f1, "hola");
	r2 = ft_printf(f2, "hola");
	compare("string precision zero", r1, r2);

	return (0);
}
