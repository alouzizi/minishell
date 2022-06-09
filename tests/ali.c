/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ali.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alouzizi <alouzizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 02:37:14 by alouzizi          #+#    #+#             */
/*   Updated: 2022/06/07 16:50:26 by alouzizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int main()
{
	char *r;

	while(42)
	{
		r = readline("minishell $ ");
		add_history(r); // i don't understand welle
		printf("%s\n",r);
		
	}
}