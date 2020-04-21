/* Generated by re2c */

#include <stddef.h> /* size_t */
#include <stdio.h>
#include <stdlib.h> /* malloc, free */
#include <string.h> /* memcpy */

static void *read_file
    ( const char *fname
    , size_t unit
    , size_t padding
    , size_t *pfsize
    )
{
    void *buffer = NULL;
    size_t fsize = 0;

    /* open file */
    FILE *f = fopen(fname, "rb");
    if (f == NULL) {
        goto error;
    }

    /* get file size */
    fseek(f, 0, SEEK_END);
    fsize = (size_t) ftell(f) / unit;
    fseek(f, 0, SEEK_SET);

    /* allocate memory for file and padding */
    buffer = malloc(unit * (fsize + padding));
    if (buffer == NULL) {
        goto error;
    }

    /* read the whole file in memory */
    if (fread(buffer, unit, fsize, f) != fsize) {
        goto error;
    }

    fclose(f);
    *pfsize = fsize;
    return buffer;

error:
    fprintf(stderr, "error: cannot read file '%s'\n", fname);
    free(buffer);
    if (f != NULL) {
        fclose(f);
    }
    return NULL;
}

#define YYCTYPE unsigned char
#define YYKEYTYPE unsigned char
#define YYPEEK() *cursor
#define YYSKIP() ++cursor
#define YYLESSTHAN(n) (limit - cursor) < n
#define YYFILL(n) { break; }

static int action_line20_r1
    ( unsigned *pkix
    , const YYKEYTYPE *keys
    , const YYCTYPE *start
    , const YYCTYPE *token
    , const YYCTYPE **cursor
    , YYKEYTYPE rule_act
    )
{
    const unsigned kix = *pkix;
    const long pos = token - start;
    const long len_act = *cursor - token;
    const long len_exp = (long) keys[kix + 1];
    const YYKEYTYPE rule_exp = keys[kix + 2];
    *pkix = kix + 3;
    if (rule_exp == 255) {
        fprintf
            ( stderr
            , "warning: lex_line20_r1: control flow is undefined for input"
                " at position %ld, rerun re2c with '-W'\n"
            , pos
            );
    }
    if (len_act == len_exp && rule_act == rule_exp) {
        const YYKEYTYPE offset = keys[kix];
        *cursor = token + offset;
        return 0;
    } else {
        fprintf
            ( stderr
            , "error: lex_line20_r1: at position %ld (key %u):\n"
                "\texpected: match length %ld, rule %u\n"
                "\tactual:   match length %ld, rule %u\n"
            , pos
            , kix
            , len_exp
            , rule_exp
            , len_act
            , rule_act
            );
        return 1;
    }
}

static int check_key_count_line20_r1(unsigned have, unsigned used, unsigned need)
{
    if (used + need <= have) return 0;
    fprintf(stderr, "error: lex_line20_r1: not enough keys\n");
    return 1;
}

