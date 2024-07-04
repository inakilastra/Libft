/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilastra- <ilastra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 15:41:29 by ilastra-          #+#    #+#             */
/*   Updated: 2024/05/23 10:55:14 by ilastra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

/** MAIN CON ARGUMENTOS * /
int	main(int argc, char **argv)
{
	char	*s;
	char	*s1;
	size_t	n;

	if (argc != 3)
	{
		printf("Error en el número de argumentos\n");
		return (0);
	}
	s = argv[1];
	s1 = argv[1];
	n = ft_atoi(argv[2]);
	ft_bzero(s, n);
	printf("ft_bzero %c\n", s[0]);
	printf("ft_bzero %c\n", s[1]);	
	printf("ft_bzero %c\n", s[2]);
	printf("ft_bzero %c\n", s[3]);
	printf("ft_bzero %c\n", s[4]);		
	bzero(s1, n);
	printf("bzero    %c\n", s1[0]);
	printf("bzero    %c\n", s1[1]);	
	printf("bzero    %c\n", s1[2]);
	printf("bzero    %c\n", s1[3]);
	printf("bzero    %c\n", s1[4]);	
	return (0);
}*/

/** TEORIA RESUMEN
void bzero(void *s, size_t n);
La función bzero se utiliza para rellenar una zona de memoria con 
bytes nulos ('\0'). En otras palabras, toma un bloque de memoria y escribe 
un valor de 0 en cada ubicación dentro de ese bloque.
*/

/** EXPLICACION CODIGO
#include "libft.h"			//	Es necesario para size_t "unistd.h"

void	ft_bzero(void *s, size_t n)
{
	// Rellenar el buffer con bytes nulos
	// Uso ft_memset y asigno 0 que es Nulo
	ft_memset(s, 0, n);
	char	*ptrs;			//	Inicio puntero

	if (n > 1)				//	Si "n" es 0 o menos
	{
		ptrs = (char *)s;	//	Asigno puntero "s" a "ptrs"
		while (n--)			//	Recorro el numero de "n"
			*ptrs++ = 0;	//	Asigno "0" a cada posición y me muevo next
	}	
}
*/
