/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 17:35:37 by gduval            #+#    #+#             */
/*   Updated: 2016/11/28 13:57:57 by gduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void		ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list	*tmp;

	tmp = lst;
	while (tmp)
	{
		(f)(tmp);
		tmp = tmp->next;
	}
}