int lex_line20_r1()
{
    const size_t padding = 1; /* YYMAXFILL */
    int status = 0;
    size_t input_len = 0;
    size_t keys_count = 0;
    YYCTYPE *input = NULL;
    YYKEYTYPE *keys = NULL;
    const YYCTYPE *cursor = NULL;
    const YYCTYPE *limit = NULL;
    const YYCTYPE *token = NULL;
    const YYCTYPE *eof = NULL;
    unsigned int i = 0;

    input = (YYCTYPE *) read_file
        ("skeleton/repeat-02.cgir--skeleton.c.line20_r1.input"
        , sizeof (YYCTYPE)
        , padding
        , &input_len
        );
    if (input == NULL) {
        status = 1;
        goto end;
    }

    keys = (YYKEYTYPE *) read_file
        ("skeleton/repeat-02.cgir--skeleton.c.line20_r1.keys"
        , sizeof (YYKEYTYPE)
        , 0
        , &keys_count
        );
    if (keys == NULL) {
        status = 1;
        goto end;
    }

    cursor = input;
    limit = input + input_len + padding;
    eof = input + input_len;

    for (i = 0; status == 0 && cursor < eof && i < keys_count;) {
        token = cursor;
        YYCTYPE yych;

        if (YYLESSTHAN (1)) YYFILL(1);
        yych = YYPEEK ();
        if (yych <= '2') {
            if (yych <= '0') goto yy3;
            if (yych <= '1') goto yy4;
            goto yy6;
        } else {
            if (yych <= '`') goto yy3;
            if (yych <= 'a') goto yy8;
            if (yych <= 'b') goto yy10;
        }
yy3:
yy4:
        YYSKIP ();
        status = check_key_count_line20_r1(keys_count, i, 3)
             || action_line20_r1(&i, keys, input, token, &cursor, 2);
        continue;
yy6:
        YYSKIP ();
        status = check_key_count_line20_r1(keys_count, i, 3)
             || action_line20_r1(&i, keys, input, token, &cursor, 3);
        continue;
yy8:
        YYSKIP ();
        status = check_key_count_line20_r1(keys_count, i, 3)
             || action_line20_r1(&i, keys, input, token, &cursor, 0);
        continue;
yy10:
        YYSKIP ();
        status = check_key_count_line20_r1(keys_count, i, 3)
             || action_line20_r1(&i, keys, input, token, &cursor, 1);
        continue;

    }
    if (status == 0) {
        if (cursor != eof) {
            status = 1;
            const long pos = token - input;
            fprintf(stderr, "error: lex_line20_r1: unused input strings left at position %ld\n", pos);
        }
        if (i != keys_count) {
            status = 1;
            fprintf(stderr, "error: lex_line20_r1: unused keys left after %u keys\n", i);
        }
    }

end:
    free(input);
    free(keys);

    return status;
}

#undef YYCTYPE
#undef YYKEYTYPE
#undef YYPEEK
#undef YYSKIP
#undef YYLESSTHAN
#undef YYFILL

#define YYCTYPE unsigned char
#define YYKEYTYPE unsigned char
#define YYPEEK() *cursor
#define YYSKIP() ++cursor
#define YYLESSTHAN(n) (limit - cursor) < n
#define YYFILL(n) { break; }

static int action_line20_r2
    ( unsigned *pkix
    , const YYKEYTYPE *keys
    , const YYCTYPE *start
    , const YYCTYPE *token
    , const YYCTYPE **cursor
    , YYKEYTYPE rule_act
    )
{
    const unsigned kix = *pkix;
    const long pos = token - start;
    const long len_act = *cursor - token;
    const long len_exp = (long) keys[kix + 1];
    const YYKEYTYPE rule_exp = keys[kix + 2];
    *pkix = kix + 3;
    if (rule_exp == 255) {
        fprintf
            ( stderr
            , "warning: lex_line20_r2: control flow is undefined for input"
                " at position %ld, rerun re2c with '-W'\n"
            , pos
            );
    }
    if (len_act == len_exp && rule_act == rule_exp) {
        const YYKEYTYPE offset = keys[kix];
        *cursor = token + offset;
        return 0;
    } else {
        fprintf
            ( stderr
            , "error: lex_line20_r2: at position %ld (key %u):\n"
                "\texpected: match length %ld, rule %u\n"
                "\tactual:   match length %ld, rule %u\n"
            , pos
            , kix
            , len_exp
            , rule_exp
            , len_act
            , rule_act
            );
        return 1;
    }
}

static int check_key_count_line20_r2(unsigned have, unsigned used, unsigned need)
{
    if (used + need <= have) return 0;
    fprintf(stderr, "error: lex_line20_r2: not enough keys\n");
    return 1;
}

