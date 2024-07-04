/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilastra- <ilastra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 14:29:10 by ilastra-          #+#    #+#             */
/*   Updated: 2024/05/16 12:01:27 by ilastra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	if (s)
	{
		i = ft_strlen(s);
		while (i >= 0)
		{
			if (s[i] == (char)c)
				return ((char *)&s[i]);
			i--;
		}
	}
	return (NULL);
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
	s = ft_strrchr(s, c);
	printf("ft_strrchr %s\n", s);
	s1 = strchr(s1, c);
	printf("strrchr    %s\n", s1);
	return (0);
}*/

/** TEORIA RESUMEN
char *strrchr(const char *s, int c);
La función strrchr se utiliza para encontrar la última aparición de un 
carácter dentro de una cadena de caracteres. Es una función muy útil para 
trabajar con cadenas y extraer información específica.
*/

/** EXPLICACION CODIGO
#include <string.h>           //	Es necesario 
char	*ft_strrchr(const char *s, int c)
{
	int	i;                  //	Inicializo contador

	
	if (s)    			//	Si "s" no es nulo
     {
          i = ft_strlen(s);	//	Asigno contador con tamaño de "s"
		while (i >= 0)      //   Recorro hasta contador 0
		{
			if (s[i] == (char)c)     //   Si puntero "s" y "c" son iguales
				return ((char *)&s[i]); //    Devuelvo puntero
			i--;           //   Disminuyo contador
		}
	}
	return (NULL);           // Devulvo NULL
}
*/
