DESCRIPTION
-----------

re2php (forked from re2c) is a free and open-source lexer generator for PHP.

Its main goal is generating fast lexers: at least as fast as their reasonably
optimized hand-coded counterparts. Instead of using traditional table-driven
approach, re2php encodes the generated finite state automata directly in the
form of conditional jumps and comparisons. The resulting programs are faster
and often smaller than their table-driven analogues, and they are much easier
to debug and understand. re2php applies quite a few optimizations in order to
speed up and compress the generated code.

Another distinctive feature is its flexible interface: instead of assuming a
fixed program template, re2php lets the programmer write most of the interface
code and adapt the generated lexer to any particular environment.


DOCKER
------

You can use the docker prebuild image to quickly use re2php.

## bash

```
docker run --rm -it -v $PWD:/src -w /src davekok/re2php file.y.php -o file.php
```

## Powershell

```
docker run --rm -it -v "${PWD}:/src" -w /src davekok/re2php file.y.php -o file.php
```

## Windows Command

```
docker run --rm -it -v "%CD%:/src" -w /src davekok/re2php file.y.php -o file.php
```

EXAMPLE
-------

A simple example

```
<?php

declare(strict_types=1);

/*!re2c
    re2c:yyfill:enable  = 0;

    digit  = [0-9];
    number = digit+;
    comma = ",";
*/
class Lexer implements Iterator
{
    public const ERROR = 0;
    public const NUMBER = 1;
    public const COMMA = 2;
    private string $buffer;
    private int $marker;
    private int $offset;
    private int $cursor;
    private int $length;

    public function __construct($buffer)
    {
        $this->buffer = $buffer;
        $this->length = strlen($buffer);
    }

    public function current()
    {
        return [$this->token, $this->value];
    }

    public function key()
    {
        return $this->offset;
    }

    public function valid(): bool
    {
        return $this->token !== self::ERROR && $this->cursor < $this->length;
    }

    public function rewind(): void
    {
        $this->cursor = 0;
        $this->offset = 0;
        $this->marker = 0;
        $this->next();
    }

    public function next(): void
    {
        /*!re2c
        *
        {
            $this->offset = $this->marker;
            $this->token = self::ERROR;
            $this->value = substr($this->buffer, $this->marker, $this->cursor - $this->marker);
            $this->marker = $this->cursor;
            return;
        }

        comma
        {
            $this->offset = $this->marker;
            $this->token = self::COMMA;
            $this->value = substr($this->buffer, $this->marker, $this->cursor - $this->marker);
            $this->marker = $this->cursor;
            return;
        }

        number
        {
            $this->offset = $this->marker;
            $this->token = self::NUMBER;
            $this->value = substr($this->buffer, $this->marker, $this->cursor - $this->marker);
            $this->marker = $this->cursor;
            return;
        }
        */
    }
}

foreach ((new Lexer("843954,3948,30454")) as $offset => [$token, $value])
    echo "[$offset] $token: $value\n";

```

BUGS
----
Please report any bugs and send feature requests to https://github.com/davekok/re2php/issues.


AUTHORS
-------
Re2c was originally written by Peter Bumbulis <peter@csg.uwaterloo.ca>.
Since then many people contributed to the project.
Re2c current maintainers are Ulya Trofimovich <skvadrik@gmail.com> and Dan Nuffer <nuffer@users.sourceforge.net>.
Re2php tries to remain as much a possible compatible with the upstream code base.
