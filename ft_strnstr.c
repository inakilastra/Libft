/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilastra- <ilastra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 08:32:29 by ilastra-          #+#    #+#             */
/*   Updated: 2024/05/16 14:10:54 by ilastra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i_haystack;
	size_t	i_needle;
	size_t	size_needle;

	i_haystack = 0;
	if (!needle[0])
		return ((char *)haystack);
	size_needle = ft_strlen(needle);
	while (haystack[i_haystack] != '\0'
		&& (i_haystack + size_needle - 1) < len)
	{
		i_needle = 0;
		while (needle[i_needle] != '\0'
			&& haystack[i_haystack + i_needle] == needle[i_needle])
		{
			if (i_needle == size_needle - 1)
				return ((char *)(haystack + i_haystack));
			i_needle++;
		}
		i_haystack++;
	}
	return (0);
}

/** MAIN CON ARGUMENTOS * /
int	main(int argc, char **argv)
{
	char	*haystack;
	char	*needle;
	size_t	len;
	char	*ft_result;

	if (argc != 4)
	{
		printf("Error en el número de argumentos\n");
		return (0);
	}
	haystack = argv[1];
	needle = argv[2];
	len = atoi(argv[3]);
	ft_result = ft_strnstr(haystack, needle, len);
	if (ft_result)
		printf("ft_result:  %s\n", ft_result);
	else
		printf("ft_result: NULL\n");
	return (0);
}*/

/** TEORIA RESUMEN
char *strnstr(const char *haystack, const char *needle, size_t len);
La función strnstr busca la primera aparición de una subcadena dentro de otra
cadena, teniendo en cuenta un número máximo de caracteres a comparar.
*/

/** EXPLICACION CODIGO
#include "libft.h"						//	Es necesario para size_t "unistd.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i_haystack;					//	Inicializo contador i_haystack
	size_t	i_needle;					//	Inicializo contador i_needle
	size_t	size_needle;				//	Inicializo tamaño size_needle

	i_haystack = 0;						//	Asigno 0 al contador
	if (!needle[0])						//	Si no hay nada que buscar
		return ((char *)haystack);		//	Devuelvo puntero haystack
	size_needle = ft_strlen(needle);	//	Obtengo tamaño needle
	//	Recorro Si haystack no ha llegado al cierre y contador
	//	i_haystack + tamaño needle menos cierre es menor que len
	while (haystack[i_haystack] != '\0'
		&& (i_haystack + size_needle - 1) < len)
	{
		i_needle = 0;					//	Asigno 0 al contador
		//	Recorro Si needle no ha llegado al cierre y posicion puntero
		//	haystack suma contadores i_haystack + i_needle = posicion
		//	puuntero needle
		while (needle[i_needle] != '\0'
			&& haystack[i_haystack + i_needle] == needle[i_needle])
		{
			//	Si contador es igual tamaño menos cierre
			if (i_needle == size_needle - 1)
				//	Devuelvo posicion puntero
				return ((char *)(haystack + i_haystack));
			i_needle++;					//	Aumento el contador
		}
		i_haystack++;					//	Aumento el contador
	}
	return (0);							//	Devuelvo 0
}
*/
