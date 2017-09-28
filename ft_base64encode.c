/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base64encode.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 20:14:04 by asarandi          #+#    #+#             */
/*   Updated: 2017/09/28 11:37:20 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*ft_b64algo(size_t i, size_t k, size_t size, char *mem, unsigned char *s)
{
	unsigned char	tab[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
	unsigned char c;
	unsigned char d;

	while (i < size)
	{
		c = s[i] >> 2;
		mem[k++] = tab[c];
		c = s[i++] << 6;
		d = s[i] >> 4;
		mem[k++] = tab[(c >> 2) + d];
		c = s[i++] << 4;
		d = s[i] >> 6;
		mem[k++] = tab[(c >> 2) + d];
		c = ((s[i++]) << 2);
		mem[k++] = tab[c >> 2];
	}
	if (i - 2 == size)
		mem[k - 2] = '=';
	if (i - 1 >= size)
		mem[k - 1] = '=';
	return (mem);
}

char	*ft_base64encode(unsigned char *o, size_t size)
{
	char			*mem;
	unsigned char	*s;
	size_t			i;

	if ((s = ft_memalloc((size + 6) * sizeof(char))) == NULL)
		return (NULL);
	ft_memcpy(s, o, size);
	i = size;
	while (i % 3)
		i++;
	i /= 3;
	i *= 4;
	if ((mem = ft_memalloc((i + 1) * sizeof(char))) == NULL)
		return (NULL);
	return (ft_b64algo(0, 0, size, mem, s));
}
