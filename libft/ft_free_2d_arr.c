/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_2d_arr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 20:10:57 by hroh              #+#    #+#             */
/*   Updated: 2021/03/09 20:18:54 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_2d_arr(void **array, int len)
{
	int i;

	i = 0;
	while (array[i])
	{
		if (len != 0)
		{
			if (i < len)
				free(array[i]);
		}
		else
			free(array[i]);
		i++;
		if (len != 0 && i == len)
		{
			free(array);
			return ;
		}
	}
	free(array);
}
