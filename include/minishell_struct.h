/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_struct.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <truello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 12:51:41 by truello           #+#    #+#             */
/*   Updated: 2024/03/18 14:34:02 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_STRUCT_H
# define MINISHELL_STRUCT_H

typedef struct s_token
{
	char	**tokens;
	int		count;
}	t_tokens;

typedef struct s_btree
{
	void			*val;
	struct s_btree	*left;
	struct s_btree	*right;
}	t_btree;

#endif
