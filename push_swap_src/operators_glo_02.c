/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators_glo_02.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldavids <ldavids@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 22:16:47 by ldavids           #+#    #+#             */
/*   Updated: 2021/04/21 22:30:01 by ldavids          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_push.h"

void	ft_rra_glo(t_struct *ps)
{
	ft_rra(ps);
	ft_putstr_fd("rra\n", 1);
	ps->moves++;
}

void	ft_rrb_glo(t_struct *ps)
{
	ft_rrb(ps);
	ft_putstr_fd("rrb\n", 1);
	ps->moves++;
}

void	ft_rrr_glo(t_struct *ps)
{
	ft_rrr(ps);
	ft_putstr_fd("rrr\n", 1);
	ps->moves++;
}
