/* Generated by re2c */
//line "golang/001_basic.--lang(go).re":1
//line "golang/001_basic.--lang(go).re":3


package main

import "fmt"

type YYCTYPE byte
type Input struct {
	data  []YYCTYPE
	cursor int
	marker int
}

func peek(input *Input) func() YYCTYPE {
	in := input
	return func() YYCTYPE {
		return in.data[in.cursor]
	}
}

func skip(input *Input) func() {
	in := input
	return func() {
		in.cursor++
	}
}

func Lex(input *Input) int {
	YYPEEK := peek(input)
	YYSKIP := skip(input)

	
//line "golang/001_basic.--lang(go).go":37
{
	var yych YYCTYPE
	yych = YYPEEK ();
	switch (yych) {
	case 0x00:	goto yy2;
	case '\t':	fallthrough
	case ' ':	goto yy6;
	case '-':	fallthrough
	case 'A':	fallthrough
	case 'B':	fallthrough
	case 'C':	fallthrough
	case 'D':	fallthrough
	case 'E':	fallthrough
	case 'F':	fallthrough
	case 'G':	fallthrough
	case 'H':	fallthrough
	case 'I':	fallthrough
	case 'J':	fallthrough
	case 'K':	fallthrough
	case 'L':	fallthrough
	case 'M':	fallthrough
	case 'N':	fallthrough
	case 'O':	fallthrough
	case 'P':	fallthrough
	case 'Q':	fallthrough
	case 'R':	fallthrough
	case 'S':	fallthrough
	case 'T':	fallthrough
	case 'U':	fallthrough
	case 'V':	fallthrough
	case 'W':	fallthrough
	case 'X':	fallthrough
	case 'Y':	fallthrough
	case 'Z':	fallthrough
	case '_':	fallthrough
	case 'a':	fallthrough
	case 'b':	fallthrough
	case 'c':	fallthrough
	case 'd':	fallthrough
	case 'e':	fallthrough
	case 'f':	fallthrough
	case 'g':	fallthrough
	case 'h':	fallthrough
	case 'i':	fallthrough
	case 'j':	fallthrough
	case 'k':	fallthrough
	case 'l':	fallthrough
	case 'm':	fallthrough
	case 'n':	fallthrough
	case 'o':	fallthrough
	case 'p':	fallthrough
	case 'q':	fallthrough
	case 'r':	fallthrough
	case 's':	fallthrough
	case 't':	fallthrough
	case 'u':	fallthrough
	case 'v':	fallthrough
	case 'w':	fallthrough
	case 'x':	fallthrough
	case 'y':	fallthrough
	case 'z':	goto yy9;
	case '0':	fallthrough
	case '1':	fallthrough
	case '2':	fallthrough
	case '3':	fallthrough
	case '4':	fallthrough
	case '5':	fallthrough
	case '6':	fallthrough
	case '7':	fallthrough
	case '8':	fallthrough
	case '9':	goto yy12;
	default:	goto yy4;
	}
yy2:
	YYSKIP ();
//line "golang/001_basic.--lang(go).re":42
	{
		fmt.Println("end")
		return 0
	}
//line "golang/001_basic.--lang(go).go":118
yy4:
	YYSKIP ();
//line "golang/001_basic.--lang(go).re":37
	{
		fmt.Println("error")
		return -1
	}
//line "golang/001_basic.--lang(go).go":126
yy6:
	YYSKIP ();
	yych = YYPEEK ();
	switch (yych) {
	case '\t':	fallthrough
	case ' ':	goto yy6;
	default:	goto yy8;
	}
yy8:
//line "golang/001_basic.--lang(go).re":57
	{
		fmt.Println("space")
		return 3
	}
//line "golang/001_basic.--lang(go).go":141
yy9:
	YYSKIP ();
	yych = YYPEEK ();
	switch (yych) {
	case '-':	fallthrough
	case 'A':	fallthrough
	case 'B':	fallthrough
	case 'C':	fallthrough
	case 'D':	fallthrough
	case 'E':	fallthrough
	case 'F':	fallthrough
	case 'G':	fallthrough
	case 'H':	fallthrough
	case 'I':	fallthrough
	case 'J':	fallthrough
	case 'K':	fallthrough
	case 'L':	fallthrough
	case 'M':	fallthrough
	case 'N':	fallthrough
	case 'O':	fallthrough
	case 'P':	fallthrough
	case 'Q':	fallthrough
	case 'R':	fallthrough
	case 'S':	fallthrough
	case 'T':	fallthrough
	case 'U':	fallthrough
	case 'V':	fallthrough
	case 'W':	fallthrough
	case 'X':	fallthrough
	case 'Y':	fallthrough
	case 'Z':	fallthrough
	case '_':	fallthrough
	case 'a':	fallthrough
	case 'b':	fallthrough
	case 'c':	fallthrough
	case 'd':	fallthrough
	case 'e':	fallthrough
	case 'f':	fallthrough
	case 'g':	fallthrough
	case 'h':	fallthrough
	case 'i':	fallthrough
	case 'j':	fallthrough
	case 'k':	fallthrough
	case 'l':	fallthrough
	case 'm':	fallthrough
	case 'n':	fallthrough
	case 'o':	fallthrough
	case 'p':	fallthrough
	case 'q':	fallthrough
	case 'r':	fallthrough
	case 's':	fallthrough
	case 't':	fallthrough
	case 'u':	fallthrough
	case 'v':	fallthrough
	case 'w':	fallthrough
	case 'x':	fallthrough
	case 'y':	fallthrough
	case 'z':	goto yy9;
	default:	goto yy11;
	}
yy11:
//line "golang/001_basic.--lang(go).re":52
	{
		fmt.Println("string")
		return 2
	}
//line "golang/001_basic.--lang(go).go":208
yy12:
	YYSKIP ();
	yych = YYPEEK ();
	switch (yych) {
	case '0':	fallthrough
	case '1':	fallthrough
	case '2':	fallthrough
	case '3':	fallthrough
	case '4':	fallthrough
	case '5':	fallthrough
	case '6':	fallthrough
	case '7':	fallthrough
	case '8':	fallthrough
	case '9':	goto yy12;
	default:	goto yy14;
	}
yy14:
//line "golang/001_basic.--lang(go).re":47
	{
		fmt.Println("number")
		return 1
	}
//line "golang/001_basic.--lang(go).go":231
}
//line "golang/001_basic.--lang(go).re":61

}

func main() {
	input := &Input{
		data:  []YYCTYPE("1024 fourty-two\x00"),
		cursor: 0,
	}

	result := 9999
	for result > 0 {
		result = Lex(input)
	}
}
