/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators00.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldavids <ldavids@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 12:34:42 by ldavids           #+#    #+#             */
/*   Updated: 2021/04/22 15:47:24 by ldavids          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_push.h"

void	ft_sa(t_struct *ps)
{
	int		temp;

	if (ps->elements_a > 1)
	{
		temp = ps->stack_a[0];
		ps->stack_a[0] = ps->stack_a[1];
		ps->stack_a[1] = temp;
	}
}

void	ft_sb(t_struct *ps)
{
	int		temp;

	if (ps->ele_b > 1)
	{
		temp = ps->stack_b[0];
		ps->stack_b[0] = ps->stack_b[1];
		ps->stack_b[1] = temp;
	}
}

void	ft_ss(t_struct *ps)
{
	ft_sa(ps);
	ft_sb(ps);
}

void	ft_pa(t_struct *ps, int argc)
{
	int		i;
	int		temp;
	int		temp2;

	i = 0;
	if (ps->ele_b > 0)
	{
		ps->elements_a++;
		temp = ps->stack_a[i];
		while (i < ps->elements_a)
		{
			temp2 = ps->stack_a[i + 1];
			ps->stack_a[i + 1] = temp;
			temp = temp2;
			i++;
		}
		ps->ele_b--;
		ps->stack_a[0] = ps->stack_b[0];
		i = 0;
		while (i < argc - 1)
		{
			ps->stack_b[i] = ps->stack_b[i + 1];
			i++;
		}
	}
}

void	ft_pb(t_struct *ps, int argc)
{
	int		i;
	int		temp;
	int		temp2;

	i = 0;
	if (ps->elements_a > 0)
	{
		ps->ele_b++;
		temp = ps->stack_b[i];
		while (i < ps->ele_b)
		{
			temp2 = ps->stack_b[i + 1];
			ps->stack_b[i + 1] = temp;
			temp = temp2;
			i++;
		}
		ps->elements_a--;
		ps->stack_b[0] = ps->stack_a[0];
		i = 0;
		while (i < argc - 1)
		{
			ps->stack_a[i] = ps->stack_a[i + 1];
			i++;
		}
	}
}
