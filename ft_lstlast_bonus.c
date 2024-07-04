/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilastra- <ilastra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 14:44:55 by ilastra-          #+#    #+#             */
/*   Updated: 2024/05/17 10:13:10 by ilastra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

/**
Nombre de función
    ft_lstlast
Prototipo 
    t_list *ft_lstlast(t_list *lst);
Archivos a entregar
    -
Parámetros 
    lst: el principio de la lista.
Valor devuelto 
    Último nodo de la lista.
Funciones autorizadas
    Ninguna
Descripción 
    Devuelve el último nodo de la lista.

*/

/**
 * EXPLICACION
#include "libft.h"			//	Es necesario para size_t "unistd.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)					//	Si el puntero "lst" es nulo
		return (NULL);			//	Devuelvo NULL
	//	Recorro el puntero comprobando que el elemento "next" no sea NULL
	while (lst->next != NULL)
		lst = lst->next;		//  Me muevo puntero al siguiente elemento
	return (lst);				//	Devuelvo el último elemento de "lst"
}
*/
