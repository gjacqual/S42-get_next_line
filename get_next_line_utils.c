/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacqual <gjacqual@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 20:27:35 by gjacqual          #+#    #+#             */
/*   Updated: 2021/07/17 15:28:37 by gjacqual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (s == NULL)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sstr;
	size_t	slen;
	size_t	subsize;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (slen < start)
		return (ft_strdup("\0"));
	subsize = ft_strlen(s + start);
	if (subsize < len)
		len = subsize;
	sstr = (char *)malloc(sizeof(char) * len + 1);
	if (!sstr)
		return (NULL);
	ft_memmove(sstr, (s + start), len);
	sstr[len] = '\0';
	return (sstr);
}

char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	strsize;

	strsize = ft_strlen(s1) + 1;
	str = (char *)malloc(sizeof(char) * strsize);
	if (str)
	{
		str = ft_memcpy(str, s1, strsize);
		return (str);
	}
	return (NULL);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	str1 = (unsigned char *)src;
	str2 = (unsigned char *)dst;
	i = 0;
	if (!dst && !src)
		return (0);
	while (i < n)
	{
		str2[i] = str1[i];
		i++;
	}
	return (dst);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*strsrc;
	unsigned char	*strdst;
	size_t			i;

	strsrc = (unsigned char *)src;
	strdst = (unsigned char *)dst;
	i = 0;
	if (!dst && !src)
		return (NULL);
	if (strdst == strsrc)
		return (dst);
	while (i < len)
	{
		if (strdst > strsrc)
		{
			strdst[len - i - 1] = strsrc[len - i - 1];
		}
		else
		{
			strdst[i] = strsrc[i];
		}
		i++;
	}	
	return (dst);
}
