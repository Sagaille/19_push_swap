/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldavids <ldavids@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 15:37:58 by ldavids           #+#    #+#             */
/*   Updated: 2021/03/25 16:12:37 by ldavids          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*newstr;
	size_t	index;

	index = 0;
	if (s == NULL)
		return (NULL);
	newstr = (char *)malloc((sizeof(char) * len + 1));
	if (!newstr)
		return (NULL);
	if (!(start > ft_strlen(s)))
	{
		while (len > index && s[start + index])
		{
			newstr[index] = s[start + index];
			index++;
		}
	}
	newstr[index] = '\0';
	return (newstr);
}
