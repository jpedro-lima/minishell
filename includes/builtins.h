/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 10:21:38 by joapedr2          #+#    #+#             */
/*   Updated: 2023/05/05 21:56:14 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "minishell.h"

//ft_cd.c
void	ft_cd(char **input);

//ft_echo.c
void	ft_echo(char **input);

//ft_env.c
void	ft_env(char **input);
void	ft_env_from_export(char **input);

//ft_exit.c
void	ft_exit(char **input);

//ft_export_check.c
char	**ft_var_export(char *cmd);

//ft_export.c
void	ft_export(char **input);

//ft_pwd.c
void	ft_pwd(void);

//ft_unset.c
void	ft_unset(char **input);

#endif //BUILTINS_H