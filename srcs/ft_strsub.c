/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 11:40:33 by gduval            #+#    #+#             */
/*   Updated: 2016/11/28 15:00:08 by gduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	int		i;
	char	*str;

	if (s)
	{
		i = 0;
		if (!(str = ft_strnew(len)))
			return (NULL);
		if (!(ft_memmove(str, s + (start), len)))
			return (NULL);
		return (str);
	}
	return (NULL);
}
