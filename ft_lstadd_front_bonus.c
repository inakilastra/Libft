/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilastra- <ilastra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 12:49:34 by ilastra-          #+#    #+#             */
/*   Updated: 2024/05/17 10:11:30 by ilastra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

/**
Nombre de función
    ft_lstadd_front
Prototipo 
    void ft_lstadd_front(t_list **lst, t_list *new);
Archivos a entregar
    -
Parámetros 
    lst: la dirección de un puntero al primer nodo de una lista.
    new: un puntero al nodo que añadir al principio de la lista.
Valor devuelto 
    Nada
Funciones autorizadas
    Ninguna
Descripción 
    Añade el nodo ’new’ al principio de la lista ’lst’.
*/

/**
 * EXPLICACION
#include "libft.h"			//	Es necesario para size_t "unistd.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)		//	Si "lst" o "new" son nulos
		return ;			//	Salgo sin hacer nada
	//	El puntero next del nuevo elemento "new->next" se actualiza para que 
	//	apunte al nodo que actualmente se encuentra en la cabeza de la 
	//	lista "*lst"
	new->next = *lst;
	*lst = new;				//	Asigno el puntero "lst" al nuevo elemento "new"
}
*/
