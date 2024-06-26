/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohma <tohma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:46:05 by truello           #+#    #+#             */
/*   Updated: 2024/04/19 12:16:04 by tohma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char		*res;
	size_t		s1_len;
	size_t		s2_len;
	size_t		i;

	i = 0;
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	res = (char *) ft_calloc(s1_len + s2_len + 1, 1);
	if (!res)
		return (NULL);
	while (i < s1_len)
	{
		res[i] = s1[i];
		i++;
	}
	while (i - s1_len < s2_len)
	{
		res[i] = s2[i - s1_len];
		i++;
	}
	return (res);
}