int lex_line20_r2()
{
    const size_t padding = 1; /* YYMAXFILL */
    int status = 0;
    size_t input_len = 0;
    size_t keys_count = 0;
    YYCTYPE *input = NULL;
    YYKEYTYPE *keys = NULL;
    const YYCTYPE *cursor = NULL;
    const YYCTYPE *limit = NULL;
    const YYCTYPE *token = NULL;
    const YYCTYPE *eof = NULL;
    unsigned int i = 0;

    input = (YYCTYPE *) read_file
        ("skeleton/repeat-02.cgir--skeleton.c.line20_r2.input"
        , sizeof (YYCTYPE)
        , padding
        , &input_len
        );
    if (input == NULL) {
        status = 1;
        goto end;
    }

    keys = (YYKEYTYPE *) read_file
        ("skeleton/repeat-02.cgir--skeleton.c.line20_r2.keys"
        , sizeof (YYKEYTYPE)
        , 0
        , &keys_count
        );
    if (keys == NULL) {
        status = 1;
        goto end;
    }

    cursor = input;
    limit = input + input_len + padding;
    eof = input + input_len;

    for (i = 0; status == 0 && cursor < eof && i < keys_count;) {
        token = cursor;
        YYCTYPE yych;

        if (YYLESSTHAN (1)) YYFILL(1);
        yych = YYPEEK ();
        if (yych <= '2') {
            if (yych <= '0') goto yy15;
            if (yych <= '1') goto yy16;
            goto yy18;
        } else {
            if (yych == 'b') goto yy20;
        }
yy15:
yy16:
        YYSKIP ();
        status = check_key_count_line20_r2(keys_count, i, 3)
             || action_line20_r2(&i, keys, input, token, &cursor, 1);
        continue;
yy18:
        YYSKIP ();
        status = check_key_count_line20_r2(keys_count, i, 3)
             || action_line20_r2(&i, keys, input, token, &cursor, 2);
        continue;
yy20:
        YYSKIP ();
        status = check_key_count_line20_r2(keys_count, i, 3)
             || action_line20_r2(&i, keys, input, token, &cursor, 0);
        continue;

    }
    if (status == 0) {
        if (cursor != eof) {
            status = 1;
            const long pos = token - input;
            fprintf(stderr, "error: lex_line20_r2: unused input strings left at position %ld\n", pos);
        }
        if (i != keys_count) {
            status = 1;
            fprintf(stderr, "error: lex_line20_r2: unused keys left after %u keys\n", i);
        }
    }

end:
    free(input);
    free(keys);

    return status;
}

#undef YYCTYPE
#undef YYKEYTYPE
#undef YYPEEK
#undef YYSKIP
#undef YYLESSTHAN
#undef YYFILL

#define YYCTYPE unsigned char
#define YYKEYTYPE unsigned char
#define YYPEEK() *cursor
#define YYSKIP() ++cursor
#define YYLESSTHAN(n) (limit - cursor) < n
#define YYFILL(n) { break; }

static int action_line32_r1
    ( unsigned *pkix
    , const YYKEYTYPE *keys
    , const YYCTYPE *start
    , const YYCTYPE *token
    , const YYCTYPE **cursor
    , YYKEYTYPE rule_act
    )
{
    const unsigned kix = *pkix;
    const long pos = token - start;
    const long len_act = *cursor - token;
    const long len_exp = (long) keys[kix + 1];
    const YYKEYTYPE rule_exp = keys[kix + 2];
    *pkix = kix + 3;
    if (rule_exp == 255) {
        fprintf
            ( stderr
            , "warning: lex_line32_r1: control flow is undefined for input"
                " at position %ld, rerun re2c with '-W'\n"
            , pos
            );
    }
    if (len_act == len_exp && rule_act == rule_exp) {
        const YYKEYTYPE offset = keys[kix];
        *cursor = token + offset;
        return 0;
    } else {
        fprintf
            ( stderr
            , "error: lex_line32_r1: at position %ld (key %u):\n"
                "\texpected: match length %ld, rule %u\n"
                "\tactual:   match length %ld, rule %u\n"
            , pos
            , kix
            , len_exp
            , rule_exp
            , len_act
            , rule_act
            );
        return 1;
    }
}

static int check_key_count_line32_r1(unsigned have, unsigned used, unsigned need)
{
    if (used + need <= have) return 0;
    fprintf(stderr, "error: lex_line32_r1: not enough keys\n");
    return 1;
}

