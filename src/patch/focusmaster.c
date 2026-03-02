void
focusmaster(const Arg *arg)
{
	Client *master;
	Monitor *m = selmon;

	if (m->nmaster < 1)
		return;

	master = nexttiled(m->clients);

	if (!master)
		return;

	focus(master);
	restack(m);
}
