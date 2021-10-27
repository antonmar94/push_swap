/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonmar <antonmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 15:17:12 by antonmar          #+#    #+#             */
/*   Updated: 2021/10/27 14:18:51 by antonmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	del_function(t_plist *node)
{
	t_plist	*aux;

	while (node != NULL)
	{
		aux = node;
		free(node);
		node->next = NULL;
		node = aux->next;
	}
	aux = NULL;
}

int	minus_checker(char *str)
{
	while (*str)
	{
		if (*str == '-' && *str)
		{
			str++;
			if (ft_isdigit(*str) == 0 || *str == '0')
				return (0);
		}
		str++;
	}
	return (1);
}

int	test_error(char **arg_list)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (arg_list[i])
	{
		j = 0;
		if (minus_checker(arg_list[i]) == 0)
			return (1);
		while (arg_list[i][j])
		{
			if (ft_isdigit(arg_list[i][j]) == 0
				&& arg_list[i][j] != ' ' && arg_list[i][j] != '-')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	dup_in_list(t_plist *list)
{
	t_plist	*aux;

	while (list)
	{
		aux = list->next;
		while (aux)
		{
			if (aux->content == list->content)
				return (1);
			aux = aux->next;
		}
		list = list->next;
	}
	return (0);
}

void	print_list(t_plist *a_list, t_plist *b_list)
{
	printf("\033[0;31m A");
	printf("\033[0;34m%20c\n", 'B');
	printf("\033[0;31m%-20s\033[0;34m%s\n", "---", "---");
	printf("\033[0m");
	while (a_list || b_list)
	{
		if (a_list)
		{
			printf(" %-20d", a_list->content);
			a_list = a_list->next;
		}
		else
			printf(" %-20s", " ");
		if (b_list)
		{
			printf("%d\n", b_list->content);
			b_list = b_list->next;
		}
		else
			printf("\n");
	}
}