int lex_line32_r1()
{
    const size_t padding = 1; /* YYMAXFILL */
    int status = 0;
    size_t input_len = 0;
    size_t keys_count = 0;
    YYCTYPE *input = NULL;
    YYKEYTYPE *keys = NULL;
    const YYCTYPE *cursor = NULL;
    const YYCTYPE *limit = NULL;
    const YYCTYPE *token = NULL;
    const YYCTYPE *eof = NULL;
    unsigned int i = 0;

    input = (YYCTYPE *) read_file
        ("skeleton/repeat-02.cgir--skeleton.c.line32_r1.input"
        , sizeof (YYCTYPE)
        , padding
        , &input_len
        );
    if (input == NULL) {
        status = 1;
        goto end;
    }

    keys = (YYKEYTYPE *) read_file
        ("skeleton/repeat-02.cgir--skeleton.c.line32_r1.keys"
        , sizeof (YYKEYTYPE)
        , 0
        , &keys_count
        );
    if (keys == NULL) {
        status = 1;
        goto end;
    }

    cursor = input;
    limit = input + input_len + padding;
    eof = input + input_len;

    for (i = 0; status == 0 && cursor < eof && i < keys_count;) {
        token = cursor;
        YYCTYPE yych;

        if (YYLESSTHAN (1)) YYFILL(1);
        yych = YYPEEK ();
        if (yych <= '2') {
            if (yych <= '0') goto yy25;
            if (yych <= '1') goto yy26;
            goto yy28;
        } else {
            if (yych <= '`') goto yy25;
            if (yych <= 'a') goto yy30;
            if (yych <= 'b') goto yy32;
        }
yy25:
yy26:
        YYSKIP ();
        status = check_key_count_line32_r1(keys_count, i, 3)
             || action_line32_r1(&i, keys, input, token, &cursor, 2);
        continue;
yy28:
        YYSKIP ();
        status = check_key_count_line32_r1(keys_count, i, 3)
             || action_line32_r1(&i, keys, input, token, &cursor, 3);
        continue;
yy30:
        YYSKIP ();
        status = check_key_count_line32_r1(keys_count, i, 3)
             || action_line32_r1(&i, keys, input, token, &cursor, 0);
        continue;
yy32:
        YYSKIP ();
        status = check_key_count_line32_r1(keys_count, i, 3)
             || action_line32_r1(&i, keys, input, token, &cursor, 1);
        continue;

    }
    if (status == 0) {
        if (cursor != eof) {
            status = 1;
            const long pos = token - input;
            fprintf(stderr, "error: lex_line32_r1: unused input strings left at position %ld\n", pos);
        }
        if (i != keys_count) {
            status = 1;
            fprintf(stderr, "error: lex_line32_r1: unused keys left after %u keys\n", i);
        }
    }

end:
    free(input);
    free(keys);

    return status;
}

#undef YYCTYPE
#undef YYKEYTYPE
#undef YYPEEK
#undef YYSKIP
#undef YYLESSTHAN
#undef YYFILL

#define YYCTYPE unsigned char
#define YYKEYTYPE unsigned char
#define YYPEEK() *cursor
#define YYSKIP() ++cursor
#define YYLESSTHAN(n) (limit - cursor) < n
#define YYFILL(n) { break; }

static int action_line32_r2
    ( unsigned *pkix
    , const YYKEYTYPE *keys
    , const YYCTYPE *start
    , const YYCTYPE *token
    , const YYCTYPE **cursor
    , YYKEYTYPE rule_act
    )
{
    const unsigned kix = *pkix;
    const long pos = token - start;
    const long len_act = *cursor - token;
    const long len_exp = (long) keys[kix + 1];
    const YYKEYTYPE rule_exp = keys[kix + 2];
    *pkix = kix + 3;
    if (rule_exp == 255) {
        fprintf
            ( stderr
            , "warning: lex_line32_r2: control flow is undefined for input"
                " at position %ld, rerun re2c with '-W'\n"
            , pos
            );
    }
    if (len_act == len_exp && rule_act == rule_exp) {
        const YYKEYTYPE offset = keys[kix];
        *cursor = token + offset;
        return 0;
    } else {
        fprintf
            ( stderr
            , "error: lex_line32_r2: at position %ld (key %u):\n"
                "\texpected: match length %ld, rule %u\n"
                "\tactual:   match length %ld, rule %u\n"
            , pos
            , kix
            , len_exp
            , rule_exp
            , len_act
            , rule_act
            );
        return 1;
    }
}

