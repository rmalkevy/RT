/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elyahove <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 15:12:57 by elyahove          #+#    #+#             */
/*   Updated: 2017/06/05 15:13:27 by elyahove         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __RT_H
# define __RT_H

# include "libft.h"
# include "vector_lib.h"
# include "translation.h"
# include "keyhooks.h"
# include "refraction_list.h"
# include "minilibx/mlx.h"
# include <math.h>
# include <errno.h>
# include <pthread.h>
# define BS 1000
# define END 1000000000
# define EPSILON 0.001
# define TWOPI 6.28318530717958648
# define TRUE	1
# define FALSE	0

typedef struct		s_color
{
	unsigned char	red;
	unsigned char	green;
	unsigned char	blue;
	unsigned char	op;
}					t_color;

typedef struct		s_pos
{
	t_vector		origin;
	t_vector		move;
	t_vector		rotation;
}					t_pos;

typedef struct		s_normal_map
{
	void			*ptr;
	unsigned char	*data;
	t_vector		**normal;
	int				bbp;
	int				end;
	int				sizeline;
	int				width;
	int				height;
}					t_normal_map;

typedef struct		s_texture
{
	void			*ptr;
	unsigned char	*data;
	t_color			**color;
	int				bbp;
	int				end;
	int				sizeline;
	int				width;
	int				height;
}					t_texture;

typedef struct		s_coefficients
{
	double			amb;
	double			refl;
	double			refl_light;
	double			trans;
	double			refr_coeff;
}					t_coefficients;

typedef struct		s_compute
{
	double			a;
	double			b;
	double			c;
	double			d;
	double			e;
	double			f;
	double			g;
	t_vector		v1;
	t_vector		v2;
	t_vector		v3;
	t_vector		v4;
	t_vector		v5;
	double			cos;
	double			sin;
}					t_compute;

typedef struct		s_quadric
{
	t_vector		a;
	t_vector		v1;
	t_vector		v2;
	t_vector		v3;
	t_vector		v4;
	t_vector		v5;
	t_vector		v6;
	t_vector		v7;
	t_vector		v8;
	t_vector		q1;
	t_vector		q2;
	t_vector		q3;
	double			k;
	t_vector		minus;
	double			dot1;
	double			dot2;
	double			dot3;
	double			dot4;
	double			dot5;
	double			dot6;
	double			dot7;
	double			dot8;
}					t_quadric;

/*
**	Objects
*/

typedef struct		s_common
{
	t_pos			pos;
	t_color			col;
	t_coefficients	coefficients;
	char			has_texture;
	t_texture		texture;
	char			has_normal_map;
	t_normal_map	normal_map;
	char			*has_obj;
	double			zoom;
	int				num_poligon;
}					t_common;

typedef struct		s_sphere
{
	t_common		details;
	double			radius;
	t_vector		dir_x;
	t_vector		dir_y;
	double			angle_x;
	double			angle_y;
}					t_sphere;

typedef struct		s_plain
{
	t_common		details;
	t_vector		normal;
	double			delta_x;
	double			delta_y;
	t_vector		dir_x;
	t_vector		dir_y;
}					t_plain;

typedef struct		s_cylinder
{
	t_common		details;
	t_vector		direction;
	double			radius;
	t_vector		dir_x;
	double			angle_x;
}					t_cylinder;

typedef struct		s_cone
{
	t_common		details;
	t_vector		direction;
	double			angle;
	t_vector		dir_x;
}					t_cone;

typedef struct		s_co_map
{
	t_cone			*cone;
	t_vector		ppoint;
	double			cos_ppoint_condir;
	double			theta;
	t_vector		dir_i;
	double			dot__dir_x_i;
	double			radius;
	double			len_v;
	t_vector		cross__dir_con_x;
	double			dot__cross;
}					t_co_map;

typedef struct		s_cyl_map
{
	t_cylinder		*cylinder;
	t_vector		ppoint;
	double			cos_ppoint_cyldir;
	double			theta;
	t_vector		dir_i;
	double			dot__dir_x_i;
	double			len_v;
	t_vector		cross__dir_cyl_x;
	double			dot__cross;
}					t_cyl_map;

typedef struct		s_pl_map
{
	t_plain			*plain;
	t_vector		dir_i;
	double			cos_u;
	double			cos_v;
	double			u;
	double			v;
}					t_pl_map;

