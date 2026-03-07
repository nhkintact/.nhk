static char *expected;
void
expect(char *expect, XKeyEvent *ev)
{
	if (sel && expected && strstr(expected, expect)) {
		if (expected && sel && !(ev->state & ShiftMask))
			puts(expect);
		printselected(ev->state);
		cleanup();
		exit(1);
	} else if (!sel && expected && strstr(expected, expect)) {
		puts(expect);
		cleanup();
		exit(1);
	}
}
