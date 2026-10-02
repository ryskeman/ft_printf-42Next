*Este proyecto ha sido creado como parte del currículo de 42 por fernfern.*

# ft_printf

## Descripción
`ft_printf` es una reimplementación de la función estándar `printf` de la biblioteca `libc`. El objetivo principal es profundizar en el manejo de funciones variádicas en C (`stdarg.h`), el parseo estructurado de cadenas de formato y la gestión precisa de memoria y flujos de salida de bajo nivel (`write`).

El proyecto cubre tanto la parte obligatoria como la totalidad de los bonus requeridos por el currículo de 42:
- **Conversiones obligatorias:** `%c`, `%s`, `%p`, `%d`, `%i`, `%u`, `%x`, `%X`, `%%`.
- **Banderas (Flags):** `-` (alineación a la izquierda), `0` (relleno con ceros), `.` (precisión), `#` (prefijo alternativo hexadecimal), `+` (signo explícito), `' '` (espacio para valores positivos).
- **Dimensiones:** Ancho mínimo de campo (*field minimum width*).

---

## Instrucciones

### Compilación
La librería se compila usando `make`. El `Makefile` incluye las reglas estándar exigidas:

```bash
# Compila la librería libftprintf.a con soporte para la parte obligatoria
make

# Compila la librería libftprintf.a incluyendo la gestión completa de bonus
make bonus

# Elimina los archivos objeto (.o)
make clean

# Elimina los archivos objeto y la librería compilada libftprintf.a
make fclean

# Recompila la librería desde cero
make re
```

Uso
Para utilizar la librería en un proyecto en C:

1.	Incluye el encabezado en tu código:

C
#include "ft_printf.h"
Compila tu archivo principal vinculando libftprintf.a:

Bash
cc -Wall -Wextra -Werror main.c -L. -lftprintf -o test_printf
./test_printf

Decisiones Técnicas y Algoritmo

1. Estructura de Datos (t_flags)
Para evitar la asignación dinámica de memoria (malloc) y garantizar cero fugas (zero leaks) y máxima velocidad de ejecución, los metadatos de formato se gestionan en una estructura alojada exclusivamente en el stack de llamadas:

C
typedef struct s_flags
{
	int		minus;		// Flag '-' (alineación izquierda)
	int		zero;		// Flag '0' (relleno con ceros)
	int		dot;		// Presencia de precisión '.' (1 si existe, 0 si no)
	int		precision;	// Valor numérico de la precisión
	int		width;		// Ancho mínimo de campo
	int		hash;		// Flag '#' (prefijo 0x o 0X)
	int		plus;		// Flag '+' (fuerza signo + en positivos)
	int		space;		// Flag ' ' (espacio si no hay signo)
	char	specifier;	// cspdiuxX%
}		t_flags;

2. Flujo y Algoritmo de Parseo
El algoritmo procesa la cadena de formato en un único paso secuencial (single-pass stream):

Paso Directo: Todo carácter distinto de % se emite directamente a salida estándar acumulando el conteo de bytes.

Detección y Parseo: Al encontrar %, se avanza el puntero de formato pasando su dirección por referencia (char **fmt). Una función de parseo itera reconociendo banderas, ancho y precisión hasta topar con un especificador válido (cspdiuxX%).

* Resolución de Conflictos: Antes de emitir datos, se aplican las reglas de precedencia estándar de POSIX:

* Si + está activo, anula la bandera ' ' (espacio).

* Si left_align (-) está activo, anula la bandera zero (0).

* En enteros (d, i, u, x, X), si se especifica precisión (dot == 1), la bandera zero queda desactivada.

* Cálculo de Padding y Emisión: Se calculan las dimensiones efectivas del dato en memoria (sin reservar strings innecesarios) para emitir el relleno previo, prefijos (0x, signos), la carga útil y el relleno posterior en orden estricto.

## Recursos

* **Manuales del Sistema:**

* **man 3 printf:** Comportamiento estándar, reglas de flags, precisión y casos límite.

* **man 3 stdarg:** Uso y ciclo de vida de va_start, va_arg, va_copy y va_end.

## Estándar:

* Especificación POSIX.1-2017 / ISO C99 para printf.

## Uso de Inteligencia Artificial (IA)
En cumplimiento con las normativas académicas de 42, se declara el uso de herramientas de IA como apoyo puntual durante el desarrollo del proyecto:

### Áreas de aplicación:
* **Consultas conceptuales y arquitectura:** Revisión y corrección de la estructura de datos `t_flags` para evitar asignaciones dinámicas innecesarias (`malloc`) y garantizar cero fugas de memoria.
* **Precedencia de flags:** Consulta y clarificación de la matriz de precedencia POSIX frente a banderas contradictorias (como la anulación de `'0'` por `-`, o de `' '` por `+`, y la prioridad de la precisión en números).
* **Refactorización bajo Norminette:** Asistencia en la adaptación sintáctica para modularizar funciones extensas sin superar los límites de 25 líneas y 5 funciones por archivo.
* **Documentación:** Estructuración y maquetación técnica del presente `README.md`.

### Implementación y autoría:
Todo el código fuente en C, el diseño de la suite de pruebas, la gestión del puntero variádico (`stdarg.h`) y los algoritmos de impresión son de autoría propia, codificados y verificados manualmente frente al comportamiento de referencia de `libc`.