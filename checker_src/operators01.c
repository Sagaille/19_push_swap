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

#include "header_checker.h"

void	ft_ra(t_struct *checker)
{
	int		i;
	int		temp;

	temp = checker->stack_a[0];
	i = 0;
	while (checker->elements_a > i)
	{
		checker->stack_a[i] = checker->stack_a[i + 1];
		i++;
	}
	checker->stack_a[i - 1] = temp;
}

void	ft_rb(t_struct *checker)
{
	int		i;
	int		temp;

	temp = checker->stack_b[0];
	i = 0;
	while (checker->ele_b > i)
	{
		checker->stack_b[i] = checker->stack_b[i + 1];
		i++;
	}
	checker->stack_b[i - 1] = temp;
}

void	ft_rr(t_struct *checker)
{
	ft_ra(checker);
	ft_rb(checker);
}
