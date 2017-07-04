/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhooks.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elyahove <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 18:02:28 by elyahove          #+#    #+#             */
/*   Updated: 2017/05/15 18:28:44 by elyahove         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KEYHOOKS_H
# define __KEYHOOKS_H

# include "rt.h"
# include "keys.h"

int		window_destroyed_hook(void *params);
int		key_press_hook(int key, void *params);
int		key_release_hook(int key, void *params);
int		button_press_hook(int button, int x, int y, void *params);
int		button_release_hook(int button, int x, int y, void *params);

#endif
