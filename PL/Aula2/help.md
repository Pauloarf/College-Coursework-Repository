# Notas e apontamentos retirados da ficha

## Operadores

- Básicos
    - ```.``` - Faz match com qualquer caratér exceto o newline(\n)
    - ```^``` - Serve de ancora ao inicio da string
    - ```$``` - Server de ancora ao fim da string
    - ```*``` - Faz match com 0 ou mais repetições daquilo que estiver antes
    - ```+``` - Faz match com 1 ou mais repetições daquilo que estiver antes
    - ```?``` - Faz match com aquilo que estiver antes se aparecer 0 ou 1 vezes
    - ```\``` - Serve de caratér de escape

- Quantificadores
    - ```{n}``` - Faz match com o n repetições do elemento anterior
    - ```{n,}``` - Faz match com n ou mais repetições do elemento anterior
    - ```{n,m}``` - Faz match com n ou mais repetições do elemento anterior

- Classes
    - ```[...]``` - Faz match com qualquer caratér que estiver dentro
    - ```[^...]``` - Faz match com qualquer caratér que não estiver dentro
    - ```\d``` - Faz match com todos os digitos
    - ```\D``` - Faz match com tudo exceto digitos
    - ```\w``` - Faz match com qualquer caratér alfaNumérico
    - ```\W``` - Faz match com qualquer caratér que não seja alfaNumérico
    - ```\s``` - Faz match com qualquer caratér que seja invisível(espaços brancos)
    - ```\S``` - Faz match com qualquer caratér que seja visivél

- Grupos
    - ```(...)``` - O que estiver dentro disto vai ser capturado e colocado em um grupo
    - ```(?:...)``` - Agrupa multiplos tokens mas não os captura
    - ```|``` - Funciona como um operador OR

- Lookahead/Lookbehind
    - ```(?=...)``` - Positive lookahead: Asserts that the given pattern can be matched ahead.
    - ```(?!...)``` - Negative lookahead: Asserts that the given pattern cannot be matched ahead.
    - ```(?<=...)``` - Positive lookbehind: Asserts that the given pattern can be matched behind.
    - ```(?<!...)``` - Negative lookbehind: Asserts that the given pattern cannot be matched behind.

- Caratéres especiais
    - ```\n``` - Matches a newline character.
    - ```\t``` - Matches a tab character.
    - ```\r``` - Matches a carriage return character.
    - ```\b``` - Matches a word boundary.
    - ```\B``` - Matches a non-word boundary.


- Flags/modificadores
    - ```i``` || `re.IGNORECASE` - Case-insensitive matching.
    - ```g``` - Global matching (find all matches, not just the first one).
    - ```m``` - Multiline mode: `^` and `$` match the start and end of each line.
    - ```s``` - Single-line mode: `.` matches newline characters as well.
    - ```u``` - Unicode mode: Treat the pattern as a sequence of Unicode code points.
    - ```y``` - Sticky mode: Matches only from the index indicated by the `lastIndex` property.
    
- Funções úteis
    - `re.search(pattern, string[, flags])`
    - `re.findall(pattern, string[, flags])`
    - `re.sub(pattern, replacement, string, count = 0)`
    - `re.split(pattern, string, maxsplit = 0)`
    - ``
    - ``
