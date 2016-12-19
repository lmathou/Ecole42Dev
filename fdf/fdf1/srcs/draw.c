/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 20:37:51 by jblancha          #+#    #+#             */
/*   Updated: 2016/12/16 18:45:55 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include "fdf.h"


void		ft_init_param_matrice (t_env *env)
{
	env->scale_w = ((((WIN_WIDTH)/(*env->field)->width))/4);
	env->scale_h = (((WIN_HEIGHT)/(*env->field)->height))/4;
	env->xcenter = XCENTER;
	env->ycenter = YCENTER;
	env->dy = (IMG_WIDTH/2) - (((*env->field)->width)/2 *env->scale_w);
	env->dx = (IMG_HEIGHT/2) - (((*env->field)->height)/2 * env->scale_h);
	env->alphax = (-45.0f * M_PI) / 180.0f;
	env->alphay = (-35.0f * M_PI) / 180.0f;
	env->dz = 0;
}

int 		ft_init_mlx(t_env *env)
{
	ft_init_param_matrice (env);
	ft_createwindow (env);
	
	
	return (0);
}

int 		ft_mouse_hook(int button, int x, int y, t_env *env)
{
	if (button == 1)
	{
		env->dx = y;
		env->dy = x;
	}
	if (button == 2)
	{
		env->dx = y;
		env->dy = x;
	}
	ft_putnbreol(env->dx);
	ft_putnbreol(env->dy);
	ft_expose_hook(env);
	return (0);
}

int			ft_key_hook(int keycode, t_env *e)
{
		if (keycode == KEY_ESC)
		{
			mlx_destroy_window(e->mlx, e->window);
			exit (0);
		}
		if (keycode == KEY_PLUS)
		{
			e->scale_w = e->scale_w * 1.2;
			e->scale_h = e->scale_h * 1.2;
		}
		if (keycode == KEY_MINUS)
		{
			e->scale_w = e->scale_w / 1.2;
			e->scale_h = e->scale_h / 1.2;
		}
		if (keycode == KEY_UP)
		{
			e->dx = e->dx - 50;
		}
		if (keycode == KEY_DOWN)
		{
			e->dx = e->dx + 50;
		}
		if (keycode == KEY_RIGHT)
		{
			e->dy = e->dy + 50;
		}
		if (keycode == KEY_LEFT)
		{
			e->dy = e->dy - 50;
		}
		ft_expose_hook(e);
		return (0);
}

int			ft_expose_hook(t_env *env)
{
	ft_createimage (env);
	ft_matrice(env);
	ft_putstr("debut expose_hook");
	ft_draw_field(env->field, env);
	mlx_put_image_to_window (env->mlx, env->window, env->image, 0 , 0);
	mlx_key_hook(env->window, ft_key_hook, env);
	mlx_mouse_hook(env->window, ft_mouse_hook, env);
	mlx_destroy_image(env->mlx, env->image);
	return (0);
}

void		ft_lightpixel(t_point point, t_env *env, int color)
{
	int 		i;
	i = (point.x * env->s_lines) + (point.y * 4);
	printf("ds lightpixel : %d\n", i);
	ft_putnbreol(i);
	env->data_adress[i] = color;
	env->data_adress[++i] = color >> 8;
	env->data_adress[++i] = color >> 16;

}
void		ft_get_line_param(t_line_param *param_line, t_point point_ori, t_point point_des)
{
		param_line->dx = ABS(point_des.x - point_ori.x);
		param_line->dy = ABS(point_des.y - point_ori.y);
		param_line->incx = point_des.x < point_ori.x ? -1 : 1;
		param_line->incy = point_des.y < point_ori.y ? -1 : 1;
}

void		ft_plotline (t_env *env,t_point point_ori, t_point point_des)
{
	t_line_param	param_line;
	int				i;
	t_point 		point;

	ft_get_line_param(&param_line, point_ori, point_des);
	point.x = point_ori.x;
	point.y = point_ori.y;
	if (param_line.dx > param_line.dy)
	{
		ft_putendl("ds else avt light pixel");
		ft_lightpixel(point, env, ft_get_color(point_ori, point_des));
		ft_putendl("ds else apreslight pixel");
		printf("ds if x : %d, y : %d\n", point.x ,point.y);
		param_line.e = (2 * param_line.dy) - param_line.dx;
		param_line.inc1 = 2 * (param_line.dy - param_line.dx);
		param_line.inc2 = 2 * param_line.dy;
		i = 0;
		while (i < param_line.dx)
		{
			if (param_line.e > 0)
			{
				point.y = point.y + param_line.incy;
				param_line.e = param_line.e + param_line.inc1;
			}
			else
				param_line.e = param_line.e + param_line.inc2;
			point.x = point.x + param_line.incx;
			ft_lightpixel(point, env, ft_get_color(point_ori, point_des));
			printf("x : %d, y : %d\n", point.x ,point.y);
			i++;
		} 
	}
	else
	{
		ft_putendl("ds else avt light pixel");
		ft_lightpixel(point, env, ft_get_color(point_ori, point_des));
		ft_putendl("ds else apreslight pixel");
		printf(" ds else x : %d, y : %d\n", point.x , point.y);
		param_line.e = (2 * param_line.dx) - param_line.dy;
		param_line.inc1 = 2 * (param_line.dx - param_line.dy);
		param_line.inc2 = 2 * param_line.dx;
		i = 0;
		while (i < param_line.dy)
		{
			if (param_line.e > 0)
			{
				point.x = point.x + param_line.incx;
				param_line.e = param_line.e + param_line.inc1;
			}
			else
				param_line.e = param_line.e + param_line.inc2;
			point.y = point.y + param_line.incy;
			ft_lightpixel(point, env, ft_get_color(point_ori, point_des));
			printf("x : %d, y : %d\n", point.x , point.y);
			i++;
		} 
	}
}

int 		ft_get_color (t_point point_ori, t_point point_des)
{
		int 	color;

		color = 0xFF6666;

		if (point_ori.relief > 0)
			color = 0x33FF66;
		if (point_ori.relief == point_des.relief && point_ori.relief > 0)
			color = 0x33FF66;
		return (color);
}
void		ft_draw_field (t_field **field, t_env *env)
{
	int       	i;
	int       	j;
	t_point		point_ori;
	t_point		point_des;

	ft_putendl("debut draw field");
	i = 0;
	while ( i < (*field)->height)
	{
		j = 0;
		while (j < (*field)->line[i].len)
		{	
			if (j < ((*field)->line[i].len) - 1)
			{
				//ft_putstr("ds if i "), ft_putnbr(i),ft_putstr("  j"), ft_putnbreol(j);
				point_ori.x = ((*field)->line[i].point[j].x + 1);
				point_ori.y = ((*field)->line[i].point[j].y + 1);
				point_ori.relief = (*field)->line[i].point[j].relief;
				point_des.x = ((*field)->line[i].point[j + 1].x + 1) ;
				point_des.y = ((*field)->line[i].point[j + 1].y + 1) ;
				point_des.relief = (*field)->line[i].point[j + 1].relief;
				printf("ligne horizontale point 1 : %d %d , point2 : %d %d\n", 
						point_ori.x, point_ori.y,point_des.x, point_des.y);
				//ft_putstr("ds if x "), ft_putnbr(point_ori.x),ft_putstr("  y"), ft_putnbreol(point_ori.y);
				ft_plotline (env, point_ori, point_des);
			}
			if (i < ((*field)->height - 1))
			{
				
				point_ori.x = ((*field)->line[i].point[j].x + 1);
				point_ori.y = ((*field)->line[i].point[j].y + 1);
				point_ori.relief = (*field)->line[i].point[j].relief;
				point_des.x = ((*field)->line[i + 1].point[j].x + 1) ;
				point_des.y = ((*field)->line[i + 1].point[j].y + 1) ;
				point_des.relief = (*field)->line[i + 1].point[j].relief;
				printf("ligne verticale point 1 : %d %d , point2 : %d %d\n", 
						point_ori.x, point_ori.y,point_des.x, point_des.y);
				ft_plotline (env, point_ori, point_des);
			}
			j++;
		}
		ft_putstr("\n");
		i++;
	}
}

void		ft_createwindow (t_env *env)
{

	env->mlx = mlx_init();
	env->window = mlx_new_window ( env->mlx, WIN_WIDTH, WIN_HEIGHT, WIN_TITLE);	
}

void		ft_createimage (t_env *env)
{
	env->image = mlx_new_image (env->mlx, IMG_WIDTH, IMG_HEIGHT);
	env->data_adress = mlx_get_data_addr (env->image, &(env->bpp), &(env->s_lines), &(env->endian));
}

void		ft_destroyimage (t_env *env)
{
	mlx_destroy_image (env-> mlx, env->image);
}
