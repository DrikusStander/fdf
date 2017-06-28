#include "fdf.h"

int        main(void)
{
	//struct s_wininfo    wininfo;
	t_mlx 				wininfo;
	t_points            orig;
	int x;
	int y;
	int color, color1, color2, color3;

	color = 0x00ffffff;
	color1 = 0x00ff0000;
	color2 = 0x0000ff00;
	color3 = 0x000000ff;

	wininfo.mlx = mlx_init();
	wininfo.win = mlx_new_window(wininfo.mlx, 600, 600, "test");
	mlx_key_hook(wininfo.win, key_hook, 0);
/*	
	orig.x1 = 0;
	orig.y1 = 0;
	orig.x2 = 600;
	orig.y2 = 0;
	put_line(&orig, &wininfo, color);*/
	
	
	orig.x1 = 300;
	orig.y1 = 300;
	x = -300;
	y = -300;
	
	while (x <= 300)
	{
		orig.x2 = x + 300;
		orig.y2 = y + 300;
		put_line(&orig, &wininfo, color);
		++(x);
	}
	--(x);
	while (y <= 300)
	{
		orig.x2 = x + 300;
		orig.y2 = y + 300;
		put_line(&orig, &wininfo, color1);
		++(y);
	}
	--(y);
	while (x >= -300)
	{
		orig.x2 = x + 300;
		orig.y2 = y + 300;
		put_line(&orig, &wininfo, color2);
		--(x);
	}
	++(x);
	while (y >= -300)
	{
		orig.x2 = x + 300;
		orig.y2 = y + 300;
		put_line(&orig, &wininfo, color3);
		--(y);
	}

	mlx_pixel_put(wininfo.mlx, wininfo.win, 300, 300, 0x000000ff);

	orig.x1 = 0;
	orig.y1 = 0;
	orig.x2 = 300;
	orig.y2 = 300;
	put_line(&orig, &wininfo, 0x00ff0000);

	mlx_loop(wininfo.mlx);
}
