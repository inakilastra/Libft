/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilastra- <ilastra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 15:45:11 by ilastra-          #+#    #+#             */
/*   Updated: 2024/05/17 09:15:27 by ilastra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

/** MAIN CON ARGUMENTOS  * /
int	main(int argc, char **argv)
{
	char	c;
	int		fd;

	if (argc != 3)
	{
		printf("Error en el número de argumentos\n");
		return (0);
	}
	c = argv[1][0];
	fd = atoi(argv[2]);
	if (fd < 0)
	{
		printf("El file descriptor debe ser un número positivo.\n");
		return (1);
	}
	ft_putchar_fd(c, fd);
	return (0);
}*/

/**
Nombre de función
	ft_putchar_fd
Prototipo 
	void ft_putchar_fd(char c, int fd);
Archivos a entregar
	-
Parámetros 
	c: El carácter a enviar.
	fd: El file descriptor sobre el que escribir.
Valor devuelto 
	Nada
Funciones autorizadas
	write
Descripción 
	Envía el carácter ’c’ al file descriptor especificado.
*/

/**
 * EXPLICACION
#include "libft.h"			//	Es necesario para write "unistd.h"

void	ft_putchar_fd(char c, int fd)
{
	//	fd es el descriptor de archivo en el que se desea escribir.
	//	&c es la dirección de memoria del carácter c. 
	//		Esto significa que write no recibirá una copia del carácter, 
	//		sino que accederá directamente a la memoria donde se almacena.
	//	1 es la cantidad de bytes que se escribirán. 
	//		En este caso, solo se escribe un único byte, 
	//		correspondiente al carácter c.
	write(fd, &c, 1);
}
//	La función ft_putchar_fd recibe un carácter 
//	y un descriptor de archivo como argumentos.
//	Utiliza la función write para imprimir el 
//	carácter en el descriptor de archivo especificado.
*/