typedef struct		s_sp_map
{
	t_sphere		*sphere;
	double			phi;
	double			theta;
	t_vector		dir_i;
	double			dot_dir_y_dir_i;
	double			dot_dir_x_dir_i;
	t_vector		cross__dir_y__dir_x;
	double			dot__cross__dir_i;
}					t_sp_map;

typedef struct		s_ellipsoid
{
	t_common		details;
	t_vector		size;
	t_vector		rot_ellipse;
	t_quadric		q;
}					t_ellipsoid;

typedef struct		s_hyperbol
{
	t_common		details;
	t_vector		size;
	t_vector		rot_hyperbol;
	t_quadric		q;
}					t_hyperbol;

typedef struct		s_torus
{
	t_common		details;
	double			inner_radius;
	double			outer_radius;
	double			in_radius2;
	double			out_radius2;
	t_vector		direction;
	t_vector		rot_torus;
	t_compute		q;
}					t_torus;

typedef struct		s_parabol
{
	t_common		details;
	t_vector		size;
	t_vector		rot_parabol;
	t_quadric		q;
}					t_parabol;

typedef struct		s_triangle
{
	t_common		details;
	t_vector		a;
	t_vector		b;
	t_vector		c;
	t_vector		normal;
	t_vector		edge1;
	t_vector		edge2;
	t_vector		p;
	double			det;
	double			inv_det;
	t_vector		rot_triangle;
}					t_triangle;

typedef struct		s_disc
{
	t_common		details;
	t_vector		normal;
	double			radius;
	t_color			color;
}					t_disc;

typedef struct		s_limited_cylinder
{
	t_common		details;
	t_vector		dir;
	double			height;
	double			radius;
	t_vector		dir_x;
	t_color			color;
}					t_limited_cylinder;

typedef struct		s_object
{
	void			*data;
	int				(*intersects)(void *data, t_vector *origin,
			t_vector *dir, double *t);
	t_vector		(*get_normal)(void *data, t_vector inters);
	t_color			(*get_point_color)(void *data);
	t_coefficients	(*get_coefficients)(void *data);
	void			(*set_params)(void *ray);
	void			(*move_object)(void *data);
	void			(*rotate_object)(void *data);
	char			*name;
	int				id;
	struct s_object	*next;
}					t_object;

/*
**	Lights
*/

/*
**	Environment and parameters
*/

typedef struct		s_l_params
{
	t_color			color;
	double			intensity;
	double			decrement;
}					t_l_params;

typedef struct		s_ray_colors
{
	t_color			ambient_color;
	t_color			reflection_color;
	t_color			refraction_color;
}					t_ray_colors;

typedef struct		s_refrect
{
	double			refr_prev;
	double			refr_curr;
}					t_refrect;

typedef struct		s_shadow_ray
{
	double			length;
	t_vector		origin;
	t_vector		direction;
	t_vector		initial_direction;
	t_vector		refl_dir;
	t_vector		refr_dir;
	t_vector		normal;
	t_l_params		options;
	void			*cur;
	t_object		*intersection_object;
	int				lgt_num;
	double			amb;
	double			refl;
	double			refr;
	double			cos_coeff;
	double			cos_phi;
	double			cos_teta;
	double			refr_cos;
	double			refr_coeff;
	double			refl_cos;
	t_refrect		refrect;
	t_refr_lst		*refracted;
	int				exit;
	int				shading;
}					t_shadow_ray;

typedef struct		s_ray_segment
{
	t_vector		origin;
	t_vector		direction;
	t_vector		refl_dir;
	t_vector		refr_dir;
	t_ray_colors	colors;
	t_vector		normal;
	t_vector		normal_map;
	char			bump_mapping;
	t_coefficients	coefficients;
	double			length;
	t_refrect		refrect;
	t_vector		intersection_point;
	t_object		*intersection_object;
	int				ray_inside_object;
}					t_ray_segment;

typedef struct		s_ray
{
	double			len;
	t_color			final;
	t_refr_lst		*refracted;
	int				refr_depth;
	int				refl_depth;
	double			*l_intens;
}					t_ray;

typedef struct		s_light_point
{
	t_pos			position;
	t_l_params		params;
}					t_light_point;

typedef struct		s_direct_light
{
	t_pos			position;
	t_vector		direction;
	double			angle;
	t_l_params		params;
}					t_direct_light;

