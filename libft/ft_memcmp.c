/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 16:43:41 by hroh              #+#    #+#             */
/*   Updated: 2020/10/08 16:04:36 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*t_s1;
	unsigned char	*t_s2;

	i = 0;
	t_s1 = (unsigned char *)s1;
	t_s2 = (unsigned char *)s2;
	while (i < n)
	{
		if (t_s1[i] != t_s2[i])
		{
			return (t_s1[i] - t_s2[i]);
		}
		i++;
	}
	return (0);
}