static int check_key_count_line32_r2(unsigned have, unsigned used, unsigned need)
{
    if (used + need <= have) return 0;
    fprintf(stderr, "error: lex_line32_r2: not enough keys\n");
    return 1;
}

int lex_line32_r2()
{
    const size_t padding = 1; /* YYMAXFILL */
    int status = 0;
    size_t input_len = 0;
    size_t keys_count = 0;
    YYCTYPE *input = NULL;
    YYKEYTYPE *keys = NULL;
    const YYCTYPE *cursor = NULL;
    const YYCTYPE *limit = NULL;
    const YYCTYPE *token = NULL;
    const YYCTYPE *eof = NULL;
    unsigned int i = 0;

    input = (YYCTYPE *) read_file
        ("skeleton/repeat-02.cgir--skeleton.c.line32_r2.input"
        , sizeof (YYCTYPE)
        , padding
        , &input_len
        );
    if (input == NULL) {
        status = 1;
        goto end;
    }

    keys = (YYKEYTYPE *) read_file
        ("skeleton/repeat-02.cgir--skeleton.c.line32_r2.keys"
        , sizeof (YYKEYTYPE)
        , 0
        , &keys_count
        );
    if (keys == NULL) {
        status = 1;
        goto end;
    }

    cursor = input;
    limit = input + input_len + padding;
    eof = input + input_len;

    for (i = 0; status == 0 && cursor < eof && i < keys_count;) {
        token = cursor;
        YYCTYPE yych;

        if (YYLESSTHAN (1)) YYFILL(1);
        yych = YYPEEK ();
        if (yych <= '2') {
            if (yych <= '0') goto yy37;
            if (yych <= '1') goto yy38;
            goto yy40;
        } else {
            if (yych == 'b') goto yy42;
        }
yy37:
yy38:
        YYSKIP ();
        status = check_key_count_line32_r2(keys_count, i, 3)
             || action_line32_r2(&i, keys, input, token, &cursor, 1);
        continue;
yy40:
        YYSKIP ();
        status = check_key_count_line32_r2(keys_count, i, 3)
             || action_line32_r2(&i, keys, input, token, &cursor, 2);
        continue;
yy42:
        YYSKIP ();
        status = check_key_count_line32_r2(keys_count, i, 3)
             || action_line32_r2(&i, keys, input, token, &cursor, 0);
        continue;

    }
    if (status == 0) {
        if (cursor != eof) {
            status = 1;
            const long pos = token - input;
            fprintf(stderr, "error: lex_line32_r2: unused input strings left at position %ld\n", pos);
        }
        if (i != keys_count) {
            status = 1;
            fprintf(stderr, "error: lex_line32_r2: unused keys left after %u keys\n", i);
        }
    }

end:
    free(input);
    free(keys);

    return status;
}

#undef YYCTYPE
#undef YYKEYTYPE
#undef YYPEEK
#undef YYSKIP
#undef YYLESSTHAN
#undef YYFILL

#define YYCTYPE unsigned char
#define YYKEYTYPE unsigned char
#define YYPEEK() *cursor
#define YYSKIP() ++cursor
#define YYLESSTHAN(n) (limit - cursor) < n
#define YYFILL(n) { break; }

static int action_line44_r1
    ( unsigned *pkix
    , const YYKEYTYPE *keys
    , const YYCTYPE *start
    , const YYCTYPE *token
    , const YYCTYPE **cursor
    , YYKEYTYPE rule_act
    )
{
    const unsigned kix = *pkix;
    const long pos = token - start;
    const long len_act = *cursor - token;
    const long len_exp = (long) keys[kix + 1];
    const YYKEYTYPE rule_exp = keys[kix + 2];
    *pkix = kix + 3;
    if (rule_exp == 255) {
        fprintf
            ( stderr
            , "warning: lex_line44_r1: control flow is undefined for input"
                " at position %ld, rerun re2c with '-W'\n"
            , pos
            );
    }
    if (len_act == len_exp && rule_act == rule_exp) {
        const YYKEYTYPE offset = keys[kix];
        *cursor = token + offset;
        return 0;
    } else {
        fprintf
            ( stderr
            , "error: lex_line44_r1: at position %ld (key %u):\n"
                "\texpected: match length %ld, rule %u\n"
                "\tactual:   match length %ld, rule %u\n"
            , pos
            , kix
            , len_exp
            , rule_exp
            , len_act
            , rule_act
            );
        return 1;
    }
}