typedef struct		s_parallel_light
{
	t_vector		direction;
	t_vector		rotation;
	t_l_params		params;
}					t_parallel_light;

typedef struct		s_light
{
	void			*source;
	int				(*set_lighting_params)(void *source, t_shadow_ray *ray,
			t_ray *ray_details, int i);
	double			(*get_light_intensity)(void *source);
	void			(*calculate_light)();
	void			(*move_light)();
	void			(*rotate_light)();
	char			*name;
	struct s_light	*next;
}					t_light;

typedef struct		s_image
{
	void			*ptr;
	char			*data;
	int				sizeline;
	int				bpp;
	int				endian;
}					t_image;

typedef struct		s_camera
{
	t_pos			position;
	t_vector		x_dir;
	t_vector		y_dir;
	t_vector		direction;
	double			distance;
}					t_camera;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	t_image			image;
	t_color			background_color;
	int				refraction_depth;
	int				reflection_depth;
	double			contrast;
	char			glares_present;
	char			shades_present;
	char			sepia;
	char			black_and_white;
	char			negative;
	int				anti_aliasing;
	int				object_counter;
	t_color			back;
}					t_env;

typedef struct		s_read
{
	int				r;
	char			buf[BS + 1];
	char			*tmp;
	int				fd;
	char			*str;
	char			**split;
}					t_read;

typedef struct		s_keyhook_info
{
	t_object		*intersected;
	int				prev_x;
	int				prev_y;
	double			dist;
	char			lmb_pressed;
}					t_keyhook_info;

typedef struct		s_params
{
	t_env			env;
	t_camera		camera;
	t_object		*objects;
	t_light			*lights;
	int				lights_qnt;
	int				objects_qnt;
	int				width;
	int				height;
	char			*name;
	int				threads_quantity;
	t_keyhook_info	kh_info;
}					t_params;

void				object_add(t_object **alst, t_object **new);
void				lights_add(t_light **alst, t_light **new);

void				read_file(char *file, t_params *par);
void				parse_object_core(char *name, t_params *par, char *dots);
void				set_camera(t_camera *camera);
void				fill_cam(t_camera *camera, char *dots);
void				fill_obj(char *name, t_params *par, char *dots);
void				fill_object_list(t_params *p, char *dots,
					t_object *obj, char *name);
void				fill_light_list(t_params *p, char *dots,
					t_light *light, char *name);
void				fill_contrast(t_params *par, char *dots);

/*
**	Creating new objects
*/

t_object			*new_sphere(t_sphere *sphere, int id);
t_object			*new_plain(t_plain *plain, int id);
t_object			*new_cylinder(t_cylinder *cylinder, int id);
t_object			*new_cone(t_cone *cone, int id);
t_object			*new_ellipsoid(t_ellipsoid *ellipse, int id);
t_object			*new_hyperbol(t_hyperbol *hyperbol, int id);
t_object			*new_triangle(t_triangle *triangle, int id);
t_object			*new_torus(t_torus *torus, int id);
t_object			*new_limited_cylinder(t_limited_cylinder *data, int id);
t_object			*new_disc(t_disc *data, int id);

void				fill_cone_data(t_cone *con, char **split, t_params *par);
void				fill_sphere_data(t_sphere *s, char **split, t_params *par);
void				fill_cylinder_data(t_cylinder *c, char **split,
					t_params *par);
void				fill_plain_data(t_plain *p, char **split, t_params *par);
void				fill_ellipsoid_data(t_ellipsoid *ell, char **split,
					t_params *par);
void				fill_hyperboloid_data(t_hyperbol *hyp, char **split,
					t_params *par);
void				fill_torus_data(t_torus *torus, char **split,
					t_params *par);
void				fill_disc_data(t_disc *disc, char **split,
					t_params *par, int f);
void				fill_lim_cyl_data(t_limited_cylinder *cyl, char **split,
					t_params *par, int f);

void				fill_cone_data_core(t_cone *con, char *split, char *space,
																t_params *par);
void				fill_sphere_data_core(t_sphere *s, char *split, char *space,
																t_params *par);
void				fill_cylinder_data_core(t_cylinder *c, char *split,
									char *space, t_params *par);
void				fill_plain_data_core(t_plain *p, char *split,
									char *space, t_params *par);
void				fill_torus_data_core(t_torus *torus, char *split,
					char *space, t_params *par);
