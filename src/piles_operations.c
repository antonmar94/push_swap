/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piles_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonmar <antonmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 15:38:34 by antonmar          #+#    #+#             */
/*   Updated: 2021/10/27 19:41:27 by antonmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap_ss(t_plist **a_list, t_plist **b_list)
{
	t_plist	*third_elem;
	t_plist	*second_elem;

	if (*a_list && *b_list && (*a_list)->next && (*b_list)->next)
	{
		second_elem = (*a_list)->next;
		third_elem = (*a_list)->next->next;
		(*a_list)->next = third_elem;
		second_elem->next = *a_list;
		*a_list = second_elem;
		second_elem = (*b_list)->next;
		third_elem = (*b_list)->next->next;
		(*b_list)->next = third_elem;
		second_elem->next = *b_list;
		*b_list = second_elem;
		write(1, "ss\n", 3);
	}
}

void	rotate_rr(t_plist **a_list, t_plist **b_list)
{
	t_plist	*aux;
	t_plist	*sec_elem;

	aux = *a_list;
	sec_elem = (*a_list)->next;
	while (aux->next)
		aux = aux->next;
	aux->next = *a_list;
	(*a_list)->next = NULL;
	*a_list = sec_elem;
	aux = *b_list;
	sec_elem = (*b_list)->next;
	while (aux->next)
		aux = aux->next;
	aux->next = *b_list;
	(*b_list)->next = NULL;
	*b_list = sec_elem;
	write(1, "rr\n", 3);
}

void	rotate_rrr(t_plist **a_list, t_plist **b_list)
{
	t_plist	*aux;
	t_plist	*sec_elem;

	aux = *a_list;
	sec_elem = *a_list;
	while (aux->next)
		aux = aux->next;
	aux->next = sec_elem;
	*a_list = aux;
	while (aux->next != *a_list)
		aux = aux->next;
	aux->next = NULL;
	aux = *b_list;
	sec_elem = *b_list;
	while (aux->next)
		aux = aux->next;
	aux->next = sec_elem;
	*b_list = aux;
	while (aux->next != *b_list)
		aux = aux->next;
	aux->next = NULL;
	write(1, "rrr\n", 4);
}

void	both_move(t_pslist *a_list, t_pslist *b_list, char oper)
{
	if (oper == 's')
	{
		swap_ss(&(a_list->list), &(b_list->list));
		a_list->cont++;
	}
	if (oper == 'r')
	{
		rotate_rr(&(a_list->list), &(b_list->list));
		a_list->cont++;
	}
	if (oper == 'o')
	{
		rotate_rrr(&(a_list->list), &(b_list->list));
		a_list->cont++;
	}
}