static int check_key_count_line44_r1(unsigned have, unsigned used, unsigned need)
{
    if (used + need <= have) return 0;
    fprintf(stderr, "error: lex_line44_r1: not enough keys\n");
    return 1;
}

int lex_line44_r1()
{
    const size_t padding = 1; /* YYMAXFILL */
    int status = 0;
    size_t input_len = 0;
    size_t keys_count = 0;
    YYCTYPE *input = NULL;
    YYKEYTYPE *keys = NULL;
    const YYCTYPE *cursor = NULL;
    const YYCTYPE *limit = NULL;
    const YYCTYPE *token = NULL;
    const YYCTYPE *eof = NULL;
    unsigned int i = 0;

    input = (YYCTYPE *) read_file
        ("skeleton/repeat-02.cgir--skeleton.c.line44_r1.input"
        , sizeof (YYCTYPE)
        , padding
        , &input_len
        );
    if (input == NULL) {
        status = 1;
        goto end;
    }

    keys = (YYKEYTYPE *) read_file
        ("skeleton/repeat-02.cgir--skeleton.c.line44_r1.keys"
        , sizeof (YYKEYTYPE)
        , 0
        , &keys_count
        );
    if (keys == NULL) {
        status = 1;
        goto end;
    }

    cursor = input;
    limit = input + input_len + padding;
    eof = input + input_len;

    for (i = 0; status == 0 && cursor < eof && i < keys_count;) {
        token = cursor;
        YYCTYPE yych;

        if (YYLESSTHAN (1)) YYFILL(1);
        yych = YYPEEK ();
        if (yych <= '2') {
            if (yych <= '0') goto yy47;
            if (yych <= '1') goto yy48;
            goto yy50;
        } else {
            if (yych <= '`') goto yy47;
            if (yych <= 'a') goto yy52;
            if (yych <= 'b') goto yy54;
        }
yy47:
yy48:
        YYSKIP ();
        status = check_key_count_line44_r1(keys_count, i, 3)
             || action_line44_r1(&i, keys, input, token, &cursor, 2);
        continue;
yy50:
        YYSKIP ();
        status = check_key_count_line44_r1(keys_count, i, 3)
             || action_line44_r1(&i, keys, input, token, &cursor, 3);
        continue;
yy52:
        YYSKIP ();
        status = check_key_count_line44_r1(keys_count, i, 3)
             || action_line44_r1(&i, keys, input, token, &cursor, 0);
        continue;
yy54:
        YYSKIP ();
        status = check_key_count_line44_r1(keys_count, i, 3)
             || action_line44_r1(&i, keys, input, token, &cursor, 1);
        continue;

    }
    if (status == 0) {
        if (cursor != eof) {
            status = 1;
            const long pos = token - input;
            fprintf(stderr, "error: lex_line44_r1: unused input strings left at position %ld\n", pos);
        }
        if (i != keys_count) {
            status = 1;
            fprintf(stderr, "error: lex_line44_r1: unused keys left after %u keys\n", i);
        }
    }

end:
    free(input);
    free(keys);

    return status;
}

#undef YYCTYPE
#undef YYKEYTYPE
#undef YYPEEK
#undef YYSKIP
#undef YYLESSTHAN
#undef YYFILL

#define YYCTYPE unsigned char
#define YYKEYTYPE unsigned char
#define YYPEEK() *cursor
#define YYSKIP() ++cursor
#define YYLESSTHAN(n) (limit - cursor) < n
#define YYFILL(n) { break; }

