/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ordenation_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonmar <antonmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 15:32:27 by antonmar          #+#    #+#             */
/*   Updated: 2021/10/27 15:36:55 by antonmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_plist	*get_pivote(t_plist *list, int len)
{
	t_plist	*aux;
	int		diff;
	t_plist	*first;
	int		i;
	int		j;

	first = list;
	i = 0;
	while (first && i++ < len)
	{
		diff = 0;
		aux = list;
		j = 0;
		while (aux && j++ < len)
		{
			if (aux->content >= first->content)
				diff++;
			aux = aux->next;
		}
		if (diff == len / 2 + len % 2)
			return (first);
		first = first->next;
	}
	return (list);
}

int	divide_alist(t_pslist *a_list, t_pslist *b_list, int len)
{
	int	reversed;
	int	num_elem;

	reversed = 0;
	num_elem = len;
	while (len != num_elem / 2 + num_elem % 2)
	{
		if (a_list->list->content < a_list->pivote->content)
		{
			single_moveb(a_list, b_list, 'p');
			len--;
		}
		else
		{
			single_movea(a_list, b_list, 'r');
			reversed++;
		}
	}
	return (reversed);
}

int	divide_blist(t_pslist *a_list, t_pslist *b_list, int len)
{
	int	reversed;
	int	num_elem;

	reversed = 0;
	num_elem = len;
	while (len != num_elem / 2)
	{
		if (b_list->list->content >= b_list->pivote->content)
		{
			single_movea(a_list, b_list, 'p');
			len--;
		}
		else
		{
			single_moveb(a_list, b_list, 'r');
			reversed++;
		}
	}
	return (reversed);
}
