// CSS_A complete lexer and grammar for CSS 2.1 as defined by the
// W3 specification.
//
// This grammar is free to use providing you retain everyhting in this header comment
// section.
//
// Author      : Jim Idle, Temporal Wave CSS_LLC & Andreas Tarandi, Frobnicators
// Contact     : jimi@temporal-wave.com
// Website     : http://www.temporal-wave.com
// License     : CSS_ANTLR Free CSS_BSD License
//
// Please visit our Web site at http://www.temporal-wave.com and try our commercial
// parsers for CSS_SQL, CSS_C#, CSS_VB.Net and more.
//
// This grammar was (heavily) modified for CSS 3 by Andreas Tarandi for frobnicators derpkit:
// https://github.com/frobnicators/derpkit
//
// This grammar is free to use providing you retain everything in this header comment
// section.
//
grammar css3;
options {
       output=AST;
       language=C;
}

tokens {
	CSS_IMPORT;
	CSS_MEDIA;
	CSS_CHARSET;
	CSS_MEDIUMS;
	CSS_MEDIA_EXPR;
	CSS_AT_RULE;
	CSS_PAGE;
	CSS_RULE;
	CSS_SELECTOR;
	CSS_SELECTOR_UNIT;
	CSS_SELECTOR_COMBINATOR;
	CSS_ATTRIB;
	CSS_PSEUDO;
	CSS_EQUAL;
	CSS_EXPR;
	CSS_EXPROP;
	CSS_CONTAINS;
	CSS_SELECTOR;
	CSS_STARTSWITH;
	CSS_ENDSWITH;
	CSS_PROPERTY;
	CSS_NUMTERM;
	CSS_HEXCOLOR;
	CSS_ARG;
	CSS_ARGS;
	CSS_TAG;
	CSS_ID;
	CSS_CLASS;
	CSS_ANY;
	CSS_IMPORTANT;
}


// -------------
// Main rule.   This is the main entry rule for the parser, the top level
//              grammar rule.
//
// CSS_A style sheet consists of an optional character set specification, an optional series
// of imports, and then the main body of style rules.
//
stylesheet
    :   charSet
        imports*
        bodylist
		WS?
		EOF!
    ;

// -----------------
// Character set.   Picks up the user specified character set, should it be present.
//
charSet
    :   CSS_CHARSET_SYM CSS_STRING CSS_SEMI -> ^( CSS_CHARSET CSS_STRING )
    |
    ;


mediums
	: medium (CSS_COMMA medium)* -> ^(CSS_MEDIUMS medium+)
	;

// ---------
// Import.  Location of an external style sheet to include in the ruleset.
//
imports
    :   CSS_IMPORT_SYM s=(CSS_STRING|CSS_URI) mediums? CSS_SEMI
		-> ^(CSS_IMPORT $s mediums*)
    ;

// ---------
// Media.   Introduce a set of rules that are to be used if the consumer indicates
//          it belongs to the signified medium.
//
media
    : CSS_MEDIA_SYM mediums
	  CSS_LBRACE
		bodyset
	  CSS_RBRACE
	  -> ^(CSS_MEDIA mediums bodyset)
    ;

atRule
	: '@' CSS_IDENT
	  (CSS_COMMA selector )* brace_block
	  -> ^(CSS_AT_RULE CSS_IDENT selector* brace_block)
	;
// ---------
// Medium.  The name of a medim that are particulare set of rules applies to.
//
medium
    : CSS_IDENT WS? s=CSS_IDENT? ( 'and' WS? media_expression )* -> CSS_IDENT $s media_expression*
	| media_expression WS? ( 'and' WS? media_expression WS? )* -> media_expression+
    ;

media_expression
	: CSS_LPAREN CSS_IDENT WS? ( CSS_COLON WS? expr )? CSS_RPAREN
	-> ^(CSS_MEDIA_EXPR CSS_IDENT expr)
	;

bodylist
    : bodyset*
    ;

bodyset
    : ruleSet
	| atRule
    | media
    | page
    ;

page
    : CSS_PAGE_SYM pseudoPage?
		CSS_LBRACE
		  bodyset
		CSS_RBRACE
		-> ^(CSS_PAGE pseudoPage? bodyset)
    ;

pseudoPage
    : CSS_COLON CSS_IDENT
    ;

