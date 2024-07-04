/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilastra- <ilastra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 11:30:18 by ilastra-          #+#    #+#             */
/*   Updated: 2024/05/16 09:24:27 by ilastra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}

/** MAIN CON ARGUMENTOS * /
int	main(int argc, char **argv)
{
	int		i;
	char	c;

	if (argc != 2)
	{
		printf("Error en el número de argumentos\n");
		return (0);
	}
	c = argv[1][0];
	i = ft_isprint(c);
	if (i == 0)
		printf("ft_isprint NO es caracter imprimible\n");
	else
		printf("ft_isprint es caracter imprimible\n");
	i = isascii(c);
	if (i == 0)
		printf("isprint    NO es caracter imprimible\n");
	else
		printf("isprint    es caracter imprimible\n");
	return (0);
}*/

/** TEORIA
int isprint(int c);
La función isprint se utiliza para verificar si un carácter dado es un 
carácter imprimible. En otras palabras, determina si el valor del código ASCII
del carácter se encuentra en el rango de caracteres imprimibles.
*/

/** EXPLICACION
int	ft_isprint(int c)
{
	// Compruebo que el caracter dado es un carácter imprimible.
	if (c >= 32 && c <= 126)
			return(1);		// Devuelvo 1
	return (0);				// Devuelvo 0
}
*/
