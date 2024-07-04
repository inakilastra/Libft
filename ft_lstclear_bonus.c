/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilastra- <ilastra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 09:03:45 by ilastra-          #+#    #+#             */
/*   Updated: 2024/05/17 10:12:23 by ilastra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*nodo_actual;
	t_list	*nodo_prox;

	nodo_actual = *lst;
	while (nodo_actual)
	{
		nodo_prox = nodo_actual->next;
		ft_lstdelone(nodo_actual, del);
		nodo_actual = nodo_prox;
	}
	*lst = NULL;
}

/**
Nombre de función
    ft_lstclear
Prototipo 
    void ft_lstclear(t_list **lst, void (*del)(void *));
Archivos a entregar
    -
Parámetros 
    lst: la dirección de un puntero a un nodo.
    del: un puntero a función utilizado para eliminar el contenido de un nodo.
Valor devuelto 
    Nada
Funciones autorizadas
    free
Descripción 
    Elimina y libera el nodo ’lst’ dado y todos los consecutivos de ese nodo, 
    utilizando la función ’del’ y free(3).
    Al final, el puntero a la lista debe ser NULL.
*/

/**
 * EXPLICACION
#include "libft.h"			//	Es necesario para size_t "unistd.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*nodo_actual;	//	Inicio puntero
	t_list	*nodo_prox;		//	Inicio puntero

	nodo_actual = *lst;		//	Asigno la "lst" a "nodo_actual"
	while (nodo_actual)		//	Recorro los nodos de la lista
	{
		//	Asigno el siguiente nodo para no perder la referencia
		nodo_prox = nodo_actual->next;
		//	Elimino el nodo actual y libero mem con ft_lstdelone
		ft_lstdelone(nodo_actual, del);
		//	Asigno el siguiente nodo para seguir recorriendo la lista
		nodo_actual = nodo_prox;
	}
	*lst = NULL;			//	Asigno NULL al puntero "lst"
}
*/