expr_operator
    : CSS_SOLIDUS
	| CSS_MINUS
	| CSS_PLUS
    | WS
    ;

combinator
    : CSS_PLUS
    | CSS_GREATER
	| CSS_TILDE
    | WS
    ;

property
    : CSS_IDENT
    ;

ruleSet
    : selector (CSS_COMMA selector)* brace_block
	-> ^(CSS_RULE selector+ brace_block)
    ;

brace_block
	: CSS_LBRACE!
		declarations?
	  CSS_RBRACE!
	;

declarations
	: WS? declaration CSS_SEMI (WS? declaration CSS_SEMI)*
	-> declaration+
	;

selector
    : WS? simpleSelector (combinator simpleSelector)*
	-> ^(CSS_SELECTOR ^(CSS_SELECTOR_UNIT simpleSelector) (^(CSS_SELECTOR_COMBINATOR combinator) ^(CSS_SELECTOR_UNIT simpleSelector))* )
    ;

simpleSelector
    : elementName
        ((esPred)=>elementSubsequent)*

    | ((esPred)=>elementSubsequent)+
    ;

esPred
    : CSS_HASH | CSS_DOT | CSS_LBRACKET | CSS_COLON
    ;

elementSubsequent
    : CSS_HASH CSS_IDENT -> ^(CSS_ID CSS_IDENT)
    | cssClass
    | attrib
    | pseudo
    ;

cssClass
    : CSS_DOT CSS_IDENT
	-> ^(CSS_CLASS CSS_IDENT)
    ;

elementName
    : CSS_IDENT -> ^(CSS_TAG CSS_IDENT)
    | CSS_STAR -> ^(CSS_ANY CSS_STAR)
    ;


attribRelate
  : CSS_OPEQ -> CSS_EQUAL
  | CSS_STAREQ -> CSS_CONTAINS
  | CSS_CIREQ -> CSS_STARTSWITH
  | CSS_DOLLAREQ -> CSS_ENDSWITH
;

attrib
    : CSS_LBRACKET

        CSS_IDENT

            (
				attribRelate
                ( s=CSS_STRING | i=CSS_IDENT )
            )?

      CSS_RBRACKET
	  -> ^(CSS_ATTRIB CSS_IDENT (attribRelate $s $i )? )
;

function_args
	: CSS_LPAREN
		(
			(
				red_expr
				(
					CSS_COMMA
					WS?
					red_expr
				)*
			)
			|
			selector WS?
		)
	CSS_RPAREN
	-> ^(CSS_ARGS ^(CSS_ARG red_expr)+ selector)
;

pseudo
    : CSS_COLON CSS_COLON? CSS_IDENT function_args? -> ^(CSS_PSEUDO CSS_IDENT function_args? )
    ;

declaration
    : property WS? CSS_COLON WS? expr WS? (CSS_COMMA WS? expr WS?)* prio?
	-> ^(CSS_PROPERTY property expr+ prio?)
    ;

prio
    : CSS_IMPORTANT_SYM
	-> CSS_IMPORTANT
    ;

expr
    : term (expr_operator term)* -> ^(CSS_EXPR term (^(CSS_EXPROP expr_operator) term)*)
    ;

// Reduced expression, no colors or functions
red_expr
	: red_term WS? (expr_operator red_term WS?)* -> red_term (^(CSS_EXPROP expr_operator) red_term)*
	;

// Reduced term
red_term
    :
		(
			CSS_NUMBER
			| CSS_HEXNUM
		)
	  -> ^(CSS_NUMTERM CSS_NUMBER CSS_HEXNUM )
    | CSS_STRING
    | CSS_URI
    ;

term
	: red_term
	| CSS_IDENT function_args? -> ^(CSS_IDENT function_args?)
	| CSS_HASH (CSS_HEXNUM | CSS_IDENT) -> ^(CSS_HEXCOLOR CSS_HEXNUM CSS_IDENT);