void				fill_ellipse_data_core(t_ellipsoid *ell, char *split,
													char *space, t_params *par);
void				fill_hyperboloid_data_core(t_hyperbol *hyp, char *split,
													char *space, t_params *par);
void				fill_disc_data_core(t_disc *disc, char *split, char *space,
										t_params *par);
void				fill_lim_cyl_data_core(t_limited_cylinder *cyl, char *split,
										char *space, t_params *par);
t_sphere			*parse_sphere(char *str, t_params *par);
t_cylinder			*parse_cylinder(char *str, t_params *par);
t_cone				*parse_cone(char *str, t_params *par);
t_plain				*parse_plain(char *str, t_params *par);
t_torus				*parse_torus(char *str, t_params *par);
t_ellipsoid			*parse_ellipsoid(char *str, t_params *par);
t_hyperbol			*parse_hyperboloid(char *str, t_params *par);
t_disc				*parse_disc(char *str, t_params *par);
void				parse_limited_cylinder(char *str, t_params *par);

void				fill_common(t_common *com, char *name,
					char *space, t_params *p);
void				coeff_normalisation(t_common *com);
void				parse_pos(t_pos *pos, char *name, char *space);
void				parse_color(t_color *col, char *str);
void				parse_vector(t_vector *origin, char *str);
void				set_initialise(t_common *com);
void				set_position(t_pos *pos);

t_light				*new_light_point(t_light_point *light_point);
t_light				*new_light_dir(t_direct_light *light_dir);
t_light				*new_parallel_light(t_parallel_light *parallel_light);

t_light_point		*parse_light_point(char	*str);
t_parallel_light	*parse_parallel_light(char	*str);
t_direct_light		*parse_light_dir(char	*str);

void				fill_light_point(t_light_point	*light, char *dots);
void				fill_par_light(t_parallel_light	*par_light, char *dots);
void				fill_dir_light(t_direct_light	*dir_light, char *dots);
void				fill_light(t_direct_light	*dir_light, char *dots,
					char *l_name);

/*
**	Preparation functions
*/

void				set_initialise_par(t_params *par);
void				create_image(t_params *par);
void				prepare_and_init_render(t_params *par);
void				set_hooks(t_params *par);

/*
**	Rays
*/

t_ray_segment		new_ray_segment(t_vector origin, t_vector dir);
t_ray				*new_ray(void);
t_vector			get_direction(t_vector origin, t_vector dest);
t_vector			get_destination_point(t_params *par, int x, int y);
t_vector			launch_reflected_ray(t_params *par, t_ray_segment ray,
							t_ray ray_details, t_color *color);
t_vector			launch_refracted_ray(t_params *par, t_ray_segment ray,
											t_ray ray_details, t_color *color);
void				free_ray(t_ray *ray);

/*
**	Rendering
*/

void				render(t_params *par);
void				init_threads(t_params *par);
void				*casting_cycle(void *param);
t_color				cast_single_ray(t_params *par, t_ray_segment ray,
															t_ray ray_details);
void				put_pixel(t_image *image, t_color *pixel_color,
																int x, int y);

/*
**	Moving and rotation
*/

void				init_camera_modifications(t_camera *cam);
void				apply_camera_modifications(t_camera *cam);
void				move_and_rotate_objects(t_params *par);
void				move_and_rotate_lights(t_params *par);
void				apply_move_and_rotation(t_params *p);

/*
**	Object information
*/

t_object			*find_closest_intersection(t_params *par, t_vector *origin,
					t_vector *direction, double *distance);
int					object_refracts(t_object *obj);
int					object_reflects(t_object *obj);

/*
**	Shapes
*/

double				discriminant(double a, double b, double c);

/*
**	Sphere
*/

t_color				get_sphere_color(void *data);
t_vector			get_sphere_normal(void *data, t_vector point);
int					intersects_sphere(void *data, t_vector *orig,
						t_vector *dir, double *t);

t_coefficients		get_sphere_coefficients(void *data);
t_coefficients		get_plain_coefficients(void *data);
t_coefficients		get_cone_coefficients(void *data);
t_coefficients		get_cylinder_coefficients(void *data);

/*
**	Plain
*/

t_color				get_plain_color(void *data);
t_vector			get_plain_normal(void *data, t_vector point);
int					intersects_plain(void *data, t_vector *orig,
						t_vector *dir, double *t);

