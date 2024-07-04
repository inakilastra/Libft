/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilastra- <ilastra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 14:00:39 by ilastra-          #+#    #+#             */
/*   Updated: 2024/05/16 14:16:09 by ilastra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		c += 32;
	return (c);
}

/** MAIN CON ARGUMENTOS * /
int	main(int argc, char **argv)
{
	int	c;
	int	c1;

	if (argc != 2)
	{
		printf("Error en el número de argumentos\n");
		return (0);
	}
	c = argv[1][0];
	c1 = c;
	c = ft_tolower(c);
	printf("ft_tolower %c\n", c);
	c1 = tolower(c1);
	printf("tolower    %c\n", c1);
	return (0);
}*/

/** TEORIA RESUMEN
int tolower(int c);
La función tolower en lenguaje C convierte un carácter en minúscula si es 
que está en mayúscula.
*/

/** EXPLICACION CODIGO
int	ft_tolower(int c)
{
	//	Si el caracter ascii es alpha en mayúscula
     if (c >= 'A' && c <= 'Z')	
		c += 32;				//	Lo transformo en minúscula
	return (c);				//	Devuelvo "c" transformado o no
}

*/
