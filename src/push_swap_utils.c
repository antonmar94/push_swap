/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonmar <antonmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 15:42:45 by antonmar          #+#    #+#             */
/*   Updated: 2021/10/27 17:41:57 by antonmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_null(char **argv, char *clean_word)
{
	if (!clean_word || **argv == '\0')
	{
		write(2, "Error\n", 6);
		return (0);
	}
	return (1);
}

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
