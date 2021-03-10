/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 16:42:14 by hroh              #+#    #+#             */
/*   Updated: 2021/03/10 21:03:24 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int argc, char **argv)
{
	t_env	env;

	if (argc < 2)
		return (0);
	ft_check_argv(argv);
	if (argc == 2)
		return (0);
	ft_set_env(&env, argc, argv);
	ft_sort(&env);
	ft_free_all(&env, NULL);
	return (0);
}
