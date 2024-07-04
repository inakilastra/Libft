/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilastra- <ilastra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 09:44:25 by ilastra-          #+#    #+#             */
/*   Updated: 2024/05/16 15:59:10 by ilastra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*c;

	if (!s || !f)
		return (NULL);
	c = (char *)malloc(sizeof(char) * (ft_strlen((char *)s) + 1));
	if (!c)
		return (NULL);
	i = 0;
	while (i < (ft_strlen((char *)s)))
	{
		c[i] = f(i, s[i]);
		i++;
	}
	c[i] = '\0';
	return (c);
}

/** MAIN CON ARGUMENTOS 
Función de mapeo para convertir caracteres a mayúsculas * /
char	map_to_uppercase(unsigned int index, char c)
{
	(void)index;
	if (c >= 'a' && c <= 'z')
		return (c - ('a' - 'A'));
	return (c);
}

int	main(int argc, char **argv)
{
	char	*s;
	char	*mapped_str;

	if (argc != 3)
	{
		printf("Error en el número de argumentos\n");
		return (0);
	}
	s = argv[1];
	mapped_str = ft_strmapi(s, map_to_uppercase);
	if (mapped_str)
	{
		printf("String original: \"%s\"\n", s);
		printf("String mapeado:  \"%s\"\n", mapped_str);
		free(mapped_str);
	}
	else
		printf("Error: no se pudo aplicar .\n");
	system("leaks main");
	return (0);
}*/

/**
Nombre de función
	ft_strmapi
Prototipo 
	char *ft_strmapi(char const *s, char (*f)(unsigned int, char));
Archivos a entregar
	-
Parámetros 
	s: La string que iterar.
	f: La función a aplicar sobre cada carácter.
Valor devuelto 
	La string creada tras el correcto uso de ’f’ sobre cada carácter.
	NULL si falla la reserva de memoria.
Funciones autorizadas
	malloc
Descripción 
	A cada carácter de la string ’s’, aplica la función ’f’ dando como 
	parámetros el índice de cada carácter dentro de ’s’ y el propio 
	carácter. Genera una nueva string con el resultado del uso sucesivo 
	de ’f’
*/

/**
 * EXPLICACION
#include "libft.h"			//	Es necesario para size_t "unistd.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;				//	Inicio contador
	char	*c;				//	Inicio puntero

	if (!s || !f)			//	Si puntero "c" o o puntero "f" son Nulos 
		return (NULL);		//	Devuelvo NULL
	//	Asigno mem a "c" tamaño char por tamaño "s" más cierre
	c = (char *)malloc(sizeof(char) * (ft_strlen((char *)s) + 1));
	if (!c)					//	Si falla al asignar mem
		return (NULL);		//	Devuelvo NULL
	i = 0;					//	Asigno 0 al contador
	//	Recorro mientras el contador "i" sea menor que el tamaño de "s"
	while (i < (ft_strlen((char *)s)))
	{
		//	Aplico la función "f" pasando como argumentos "i" y "s[i]"
		c[i] = f(i, s[i]);
		i++;				//	Aumento el contador
	}
	c[i] = '\0';			//	Cierro
	//	Devuelvo puntero "c" con los valores modificados según la función "f"
	return (c);
}
*/
