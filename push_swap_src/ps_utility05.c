/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utility05.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldavids <ldavids@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 15:08:48 by ldavids           #+#    #+#             */
/*   Updated: 2021/04/22 15:47:24 by ldavids          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_push.h"

int	ft_order_b_sub_1(t_struct *ps, int i)
{
	ps->order_b = i + 1;
	if (i != ps->ele_b - 1)
		ps->b_order_max = ps->stack_b[i + 1];
	return (0);
}

int	ft_order_b_sub_2(t_struct *ps, int i)
{
	int	j;

	j = 0;
	while (j < ps->elements_a)
	{
		if (ps->stack_a[j] < ps->stack_b[i])
			return (ft_order_b_sub_1(ps, i));
		j++;
	}
	j = 0;
	if (ps->stack_b[i] < ps->stack_b[i - 1])
	{
		j = 0;
		while (j < i)
		{
			if (ps->stack_b[i] < ps->stack_b[j])
				j++;
			else
				return (ft_order_b_sub_1(ps, i));
		}
		i--;
	}
	else
		return (ft_order_b_sub_1(ps, i));
	return (i);
}

int	ft_order_b(t_struct *ps)
{
	int	i;
	int	j;

	i = ps->ele_b - 1;
	j = 0;
	while (i > 0)
	{
		if (ft_order_b_sub_2(ps, i) == 0)
			return (0);
		i = ft_order_b_sub_2(ps, i);
	}
	j = 0;
	while (j < ps->elements_a)
	{
		if (ps->stack_a[j] < ps->stack_b[0])
			return (0);
		j++;
	}
	ps->order_b = i;
	if (i != ps->ele_b - 1)
		ps->b_order_max = ps->stack_b[i];
	return (1);
}
