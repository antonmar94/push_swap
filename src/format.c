/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonmar <antonmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 15:17:12 by antonmar          #+#    #+#             */
/*   Updated: 2021/10/27 17:44:21 by antonmar         ###   ########.fr       */
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

int	create_list(t_plist **a_list, char **argv)
{
	t_plist	*aux_list;
	char	*clean_word;
	char	*aux;

	while (*argv)
	{
		aux = *argv;
		while (*aux || **argv == '\0')
		{
			clean_word = *ft_split(aux, ' ');
			if (check_null(argv, clean_word) == 0)
				return (-1);
			aux_list = ft_pslstnew(ft_atoi(clean_word));
			ft_pslstadd_back(a_list, aux_list);
			while (*aux == ' ' && *aux)
				aux++;
			while (*aux != ' ' && *aux)
				aux++;
			while (*aux == ' ' && *aux)
				aux++;
		}
		argv++;
	}
	return (1);
}
