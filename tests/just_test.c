/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   just_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alouzizi <alouzizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 11:25:23 by alouzizi          #+#    #+#             */
/*   Updated: 2022/06/08 12:58:44 by alouzizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
extern char **environ;
int main()
{
	// char *v;

	// v = getenv("PATH");
	// printf("PATH = %s\n",v);
	// v = getenv("USER");
	// printf("USER = %s\n",v);
	int i =0;
	while(environ[i])
		printf("%s\n",environ[i++]);
}

