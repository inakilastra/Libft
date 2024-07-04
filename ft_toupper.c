/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilastra- <ilastra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 13:49:02 by ilastra-          #+#    #+#             */
/*   Updated: 2024/05/16 14:15:40 by ilastra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		c -= 32;
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
	c = ft_toupper(c);
	printf("ft_toupper %c\n", c);
	c1 = toupper(c1);
	printf("toupper    %c\n", c1);
	return (0);
}*/

/** TEORIA RESUMEN
int toupper(int c);
La función toupper se utiliza para convertir una letra minúscula a su 
correspondiente letra mayúscula. En otras palabras, toma un carácter como 
entrada y devuelve su versión en mayúscula si existe.
*/

/** EXPLICACION CODIGO
int	ft_toupper(int c)
{
     //	Si el caracter ascii es alpha en minuscula
	if (c >= 'a' && c <= 'z')	
		c -= 32;				//	Lo transformo en mayuscula
	return (c);				//	Devuelvo "c" transformado o no
}
*/
