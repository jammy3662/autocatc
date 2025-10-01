## autocatc
#### compiler for Cat(lang) based on formal grammar

Cat uses ANTLR to generate a lexer and parser for an EBNF grammar. The resulting parser is deterministic and requires no backtracking or duplication.

At first, Bison was used to generate a parser, with Flex creating the corresponding lexer. However, Bison's LALR(1) parsing became counterproductive with the level of required verbosity for several common patterns in the grammar. It also failed to disambiguate several determinstic patterns that an ALL(*) parser can handle just fine, which made GLR parsing a requirement for this grammar under Bison. Considering that GLR parsing is neither deterministic nor intelligent when encountering ambiguities (creating spurious forks), it made far more sense to generate the parser from an EBNF grammar, which can succinctly and precisely model the entire language.

This project of a generated compiler started during the development of `minicatc`, a hand-written Cat compiler which was becoming increasingly messy and impractical to write manually. It **stands to reason** that if you aren't writing a more efficient algorithm than an ALL(*) parser engine, it's absolutely, truly better to use a parser generator.