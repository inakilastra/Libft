/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilastra- <ilastra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 12:53:24 by ilastra-          #+#    #+#             */
/*   Updated: 2024/05/16 11:48:32 by ilastra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dstlen;
	size_t	srclen;
	size_t	i;

	if (!dst && !src)
		return (0);
	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	i = 0;
	if (dstsize == 0)
		return (srclen);
	if (dstlen >= dstsize)
		return (srclen + dstsize);
	while (i < srclen && (dstlen + i + 1) < dstsize)
	{
		dst[dstlen + i] = src[i];
		i++;
	}
	dst[dstlen + i] = '\0';
	return (dstlen + srclen);
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
	i = ft_strlcat(dst, src, dstsize);
	printf("ft_strlcat %zu \n", i);
	return (0);
}*/

/** TEORIA RESUMEN
size_t strlcpy(char * dst, const char * src, size_t dstsize);
La función strlcat concatena dos cadenas de caracteres, pero con un límite de 
tamaño para la cadena destino. Es similar a la función strcat, pero ofrece mayor
seguridad al evitar el desbordamiento del búfer.
*/

/** EXPLICACION CODIGO
#include "libft.h"			          //	Es necesario para size_t "unistd.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;				//	Inicializo tamaño dst
	size_t	src_len;				//	Inicializo tamaño src
	size_t	i;					//	Inicializo un contador

	i = 0;						//	Le asigno un 0
	dst_len = ft_strlen(dst);		//	Le asigno el tamaño con strlen
	src_len = ft_strlen(src);		//	Le asigno el tamaño con strlen
	if (dstsize == 0)				//	Si el tamaño de dst es 0
		return (src_len);			//	Devuelvo tamaño src
	if (dst_len >= dstsize)			//	Si el tamaño dst_len >= dstsize
		return (src_len + dstsize);	//	Devuelvo tamaño src + dstsize
	// Recorro si contador es menor que src_len y dst_len + i + 1 (esto es el
		espacio de src y dst concatenadas) menor que dstsize
	while (i < src_len && (dst_len + i + 1) < dstsize)
	{
		dst[dst_len + i] = src[i];	//	Asigno origen a destino
		i++;						//	Aument el contador
	}
	dst[dst_len + i] = '\0';			//	Cierro dst con una posicion más
	return (dst_len + src_len);		//	Devuelvo suma tamaños dst y src
}
*/
