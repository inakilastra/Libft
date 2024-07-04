/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilastra- <ilastra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:12:38 by ilastra-          #+#    #+#             */
/*   Updated: 2024/05/17 09:32:37 by ilastra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	*str;

	str = ft_itoa(n);
	ft_putstr_fd(str, fd);
	free(str);
}

/** MAIN CON ARGUMENTOS  * /
int	main(int argc, char **argv)
{
	int	n;
	int	fd;

	if (argc != 3)
	{
		printf("Error en el número de argumentos\n");
		return (0);
	}
	n = atoi(argv[1]);
	fd = atoi(argv[2]);
	if (fd < 0)
	{
		printf("El file descriptor debe ser un número positivo.\n");
		return (1);
	}
	ft_putnbr_fd(n, fd);
	return (0);
}*/

/**
Nombre de función
    ft_putnbr_fd
Prototipo 
    void ft_putnbr_fd(int n, int fd);
Archivos a entregar
    -
Parámetros 
    n: El número que enviar.
    fd: El file descriptor sobre el que escribir.
Valor devuelto 
    Nada
Funciones autorizadas
    write
Descripción 
    Envía el número ’n’ al file descriptor dado.
*/

/**
 * EXPLICACION
#include "libft.h"			//	Es necesario para size_t "unistd.h"

void	ft_putnbr_fd(int n, int fd)
{
	//	Con ft_itoa convierto lo numeros en str
	//	Con ft_putstr_fd envio el str a fd
    char *str = ft_itoa(n); // Call ft_itoa to convert int to string
    ft_putstr_fd(str, fd);     // Use the string 
    free(str);                // Free the memory allocated by ft_itoa   
}
*/
