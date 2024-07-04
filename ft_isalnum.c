/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilastra- <ilastra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 09:57:59 by ilastra-          #+#    #+#             */
/*   Updated: 2024/05/16 15:23:23 by ilastra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 'A' && c <= 'Z')
		|| (c >= 'a' && c <= 'z')
		|| (c >= '0' && c <= '9'))
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
	i = ft_isalnum(c);
	if (i == 0)
		printf("ft_isalnum NO es alfanumérico\n");
	else
		printf("ft_isalnum es alfanumérico\n");
	i = isalnum(c);
	if (i == 0)
		printf("isalnum    NO es alfanumérico\n");
	else
		printf("isalnum    es alfanumérico\n");
	return (0);
}*/

/** TEORIA RESUMEN
int isalnum(int c);
La función isalnum se utiliza para comprobar si un carácter es alfanumérico, 
es decir, si es una letra o un número.
*/

/** EXPLICACION CODIGO
int	ft_isalnum(int c)
{
	// Compruebo que el caracter es una letra del alfabeto May o
	// Compruebo que el caracter es una letra del alfabeto Min o
	// Compruebo que el caracter es n dígito decimal (entre 0 y 9)
	if ((c >= 65 && c <= 90)
		|| (c >= 97 && c <= 122)
		|| (c >= 48 && c <= 57))
	if ((c >= 'A' && c <= 'Z')
		|| (c >= 'a' && c <= 'z')
		|| (c >= '0' && c <= '9'))		
		return(1);		// Devuelvo 1
	return (0);			// Devuelvo 0
}
*/