static int action_line44_r2
    ( unsigned *pkix
    , const YYKEYTYPE *keys
    , const YYCTYPE *start
    , const YYCTYPE *token
    , const YYCTYPE **cursor
    , YYKEYTYPE rule_act
    )
{
    const unsigned kix = *pkix;
    const long pos = token - start;
    const long len_act = *cursor - token;
    const long len_exp = (long) keys[kix + 1];
    const YYKEYTYPE rule_exp = keys[kix + 2];
    *pkix = kix + 3;
    if (rule_exp == 255) {
        fprintf
            ( stderr
            , "warning: lex_line44_r2: control flow is undefined for input"
                " at position %ld, rerun re2c with '-W'\n"
            , pos
            );
    }
    if (len_act == len_exp && rule_act == rule_exp) {
        const YYKEYTYPE offset = keys[kix];
        *cursor = token + offset;
        return 0;
    } else {
        fprintf
            ( stderr
            , "error: lex_line44_r2: at position %ld (key %u):\n"
                "\texpected: match length %ld, rule %u\n"
                "\tactual:   match length %ld, rule %u\n"
            , pos
            , kix
            , len_exp
            , rule_exp
            , len_act
            , rule_act
            );
        return 1;
    }
}

static int check_key_count_line44_r2(unsigned have, unsigned used, unsigned need)
{
    if (used + need <= have) return 0;
    fprintf(stderr, "error: lex_line44_r2: not enough keys\n");
    return 1;
}

int lex_line44_r2()
{
    const size_t padding = 1; /* YYMAXFILL */
    int status = 0;
    size_t input_len = 0;
    size_t keys_count = 0;
    YYCTYPE *input = NULL;
    YYKEYTYPE *keys = NULL;
    const YYCTYPE *cursor = NULL;
    const YYCTYPE *limit = NULL;
    const YYCTYPE *token = NULL;
    const YYCTYPE *eof = NULL;
    unsigned int i = 0;

    input = (YYCTYPE *) read_file
        ("skeleton/repeat-02.cgir--skeleton.c.line44_r2.input"
        , sizeof (YYCTYPE)
        , padding
        , &input_len
        );
    if (input == NULL) {
        status = 1;
        goto end;
    }

    keys = (YYKEYTYPE *) read_file
        ("skeleton/repeat-02.cgir--skeleton.c.line44_r2.keys"
        , sizeof (YYKEYTYPE)
        , 0
        , &keys_count
        );
    if (keys == NULL) {
        status = 1;
        goto end;
    }

    cursor = input;
    limit = input + input_len + padding;
    eof = input + input_len;

    for (i = 0; status == 0 && cursor < eof && i < keys_count;) {
        token = cursor;
        YYCTYPE yych;

        if (YYLESSTHAN (1)) YYFILL(1);
        yych = YYPEEK ();
        if (yych <= '2') {
            if (yych <= '0') goto yy59;
            if (yych <= '1') goto yy60;
            goto yy62;
        } else {
            if (yych == 'b') goto yy64;
        }
yy59:
yy60:
        YYSKIP ();
        status = check_key_count_line44_r2(keys_count, i, 3)
             || action_line44_r2(&i, keys, input, token, &cursor, 1);
        continue;
yy62:
        YYSKIP ();
        status = check_key_count_line44_r2(keys_count, i, 3)
             || action_line44_r2(&i, keys, input, token, &cursor, 2);
        continue;
yy64:
        YYSKIP ();
        status = check_key_count_line44_r2(keys_count, i, 3)
             || action_line44_r2(&i, keys, input, token, &cursor, 0);
        continue;

    }
    if (status == 0) {
        if (cursor != eof) {
            status = 1;
            const long pos = token - input;
            fprintf(stderr, "error: lex_line44_r2: unused input strings left at position %ld\n", pos);
        }
        if (i != keys_count) {
            status = 1;
            fprintf(stderr, "error: lex_line44_r2: unused keys left after %u keys\n", i);
        }
    }

end:
    free(input);
    free(keys);

    return status;
}

#undef YYCTYPE
#undef YYKEYTYPE
#undef YYPEEK
#undef YYSKIP
#undef YYLESSTHAN
#undef YYFILL