/*
**	Cylinder
*/

t_color				get_cylinder_color(void *data);
t_vector			get_cylinder_normal(void *data, t_vector ipoint);
void				cylinder_get_abc(double *a, double *b, double *c,
						t_compute *tmp);
int					intersects_cylinder(void *data, t_vector *orig,
						t_vector *dir, double *t);

/*
**	Cone
*/

t_color				get_cone_color(void *data);
t_vector			get_cone_normal(void *data, t_vector ipoint);
int					intersects_cone(void *data, t_vector *orig,
						t_vector *dir, double *t);

/*
**	Triangle
*/

double				find_t(t_triangle *triangle, t_vector *dir, t_vector *ori);

/*
**	Disc
*/

t_color				get_disc_color(void *data);
t_vector			get_disc_normal(void *data, t_vector i_point);
t_coefficients		get_disc_coefficients(void *data);
void				move_disc(void *data);
void				rotate_disc(void *data);

/*
**	Shading
*/

void				check_light_side(t_vector *normal, t_vector *ray_dir);
void				shadow_ray_set_params(t_shadow_ray *ray,
					t_ray_segment ray_segment, t_refr_lst *refracted);
void				shade_pixel(t_params *par, t_ray_segment *ray_segment,
					t_ray *ray_details, t_refr_lst *refracted);
void				set_calculate_light(t_params *par, t_ray *ray_details,
										t_shadow_ray *shadow_ray);
void				shadow_ray_set_params(t_shadow_ray *ray,
					t_ray_segment ray_segment, t_refr_lst *refracted);
void				final_shadow_ray_set_params(t_shadow_ray *ray);

/*
**	Lights
*/

int					set_light_point_params(void *source, t_shadow_ray *ray,
					t_ray *ray_details, int i);
int					set_light_direct_params(void *source, t_shadow_ray *ray,
					t_ray *ray_details, int i);
int					set_light_parallel_params(void *source, t_shadow_ray *ray,
					t_ray *ray_details, int i);

void				par_light_processing(t_parallel_light	*light, char *name,
					char *space);
void				point_light_processing(t_light_point *light, char *name,
					char *space);
void				dir_light_processing(t_direct_light	*light, char *name,
					char *space);

void				define_cos_phi(double *cos_phi, t_vector *normal,
					t_vector *dir, int shading);
void				define_cos_teta(double *cos_teta, t_vector *ray_dir,
					t_vector *shadow_dir, int shading);
t_shadow_ray		create_reflected_shadow_ray(t_shadow_ray *shadow_ray,
					t_object *object, double t, t_ray *ray_details);
t_shadow_ray		create_refracted_shadow_ray(t_shadow_ray *shadow_ray,
					t_object *object, double t, t_ray *ray_details);
void				clear_refracted(t_refr_lst	*begin);
void				define_prev_curr_refraction(t_refrect *refract,
					double refr_coeff, t_ray *ray_details, int id);
int					define_refr_direction(t_vector *new_direction,
					t_vector *in_direction, t_vector *n, t_refrect *refrect);
double				define_cos_coefficient(t_params *par, t_shadow_ray *s_ray,
					t_ray ray_details, t_shadow_ray *final_ray);
void				define_shade_and_glare(t_params *par, t_shadow_ray *s_ray,
								t_ray_segment *ray_segment);
double				get_light_direct_intense(void *source);
double				get_light_point_intense(void *source);
double				get_light_parallel_intense(void *source);
void				define_ray_intensity(double	len, double *intensity,
					double decrement, double intens_0);

void				set_light_intensity(t_params *par, t_ray *ray);

/*
**	Color management
*/

t_color				cast_single_ray(t_params *par, t_ray_segment ray,
		t_ray ray_details);
t_color				new_color(char red, char green, char blue, char op);
t_color				antialiasing_color(t_color color, int antialiasing);
t_color				add_color(t_color first, t_color second);
t_color				combine_colors(t_ray_segment ray);
void				apply_black_and_white(t_color *color);
void				apply_sepia(t_color *color);
void				apply_negative(t_color *color);
void				apply_contrast(t_color *color, int contrast);

/*
**	Vector (non-pointer)
*/

t_vector			new_vector_stack(double x, double y, double z);
t_vector			vector_sub_stack(t_vector v1, t_vector v2);
t_vector			unit_vector_stack(t_vector vec);

