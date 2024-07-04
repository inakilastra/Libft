/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilastra- <ilastra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 10:51:37 by ilastra-          #+#    #+#             */
/*   Updated: 2024/05/16 15:16:45 by ilastra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	char	*dst;

	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	dst = (char *)malloc(sizeof(*s) * (len + 1));
	if (!dst)
		return (NULL);
	ft_strlcpy(dst, s + start, len + 1);
	return (dst);
}

/** MAIN CON ARGUMENTOS * /
int	main(int argc, char **argv)
{
	char	*s;
	int		start;
	size_t	len;
	char	*substring;

	if (argc != 4)
	{
		printf("Error en el número de argumentos\n");
		return (0);
	}
	s = argv[1];
	start = ft_atoi(argv[2]);
	len = ft_atoi(argv[3]);
	substring = ft_substr(s, start, len);
	if (substring)
	{
		printf("Original string: %s\n", s);
		printf("Substring: %s\n", substring);
		free(substring);
	}
	else
		printf("Error: no se pudo crear la subcadena.\n");
	return (0);
}*/
/**
Nombre de función
    ft_substr
Prototipo 
    char *ft_substr(char const *s, unsigned int start, size_t len);
Archivos a entregar
    -
Parámetros
    s: La string desde la que crear la substring.
    start: El índice del caracter en ’s’ desde el que empezar la substring.
    len: La longitud máxima de la substring.
Valor devuelto 
    La substring resultante.
    NULL si falla la reserva de memoria.
Funciones autorizadas
    malloc
Descripción 
    Reserva (con malloc(3)) y devuelve una substring de la string ’s’.
    La substring empieza desde el índice ’start’ y tiene una longitud 
	máxima ’len’.
*/

/** EXPLICACION
 #include "libft.h"						//	Es necesario para size_t "unistd.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;						//	Inicio tamaño "s"
	char	*dst;						//	Inicio puntero a "dst"

	s_len = ft_strlen(s);				//	Asigno tamaño con strlen de "s"
	if (start >= s_len)					//	Si inicio >= tamaño de "s"
		return (ft_strdup(""));			//	Devuelvo un dup sin nada
	if (len > s_len - start)			//	Si len > tamaño "s" - inicio
		len = s_len - start;			//	len = tamaño "s" - inicio
	//	Asigno a punter "dst" mem reservada
	dst = (char *)malloc(sizeof(*s) * (len + 1));
	if (!dst)							//	Si da error al reservar memoria
		return (NULL);					//	Devuelvo NULL
	//	Copio en "dst" "s" + inicio segun len + cierre
	ft_strlcpy(dst, s + start, len + 1);
	return (dst);						//	Devuelvo puntero "dst"
}
*/
