/* Generated by re2c */
#line 1 "input5.re"

#line 5 "<stdout>"
{
	YYCTYPE yych;
	goto yy0;
	++YYCURSOR;
yy0:
	if(YYLIMIT == YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	switch(yych){
	case 'a':	goto yy2;
	default:	goto yy4;
	}
yy2:	++YYCURSOR;
	goto yy3;
yy3:
#line 3 "input5.re"
{ return 0; }
#line 22 "<stdout>"
yy4:	++YYCURSOR;
	goto yy5;
yy5:
#line 4 "input5.re"
{ return 1; }
#line 28 "<stdout>"
}
#line 6 "input5.re"

