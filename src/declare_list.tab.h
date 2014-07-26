/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_DECLARE_LIST_TAB_H_INCLUDED
# define YY_YY_DECLARE_LIST_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    T_STRING = 258,
    T_RET = 259,
    T_NAMESPACE = 260,
    T_NS_SEPARATOR = 261,
    T_ARRAY = 262,
    T_CLASS = 263,
    T_CLASS_C = 264,
    T_TRAIT_C = 265,
    T_FUNC_C = 266,
    T_METHOD_C = 267,
    T_LINE = 268,
    T_FILE = 269,
    T_DIR = 270,
    T_NS_C = 271,
    T_LNUMBER = 272,
    T_DNUMBER = 273,
    T_CONSTANT_ENCAPSED_STRING = 274,
    T_START_HEREDOC = 275,
    T_END_HEREDOC = 276,
    T_ENCAPSED_AND_WHITESPACE = 277,
    T_DTWO_POINTS = 278,
    T_SL = 279,
    T_SR = 280,
    T_LOGICAL_OR = 281,
    T_LOGICAL_XOR = 282,
    T_LOGICAL_AND = 283,
    T_BOOLEAN_OR = 284,
    T_BOOLEAN_AND = 285,
    T_IS_EQUAL = 286,
    T_IS_NOT_EQUAL = 287,
    T_IS_IDENTICAL = 288,
    T_IS_NOT_IDENTICAL = 289,
    T_IS_SMALLER_OR_EQUAL = 290,
    T_IS_GREATER_OR_EQUAL = 291,
    T_STATIC = 292,
    T_DOUBLE_ARROW = 293,
    T_POW = 294,
    T_END = 295
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 29 "declare_list.y" /* yacc.c:1909  */

	int val;
	float f;
	char *text;

#line 101 "declare_list.tab.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_DECLARE_LIST_TAB_H_INCLUDED  */
