/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilastra- <ilastra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 16:31:40 by ilastra-          #+#    #+#             */
/*   Updated: 2024/05/17 09:25:30 by ilastra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (s)
	{
		ft_putstr_fd(s, fd);
		ft_putchar_fd('\n', fd);
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
	ft_putendl_fd(str, fd);
	return (0);
}*/

/**
Nombre de función
    ft_putendl_fd
Prototipo 
    void ft_putendl_fd(char *s, int fd);
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
    Envía la string ’s’ al file descriptor dado, seguido de un salto de línea.
*/

/**
 * EXPLICACION
#include "libft.h"			//	Es necesario para size_t "unistd.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (s)                      //  Si "s" es nulo
	{
		//  Envía la string ’s’ al file descriptor especificado.
        ft_putstr_fd(s, fd);
        //  Envía el caracter ’\n’ al file descriptor especificado.
		ft_putchar_fd('\n', fd);
	}
}
*/
