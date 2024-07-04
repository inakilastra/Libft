/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilastra- <ilastra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 09:28:04 by ilastra-          #+#    #+#             */
/*   Updated: 2024/05/16 10:44:57 by ilastra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*ptrdst;
	char	*ptrsrc;

	if (!src || !len || len == 0)
		return (dst);
	ptrdst = (char *)dst;
	ptrsrc = (char *)src;
	if (ptrsrc < ptrdst)
		while (len--)
			ptrdst[len] = ptrsrc[len];
	else
		ft_memcpy(ptrdst, ptrsrc, len);
	return (dst);
}

/** MAIN CON ARGUMENTOS * /
int	main(int argc, char **argv)
{
	char	*dst;
	char	*dst1;
	char	*src;
	size_t	len;

	if (argc != 4)
	{
		printf("Error en el número de argumentos\n");
		return (0);
	}
	dst = argv[1];
	dst1 = argv[1];
	src = argv[2];
	len = ft_atoi(argv[3]);
	ft_memmove(dst, src, len);
	printf("ft_memmove %s\n", dst);
	memmove(dst1, src, len);
	printf("memmove    %s\n", dst1);
	return (0);
}*/

/** TEORIA RESUMEN
void *memmove(void *dst, const void *src, size_t len);
La función memmove se utiliza para copiar un bloque de memoria de un lugar a 
otro, incluso si los bloques se superponen. En otras palabras, puedes mover 
datos dentro de la misma zona de memoria sin corromperla.
*/

/** EXPLICACION CODIGO
#include "libft.h"			//	Es necesario para size_t "unistd.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*ptrdst;            //	Inicio un puntero a dst
	char	*ptrsrc;            //	Inicio un puntero a src

	if (!src || !len || len == 0)      //	Si src,len no existen o son nulos
		return (dst);
	ptrdst = (char *)dst;		     //	Asigno al puntero prtdst el *dst
	ptrsrc = ( char *)src;             //	Asigno al puntero prtsrc el *src
	if (ptrsrc < ptrdst)			//	Si el src es menor que dst
		while (len--)				//	Recorro hasta n = 0
			ptrdst[len] = ptrsrc[len];//	Asigno origen a destino
	else
		ft_memcpy(ptrdst, ptrsrc, len);//	Copio la memoria de src a dst
	return (dst);					//	Devuelvo destino
}
*/
