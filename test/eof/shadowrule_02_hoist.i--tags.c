/* Generated by re2c */
// R1 matches any single character => all transitions from the initial
// state have the same tags which can be hoisted

{
	YYCTYPE yych;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	yyt1 = YYCURSOR;
yy2:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	switch (yych) {
	case 'b':	goto yy2;
	default:	goto yy4;
	}
yy4:
	x = yyt1;
	{ /* R1, x must be set */  }
}


// R1 matches any single character, but it is also possible to match zero
// characters with EOF rule => tags cannot be hoisted in the initial state
// because of the possible untagged transition to EOF rule

{
	YYCTYPE yych;
yy6_:
	yych = *YYCURSOR;
	if (yych >= 0x01) {
		yyt1 = YYCURSOR;
		goto yy7;
	}
	if (YYLIMIT <= YYCURSOR) {
		if (YYFILL () == 0) goto yy6_;
		goto yyeofrule2;
	}
	yyt1 = YYCURSOR;
yy7:
	++YYCURSOR;
yy7_:
	yych = *YYCURSOR;
	switch (yych) {
	case 'b':	goto yy7;
	default:
		if (YYLIMIT <= YYCURSOR) {
			if (YYFILL () == 0) goto yy7_;
		}
		goto yy9;
	}
yy9:
	x = yyt1;
	{ /* R1, x must be set */  }
yyeofrule2:
	{ /* EOF, x must not be set */ }
}

