/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilastra- <ilastra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 16:23:00 by ilastra-          #+#    #+#             */
/*   Updated: 2024/05/16 13:02:53 by ilastra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	char	*d1;
	char	*d2;

	if (n == 0)
		return (0);
	i = 0;
	d1 = (char *)s1;
	d2 = (char *)s2;
	while (n--)
	{
		if (*(unsigned char *)(d1 + i) != *(unsigned char *)(d2 + i))
			return (*(unsigned char *)(d1 + i) - *(unsigned char *)(d2 + i));
		i++;
	}
	return (0);
}

/** MAIN CON ARGUMENTOS * /
int	main(int argc, char **argv)
{
	char	*s1;
	char	*s2;
	size_t	n;
	int		ft_result;
	int		std_result;

	if (argc != 4)
	{
		printf("Error en el número de argumentos\n");
		return (0);
	}
	s1 = argv[1];
	s2 = argv[2];
	n = atoi(argv[3]);
	ft_result = ft_memcmp(s1, s2, n);
	printf("Resultado de ft_memcmp: %d\n", ft_result);
	std_result = memcmp(s1, s2, n);
	printf("Resultado de memcmp: %d\n", std_result);
	if (ft_result == 0 && std_result == 0)
		printf("Las cadenas son iguales\n");
	else if (ft_result != std_result)
		printf("El resultados de ft_memcmp y memcmp es diferente.\n");
	else
		printf("Las cadenas no son iguales\n");
	return (0);
}*/

/** TEORIA RESUMEN
int memcmp(const void *s1, const void *s2, size_t n);
La función memcmp se utiliza para comparar dos bloques de memoria. En otras 
palabras, toma dos punteros a zonas de memoria y determina si el contenido 
de esas zonas es idéntico o no.
*/

/** EXPLICACION CODIGO
#include "libft.h"						//	Es necesario para size_t "unistd.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;							//	Inicializo un contador
	char	*d1;						//	Inicializo puntero "d1"
	char	*d2;						//	Inicializo puntero "d2"

	if (n == 0)							//	Si "n" es igual a 0
		return (0);						//	Devuelvo 0
	i = 0;								//	Asigno 0 al contador
	d1 = (char *)s1;					//	Asigno a "d1" el puntero "s1"
	d2 = (char *)s2;					//	Asigno a "d2" el puntero "s2"
	while (n--)							//	Recorro n hasta 0
	{
		//	Si la posicion de los punteros "s1" y "s2" es diferente
		if (*(unsigned char *)(s1 + i) != *(unsigned char *)(s2 + i))
			//	Devuevo la diferencia entre ambos punteros
			return (*(unsigned char *)(s1 + i) - *(unsigned char *)(s2 + i));
		i++;							//	Aumento el contador
	}
	return (0);							//	Devuelvo 0
}
*/
