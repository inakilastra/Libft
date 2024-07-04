/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilastra- <ilastra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 09:25:41 by ilastra-          #+#    #+#             */
/*   Updated: 2024/05/16 15:09:02 by ilastra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dst;
	size_t	s1_len;

	s1_len = ft_strlen(s1);
	dst = malloc(sizeof(*s1) * (s1_len + 1));
	if (!dst)
		return (0);
	ft_memcpy(dst, s1, s1_len);
	dst[s1_len] = '\0';
	return (dst);
}

/** MAIN CON ARGUMENTOS * /
int	main(int argc, char **argv)
{
	char	*s1;
	char	*dst1;
	char	*dst2;

	if (argc != 2)
	{
		printf("Error en el número de argumentos\n");
		return (0);
	}
	s1 = argv[1];
	dst1 = ft_strdup(s1);
	printf("ft_strdup vs strdup s1   %s\n", s1);
	printf("ft_strdup Duplicada dst1 %s\n", dst1);
	free(dst1);
	dst2 = strdup(s1);
	printf("strdup    Duplicada dst2 %s\n", dst2);
	free(dst2);
	system("leaks main");
	return (0);
}*/

/** TEORIA RESUMEN
char *strdup(const char *s1);
La función strdup (del inglés "duplicate string") se utiliza para crear una 
copia duplicada de una cadena de caracteres. En otras palabras, toma una 
cadena de caracteres existente y devuelve un puntero a una nueva cadena que 
contiene el mismo contenido.
*/

/** EXPLICACION CODIGO
#include "libft.h"			//	Es necesario para size_t "unistd.h"

char	*fn_strdup(const char *s1)
{
	char	*dst;                   //  Inicio puntero
	size_t	s1_len;                 //  Inicio contador tamaño

	s1_len = ft_strlen(s1);         //  Asigno tamaño "s1" con strlen
    //  Reservo memoria para el tipo de datos y el tamaño de "s1" + cierre
	dst = malloc(sizeof(*s1) * (s1_len + 1));
	if (!dst)                       //  Si la reserva falla
		return (0);                 //  Devuelvo 0
	//  Copio el contenido de la mem "s1" en "dst" segun tamaño "s1_len"
    ft_memcpy(dst, s1, s1_len);
	dst[s1_len] = '\0';             //  Cierro en la ultima posición
	return (dst);                   //  Devulevo el puntero
}
*/
