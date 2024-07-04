/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilastra- <ilastra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 14:46:27 by ilastra-          #+#    #+#             */
/*   Updated: 2024/05/16 15:23:43 by ilastra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
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
	i = ft_isdigit(c);
	if (i == 0)
		printf("ft_isdigit NO es un dígito decimal\n");
	else
		printf("ft_isdigit es un dígito decimal\n");
	i = isdigit(c);
	if (i == 0)
		printf("isdigit    NO es un dígito decimal\n");
	else
		printf("isdigit    es un dígito decimal\n");
	return (0);
}*/

/** TEORIA RESUMEN
int isdigit(int c);
La función isdigit se utiliza para comprobar si un carácter dado es un dígito 
decimal (entre 0 y 9). Esta función es parte de la biblioteca estándar de C y 
se define en la cabecera <ctype.h>.
*/

/** EXPLICACION CODIGO
int	ft_isdigit(int c)
{
	// Compruebo que el caracter es un dígito decimal (entre 0 y 9)
	if (c >= '0' && c <= '9')
    if (c >= 48 && c <= 57)
		return(1);		// Devuelvo 1
	return (0);			// Devuelvo 0
}
*/
