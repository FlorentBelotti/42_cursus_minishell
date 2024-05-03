/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 11:29:46 by truello           #+#    #+#             */
/*   Updated: 2024/05/03 02:28:39 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static void	parse_line(char *line, t_env *env)
{
	t_token		*tlist;
	t_command	*cmds;

	if (line[0] == '\0')
		return ;
	cmds = NULL;
	tlist = tokenize(line, env);
	parse_commands(tlist, &cmds);
	print_commands(cmds);
	choose_exec_path(cmds, env);
	if (!check_commands(cmds))
		return (free_command(cmds), free_token(tlist), (void) 0);
	free_command(cmds);
	free_token(tlist);
}

int	main(int ac, char **av, char **envp)
{
	char	*line;
	t_env	*env;

	ac = ac + 1 - 1;
	*av = *av;
	env = make_env(envp);
	setup_signal_handler();
	line = readline("minishell > ");
	if (line && line[0] != '\0')
		add_history(line);
	while (line && !ft_strcmp(line, "exit"))
	{
		parse_line(line, env);
		free(line);
		line = readline("minishell > ");
		if (line && line[0] != '\0')
			add_history(line);
	}
	return (ft_free(line), free_env(env), 0);
}
