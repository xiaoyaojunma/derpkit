/** \file
 *  This C header file was generated by $ANTLR version 3.2 debian-7ubuntu3
 *
 *     -  From the grammar source file : ../src/css/parser/css3.g
 *     -                            On : 2015-01-02 17:44:08
 *     -                for the parser : css3ParserParser *
 * Editing it, at least manually, is not wise. 
 *
 * C language generator and runtime by Jim Idle, jimi|hereisanat|idle|dotgoeshere|ws.
 *
 *
 * The parser css3Parser has the callable functions (rules) shown below,
 * which will invoke the code for the associated rule in the source grammar
 * assuming that the input stream is pointing to a token/text stream that could begin
 * this rule.
 * 
 * For instance if you call the first (topmost) rule in a parser grammar, you will
 * get the results of a full parse, but calling a rule half way through the grammar will
 * allow you to pass part of a full token stream to the parser, such as for syntax checking
 * in editors and so on.
 *
 * The parser entry points are called indirectly (by function pointer to function) via
 * a parser context typedef pcss3Parser, which is returned from a call to css3ParserNew().
 *
 * The methods in pcss3Parser are  as follows:
 *
 *  - css3Parser_stylesheet_return      pcss3Parser->stylesheet(pcss3Parser)
 *  - css3Parser_charSet_return      pcss3Parser->charSet(pcss3Parser)
 *  - css3Parser_mediums_return      pcss3Parser->mediums(pcss3Parser)
 *  - css3Parser_imports_return      pcss3Parser->imports(pcss3Parser)
 *  - css3Parser_media_return      pcss3Parser->media(pcss3Parser)
 *  - css3Parser_atRule_return      pcss3Parser->atRule(pcss3Parser)
 *  - css3Parser_medium_return      pcss3Parser->medium(pcss3Parser)
 *  - css3Parser_media_expression_return      pcss3Parser->media_expression(pcss3Parser)
 *  - css3Parser_bodylist_return      pcss3Parser->bodylist(pcss3Parser)
 *  - css3Parser_bodyset_return      pcss3Parser->bodyset(pcss3Parser)
 *  - css3Parser_page_return      pcss3Parser->page(pcss3Parser)
 *  - css3Parser_pseudoPage_return      pcss3Parser->pseudoPage(pcss3Parser)
 *  - css3Parser_expr_operator_return      pcss3Parser->expr_operator(pcss3Parser)
 *  - css3Parser_combinator_return      pcss3Parser->combinator(pcss3Parser)
 *  - css3Parser_unaryOperator_return      pcss3Parser->unaryOperator(pcss3Parser)
 *  - css3Parser_property_return      pcss3Parser->property(pcss3Parser)
 *  - css3Parser_ruleSet_return      pcss3Parser->ruleSet(pcss3Parser)
 *  - css3Parser_brace_block_return      pcss3Parser->brace_block(pcss3Parser)
 *  - css3Parser_declarations_return      pcss3Parser->declarations(pcss3Parser)
 *  - css3Parser_selector_return      pcss3Parser->selector(pcss3Parser)
 *  - css3Parser_simpleSelector_return      pcss3Parser->simpleSelector(pcss3Parser)
 *  - css3Parser_esPred_return      pcss3Parser->esPred(pcss3Parser)
 *  - css3Parser_elementSubsequent_return      pcss3Parser->elementSubsequent(pcss3Parser)
 *  - css3Parser_cssClass_return      pcss3Parser->cssClass(pcss3Parser)
 *  - css3Parser_elementName_return      pcss3Parser->elementName(pcss3Parser)
 *  - css3Parser_attribRelate_return      pcss3Parser->attribRelate(pcss3Parser)
 *  - css3Parser_attrib_return      pcss3Parser->attrib(pcss3Parser)
 *  - css3Parser_function_args_return      pcss3Parser->function_args(pcss3Parser)
 *  - css3Parser_pseudo_return      pcss3Parser->pseudo(pcss3Parser)
 *  - css3Parser_declaration_return      pcss3Parser->declaration(pcss3Parser)
 *  - css3Parser_prio_return      pcss3Parser->prio(pcss3Parser)
 *  - css3Parser_expr_return      pcss3Parser->expr(pcss3Parser)
 *  - css3Parser_red_expr_return      pcss3Parser->red_expr(pcss3Parser)
 *  - css3Parser_red_term_return      pcss3Parser->red_term(pcss3Parser)
 *  - css3Parser_term_return      pcss3Parser->term(pcss3Parser)
 *
 * The return type for any particular rule is of course determined by the source
 * grammar file.
 */