// ==============================================================
// CSS_LEXER
//
// The lexer follows the normative section of CSS_WWW standard as closely
// as it can. For instance, where the CSS_ANTLR lexer returns a token that
// is unambiguous for both CSS_ANTLR and lex (the standard defines tokens
// in lex notation), then the token names are equivalent.
//
// Note however that lex has a match order defined as top to bottom
// with longest match first. This results in a fairly inefficent, match,
// CSS_REJECT, match CSS_REJECT set of operations. CSS_ANTLR lexer grammars are actaully
// CSS_LL grammars (and hence CSS_LL recognizers), which means that we must
// specifically disambiguate longest matches and so on, when the lex
// like normative grammar results in ambiguities as far as CSS_ANTLR is concerned.
//
// This means that some tokens will either be combined compared to the
// normative spec, and the paresr will recognize them for what they are.
// In this case, the token will named as XXX_YYY where CSS_XXX and CSS_YYY are the
// token names used in the specification.
//
// Lex style macro names used in the spec may sometimes be used (in upper case
// version) as fragment rules in this grammar. However CSS_ANTLR fragment rules
// are not quite the same as lex macros, in that they generate actual
// methods in the recognizer class, and so may not be as effecient. In
// some cases then, the macro contents are embedded. Annotation indicate when
// this is the case.
//
// See comments in the rules for specific details.
// --------------------------------------------------------------
//
// CSS_N.CSS_B. CSS 2.1 is defined as case insensitive, but because each character
//      is allowed to be written as in escaped form we basically define each
//      character as a fragment and reuse it in all other rules.
// ==============================================================


// --------------------------------------------------------------
// Define all the fragments of the lexer. These rules neither recognize
// nor create tokens, but must be called from non-fragment rules, which
// do create tokens, using these fragments to either purely define the
// token number, or by calling them to match a certain portion of
// the token string.
//

fragment	CSS_WHITESPACE	: (' '|'\t')+;

fragment    CSS_HEXCHAR     : ('a'..'f'|'A'..'F'|'0'..'9')  ;

fragment    CSS_NONASCII    : '\u0080'..'\uFFFF'            ;   // CSS_NB: Upper bound should be \u4177777

fragment    CSS_UNICODE     : '\\' CSS_HEXCHAR
                                (CSS_HEXCHAR
                                    (CSS_HEXCHAR
                                        (CSS_HEXCHAR
                                            (CSS_HEXCHAR CSS_HEXCHAR?)?
                                        )?
                                    )?
                                )?
                                ('\r'|'\n'|'\t'|'\f'|' ')*  ;

fragment    CSS_ESCAPE      : CSS_UNICODE | '\\' ~('\r'|'\n'|'\f'|CSS_HEXCHAR)  ;

fragment    CSS_NMSTART     : '_'
                        | 'a'..'z'
                        | 'A'..'Z'
                        | CSS_NONASCII
                        | CSS_ESCAPE
                        ;

fragment    CSS_NMCHAR      : '_'
                        | 'a'..'z'
                        | 'A'..'Z'
                        | '0'..'9'
                        | '-'
                        | CSS_NONASCII
                        | CSS_ESCAPE
                        ;

fragment    CSS_URL         : (
                              '['|'!'|'#'|'$'|'%'|'&'|'*'|'-'|'~'
                            | CSS_NONASCII
                            | CSS_ESCAPE
                          )*
                        ;


// Basic Alpha characters in upper, lower and escaped form. Note that
// whitespace and newlines are unimportant even within keywords. We do not
// however call a further fragment rule to consume these characters for
// reasons of performance - the rules are still eminently readable.
//
fragment    CSS_A   :   ('a'|'A') ('\r'|'\n'|'\t'|'\f'|' ')*
                |   '\\' ('0' ('0' ('0' '0'?)?)?)? ('4'|'6')'1'
                ;
fragment    CSS_B   :   ('b'|'B') ('\r'|'\n'|'\t'|'\f'|' ')*
                |   '\\' ('0' ('0' ('0' '0'?)?)?)? ('4'|'6')'2'
                ;
fragment    CSS_C   :   ('c'|'C') ('\r'|'\n'|'\t'|'\f'|' ')*
                |   '\\' ('0' ('0' ('0' '0'?)?)?)? ('4'|'6')'3'
                ;
fragment    CSS_D   :   ('d'|'D') ('\r'|'\n'|'\t'|'\f'|' ')*
                |   '\\' ('0' ('0' ('0' '0'?)?)?)? ('4'|'6')'4'
                ;
