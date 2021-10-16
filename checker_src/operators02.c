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

#include "header_checker.h"

void	ft_rra(t_struct *checker)
{
	int		i;
	int		temp;
	int		temp2;

	i = 0;
	temp = checker->stack_a[i];
	while (checker->elements_a > i + 1)
	{
		temp2 = checker->stack_a[i + 1];
		checker->stack_a[i + 1] = temp;
		temp = temp2;
		i++;
	}
	checker->stack_a[0] = temp;
}

void	ft_rrb(t_struct *checker)
{
	int		i;
	int		temp;
	int		temp2;

	i = 0;
	temp = checker->stack_b[i];
	while (checker->ele_b > i + 1)
	{
		temp2 = checker->stack_b[i + 1];
		checker->stack_b[i + 1] = temp;
		temp = temp2;
		i++;
	}
	checker->stack_b[0] = temp;
}

void	ft_rrr(t_struct *checker)
{
	ft_rra(checker);
	ft_rrb(checker);
}
