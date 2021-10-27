/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonmar <antonmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 15:42:45 by antonmar          #+#    #+#             */
/*   Updated: 2021/10/26 15:47:44 by antonmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_orden(t_plist *list)
{
	t_plist	*aux;

	if (!list)
		return (1);
	while (list->next)
	{
		aux = list->next;
		while (aux)
		{
			if (aux->content < list->content)
				return (0);
			if (aux->next)
				aux = aux->next;
			else
				break ;
		}
		list = list->next;
	}
	return (1);
}

int	is_invorden(t_plist *list)
{
	t_plist	*aux;

	if (!list)
		return (1);
	while (list->next)
	{
		aux = list->next;
		while (aux)
		{
			if (aux->content > list->content)
				return (0);
			if (aux->next)
				aux = aux->next;
			else
				break ;
		}
		list = list->next;
	}
	return (1);
}

int	is_in_list(t_plist *list, t_plist *elemen)
{
	t_plist	*aux;

	aux = list;
	while (aux)
	{
		if (aux == elemen)
			return (1);
		aux = aux->next;
	}
	return (0);
}

int	is_thelowest(t_plist *list, t_plist *elemen)
{
	t_plist	*aux;

	aux = list;
	if (!list || !elemen)
		return (0);
	while (aux)
	{
		if (aux->content < elemen->content)
			return (0);
		aux = aux->next;
	}
	return (1);
}

int	is_thebigger(t_plist *list, t_plist *elemen)
{
	t_plist	*aux;

	aux = list;
	if (!list || !elemen)
		return (0);
	while (aux)
	{
		if (aux->content > elemen->content)
			return (0);
		aux = aux->next;
	}
	return (1);
}
