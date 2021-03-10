/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 19:52:17 by hroh              #+#    #+#             */
/*   Updated: 2021/03/10 21:06:58 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_all(t_env *env, char *line)
{
	ft_free_2d_arr((void **)env->arr_a, env->ori_cnt);
	ft_free_2d_arr((void **)env->arr_b, env->ori_cnt);
	if (line)
		free(line);
}
