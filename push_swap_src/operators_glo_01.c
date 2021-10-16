/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators_glo_01.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldavids <ldavids@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 22:13:11 by ldavids           #+#    #+#             */
/*   Updated: 2021/04/21 22:30:01 by ldavids          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_push.h"

void	ft_ra_glo(t_struct *ps)
{
	ft_ra(ps);
	ft_putstr_fd("ra\n", 1);
	ps->moves++;
}

void	ft_rb_glo(t_struct *ps)
{
	ft_rb(ps);
	ft_putstr_fd("rb\n", 1);
	ps->moves++;
}

void	ft_rr_glo(t_struct *ps)
{
	ft_rr(ps);
	ft_putstr_fd("rr\n", 1);
	ps->moves++;
}
