/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators_glo_00.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldavids <ldavids@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 22:05:13 by ldavids           #+#    #+#             */
/*   Updated: 2021/04/21 22:30:01 by ldavids          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_push.h"

void	ft_sa_glo(t_struct *ps)
{
	ft_sa(ps);
	ft_putstr_fd("sa\n", 1);
	ps->moves++;
}

void	ft_sb_glo(t_struct *ps)
{
	ft_sb(ps);
	ft_putstr_fd("sb\n", 1);
	ps->moves++;
}

void	ft_ss_glo(t_struct *ps)
{
	ft_ss(ps);
	ft_putstr_fd("ss\n", 1);
	ps->moves++;
}

void	ft_pa_glo(t_struct *ps, int argc)
{
	ft_pa(ps, argc);
	ft_putstr_fd("pa\n", 1);
	ps->moves++;
}

void	ft_pb_glo(t_struct *ps, int argc)
{
	ft_pb(ps, argc);
	ft_putstr_fd("pb\n", 1);
	ps->moves++;
}
