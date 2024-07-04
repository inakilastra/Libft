/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilastra- <ilastra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 10:59:47 by ilastra-          #+#    #+#             */
/*   Updated: 2024/05/23 11:11:16 by ilastra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ptrb;

	ptrb = b;
	while (len > 0)
	{
		*ptrb = (unsigned char)c;
		ptrb++;
		len--;
	}
	return (b);
}

/** MAIN CON ARGUMENTOS * /
int	main(int argc, char **argv)
{
	char	*b;
	char	c;
	size_t	len;

	if (argc != 4)
	{
		printf("Error en el número de argumentos\n");
		return (0);
	}
	b = argv[1];
	c = argv[2][0];
	len = ft_atoi(argv[3]);
	ft_memset(b, c, len);
	printf("ft_memset %s\n", b);
	memset(b, c, len);
	printf("memset    %s\n", b);
	return (0);
}*/

/** TEORIA RESUMEN
void *memset(void *b, int c, size_t len);
La función memset en lenguaje C se utiliza para rellenar una región de memoria
con un valor constante. En otras palabras, permite escribir un byte específico
en cada ubicación dentro de un bloque de memoria.
*/

/** EXPLICACION CODIGO
#include "libft.h"			//	Es necesario para size_t "unistd.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ptrb;	//	Inicializo un puntero

	if (!b || !c)     		//   Si "b" o "c" son Nulos
		return (0);         //   Devuelvo 0
	ptrb = (unsigned char *)b; //	Le asigno "b" como puntero char
	while (len--)           //	Recorro el puntero "len"
		//	Asigno a la posición del puntero el valor "c"
		*ptrb++ = (unsigned char)c;  
	return (b);             //	Devuelvo "b"
}
*/