fragment    CSS_E   :   ('e'|'E') ('\r'|'\n'|'\t'|'\f'|' ')*
                |   '\\' ('0' ('0' ('0' '0'?)?)?)? ('4'|'6')'5'
                ;
fragment    CSS_F   :   ('f'|'F') ('\r'|'\n'|'\t'|'\f'|' ')*
                |   '\\' ('0' ('0' ('0' '0'?)?)?)? ('4'|'6')'6'
                ;
fragment    CSS_G   :   ('g'|'G') ('\r'|'\n'|'\t'|'\f'|' ')*
                |   '\\'
                        (
                              'g'
                            | 'G'
                            | ('0' ('0' ('0' '0'?)?)?)? ('4'|'6')'7'
                        )
                ;
fragment    CSS_H   :   ('h'|'H') ('\r'|'\n'|'\t'|'\f'|' ')*
                | '\\'
                        (
                              'h'
                            | 'H'
                            | ('0' ('0' ('0' '0'?)?)?)? ('4'|'6')'8'
                        )
                ;
fragment    CSS_I   :   ('i'|'I') ('\r'|'\n'|'\t'|'\f'|' ')*
                | '\\'
                        (
                              'i'
                            | 'I'
                            | ('0' ('0' ('0' '0'?)?)?)? ('4'|'6')'9'
                        )
                ;
fragment    CSS_J   :   ('j'|'J') ('\r'|'\n'|'\t'|'\f'|' ')*
                | '\\'
                        (
                              'j'
                            | 'J'
                            | ('0' ('0' ('0' '0'?)?)?)? ('4'|'6')('A'|'a')
                        )
                ;
fragment    CSS_K   :   ('k'|'K') ('\r'|'\n'|'\t'|'\f'|' ')*
                | '\\'
                        (
                              'k'
                            | 'K'
                            | ('0' ('0' ('0' '0'?)?)?)? ('4'|'6')('B'|'b')
                        )
                ;
fragment    CSS_L   :   ('l'|'L') ('\r'|'\n'|'\t'|'\f'|' ')*
                | '\\'
                        (
                              'l'
                            | 'L'
                            | ('0' ('0' ('0' '0'?)?)?)? ('4'|'6')('C'|'c')
                        )
                ;
fragment    CSS_M   :   ('m'|'M') ('\r'|'\n'|'\t'|'\f'|' ')*
                | '\\'
                        (
                              'm'
                            | 'M'
                            | ('0' ('0' ('0' '0'?)?)?)? ('4'|'6')('D'|'d')
                        )
                ;
fragment    CSS_N   :   ('n'|'N') ('\r'|'\n'|'\t'|'\f'|' ')*
                | '\\'
                        (
                              'n'
                            | 'N'
                            | ('0' ('0' ('0' '0'?)?)?)? ('4'|'6')('E'|'e')
                        )
                ;
fragment    CSS_O   :   ('o'|'O') ('\r'|'\n'|'\t'|'\f'|' ')*
                | '\\'
                        (
                              'o'
                            | 'O'
                            | ('0' ('0' ('0' '0'?)?)?)? ('4'|'6')('F'|'f')
                        )
                ;
fragment    CSS_P   :   ('p'|'P') ('\r'|'\n'|'\t'|'\f'|' ')*
                | '\\'
                        (
                              'p'
                            | 'P'
                            | ('0' ('0' ('0' '0'?)?)?)? ('5'|'7')('0')
                        )
                ;
fragment    CSS_Q   :   ('q'|'Q') ('\r'|'\n'|'\t'|'\f'|' ')*
                | '\\'
                        (
                              'q'
                            | 'Q'
                            | ('0' ('0' ('0' '0'?)?)?)? ('5'|'7')('1')
                        )
                ;
fragment    CSS_R   :   ('r'|'R') ('\r'|'\n'|'\t'|'\f'|' ')*
                | '\\'
                        (
                              'r'
                            | 'R'
                            | ('0' ('0' ('0' '0'?)?)?)? ('5'|'7')('2')
                        )
                ;
fragment    CSS_S   :   ('s'|'S') ('\r'|'\n'|'\t'|'\f'|' ')*
                | '\\'
                        (
                              's'
                            | 'S'
                            | ('0' ('0' ('0' '0'?)?)?)? ('5'|'7')('3')
                        )
                ;