// [The "BSD licence"]
// Copyright (c) 2005-2009 Jim Idle, Temporal Wave LLC
// http://www.temporal-wave.com
// http://www.linkedin.com/in/jimidle
//
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions
// are met:
// 1. Redistributions of source code must retain the above copyright
//    notice, this list of conditions and the following disclaimer.
// 2. Redistributions in binary form must reproduce the above copyright
//    notice, this list of conditions and the following disclaimer in the
//    documentation and/or other materials provided with the distribution.
// 3. The name of the author may not be used to endorse or promote products
//    derived from this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
// IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
// OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
// IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
// INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
// NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
// THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#ifndef	_css3Parser_H
#define _css3Parser_H
/* =============================================================================
 * Standard antlr3 C runtime definitions
 */
#include    <antlr3.h>

/* End of standard antlr 3 runtime definitions
 * =============================================================================
 */
 
#ifdef __cplusplus
extern "C" {
#endif

// Forward declare the context typedef so that we can use it before it is
// properly defined. Delegators and delegates (from import statements) are
// interdependent and their context structures contain pointers to each other
// C only allows such things to be declared if you pre-declare the typedef.
//
typedef struct css3Parser_Ctx_struct css3Parser, * pcss3Parser;



#ifdef	ANTLR3_WINDOWS
// Disable: Unreferenced parameter,							- Rules with parameters that are not used
//          constant conditional,							- ANTLR realizes that a prediction is always true (synpred usually)
//          initialized but unused variable					- tree rewrite variables declared but not needed
//          Unreferenced local variable						- lexer rule declares but does not always use _type
//          potentially unitialized variable used			- retval always returned from a rule 
//			unreferenced local function has been removed	- susually getTokenNames or freeScope, they can go without warnigns
//
// These are only really displayed at warning level /W4 but that is the code ideal I am aiming at
// and the codegen must generate some of these warnings by necessity, apart from 4100, which is
// usually generated when a parser rule is given a parameter that it does not use. Mostly though
// this is a matter of orthogonality hence I disable that one.
//
#pragma warning( disable : 4100 )
#pragma warning( disable : 4101 )
#pragma warning( disable : 4127 )
#pragma warning( disable : 4189 )
#pragma warning( disable : 4505 )
#pragma warning( disable : 4701 )
#endif

/* ========================
 * BACKTRACKING IS ENABLED
 * ========================
 */
typedef struct css3Parser_stylesheet_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;
   
}
    css3Parser_stylesheet_return;

typedef struct css3Parser_charSet_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;
   
}
    css3Parser_charSet_return;

typedef struct css3Parser_mediums_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;
   
}
    css3Parser_mediums_return;

typedef struct css3Parser_imports_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;
   
}
    css3Parser_imports_return;

typedef struct css3Parser_media_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;
   
}
    css3Parser_media_return;

typedef struct css3Parser_atRule_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;
   
}
    css3Parser_atRule_return;

typedef struct css3Parser_medium_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;
   
}
    css3Parser_medium_return;

typedef struct css3Parser_media_expression_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;
   
}
    css3Parser_media_expression_return;

typedef struct css3Parser_bodylist_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;
   
}
    css3Parser_bodylist_return;

typedef struct css3Parser_bodyset_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;
   
}
    css3Parser_bodyset_return;

typedef struct css3Parser_page_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;
   
}
    css3Parser_page_return;

typedef struct css3Parser_pseudoPage_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;
   
}
    css3Parser_pseudoPage_return;

typedef struct css3Parser_expr_operator_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;
   
}
    css3Parser_expr_operator_return;

typedef struct css3Parser_combinator_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;
   
}
    css3Parser_combinator_return;

typedef struct css3Parser_unaryOperator_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;
   
}
    css3Parser_unaryOperator_return;

typedef struct css3Parser_property_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;
   
}
    css3Parser_property_return;

typedef struct css3Parser_ruleSet_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;
   
}
    css3Parser_ruleSet_return;

typedef struct css3Parser_brace_block_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;
   
}
    css3Parser_brace_block_return;

typedef struct css3Parser_declarations_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;
   
}
    css3Parser_declarations_return;

typedef struct css3Parser_selector_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;
   
}
    css3Parser_selector_return;

typedef struct css3Parser_simpleSelector_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;
   
}
    css3Parser_simpleSelector_return;

typedef struct css3Parser_esPred_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;
   
}
    css3Parser_esPred_return;

typedef struct css3Parser_elementSubsequent_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;
   
}
    css3Parser_elementSubsequent_return;

typedef struct css3Parser_cssClass_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;
   
}
    css3Parser_cssClass_return;

typedef struct css3Parser_elementName_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;
   
}
    css3Parser_elementName_return;

typedef struct css3Parser_attribRelate_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;
   
}
    css3Parser_attribRelate_return;

typedef struct css3Parser_attrib_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;
   
}
    css3Parser_attrib_return;

typedef struct css3Parser_function_args_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;
   
}
    css3Parser_function_args_return;

typedef struct css3Parser_pseudo_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;
   
}
    css3Parser_pseudo_return;

