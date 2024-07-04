/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilastra- <ilastra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 14:07:32 by ilastra-          #+#    #+#             */
/*   Updated: 2024/05/16 11:58:00 by ilastra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (0);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (0);
}

/** MAIN CON ARGUMENTOS * /
int	main(int argc, char **argv)
{
	char	*s;
	int		c;
	char	*s1;

	if (argc != 3)
	{
		printf("Error en el número de argumentos\n");
		return (0);
	}
	s = argv[1];
	s1 = argv[1];
	c = argv[2][0];
	s = ft_strchr(s, c);
	printf("ft_strchr %s\n", s);
	s1 = strchr(s, c);
	printf("strchr    %s\n", s1);
	return (0);
}*/

/** TEORIA RESUMEN
char *strchr(const char *s, int c);
La función strchr se utiliza para buscar la primera aparición de un 
carácter específico dentro de una cadena de caracteres.
*/

/** EXPLICACION CODIGO
#include <string.h>         //	Es necesario
char *fn_strchr(const char *s, int c)
{
	if (!s)					//	Si "s" es Nulo
		return (0);			//	Devuelvo 0
	while (*s)				// Recorro puntero "s"
	{
		if (*s == (char)c)	//   Si puntero "s" = a c
			return ((char *)s); //   Devuelvo puntero "s"
		s++;                //   Aumento posicion puntero "s"
	}
	if (*s == (char)c)		//	Compruebo si concide el cierre '\0'
		return ((char *)s);	//   Devuelvo puntero "s"
	return (0);				//   Devuelvo 0
}

*/
