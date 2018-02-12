/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 14:48:22 by jmeier            #+#    #+#             */
/*   Updated: 2017/12/12 12:39:41 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t size, size_t new_size)
{
	void	*new;

	new = (void *)malloc(size + new_size);
	if (new == NULL)
		return (NULL);
	new = ft_memcpy(new, ptr, new_size);
	free(ptr);
	return (new);
}
