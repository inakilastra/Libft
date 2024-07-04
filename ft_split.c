/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilastra- <ilastra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 14:54:52 by ilastra-          #+#    #+#             */
/*   Updated: 2024/05/27 14:46:46 by ilastra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_mem(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
}

static int	count_words(const char *s, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			words++;
			while (s[i] != '\0' && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (words);
}
/**
 * MODIFICAR CON FT_STRLCPY
*/

static char	*write_word(const char *s, int n)
{
	char	*dst;
	int		i;

	dst = malloc(sizeof(char) * (n + 1));
	if (!dst)
		return (NULL);
	i = 0;
	while (i < n)
	{
		dst[i] = s[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	**ft_split(const char *s, char c)
{
	int		i;
	int		j;
	char	**dst;

	dst = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!dst || !s)
		return (NULL);
	i = 0;
	while (*s && *s == c)
		s ++;
	while (*s)
	{
		j = 0;
		while (s[j] && s[j] != c)
			j ++;
		dst[i] = write_word(s, j);
		if (dst[i++] == NULL)
			return (free_mem(dst), NULL);
		s += j;
		while (*s && *s == c)
			s ++;
	}
	dst[i] = NULL;
	return (dst);
}

/** MAIN CON ARGUMENTOS * /
int	main(int argc, char **argv)
{
	char			*s;
	char			c;
	char			**str;
	int				i;

	i = 0;
	if (argc != 3)
	{
		printf("Error en el número de argumentos\n");
		return (0);
	}
	s = argv[1];
	c = argv[2][0];
	str = ft_split(s, c);
	printf("ft_split s: %s c: %c\n", s, c);
	while (str[i] != NULL)
	{
		printf("str[%d]: %s\n", i, str[i]);
		i++;
	}
	printf("\n");
	system("leaks main");
	return (0);
}*/

/**
Nombre de función
ft_split
Prototipo 
	char **ft_split(char const *s, char c);
Archivos a entregar
	-
Parámetros 
	s: La string a separar.
	c: El carácter delimitador.
Valor devuelto 
	El array de nuevas strings resultante de la separación.
	NULL si falla la reserva de memoria.
Funciones autorizadas
	malloc, free
Descripción 
	Reserva (utilizando malloc(3)) un array de strings resultante de separar 
	la string ’s’ en substrings utilizando el caracter ’c’ como delimitador. 
	El array debe terminar con un puntero NULL.
*/

/**
 * EXPLICACION
#include "libft.h"			//	Es necesario para size_t "unistd.h"
//	free_mem: Libera la memoria asignada a un array de cadenas.
static int	free_mem(char **s, int size)
{
	while (size--)		//	Recorro el tamaño a liberar
		free(s[size]);	//	Libero mem
	return (-1);		//	Devuelvo -1 Para usarlo en "str_split"
}
//	count_words: Cuenta el número de palabras en una cadena dada un delimitador.
static int	count_words(const char *s, char c)
{
	int	i;				//	Inicio contador posicion
	int	words;			//	Inicio contador palabras

	words = 0;			//	Asigno 0 a "words"
	i = 0;				//	Asigno 0 a "i"
	if (c == '\0')		//	Si c es \0 NULL
		return (1);		//	Devuelvo 1 (una palabra)
	while (s[i] != '\0')//	Recorro las posiciones de "s"
	{
		// Si la posicion no es como "c" y la siguiente no es "c" o cierre
		if ((s[i] != c) && (s[i + 1] == c || s[i + 1] == '\0'))
			words++;	//	Aumento el contador "words"
		i++;			//	Aumento el contador "i"
	}
	return (words);		//	 Devuelvo el valor de "words"
}
//	write_word: Copia una palabra de una cadena fuente a una cadena destino 
//	hasta encontrar el delimitador o el final de la cadena.
static void	write_word(char *dst, const char *src, char c)
{
	int	i;				//	Inicio contador

	i = 0;				//	Asigno 0 al contador
	//	Recorro "src" hasta encontrar posicion = "c" o cierre
	while (src[i] != c && src[i] != '\0')
	{
		dst[i] = src[i];//	Copio posicion "src" en "dst"
		i++;			//	Aumento contador
	}
	dst[i] = '\0';		//	Cierro
}
//	str_split divide la cadena "s" en palabras usando "c" como delimitador.
static int	str_split(char **split, const char *s, char c)
{
	int		i;			//	Inicio contador para recorrer "s"
	int		j;			//	Inicio contador posiciones de la palabra
	int		word;		//	Inicio contador	palabra

	word = 0;			//	Asigno 0 a "word"
	i = 0;				//	Asigno 0 a "i"
	while (s[i] != '\0')//	Recorro "s"
	{
		if (s[i] == c)	//	Si "s" es igual a "c"
			i++;		//	Aumento contado "i"
		else			
		{
			j = 0;		//	Asigno 0 al contador "j"
			//	Si la posicion de "s" no es "c" ni cierre
			while (s[i + j] != c && s[i + j] != '\0')
				j++;	//	Aumento el contador "j"
			//	Reservo mem para la palabra con tamaño "j" más cierre
			split[word] = (char *)malloc(sizeof(char) * (j + 1));
			//	Si la reseva es nulo
			if (split[word] == NULL)
				//	Libero la memoria y devuelvo un "-1" a ft_split
				return (free_mem(split, word - 1));
			//	Asigno la palabra de "split" al array split[word]
			write_word(split[word], s + i, c);
			i += j;		//	Asigno al contador "i" el contador "j"
			word++;		//	Aumento el contador "word" Avanzo palabra
		}
	}
	return (0);			//	Devuelvo 0 (Todo ok)
}

char	**ft_split(const char *s, char c)
{
	char	**new_str;	//	Inicio doble puntero
	int		words;		//	Inicio contador

	if (!s)				//	Si "s" es nulo
		return (NULL);	//	Devuelvo NULL
	//	Asigno al contador "words" el numero de palabras con "count_words"
	words = count_words(s, c);
	//	Asigno mem a "new_str" tamaño de char por "words" más cierre
	new_str = (char **)malloc(sizeof(char *) * (words + 1));
	if (!new_str)		//	Si la asignación falla
		return (NULL);	//	Devuelvo NULL
	//	Asigno NULL al último elemento del array "new_str[words]" para 
	//	marcar el final
	new_str[words] = NULL;
	//	Si al realizar la división en palabras con "str_split" devuelve -1
	if (str_split(new_str, s, c) == -1)
	{
		free(new_str);	//	Libero mem de "new_str"
		return (NULL);	//	Devuelvo NULL
	}
	return (new_str);	//	Devuelvo el array "new_str"
}
*/
