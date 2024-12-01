/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 00:05:01 by wimam             #+#    #+#             */
/*   Updated: 2024/12/01 00:17:14 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

int		ft_strlen_bonus(char *str);
char	*ft_strljoin_bonus(char *s1, char *s2, int size);
int		ft_new_line_check_bonus(char *str);
char	*ft_init_bonus(char *str);
char	*ft_strdup_bonus(char *s);
char	*get_next_line(int fd);

#endif