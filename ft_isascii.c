/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilastra- <ilastra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 15:46:44 by ilastra-          #+#    #+#             */
/*   Updated: 2024/05/16 15:23:39 by ilastra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
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
	i = ft_isascii(c);
	if (i == 0)
		printf("ft_isascii NO es caracter imprimible o de control\n");
	else
		printf("ft_isascii es caracter imprimible o de control\n");
	i = isascii(c);
	if (i == 0)
		printf("isascii    NO es caracter imprimible o de control\n");
	else
		printf("isascii    es caracter imprimible o de control\n");
	return (0);
}*/

/**
 * TEORIA RESUMEN
int isascii(int c);
La función isascii se utiliza para comprobar si un carácter dado es un 
carácter ASCII de 7 bits. Es decir, verifica si el valor del carácter está 
entre 0 y 127, que corresponde a los caracteres imprimibles y algunos 
caracteres de control en el conjunto de caracteres ASCII.
*/

/**
 * EXPLICACION CODIGO
int	ft_isascii(int c)
{
	// Compruebo que el caracter corresponde a los caracteres imprimibles 
	// y algunos caracteres de control
		if (c >= 0 && c <= 127)
		return(1);		// Devuelvo 1
	return (0);			// Devuelvo 0
}
*/
