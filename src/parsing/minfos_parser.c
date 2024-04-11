/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minfos_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohma <tohma@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 15:21:11 by truello           #+#    #+#             */
/*   Updated: 2024/04/05 16:25:02 by tohma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	handle_double_modes(t_redir_files **rf, char *cur_str)
{
	int	fd_start_str;

	if (cur_str[0] != cur_str[1] || cur_str[1] == '\0')
		return (FALSE);
	if (cur_str[2] == '>' || cur_str[2] == '<')
		return (FALSE);
	fd_start_str = ft_nstrchr_i(cur_str + 2, ' ') + 2;
	if (cur_str[0] == '<')
		push_redir_file(rf, ft_strcpy(cur_str + fd_start_str), E_HERE_DOC);
	else if (cur_str[0] == '>')
		push_redir_file(rf, ft_strcpy(cur_str + fd_start_str), E_APPEND);
	return (TRUE);
}

static int	handle_simple_modes(t_redir_files **rf, char *cur_str)
{
	int	fd_start_str;

	if (cur_str[1] == '>' || cur_str[1] == '<')
		return (FALSE);
	fd_start_str = ft_nstrchr_i(cur_str + 1, ' ') + 1;
	if (cur_str[0] == '>')
		push_redir_file(rf, ft_strcpy(cur_str + fd_start_str), E_OUTPUT);
	else if (cur_str[0] == '<')
		push_redir_file(rf, ft_strcpy(cur_str + fd_start_str), E_INPUT);
	return (TRUE);
}

static int	parse_minfos_redirs(t_redir_files **side, char symbol,
	t_token_lst *tlst)
{
	int	i;

	while (tlst)
	{
		i = ft_strchr_i_nquotes(tlst->data, symbol);
		if (i > -1)
			if (!handle_double_modes(side, tlst->data + i))
				if (!handle_simple_modes(side, tlst->data + i))
					return (FALSE);
		tlst = tlst->next;
	}
	return (TRUE);
}

int	parse_minfos(t_minishell *minfos, t_token_lst *tlst)
{
	char	*env_path;

	if (!parse_minfos_redirs(&(minfos->input_files), '<', tlst)
		|| !parse_minfos_redirs(&(minfos->output_files), '>', tlst))
		return (FALSE);
	env_path = getenv("PATH");
	if (!env_path)
		return (FALSE);
	minfos->env = ft_split(env_path, ':');
	if (!minfos->env)
		return (FALSE);
	return (TRUE);
}