int main()
{
    if (lex_line20_r1() != 0) {
        return 1;
    }
    if (lex_line20_r2() != 0) {
        return 1;
    }
    if (lex_line32_r1() != 0) {
        return 1;
    }
    if (lex_line32_r2() != 0) {
        return 1;
    }
    if (lex_line44_r1() != 0) {
        return 1;
    }
    if (lex_line44_r2() != 0) {
        return 1;
    }
    return 0;
}
12ab 	
 !"#$%&'()*+,-./03456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\]^_`cdefghijklmnopqrstuvwxyz{|}~ ЁЂЃЄЅІЇЈЉЊЋЌ­ЎЏАБВГДЕЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯабвгдежзийклмнопрстуфхцчшщъыьэюя№ёђѓєѕіїјљњћќ§ўџ  џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ12b 	
 !"#$%&'()*+,-./03456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\]^_`acdefghijklmnopqrstuvwxyz{|}~ ЁЂЃЄЅІЇЈЉЊЋЌ­ЎЏАБВГДЕЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯабвгдежзийклмнопрстуфхцчшщъыьэюя№ёђѓєѕіїјљњћќ§ўџ  џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ12ab 	
 !"#$%&'()*+,-./03456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\]^_`cdefghijklmnopqrstuvwxyz{|}~ ЁЂЃЄЅІЇЈЉЊЋЌ­ЎЏАБВГДЕЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯабвгдежзийклмнопрстуфхцчшщъыьэюя№ёђѓєѕіїјљњћќ§ўџ  џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ12b 	
 !"#$%&'()*+,-./03456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\]^_`acdefghijklmnopqrstuvwxyz{|}~ ЁЂЃЄЅІЇЈЉЊЋЌ­ЎЏАБВГДЕЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯабвгдежзийклмнопрстуфхцчшщъыьэюя№ёђѓєѕіїјљњћќ§ўџ  џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ12ab 	
 !"#$%&'()*+,-./03456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\]^_`cdefghijklmnopqrstuvwxyz{|}~ ЁЂЃЄЅІЇЈЉЊЋЌ­ЎЏАБВГДЕЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯабвгдежзийклмнопрстуфхцчшщъыьэюя№ёђѓєѕіїјљњћќ§ўџ  џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ12b 	
 !"#$%&'()*+,-./03456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\]^_`acdefghijklmnopqrstuvwxyz{|}~ ЁЂЃЄЅІЇЈЉЊЋЌ­ЎЏАБВГДЕЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯабвгдежзийклмнопрстуфхцчшщъыьэюя№ёђѓєѕіїјљњћќ§ўџ  џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џ џskeleton/repeat-02.cgir--skeleton.re:20:2: warning: control flow in condition 'r1' is undefined for strings that match '[\x0-\x30\x33-\x60\x63-\xFF]', use default rule '*' [-Wundefined-control-flow]
skeleton/repeat-02.cgir--skeleton.re:20:2: warning: control flow in condition 'r2' is undefined for strings that match '[\x0-\x30\x33-\x61\x63-\xFF]', use default rule '*' [-Wundefined-control-flow]
skeleton/repeat-02.cgir--skeleton.re:32:2: warning: control flow in condition 'r1' is undefined for strings that match '[\x0-\x30\x33-\x60\x63-\xFF]', use default rule '*' [-Wundefined-control-flow]
skeleton/repeat-02.cgir--skeleton.re:32:2: warning: control flow in condition 'r2' is undefined for strings that match '[\x0-\x30\x33-\x61\x63-\xFF]', use default rule '*' [-Wundefined-control-flow]
skeleton/repeat-02.cgir--skeleton.re:44:2: warning: control flow in condition 'r1' is undefined for strings that match '[\x0-\x30\x33-\x60\x63-\xFF]', use default rule '*' [-Wundefined-control-flow]
skeleton/repeat-02.cgir--skeleton.re:44:2: warning: control flow in condition 'r2' is undefined for strings that match '[\x0-\x30\x33-\x61\x63-\xFF]', use default rule '*' [-Wundefined-control-flow]
