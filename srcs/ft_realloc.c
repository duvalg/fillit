/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 11:44:37 by gduval            #+#    #+#             */
/*   Updated: 2016/12/03 12:41:54 by gduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdlib.h>

char		*ft_realloc(char **src, size_t size, size_t option)
{
	char	*new;

	if (!*src)
		return (NULL);
	else if (!(new = ft_strnew(size)))
		return (NULL);
	else
	{
		ft_memcpy(new, *src, ft_strlen(*src));
		if (option == 1)
			ft_memdel((void **)src);
		if (option == 2)
			ft_bzero(*src, ft_strlen(*src));
	}
	return (new);
}
