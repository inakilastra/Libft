/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilastra- <ilastra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 16:03:33 by ilastra-          #+#    #+#             */
/*   Updated: 2024/05/17 09:21:29 by ilastra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}

/** MAIN CON ARGUMENTOS  * /
int	main(int argc, char **argv)
{
	char	*str;
	int		fd;

	if (argc != 3)
	{
		printf("Error en el número de argumentos\n");
		return (0);
	}
	str = argv[1];
	fd = atoi(argv[2]);
	if (fd < 0)
	{
		printf("El file descriptor debe ser un número positivo.\n");
		return (1);
	}
	ft_putstr_fd(str, fd);
	printf("\n");
	return (0);
}*/

/**
Nombre de función
    ft_putstr_fd
Prototipo 
    void ft_putstr_fd(char *s, int fd);
Archivos a entregar
    -
Parámetros 
    s: La string a enviar.
    fd: El file descriptor sobre el que escribir.
Valor devuelto 
    Nada
Funciones autorizadas
    write
Descripción 
    Envía la string ’s’ al file descriptor especificado.
*/

/**
 * EXPLICACION
#include "libft.h"			//	Es necesario para size_t "unistd.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;          //  Inicio contador

	if (!s)         //  Si "s" es nulo
		return ;    //	No devuelvo nada
	i = 0;          //  Asigno 0 al contador
	while (s[i])    //  Recorro "s"
	{
        //	La función ft_putchar_fd recibe un carácter 
        //	y un descriptor de archivo como argumentos.
        //	Utiliza la función write para imprimir el 
        //	carácter en el descriptor de archivo especificado.
        ft_putchar_fd(s[i], fd);
		i++;        //  Aumento el contador
	}
}

*/
