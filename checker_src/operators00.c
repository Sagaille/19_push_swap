/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators00.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldavids <ldavids@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 12:34:42 by ldavids           #+#    #+#             */
/*   Updated: 2021/04/27 14:48:24 by ldavids          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_checker.h"

void	ft_sa(t_struct *checker)
{
	int		temp;

	if (checker->elements_a > 1)
	{
		temp = checker->stack_a[0];
		checker->stack_a[0] = checker->stack_a[1];
		checker->stack_a[1] = temp;
	}
}

void	ft_sb(t_struct *checker)
{
	int		temp;

	if (checker->ele_b > 1)
	{
		temp = checker->stack_b[0];
		checker->stack_b[0] = checker->stack_b[1];
		checker->stack_b[1] = temp;
	}
}

void	ft_ss(t_struct *checker)
{
	ft_sa(checker);
	ft_sb(checker);
}

void	ft_pa(t_struct *checker, int argc)
{
	int		i;
	int		temp;
	int		temp2;

	i = 0;
	if (checker->ele_b > 0)
	{
		checker->elements_a++;
		temp = checker->stack_a[i];
		while (i < checker->elements_a)
		{
			temp2 = checker->stack_a[i + 1];
			checker->stack_a[i + 1] = temp;
			temp = temp2;
			i++;
		}
		checker->ele_b--;
		checker->stack_a[0] = checker->stack_b[0];
		i = 0;
		while (i < argc - 1)
		{
			checker->stack_b[i] = checker->stack_b[i + 1];
			i++;
		}
	}
}

void	ft_pb(t_struct *checker, int argc)
{
	int		i;
	int		temp;
	int		temp2;

	i = 0;
	if (checker->elements_a > 0)
	{
		checker->ele_b++;
		temp = checker->stack_b[i];
		while (i < checker->ele_b)
		{
			temp2 = checker->stack_b[i + 1];
			checker->stack_b[i + 1] = temp;
			temp = temp2;
			i++;
		}
		checker->elements_a--;
		checker->stack_b[0] = checker->stack_a[0];
		i = 0;
		while (i < argc - 1)
		{
			checker->stack_a[i] = checker->stack_a[i + 1];
			i++;
		}
	}
}
