/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilastra- <ilastra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 14:57:13 by ilastra-          #+#    #+#             */
/*   Updated: 2024/05/17 10:12:03 by ilastra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last_nodo;

	if (!lst || !new)
		return ;
	last_nodo = ft_lstlast(*lst);
	if (!last_nodo)
		*lst = new;
	else
		last_nodo->next = new;
}

/**
Nombre de función
    ft_lstadd_back
Prototipo 
    void ft_lstadd_back(t_list **lst, t_list *new);
Archivos a entregar
    -
Parámetros 
    lst: el puntero al primer nodo de una lista.
    new: el puntero a un nodo que añadir a la lista.
Valor devuelto 
    Nada
Funciones autorizadas
    Ninguna
Descripción 
    Añade el nodo ’new’ al final de la lista ’lst’.
*/

/**
 * EXPLICACION
#include "libft.h"			//	Es necesario para size_t "unistd.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last_nodo;		//	Inicio puntero last_nodo

	if (!lst || !new)		//	Si "lst" no esta iniciada o "new" es nulo
		return ;			//	Devuelvo NULL
	//	Asigno a "last_nodo" el último nodo de "lst" con ft_lstlast
	last_nodo = ft_lstlast(*lst);
	if (!last_nodo)			//	Si último nodo nulo
		*lst = new;			//	Asigno "new" al puntero "lst"
	else
		last_nodo->next = new;	// Agrego el nuevo nodo "new" 
}
*/
