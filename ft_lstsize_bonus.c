/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilastra- <ilastra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 14:33:29 by ilastra-          #+#    #+#             */
/*   Updated: 2024/05/17 10:13:32 by ilastra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

/*
Nombre de función
    ft_lstsize
Prototipo 
    int ft_lstsize(t_list *lst);
Archivos a entregar
    -
Parámetros 
    lst: el principio de la lista.
Valor devuelto 
    La longitud de la lista.
Funciones autorizadas
    Ninguna
Descripción 
    Cuenta el número de nodos de una lista.
*/

/**
 * EXPLICACION
#include "libft.h"			//	Es necesario para size_t "unistd.h"

int	ft_lstsize(t_list *lst)
{
	int	i;                  //  Inicio contador

	i = 0;                  //  Asigno 0 al contador
	while (lst != NULL)     //  Recorro "lst"
	{
		lst = lst->next;    //  Me muevo puntero al siguiente elemento
		i++;                //  Aumento el contador
	}
	return (i);             //  Devulevo el contador
}
*/
