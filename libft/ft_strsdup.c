/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 15:18:50 by hroh              #+#    #+#             */
/*   Updated: 2021/03/09 16:43:55 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsdup(char *str[])
{
	char		**rtn;
	int			i;

	i = 0;
	while (str[i] != 0)
		i++;
	rtn = malloc(sizeof(char *) * (i + 1));
	if (rtn == 0)
		return (0);
	while (i >= 0)
	{
		if (str[i] != 0)
			rtn[i] = ft_strdup(str[i]);
		else
			rtn[i] = 0;
		i--;
	}
	return (rtn);
}