fragment    CSS_T   :   ('t'|'T') ('\r'|'\n'|'\t'|'\f'|' ')*
                | '\\'
                        (
                              't'
                            | 'T'
                            | ('0' ('0' ('0' '0'?)?)?)? ('5'|'7')('4')
                        )
                ;
fragment    CSS_U   :   ('u'|'U') ('\r'|'\n'|'\t'|'\f'|' ')*
                | '\\'
                        (
                              'u'
                            | 'U'
                            | ('0' ('0' ('0' '0'?)?)?)? ('5'|'7')('5')
                        )
                ;
fragment    CSS_V   :   ('v'|'V') ('\r'|'\n'|'\t'|'\f'|' ')*
                | '\\'
                        (     'v'
                            | 'V'
                            | ('0' ('0' ('0' '0'?)?)?)? ('5'|'7')('6')
                        )
                ;
fragment    CSS_W   :   ('w'|'W') ('\r'|'\n'|'\t'|'\f'|' ')*
                | '\\'
                        (
                              'w'
                            | 'W'
                            | ('0' ('0' ('0' '0'?)?)?)? ('5'|'7')('7')
                        )
                ;
fragment    CSS_X   :   ('x'|'X') ('\r'|'\n'|'\t'|'\f'|' ')*
                | '\\'
                        (
                              'x'
                            | 'X'
                            | ('0' ('0' ('0' '0'?)?)?)? ('5'|'7')('8')
                        )
                ;
fragment    CSS_Y   :   ('y'|'Y') ('\r'|'\n'|'\t'|'\f'|' ')*
                | '\\'
                        (
                              'y'
                            | 'Y'
                            | ('0' ('0' ('0' '0'?)?)?)? ('5'|'7')('9')
                        )
                ;
fragment    CSS_Z   :   ('z'|'Z') ('\r'|'\n'|'\t'|'\f'|' ')*
                | '\\'
                        (
                              'z'
                            | 'Z'
                            | ('0' ('0' ('0' '0'?)?)?)? ('5'|'7')('A'|'a')
                        )
                ;


// -------------
// Comments.    Comments may not be nested, may be multilined and are delimited
//              like CSS_C comments: /* ..... */
//              CSS_COMMENTS are hidden from the parser which simplifies the parser
//              grammar a lot.
//
CSS_COMMENT         : '/*' ( options { greedy=false; } : .*) '*/'

                    {
                        $channel = 2;   // Comments on channel 2 in case we want to find them
                    }
                ;

CSS_SL_COMMENT
	:	'//'
		(~('\n'|'\r'))* ('\n'|'\r'('\n')?)
		{$channel=2;}
	;

// ---------------------
// CSS_HTML comment open.   CSS_HTML/CSS_XML comments may be placed around style sheets so that they
//                      are hidden from higher scope parsing engines such as CSS_HTML parsers.
//                      They comment open is therfore ignored by the CSS parser and we hide
//                      it from the CSS_ANLTR parser.
//
CSS_CDO             : CSS_WHITESPACE? '<!--' CSS_WHITESPACE?

                    {
                        $channel = 3;   // CSS_CDO on channel 3 in case we want it later
                    }
                ;

// ---------------------
// CSS_HTML comment close.  CSS_HTML/CSS_XML comments may be placed around style sheets so that they
//                      are hidden from higher scope parsing engines such as CSS_HTML parsers.
//                      They comment close is therfore ignored by the CSS parser and we hide
//                      it from the CSS_ANLTR parser.
//
CSS_CDC             : CSS_WHITESPACE? '-->' CSS_WHITESPACE?

                    {
                        $channel = 4;   // CSS_CDC on channel 4 in case we want it later
                    }
                ;

CSS_STAREQ	        : CSS_WHITESPACE? '*=' CSS_WHITESPACE?     ;
CSS_CIREQ			: CSS_WHITESPACE? '^=' CSS_WHITESPACE?     ;
CSS_DOLLAREQ	    : CSS_WHITESPACE? '$=' CSS_WHITESPACE?     ;

