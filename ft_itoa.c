/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilastra- <ilastra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:12:27 by ilastra-          #+#    #+#             */
/*   Updated: 2024/05/16 15:47:32 by ilastra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	n_dig(int n)
{
	int	i;
	int	tmp;

	tmp = n;
	i = 1;
	if (tmp < 0)
	{
		tmp *= -1;
		i++;
	}
	while (tmp >= 10)
	{
		tmp /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		dig;
	char	*str;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	dig = n_dig(n);
	str = (char *)malloc(sizeof(char) * (dig + 1));
	if (!str)
		return (NULL);
	str[dig--] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	while (n > 0)
	{
		str[dig--] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}

/** MAIN CON ARGUMENTOS * /
int	main(int argc, char **argv)
{
	int		n;
	char	*str;

	if (argc != 2)
	{
		printf("Error en el número de argumentos\n");
		return (0);
	}
	n = ft_atoi(argv[1]);
	str = ft_itoa(n);
	if (str)
	{
		printf("Número entero: %d\n", n);
		printf("Cadena equivalente: %s\n", str);
		free(str);
	}
	else
		printf("Error al convertir el número a cadena\n");
	return (0);
}*/

/**
Nombre de función
    ft_itoa
Prototipo 
    char *ft_itoa(int n);
Archivos a entregar
    -
Parámetros 
    n: el entero a convertir.
Valor devuelto 
    La string que represente el número.
    NULL si falla la reserva de memoria.
Funciones autorizadas
    malloc
Descripción 
    Utilizando malloc(3), genera una string que represente el valor entero 
    recibido como argumento.
    Los números negativos tienen que gestionarse.
*/

/**
 * EXPLICACION
#include "libft.h"			//	Es necesario para size_t "unistd.h"
//	n_dig: Cuenta el número de dígitos de un número "n"
static	int	n_dig(int n)
{
	int	i;				//	Inicio un contador de digitos
	int	tmp;			//	Inicio numero temporal para no alterar "n"

	tmp = n;			//	Asigno "n" a "tmp"
	i = 1;				//	Asingo 1 al contador (primer digito)
	if (tmp < 0)		//	Si "tmp" es menos que 0 (n es negativo)
	{
		tmp *= -1;		//	Multiplico por -1 para hacerlo positivo
		i++;			//	Aumento el contador
	}
	while (tmp >= 10)	//	Recorro "tmp" hasta que sea menor de 10
	{
		tmp /= 10;		//	Asigno a "tmp" su propio valor dividido por 10
		i++;			//	Aumento el contador			
	}
	return (i);			//	Devuelvo el contador de digitos
}

char	*ft_itoa(int n)
{
	int		dig;		//	Inicio contador posiciones dig
	char	*str;		//	Inicio puntero cadena "str"

	//	Si "n" == -2147483648 (no se puede controlar de otra manera)
	if (n == -2147483648)
		//	Devuelvo el str literal mediante strdup que duplica str en dst	
		return (ft_strdup("-2147483648"));
	Si "n" == 0 (no se puede controlar de otra manera)
	if (n == 0)
		//	Devuelvo el str literal mediante strdup que duplica str en dst
		return (ft_strdup("0"));
	dig = n_dig(n);		//	Asigno al contador "dig" el numero de digitos
	//	Reservo mem con tamaño de char por "dig" más cierre
	str = (char *)malloc(sizeof(char) * (dig + 1));
	if (!str)			//	Si falla la asignación de mem
		return (NULL);	//	Devuelvo NULL
	str[dig--] = '\0';	//	Cierro
	if (n < 0)			//	Si "n" es menos que 0 (n es negativo)
	{
		str[0] = '-';	//	Asgino "-" a la primera posicion de "str"
		n *= -1;		//	Multiplico por -1 para hacerlo positivo
	}
	while (n > 0)		//	Recorro "n" 
	{
		//	Asigno a la posicion "str" el resto de la división de "n" entre 10
		//	convirtiendolo en caracter con "+ '0'"
		str[dig--] = (n % 10) + '0';
		n /= 10;		//	Divido "n" entre 10 y lo guardo en "n"
	}
	return (str);		//	Devuelvo la cadena con el número convertido en char
}
*/
