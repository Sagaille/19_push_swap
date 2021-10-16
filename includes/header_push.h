/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header_push.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldavids <ldavids@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 15:43:35 by ldavids           #+#    #+#             */
/*   Updated: 2021/04/27 21:44:45 by ldavids          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_PUSH_H
# define HEADER_PUSH_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# define TRUE 1
# define FALSE 0

typedef struct s_struct
{
	char		**args_a;
	int			*stack_a;
	int			*stack_b;
	int			*stack_temp_a;
	int			*stack_temp_b;
	int			elements_a;
	int			ele_b;
	int			mini_chunk[50];
	int			chunk[501];
	int			order;
	int			ordered_ele;
	int			b_order_max;
	int			order_b;
	int			min;
	int			max;
	int			max_b_one;
	int			max_b;
	int			min_plus_one;
	int			med;
	int			moves;
	int			min_select;
	int			temp;
	int			i;
	int			counter2;
	int			bonus;
}	t_struct;

/*
** utility00.c
*/
int				ft_atoi_spec(const char *str);
void			ft_error(void);
unsigned int	ft_checkmax(unsigned long nb, int pos);
void			*ft_realloc(void *ptr, size_t size);
char			*ft_strcpy(char *dest, char *src);

/*
** utility01.c
*/
void			*ft_calloc_exit(size_t num, size_t size);
void			ft_ps_init(t_struct *ps, int argc);
void			ft_print_tab(int *tab, int argc);
int				ft_ok_ko(t_struct *ps, int argc);

/*
** utility02.c
*/
int				ft_under_med(t_struct *ps);
int				ft_over_med(t_struct *ps);
void			ft_check_switch_a(t_struct *ps);
void			ft_selection(int argc, t_struct *ps);

/*
** utility03.c
*/
int				ft_shorter_route(t_struct *ps, int argc);
int				ft_order_b(t_struct *ps);
int				ft_order(t_struct *ps);
void			ft_max_b(t_struct *ps);

/*
** utility04.c
*/
int				ft_in_order(t_struct *ps);
int				ft_mini_a_to_b(t_struct *ps, int temp, int argc);
void			ft_mini_b_to_a(t_struct *ps, int temp, int argc, int x);

/*
** sort.c
*/
int				ft_sort(int argc, t_struct *ps);
int				ft_min_max_med(int argc, t_struct *ps);

/*
** operators_glo_00.c
*/
void			ft_sa_glo(t_struct *ps);
void			ft_sb_glo(t_struct *ps);
void			ft_ss_glo(t_struct *ps);
void			ft_pa_glo(t_struct *ps, int argc);
void			ft_pb_glo(t_struct *ps, int argc);

/*
** operators_glo_01.c
*/
void			ft_ra_glo(t_struct *ps);
void			ft_rb_glo(t_struct *ps);
void			ft_rr_glo(t_struct *ps);

/*
** operators_glo_02.c
*/
void			ft_rra_glo(t_struct *ps);
void			ft_rrb_glo(t_struct *ps);
void			ft_rrr_glo(t_struct *ps);

/*
** operators00.c
*/
void			ft_sa(t_struct *ps);
void			ft_sb(t_struct *ps);
void			ft_ss(t_struct *ps);
void			ft_pa(t_struct *ps, int argc);
void			ft_pb(t_struct *ps, int argc);

/*
** operators01.c
*/
void			ft_ra(t_struct *ps);
void			ft_rb(t_struct *ps);
void			ft_rr(t_struct *ps);

/*
** operators02.c
*/
void			ft_rra(t_struct *ps);
void			ft_rrb(t_struct *ps);
void			ft_rrr(t_struct *ps);

/*
** quicksort.c
*/
int				ft_exceptions(t_struct *ps, int temp, int argc, int counter);
int				ft_quicksort(int argc, t_struct *ps);
int				ft_quicksort_a_to_b(t_struct *ps, int temp, int argc, int x);
void			ft_quicksort_b_to_a(t_struct *ps, int temp, int argc, int x);

/*
** optmimization.c
*/
int				ft_switch_down_a(t_struct *ps, int temp);

/*
** selection_a.c
*/
void			ft_stack_copy(int argc, t_struct *ps);
void			ft_selection_a(int argc, t_struct *ps, int counter);

/*
** selection_b.c
*/
void			ft_stack_copy_b(int argc, t_struct *ps);
void			ft_selection_chunk(int argc, t_struct *ps, int \
				chunk, int counter);

/*
** bonus.c
*/
char			**ft_relocate(int argc, char **argv);
int				ft_bonus(int argc, char **argv, t_struct *ps);

#endif
