/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joapedr2 < joapedr2@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 10:31:03 by joapedr2          #+#    #+#             */
/*   Updated: 2023/05/17 13:39:43 by joapedr2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_minishell	g_data;

int	terminal_loop(void)
{
	while (1)
	{
		init_data_line();
		signals_handler();
		g_data.tml_line = tml_get_pwd();
		g_data.input = readline(g_data.tml_line);
		free(g_data.tml_line);
		if (g_data.input == NULL)
			break ;
		if (*g_data.input)
		{
			add_history(g_data.input);
			if (lexical_analyzer() == TRUE)
			{
				run_all_checks();
				run_command();
			}
		}
		free_line();
	}
	exit_terminal();
	return (TRUE);
}

int	main(int argc, char **argv, char **envp)
{
	errno = 0;
	(void)argv;
	if (argc == 1)
	{
		init_data(envp);
		ft_printf("\n\t\t=================================\n");
		ft_printf("\t\t|\tWelcome to Minishell\t|\n");
		ft_printf("\t\t=================================\n\n");
		terminal_loop();
	}
	else
		terminate(ERR_ARG);
}