/*
**	Key-hooks
*/

void				rotate_camera(t_params *par, double x, double y, double z);
void				move_camera_hook(t_params *par, double x, double y,
					double z);

/*
**	Error management
*/

void				error(int errnum);
void				error_add(int errnum);
void				error_validate(int errnum);
void				validate_str(char *str);
int					validate_split(char	*str, char **split, int i);
void				validate_env(t_env *env);

/*
** Quadric, quartic, cubic calculations
*/

void				set_q_figure(t_vector size, t_vector pos, t_quadric *q);
void				quadric_calculations(t_vector origin, t_vector dir,
					t_quadric *q);
void				quadric_get_abc(double *a, double *b, double *c,
					t_quadric *q);
int					solve_quartic_4(double *x, double *q);
int					solve_p4de(double *x, double b, double c, double d);
int					solve_p4bi(double *x, double b, double d);
void				c_sqrt(double x, double y, double *a, double *b);
int					solve_p3(double *x, double a, double b, double c);

/*
**	Ellipsoid
*/

t_color				get_ellipse_color(void *data);
t_vector			get_ellipse_normal(void *data, t_vector ipoint);
int					intersects_ellipse(void *data, t_vector *orig,
						t_vector *dir, double *t);
t_coefficients		get_ellipse_coefficients(void *data);
void				rotate_ellipse(void *data);
void				move_ellipse(void *data);

/*
**	Torus
*/

t_color				get_torus_color(void *data);
t_vector			get_torus_normal(void *data, t_vector ipoint);
int					intersects_torus(void *data, t_vector *orig,
						t_vector *dir, double *t);
double				find_t_torus(t_torus *tor, t_vector *dir, t_vector *orig,
						double *t);
t_coefficients		get_torus_coefficients(void *data);
void				rotate_torus(void *data);
void				move_torus(void *data);
double				find_t_torus(t_torus *tor, t_vector *dir, t_vector *orig,
						double *t);

/*
**	Hyperboloid
*/

t_color				get_hyperbol_color(void *data);
t_vector			get_hyperbol_normal(void *data, t_vector ipoint);
int					intersects_hyperbol(void *data, t_vector *orig,
						t_vector *dir, double *t);
t_coefficients		get_hyperbol_coefficients(void *data);
void				rotate_hyperbol(void *data);
void				move_hyperbol(void *data);

/*
**	Paraboloid
*/

t_color				get_parabol_color(void *data);
t_vector			get_parabol_normal(void *data, t_vector ipoint);
int					intersects_parabol(void *data, t_vector *orig,
						t_vector *dir, double *t);
t_parabol			*set_parabol(t_vector origin);
t_coefficients		get_parabol_coefficients(void *data);

/*
**	Texture and bump mapping
*/

void				set_affine_vectors(t_plain *plain);
int					read_normal_map(char *filename, void *mlx,
						t_normal_map *normal);
int					read_texture(char *filename, void *mlx,
						t_texture *texture);
void				set_sphere_params(void *ray);
void				set_cylinder_params(void *ray);
void				set_cone_params(void *p);
void				set_plain_params(void *p);
void				set_ellipse_params(void *p);
void				set_torus_params(void *p);
void				set_hyper_params(void *p);
void				set_limited_cylinder_params(void *p);
void				set_disc_params(void *p);
void				set_triangle_params(void *p);
void				bump_mapping(t_shadow_ray *shad_ray,
						t_ray_segment *seg_ray);

/*
**	Triangle and parsing objectcs
*/

void				fill_common_for_obj(t_common *com, char *name,
						char *space);
void				add_triangle_to_list(t_params *par, double **vertices,
										int *faces, t_common com);
t_triangle			*parse_triangle(char *str);
void				fill_triangle_data(t_triangle *triangle,
									char **split);
t_color				get_triangle_color(void *data);
t_vector			get_triangle_normal(void *data, t_vector ipoint);
int					intersects_triangle(void *data, t_vector *orig,
							t_vector *dir, double *t);
t_coefficients		get_triangle_coefficients(void *data);
t_object			*new_triangle(t_triangle *triangle, int id);
void				rotate_triangle(void *data);
void				move_triangle(void *data);
char				*read_obj(char *file);
void				work_with_obj(t_params *p, char *dots);
void				parse_obj(char **split, t_params *par, t_common com);

#endif
