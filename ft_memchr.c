/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilastra- <ilastra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 15:59:10 by ilastra-          #+#    #+#             */
/*   Updated: 2024/05/16 12:14:28 by ilastra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*data;

	i = 0;
	data = (char *)s;
	while (i < n)
	{
		if (data[i] == (char)c)
			return ((void *)(data + i));
		i++;
	}
	return (NULL);
}

/** MAIN CON ARGUMENTOS * /
int	main(int argc, char **argv)
{
	char	*s;
	char	*s1;
	char	c;
	size_t	n;

	if (argc != 4)
	{
		printf("Error en el número de argumentos\n");
		return (0);
	}
	s = argv[1];
	s1 = argv[1];
	c = argv[2][0];
	n = ft_atoi(argv[3]);
	s = ft_memchr(s, c, n);
	printf("ft_memchr %s\n", s);
	s1 = memchr(s1, c, n);
	printf("memchr    %s\n", s1);
	return (0);
}*/

/** TEORIA RESUMEN
void *memchr(const void *s, int c, size_t n);
La función memchr busca la primera aparición de un carácter específico dentro
de un bloque de memoria. Es útil para encontrar subcadenas dentro de cadenas 
más grandes o para identificar valores específicos en un conjunto de datos.
*/

/** EXPLICACION CODIGO
#include <string.h>           //	Es necesario

void	*fn_memchr(const void *s, int c, size_t n)
{
	char	     *str;          //	Inicializo un puntero
	size_t	i;             //	Inicializo un contador

	if (!s)                  //   Si "s" es nulo
		return (NULL);      //   Devuelvo NULL
	str = (char *)s;         //	Asigno a "str" el puntero "s"
	i = 0;                   //	Asigno 0 al contador
	while (i < n)            //	Recorro el contador hasta i = "n"
	{
		if (str[i] == (char)c)   //	Si la posicion de "str" = "c"
			return ((void *)(str + i));//	Devuelvo puntero al primer byte
		i++;                //	Aumento el contador
	}
	return (NULL);           //	Devuelvo NULL
}
*/
