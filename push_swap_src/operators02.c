/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators02.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldavids <ldavids@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 12:36:15 by ldavids           #+#    #+#             */
/*   Updated: 2021/04/22 15:47:24 by ldavids          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_push.h"

void	ft_rra(t_struct *ps)
{
	int		i;
	int		temp;
	int		temp2;

	i = 0;
	temp = ps->stack_a[i];
	while (ps->elements_a > i + 1)
	{
		temp2 = ps->stack_a[i + 1];
		ps->stack_a[i + 1] = temp;
		temp = temp2;
		i++;
	}
	ps->stack_a[0] = temp;
}

void	ft_rrb(t_struct *ps)
{
	int		i;
	int		temp;
	int		temp2;

	i = 0;
	temp = ps->stack_b[i];
	while (ps->ele_b > i + 1)
	{
		temp2 = ps->stack_b[i + 1];
		ps->stack_b[i + 1] = temp;
		temp = temp2;
		i++;
	}
	ps->stack_b[0] = temp;
}

void	ft_rrr(t_struct *ps)
{
	ft_rra(ps);
	ft_rrb(ps);
}
