/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 16:59:21 by hroh              #+#    #+#             */
/*   Updated: 2021/03/09 22:19:04 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "./libft/libft.h"

#include <stdio.h> // 테스트용

typedef struct	s_env
{
	int			**arr_a;
	int			**arr_b;
	int			a_cnt;
	int			b_cnt;
	int			peak;
	int			sorted_num;
	int			ok;
}				t_env;

void	ft_check_argv(char **argv);
int		ft_puterr(void);
int		**ft_cast_int_argv(int argc, char **argv);
int		**ft_make_arr_b(int argc);
void	ft_action_sa(t_env *env, int mute);
void	ft_action_sb(t_env *env, int mute);
void	ft_action_ss(t_env *env);
void	ft_action_pa(t_env *env);
void	ft_action_pb(t_env *env);
void	ft_action_ra(t_env *env, int mute);
void	ft_action_rb(t_env *env, int mute);
void	ft_action_rr(t_env *env);
void	ft_action_rra(t_env *env, int mute);
void	ft_action_rrb(t_env *env, int mute);
void	ft_action_rrr(t_env *env);
void	ft_set_env(t_env *env, int argc, char **argv);
void	ft_sort(t_env *env);

#endif