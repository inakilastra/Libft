/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilastra- <ilastra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 12:04:49 by ilastra-          #+#    #+#             */
/*   Updated: 2024/05/16 11:31:11 by ilastra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (!dst || !src)
		return (i);
	if (dstsize > 0)
	{
		while (src[i] && i < (dstsize - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	i = ft_strlen(src);
	return (i);
}

/** MAIN CON ARGUMENTOS * /
int	main(int argc, char **argv)
{
	char	*dst;
	char	*src;
	size_t	dstsize;
	size_t	i;

	if (argc != 3)
	{
		printf("Error en el número de argumentos\n");
		return (0);
	}
	dst = argv[1];
	src = argv[2];
	dstsize = ft_strlen(dst);
	i = ft_strlcpy(dst, src, dstsize);
	printf("ft_strlcpy %zu\n", i);
	return (0);
}*/

/** TEORIA RESUMEN
size_t strlcpy(char * restrict dst, const char * restrict src, size_t dstsize);
La función strlcpy copia una cadena de caracteres de origen a una cadena de 
destino, controlando el tamaño del destino para evitar desbordamientos.
*/

/** EXPLICACION CODIGO
#include "libft.h"			//	Es necesario para size_t "unistd.h"


size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;					//	Inicializo un contador

	if (!dst || !src)				//	Si dst o src no existen o nulos
		return (0);				//	Devuelvo un 0
	i = 0;						//	Le asigno un 0
	if (dstsize > 0)				//	Si el tamaño de dst es mayor que 0
	{
		//	Recorro src mientras contador menor que dstsize -1 (sin cierre)
		while (src[i] && i < (dstsize - 1))
		{
			dst[i] = src[i];		//	Asigno origen a destino
			i++;					//	Aumento el contador
		}
		dst[i] = '\0';				//	Cierro dst con una posicion más
	}
	i = ft_strlen(src);				//	Obtengo el tamaño con strlen
	return (i);					//	Devuelvo tamaño contador
}
*/
