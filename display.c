#include <uvsqgraphics.h>

#include "struct.h"
#include "message.h"
#include "move.h"

void init_display(SLIDER S)
{
	if (S.L >= 5) {
		init_graphics(50 * S.L, 50 * S.H + 100);
	} else {
		init_graphics(50 * (S.L + (5 - S.L)), 50 * S.H + 100);
	}
}

void board(SLIDER S)
{
	POINT p1, p2;
	p1.x = 0;
	p2.x = 50 * S.L; p2.y = 0;
	for (p1.y = 50; p1.y < 50 * S.H; p1.y += 50) {
		p2.y += 50;
		draw_line(p1, p2, white);
	}
	p1.y = 0;
	p2.x = 0; p2.y = 50 * S.H;
	for (p1.x = 50; p1.x < 50 * S.L; p1.x += 50) {
		p2.x += 50;
		draw_line(p1, p2, white);
	}
}

void display_wall(SLIDER S)
{
	POINT p1, p2;
	for (int j = 0; j < S.K; j++) {
		if (S.wall[j].C == 9 || S.wall[j].C == 3) {
			p1.x = 50 * S.wall[j].A; p1.y = 50 * S.wall[j].B;
			p2.x = 50 * S.wall[j].A + 2; p2.y = 50 * S.wall[j].B + 50;
			if (S.wall[j].C == 3) {
				p1.x += 50; p2.x += 50;
			}
			draw_fill_rectangle(p1, p2, red);
		}
		if (S.wall[j].C == 12 || S.wall[j].C == 6) {
			p1.x = 50 * S.wall[j].A; p1.y = 50 * S.wall[j].B;
			p2.x = 50 * S.wall[j].A + 50; p2.y = 50 * S.wall[j].B + 2;
			if (S.wall[j].C == 12) {
				p1.y += 50; p2.y += 50;
			}
			draw_fill_rectangle(p1, p2, red);
		}
	}
}

void display_player(SLIDER S)
{
	POINT jo;
	jo.x = 25 + S.I * 50; jo.y = 25 + S.J * 50;
	draw_fill_circle(jo, 20, blue);
}

void clean_player(SLIDER S)
{
	POINT so;
	so.x = 25 + S.I * 50; so.y = 25 + S.J * 50;
	draw_fill_circle(so, 20, black);
}

void display_sortie(SLIDER S)
{
	POINT so;
	so.x = 25 + S.Z * 50; so.y = 25 + S.X * 50;
	draw_fill_circle(so, 20, green);
}

void message_space(SLIDER S)
{
	POINT p1, p2, p3, p4;
	if (S.L >= 5) {
		p1.x = 0; p1.y = 50 * S.H + 99;
		p2.x = 50 * S.L - 1; p2.y = 50 * S.H;
	} else {
		p1.x = 0; p1.y = 50 * S.H + 99;
		p2.x = 50 * (S.L + (5 - S.L)) - 1; p2.y = 50 * S.H;

		p3.x = 50 * S.L; p3.y = 0;
		p4.x = 50 * (S.L + (5 - S.L)) - 1; p4.y = 50 * S.H;
		draw_fill_rectangle(p3, p4, white);
		draw_rectangle(p3, p4, red);
		draw_line(p3, p4, red);

		p3.x = 50 * (S.L + (5 - S.L)) - 1;
		p4.x = 50 * S.L;
		draw_line(p3, p4, red);
	}
	draw_fill_rectangle(p1, p2, white);
	draw_rectangle(p1, p2, red);
}

void display_game(SLIDER S)
{
	init_display(S);
	board(S);
	display_wall(S);
	message_space(S);
}

void player_exit(SLIDER S)
{
	display_player(S);
	display_sortie(S);
	message_help(S);
}

void play_game(SLIDER S)
{
	display_game(S);
	player_exit(S);
	move_player(S);
	printf("fin move_player & play_game\n");
}

void end_display(SLIDER S)
{
	wait_escape();
}
