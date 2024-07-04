/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilastra- <ilastra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 12:20:01 by ilastra-          #+#    #+#             */
/*   Updated: 2024/05/16 15:20:58 by ilastra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;
	int		i;
	int		i_dst;

	i = 0;
	i_dst = 0;
	dst = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!dst)
		return (NULL);
	while (s1[i])
		dst[i_dst++] = s1[i++];
	i = 0;
	while (s2[i])
		dst[i_dst++] = s2[i++];
	dst[i_dst] = '\0';
	return (dst);
}

/** MAIN CON ARGUMENTOS * /
int	main(int argc, char **argv)
{
	char			*s1;
	char			*s2;
	char			*str;

	if (argc != 3)
	{
		printf("Error en el número de argumentos\n");
		return (0);
	}
	s1 = argv[1];
	s2 = argv[2];
	str = ft_strjoin(s1, s2);
	printf("ft_strjoin s1: %s s2: %s\n", s1, s2);
	printf("str: %s\n", str);
	free(str);
	printf("\n");
	system("leaks main");
	return (0);
}*/

/**	
Nombre de función
	ft_strjoin
Prototipo 
	char *ft_strjoin(char const *s1, char const *s2);
Archivos a entregar
	-
Parámetros 
	s1: La primera string.
	s2: La string a añadir a ’s1’.
Valor devuelto 
	La nueva string.
	NULL si falla la reserva de memoria.
Funciones autorizadas
	malloc
Descripción 
	Reserva (con malloc(3)) y devuelve una nueva string
*/

/** EXPLICACION
#include "libft.h"						//	Es necesario para size_t "unistd.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;						//	Inicio un puntero a dst
	int		i;							//	Inicio contador para src
	int		i_dst;						//	Inicio contador para dst

	i = 0;								//	Asigno 0 a "i"
	i_dst = 0;							//	Asigno 0 a "i_dst"
	//	Asigno a *dst mem de tamaño byt (char) por tamaño "s2" + cierre
	dst = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!dst)							//	Si da error al reservar memoria
		return (NULL);					//	Devuelvo NULL
	while (s1[i])						//	Recorro "s1"
		dst[i_dst++] = s1[i+];			//	Relleno "dst" con "s1" i_dst++
	i = 0;								//	Reinicio contador "i" a 0
	while (s2[i])						//	Recorro "s2"
		dst[i_dst++] = s2[i++];			//	Relleno "dst" con "s2" i_dst++
	dst[i_dst] = '\0';					//	Cierro
	return (dst);						//	Devuelvo puntero "dst"
}
*/
