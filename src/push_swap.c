/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 16:42:14 by hroh              #+#    #+#             */
/*   Updated: 2021/03/14 14:38:02 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		main(int argc, char **argv)
{
	t_env	env;

	if (argc < 2)
		return (0);
	ft_check_argv(argv);
	if (argc == 2)
		return (0);
	ft_set_env(&env, argc, argv);
	if (!ft_is_ok(&env, env.ori_cnt))
		ft_sort(&env);
	ft_free_all(&env, NULL);
	return (0);
}
