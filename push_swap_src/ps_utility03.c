/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utility03.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldavids <ldavids@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 15:40:39 by ldavids           #+#    #+#             */
/*   Updated: 2021/04/23 12:25:58 by ldavids          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_push.h"

int	ft_shorter_route(t_struct *ps, int argc)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < argc - 1)
	{
		if (ps->stack_b[ps->ele_b - j] > ps->med && ps->stack_b \
			[ps->ele_b - j] != ps->min && ps->stack_b[ps->ele_b - j] \
			!= ps->min_plus_one)
			break ;
		j++;
	}
	while (i < argc - 1)
	{
		if (ps->stack_b[i] > ps->med \
		 && ps->stack_b[i] != ps->min && \
		ps->stack_b[i] != ps->min_plus_one)
			break ;
		i++;
	}
	if (i + 1 >= j)
		return (1);
	return (0);
}

void	ft_max_b(t_struct *ps)
{
	int	i;

	i = 0;
	ps->max_b = ps->stack_b[i];
	ps->max_b_one = ps->stack_b[i];
	while (i < ps->ele_b)
	{
		if (ps->stack_b[i] > ps->max_b)
			ps->max_b = ps->stack_b[i];
		i++;
	}
	i = 0;
	while (i < ps->ele_b)
	{
		if (ps->stack_b[i] > ps->max_b_one && ps->stack_b[i] < ps->max_b)
			ps->max_b_one = ps->stack_b[i];
		i++;
	}
}

int	ft_in_order(t_struct *ps)
{
	int	i;
	int	j;

	i = ps->elements_a - 1;
	while (i >= 0)
	{
		j = 0;
		while (j < ps->ele_b)
		{
			if (ps->stack_b[j] > ps->stack_a[i])
				return (0);
			j++;
		}
		if (i == 0 || ps->stack_a[i] > ps->stack_a[i - 1])
			i--;
		else
			return (0);
	}
	return (1);
}