typedef struct css3Parser_declaration_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;
   
}
    css3Parser_declaration_return;

typedef struct css3Parser_prio_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;
   
}
    css3Parser_prio_return;

typedef struct css3Parser_expr_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;
   
}
    css3Parser_expr_return;

typedef struct css3Parser_red_expr_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;
   
}
    css3Parser_red_expr_return;

typedef struct css3Parser_red_term_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;
   
}
    css3Parser_red_term_return;

typedef struct css3Parser_term_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;
   
}
    css3Parser_term_return;



/** Context tracking structure for css3Parser
 */
struct css3Parser_Ctx_struct
{
    /** Built in ANTLR3 context tracker contains all the generic elements
     *  required for context tracking.
     */
    pANTLR3_PARSER   pParser;


     css3Parser_stylesheet_return (*stylesheet)	(struct css3Parser_Ctx_struct * ctx);
     css3Parser_charSet_return (*charSet)	(struct css3Parser_Ctx_struct * ctx);
     css3Parser_mediums_return (*mediums)	(struct css3Parser_Ctx_struct * ctx);
     css3Parser_imports_return (*imports)	(struct css3Parser_Ctx_struct * ctx);
     css3Parser_media_return (*media)	(struct css3Parser_Ctx_struct * ctx);
     css3Parser_atRule_return (*atRule)	(struct css3Parser_Ctx_struct * ctx);
     css3Parser_medium_return (*medium)	(struct css3Parser_Ctx_struct * ctx);
     css3Parser_media_expression_return (*media_expression)	(struct css3Parser_Ctx_struct * ctx);
     css3Parser_bodylist_return (*bodylist)	(struct css3Parser_Ctx_struct * ctx);
     css3Parser_bodyset_return (*bodyset)	(struct css3Parser_Ctx_struct * ctx);
     css3Parser_page_return (*page)	(struct css3Parser_Ctx_struct * ctx);
     css3Parser_pseudoPage_return (*pseudoPage)	(struct css3Parser_Ctx_struct * ctx);
     css3Parser_expr_operator_return (*expr_operator)	(struct css3Parser_Ctx_struct * ctx);
     css3Parser_combinator_return (*combinator)	(struct css3Parser_Ctx_struct * ctx);
     css3Parser_unaryOperator_return (*unaryOperator)	(struct css3Parser_Ctx_struct * ctx);
     css3Parser_property_return (*property)	(struct css3Parser_Ctx_struct * ctx);
     css3Parser_ruleSet_return (*ruleSet)	(struct css3Parser_Ctx_struct * ctx);
     css3Parser_brace_block_return (*brace_block)	(struct css3Parser_Ctx_struct * ctx);
     css3Parser_declarations_return (*declarations)	(struct css3Parser_Ctx_struct * ctx);
     css3Parser_selector_return (*selector)	(struct css3Parser_Ctx_struct * ctx);
     css3Parser_simpleSelector_return (*simpleSelector)	(struct css3Parser_Ctx_struct * ctx);
     css3Parser_esPred_return (*esPred)	(struct css3Parser_Ctx_struct * ctx);
     css3Parser_elementSubsequent_return (*elementSubsequent)	(struct css3Parser_Ctx_struct * ctx);
     css3Parser_cssClass_return (*cssClass)	(struct css3Parser_Ctx_struct * ctx);
     css3Parser_elementName_return (*elementName)	(struct css3Parser_Ctx_struct * ctx);
     css3Parser_attribRelate_return (*attribRelate)	(struct css3Parser_Ctx_struct * ctx);
     css3Parser_attrib_return (*attrib)	(struct css3Parser_Ctx_struct * ctx);
     css3Parser_function_args_return (*function_args)	(struct css3Parser_Ctx_struct * ctx);
     css3Parser_pseudo_return (*pseudo)	(struct css3Parser_Ctx_struct * ctx);
     css3Parser_declaration_return (*declaration)	(struct css3Parser_Ctx_struct * ctx);
     css3Parser_prio_return (*prio)	(struct css3Parser_Ctx_struct * ctx);
     css3Parser_expr_return (*expr)	(struct css3Parser_Ctx_struct * ctx);
     css3Parser_red_expr_return (*red_expr)	(struct css3Parser_Ctx_struct * ctx);
     css3Parser_red_term_return (*red_term)	(struct css3Parser_Ctx_struct * ctx);
     css3Parser_term_return (*term)	(struct css3Parser_Ctx_struct * ctx);
     ANTLR3_BOOLEAN (*synpred1_css3)	(struct css3Parser_Ctx_struct * ctx);
     ANTLR3_BOOLEAN (*synpred2_css3)	(struct css3Parser_Ctx_struct * ctx);
    // Delegated rules
    const char * (*getGrammarFileName)();
    void	    (*free)   (struct css3Parser_Ctx_struct * ctx);
    /* @headerFile.members() */
    pANTLR3_BASE_TREE_ADAPTOR	adaptor;
    pANTLR3_VECTOR_FACTORY		vectors;
    /* End @headerFile.members() */
};

