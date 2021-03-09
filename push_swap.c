/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 16:42:14 by hroh              #+#    #+#             */
/*   Updated: 2021/03/09 22:18:10 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void test_print(int argc, char **argv, t_env *env)
{
	/****************************************************/
	int i;

	if (!argv)
		return ;
	//i = 0;
	//while (++i < argc)
	//	printf("argv[%d] : %s\n", i, argv[i]);
	i = -1;
	while (++i < argc - 1)
		printf("a[%d] : %d     b[%d] : %d\n", i, *((env->arr_a)[i]), i, *((env->arr_b)[i]));
	printf("a_cnt : %d\n", env->a_cnt);
	printf("b_cnt : %d\n", env->b_cnt);
	printf("peak : %d\n", env->peak);
	printf("sorted num : %d\n", env->sorted_num);
	printf("env->ok : %d\n", env->ok);
	
	/****************************************************/
}

int		main(int argc, char **argv)
{
	t_env	env;

	if (argc < 2)
		return (0);
	ft_check_argv(argv);
	if (argc == 2)
		return (0);
	ft_set_env(&env, argc, argv);
	test_print(argc, argv, &env);// 테스트용
	ft_sort(&env);
	ft_free_2d_arr((void **)env.arr_a, argc - 1);
	ft_free_2d_arr((void **)env.arr_b, argc - 1);
	return (0);
}
