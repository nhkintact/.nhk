int
width_launcher(Bar *bar, BarArg *a)
{
	int i, x = 0;

	for (i = 0; i < LENGTH(launchers); i++) {
		x += TEXTW(launchers[i].name);
	}
	return x;
}

int
draw_launcher(Bar *bar, BarArg *a)
{
	int i, x = 0, w = 0;;

	for (i = 0; i < LENGTH(launchers); i++) {
		w = TEXTW(launchers[i].name);
		drw_text(drw, x, 0, w, bh, lrpad / 2, launchers[i].name, 0, True);
		x += w;
	}

	return x;
}

int
click_launcher(Bar *bar, Arg *arg, BarArg *a)
{
	int i, x = 0;

	for (i = 0; i < LENGTH(launchers); i++) {
		x += TEXTW(launchers[i].name);
		if (a->x < x) {
		    spawn(&launchers[i].command);
		    break;
		}
	}
	return -1;
}