// Function protoypes for the constructor functions that external translation units
// such as delegators and delegates may wish to call.
//
ANTLR3_API pcss3Parser css3ParserNew         (pANTLR3_COMMON_TOKEN_STREAM instream);
ANTLR3_API pcss3Parser css3ParserNewSSD      (pANTLR3_COMMON_TOKEN_STREAM instream, pANTLR3_RECOGNIZER_SHARED_STATE state);

/** Symbolic definitions of all the tokens that the parser will work with.
 * \{
 *
 * Antlr will define EOF, but we can't use that as it it is too common in
 * in C header files and that would be confusing. There is no way to filter this out at the moment
 * so we just undef it here for now. That isn't the value we get back from C recognizers
 * anyway. We are looking for ANTLR3_TOKEN_EOF.
 */
#ifdef	EOF
#undef	EOF
#endif
#ifdef	Tokens
#undef	Tokens
#endif 
#define CSS_IDENT      37
#define CSS_ENDSWITH      20
#define CSS_CONTAINS      18
#define CSS_B      69
#define CSS_C      70
#define CSS_A      68
#define CSS_SELECTOR_UNIT      13
#define CSS_J      77
#define CSS_K      78
#define CSS_H      75
#define CSS_I      76
#define CSS_TILDE      47
#define CSS_LBRACKET      51
#define CSS_F      73
#define CSS_G      74
#define CSS_D      71
#define CSS_E      72
#define CSS_S      86
#define CSS_RBRACKET      56
#define CSS_R      85
#define CSS_Q      84
#define CSS_P      83
#define CSS_O      82
#define CSS_N      81
#define CSS_M      80
#define CSS_L      79
#define CSS_COMMA      31
#define CSS_Z      93
#define EOF      -1
#define CSS_SELECTOR      12
#define CSS_Y      92
#define CSS_X      91
#define CSS_STAREQ      53
#define CSS_W      90
#define CSS_V      89
#define CSS_U      88
#define CSS_T      87
#define CSS_GREATER      46
#define CSS_CHARSET_SYM      28
#define CSS_STAR      52
#define CSS_NMSTART      65
#define CSS_ATTRIB      15
#define CSS_IMPORTANT      27
#define CSS_URL      67
#define CSS_URI      33
#define T__99      99
#define CSS_PSEUDO      16
#define CSS_CLASS      25
#define CSS_EQUAL      17
#define CSS_HASH      49
#define CSS_TAG      23
#define CSS_CIREQ      54
#define CSS_CDC      97
#define WS      38
#define CSS_AT_RULE      9
#define CSS_CDO      96
#define CSS_PAGE      10
#define CSS_NUMBER      58
#define CSS_SL_COMMENT      95
#define CSS_LPAREN      39
#define CSS_NONASCII      62
#define CSS_DOT      50
#define CSS_RBRACE      36
#define CSS_LBRACE      35
#define CSS_NMCHAR      66
#define CSS_PAGE_SYM      42
#define CSS_WHITESPACE      60
#define CSS_SOLIDUS      43
#define CSS_SEMI      30
#define CSS_STRING      29
#define CSS_UNICODE      63
#define CSS_STARTSWITH      19
#define CSS_HEXCHAR      61
#define CSS_HEXNUM      59
#define CSS_DOLLAREQ      55
#define CSS_ID      24
#define CSS_PROPERTY      21
#define CSS_NL      98
#define CSS_IMPORT      4
#define CSS_IMPORT_SYM      32
#define CSS_ESCAPE      64
#define CSS_ANY      26
#define CSS_COMMENT      94
#define T__100      100
#define CSS_CHARSET      6
#define CSS_IMPORTANT_SYM      57
#define CSS_MINUS      48
#define CSS_COLON      40
#define CSS_PLUS      45
#define CSS_MEDIA_SYM      34
#define CSS_ARGS      22
#define CSS_SELECTOR_COMBINATOR      14
#define CSS_RPAREN      41
#define CSS_RULE      11
#define CSS_MEDIUMS      7
#define CSS_MEDIA      5
#define CSS_MEDIA_EXPR      8
#define CSS_OPEQ      44
#ifdef	EOF
#undef	EOF
#define	EOF	ANTLR3_TOKEN_EOF
#endif

#ifndef TOKENSOURCE
#define TOKENSOURCE(lxr) lxr->pLexer->rec->state->tokSource
#endif

/* End of token definitions for css3Parser
 * =============================================================================
 */
/** \} */

#ifdef __cplusplus
}
#endif

#endif

/* END - Note:Keep extra line feed to satisfy UNIX systems */
