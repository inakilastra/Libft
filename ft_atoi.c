/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilastra- <ilastra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 10:56:48 by ilastra-          #+#    #+#             */
/*   Updated: 2024/07/08 08:29:56 by ilastra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	num;
	int	neg;

	i = 0;
	num = 0;
	neg = 1;
	if (!str)
		return (0);
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (num * neg);
}

/** MAIN CON ARGUMENTOS * /
int	main(int argc, char **argv)
{
	char	*str;
	int		i;

	if (argc != 2)
	{
		printf("Error en el número de argumentos\n");
		return (0);
	}
	str = argv[1];
	i = ft_atoi(str);
	printf("ft_atoi %d\n", i);
	i = atoi(str);
	printf("atoi    %d\n", i);
	return (0);
}*/

/** TEORIA RESUMEN
int atoi(const char *str);
La función atoi (que viene del inglés "ASCII to Integer") es una función de 
la biblioteca estándar de C (stdlib.h) que se utiliza para convertir una 
cadena de caracteres ASCII que representa un número entero a su valor numérico 
real. En otras palabras, toma una secuencia de dígitos como "1234" y la 
transforma en el número entero 1234.
*/

/** EXPLICACION CODIGO
#include "libft.h"			//	Es necesario para size_t "unistd.h"

//	Contador para recorrer el string str
//	Variable para recoger el valor numerico del string
//	Control valor negativo
	int	i;
	int	num;
	int	neg;

//	Inicializo el contador a 0
//	Inicializo el número a 0
//	Inicializo el valor 1
	i = 0;
	num = 0;
	neg = 1;
	neg = 1;
//   Si str es nulo Devuelvo 0     
	if (!str) 
		return (0);     
//	Reccoro str obviando TAB Horizontal, \n y el ESPACIO
//	Aumento el contador
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
//	Si la posición str es "+" o "-"
	if (str[i] == '+' || str[i] == '-')
	{
//	Si es "-" 
//	Cambio negativo a -1		
		if (str[i] == '-')
			neg = -1;
//	Si la posición str es "+" o "-" Aumento el contador			
		i++;
	}
//	Si la posición str es un caracter numerico
	while (str[i] >= '0' && str[i] <= '9')
	{
//	Transformo el caracter en numero y lo multiplico por 10 para y 
//	agregando decena...	
		num = num * 10 + str[i] - '0';
//	Aumento el contador		
		i++;
	}
//	En caso de que str no tuviese ningun caracter numerico num tiene valor 0
//	Retorno el valor numerico con su signo correspondiente	
	return (num * neg);
*/
