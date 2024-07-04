/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilastra- <ilastra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 14:43:40 by ilastra-          #+#    #+#             */
/*   Updated: 2024/05/16 12:05:01 by ilastra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (!s1 || !s2)
		return (0);
	if (n == 0)
		return (0);
	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i] || i >= (n - 1))
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	if (n <= i)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

/** MAIN CON ARGUMENTOS * /
int	main(int argc, char **argv)
{
	char	*s1;
	char	*s2;
	size_t	n;
	size_t	result;

	if (argc != 4)
	{
		printf("Error en el número de argumentos\n");
		return (0);
	}
	s1 = argv[1];
	s2 = argv[2];
	n = ft_atoi(argv[3]);
	result = ft_strncmp(s1, s2, n);
	printf("ft_strncmp %zu\n", result);
	result = strncmp(s1, s2, n);
	printf("strncmp    %zu\n", result);
	return (0);
}*/

/** TEORIA RESUMEN
int strncmp(const char *s1, const char *s2, size_t n);
La función strncmp compara dos cadenas de caracteres ASCII hasta un número 
máximo de caracteres especificado. La función devuelve un valor que indica 
si las cadenas son iguales, si la primera cadena es menor que la segunda o 
si la primera cadena es mayor que la segunda.
*/

/** EXPLICACION CODIGO
#include <string.h>                          //   Es necesario
	size_t	i;						//	Inicio contador
	
	if (!s1 || !s2)					// Si "s1! o "s2" es nulo
		return (0);					//	Devuelvo 0
	if (n == 0)						//	Si es 0 no hay nada que buscar
		return (0);					//	Devuelvo 0
	i = 0;							//	Asigno 0 al contador		
	while (s1[i] && s2[i])			//	Recorro "s1" y "s2"
	{
		// Si puntero "s1" no es igual a "s2" o contador >= a n - cierre
		if (s1[i] != s2[i] || i >= (n - 1))
			//		Devuelvo diff "s1" - "s2"
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;						//	Aumneto contador
	}
	if (n <= i)						//	Si n <= a contador
		return (0);					//	Deuvelvo 0
	//		Devuelvo diff "s1" - "s2"
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
*/
