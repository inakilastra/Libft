/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilastra- <ilastra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 08:40:31 by ilastra-          #+#    #+#             */
/*   Updated: 2024/05/16 14:20:18 by ilastra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char			*c;
	size_t			len;
	unsigned char	*ptrc;

	c = malloc(count * size);
	if (!c)
		return (0);
	len = count * size;
	ptrc = (unsigned char *)c;
	while (len--)
		*ptrc++ = 0;
	return (c);
}

/** MAIN CON ARGUMENTOS * /
void	fn_print(int f, size_t count, size_t size)
{
	int		*ptr;
	size_t	i;

	i = 0;
	if (f == 0)
		ptr = (int *)ft_calloc(count, size);
	else
		ptr = (int *)calloc(count, size);
	if (ptr)
	{
		while (i < count)
		{
			ptr[i] = 42;
			printf("%d ", ptr[i]);
			i++;
		}
		printf("\n");
		free(ptr);
	}
	else
		printf("Error al asignar memoria.\n");
}

int	main(int argc, char **argv)
{
	size_t	count;
	size_t	size;

	if (argc != 3)
	{
		printf("Error en el número de argumentos\n");
		return (0);
	}
	count = (size_t)ft_atoi(argv[1]);
	size = ft_atoi(argv[1]);
	fn_print(0, count, size);
	fn_print(1, count, size);
	return (0);
}*/

/** TEORIA RESUMEN
void *calloc(size_t count, size_t size);
La función calloc (contracción de "contiguous allocation") se utiliza para 
asignar dinámicamente un bloque de memoria contiguo y rellenar cada byte de 
la memoria asignada con el valor 0. En otras palabras, reserva memoria para 
un número específico de elementos del mismo tipo y la inicializa a ceros.

 * void *malloc(size_t size);
La función malloc (del inglés "Memory Allocation") se utiliza para solicitar 
memoria dinámica en el montón. En otras palabras, permite reservar un bloque 
de memoria de un tamaño específico para su uso posterior en el programa.
*/

/** EXPLICACION CODIGO
#include "libft.h"			//	Es necesario para size_t "unistd.h"

void	*fn_calloc(size_t count, size_t size)
{
	char			*c;			//	Inicializo un puntero
	size_t			len;		//	Inicializo un contador
	unsigned char	*ptrc;		//	Inicializo un puntero a puntero

	c = malloc(count * size);	//	Reservo memoria 
	if (!c)						//	Si da error al reservar
		return (0);				//	Devuelvo 0
	len = count * size;			//	Asigno tamaño x cantidad al contador
	ptrc = (unsigned char *)c;	//	Asigno puntero "c" a puntero "ptrc"
	while (len--)				//	Recorro contador
		*ptrc++ = 0;			//	Asigno 0 a cada cosición del puntero
	return (c);					//	Devuelvo puntero "c"
}
*/