CSS_GREATER         : CSS_WHITESPACE? '>' CSS_WHITESPACE?      ;
CSS_LBRACE          : CSS_WHITESPACE? '{' CSS_WHITESPACE?      ;
CSS_RBRACE          : CSS_WHITESPACE? '}' CSS_WHITESPACE?      ;
CSS_LBRACKET        : CSS_WHITESPACE? '[' CSS_WHITESPACE?      ;
CSS_RBRACKET        : CSS_WHITESPACE? ']' CSS_WHITESPACE?      ;
CSS_OPEQ            : CSS_WHITESPACE? '=' CSS_WHITESPACE?      ;
CSS_SEMI            : CSS_WHITESPACE? ';' CSS_WHITESPACE?      ;
CSS_COLON           : ':' ;
CSS_SOLIDUS         : CSS_WHITESPACE? '/' CSS_WHITESPACE?      ;
CSS_MINUS           : CSS_WHITESPACE? '-' CSS_WHITESPACE?      ;
CSS_PLUS            : CSS_WHITESPACE? '+' CSS_WHITESPACE?      ;
CSS_STAR            : CSS_WHITESPACE? '*' CSS_WHITESPACE?      ;
CSS_LPAREN          : CSS_WHITESPACE? '(' CSS_WHITESPACE?      ;
CSS_RPAREN          : CSS_WHITESPACE? ')' CSS_WHITESPACE?      ;
CSS_COMMA           : CSS_WHITESPACE? ',' CSS_WHITESPACE?      ;
CSS_DOT             : '.' ;
CSS_TILDE			: CSS_WHITESPACE? '~' CSS_WHITESPACE?      ;
CSS_HASH            : '#'     ;

// -----------------
// Literal strings. Delimited by either ' or "
//
CSS_STRING          : '\'' ( ~('\n'|'\r'|'\f'|'\'') )* '\''

                | '"' ( ~('\n'|'\r'|'\f'|'"') )* '"'
                ;

// -------------
// Identifier.  Identifier tokens pick up properties names and values
//
CSS_IDENT           : '-'? CSS_NMSTART CSS_NMCHAR*  ;

CSS_HEXNUM			: CSS_HEXCHAR+ ;


CSS_IMPORT_SYM      : '@' CSS_I CSS_M CSS_P CSS_O CSS_R CSS_T       ;
CSS_PAGE_SYM        : '@' CSS_P CSS_A CSS_G CSS_E           ;
CSS_MEDIA_SYM       : '@' CSS_M CSS_E CSS_D CSS_I CSS_A         ;
CSS_CHARSET_SYM     : '@charset '           ;

CSS_IMPORTANT_SYM   : '!' (WS|CSS_COMMENT)* CSS_I CSS_M CSS_P CSS_O CSS_R CSS_T CSS_A CSS_N CSS_T   ;

// TODO: Handle scientific form (ex 10e-2)
CSS_NUMBER
    :   ( '+' | '-') ?
	    (
              '0'..'9'+ ('.' '0'..'9'+)?
            | '.' '0'..'9'+
        )
        (
              (CSS_E (CSS_M|CSS_X))=>
                CSS_E
                (
                      CSS_M
                    | CSS_X
                )
            | (CSS_P(CSS_X|CSS_T|CSS_C))=>
                CSS_P
                (
                      CSS_X
                    | CSS_T
                    | CSS_C
                )
            | (CSS_C CSS_M)=>
                CSS_C CSS_M
            | (CSS_M (CSS_M|CSS_S))=>
                CSS_M
                (
                      CSS_M

                    | CSS_S
                )
            | (CSS_I CSS_N)=>
                CSS_I CSS_N

            | (CSS_D CSS_E CSS_G)=>
                CSS_D CSS_E CSS_G
            | (CSS_R CSS_A CSS_D)=>
                CSS_R CSS_A CSS_D

            | (CSS_S)=>CSS_S

            | (CSS_K? CSS_H CSS_Z)=>
                CSS_K? CSS_H    CSS_Z

            | CSS_IDENT

            | '%'
        ) ?
    ;

// ------------
// url and uri.
// todo: parse better
//
CSS_URI :   CSS_U CSS_R CSS_L
        '('
            ((WS)=>WS)? (CSS_URL|CSS_STRING) WS?
        ')'
    ;

WS			: CSS_WHITESPACE;
CSS_NL      : ('\r' '\n'? | '\n')   { $channel = HIDDEN;    }   ;


// -------------
//  Illegal.    Any other character shoudl not be allowed.
//
