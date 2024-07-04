/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilastra- <ilastra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 11:42:57 by ilastra-          #+#    #+#             */
/*   Updated: 2024/05/16 09:27:29 by ilastra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

/** MAIN CON ARGUMENTOS * /
int	main(int argc, char **argv)
{
	size_t	i;
	char	*s;

	if (argc != 2)
	{
		printf("Error en el número de argumentos\n");
		return (0);
	}
	s = argv[1];
	i = ft_strlen(s);
	printf("Size of %s --> %zu\n", s, i);
	i = strlen(s);
	printf("Size of %s --> %zu\n", s, i);
	return (0);
}*/

/** TEORIA RESUMEN
size_t strlen(const char *s);
La función strlen calcula la longitud de una cadena de caracteres.
La función es útil para determinar el tamaño de una cadena y para realizar 
operaciones con cadenas.
La función no modifica la cadena original.
*/

/** EXPLICACION CODIGO
#include "libft.h"			//	Es necesario para size_t "unistd.h"
size_t	ft_strlen(const char *s)
{
	size_t	i;						//	Inicio un contador

	i = 0;							//	Le asigo valor 0
	if (!s)							//	Si "s" es Nulo
		return (0);					//	Devuelvo 0
	while (s[i] != '\0')			//	Recorro el puntero str
		i++;						//	Aumento el valor del contador
	return (i);						//	Devuelvo el valor del contador
}
*/
