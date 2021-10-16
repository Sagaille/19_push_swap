/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators01.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldavids <ldavids@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 12:35:15 by ldavids           #+#    #+#             */
/*   Updated: 2021/04/22 15:47:24 by ldavids          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_push.h"

void	ft_ra(t_struct *ps)
{
	int		i;
	int		temp;

	temp = ps->stack_a[0];
	i = 0;
	while (ps->elements_a > i)
	{
		ps->stack_a[i] = ps->stack_a[i + 1];
		i++;
	}
	ps->stack_a[i - 1] = temp;
}

void	ft_rb(t_struct *ps)
{
	int		i;
	int		temp;

	temp = ps->stack_b[0];
	i = 0;
	while (ps->ele_b > i)
	{
		ps->stack_b[i] = ps->stack_b[i + 1];
		i++;
	}
	ps->stack_b[i - 1] = temp;
}

void	ft_rr(t_struct *ps)
{
	ft_ra(ps);
	ft_rb(ps);
}
