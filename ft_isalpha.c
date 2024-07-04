/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilastra- <ilastra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 12:14:53 by ilastra-          #+#    #+#             */
/*   Updated: 2024/05/27 09:09:10 by ilastra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
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
	c = (char)argv[1][0];
	i = ft_isalpha(c);
	if (i == 0)
		printf("ft_isalpha NO es una letra\n");
	else
		printf("ft_isalpha es una letra\n");
	i = isalpha(c);
	if (i == 0)
		printf("isalpha    NO es una letra\n");
	else
		printf("isalpha    es una letra\n");
	return (0);	
}
*/

/** TEORIA RESUMEN
int isalpha(int c);
La función isalpha en lenguaje C se utiliza para comprobar si un carácter 
dado es una letra del alfabeto (mayúscula o minúscula).
*/

/** EXPLICACION CODIGO
int	ft_isalpha(int c)
{
	// Compruebo que el caracter es una letra del alfabeto May o Min
	if((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return(1);		// Devuelvo 1
	return (0);			// Devuelvo 0
}
*/
