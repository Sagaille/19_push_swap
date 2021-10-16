/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldavids <ldavids@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 13:20:45 by ldavids           #+#    #+#             */
/*   Updated: 2021/04/27 21:10:05 by ldavids          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_push.h"

int	ft_switch_down_a_sub(t_struct *ps, int i, int temp)
{
	if (i == ps->elements_a - 1 && temp < ps->elements_a / 2)
	{
		while (temp > -1)
		{
			ft_ra_glo(ps);
			temp--;
			ps->moves++;
		}
		return (1);
	}
	else if (i == ps->elements_a - 1)
	{
		temp = ps->elements_a - temp - 2;
		while (temp > -1)
		{
			ft_rra_glo(ps);
			temp--;
			ps->moves++;
		}
		return (1);
	}
	return (0);
}

int	ft_switch_down_a(t_struct *ps, int temp)
{
	int	i;

	i = 0;
	while (i <= ps->elements_a)
	{
		if (ps->stack_a[i] < ps->stack_a[i + 1])
			i++;
		else if (ps->stack_a[i] == ps->max && \
			ps->stack_a[i + 1] == ps->min)
		{
			temp = i;
			i++;
		}
		else
			break ;
	}
	if (ft_switch_down_a_sub(ps, i, temp) == 1)
		return (1);
	return (0);
}
