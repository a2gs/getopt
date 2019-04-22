/*
 * Andre Augusto Giannotti Scota Tool Box Library.
 *
 * MIT License
 *
 */


/*
 * dump.c
 * This file implement the dump buffer function.
 *
 *
 *  Who     | When       | What
 *  --------+------------+----------------------------
 *   a2gs   | 2005 06 30 | Creation v0.1
 */


/* *** INCLUDES *** */
	#include <getopt.h>
	#include <strings.h>
	#include <ctype.h>


/* *** DEFINES AND LOCAL DATA TYPE DEFINATION *** */


/* *** LOCAL PROTOTYPES *** */


/* *** EXTERNS / LOCAL GLOBALS *** */


/* ------------------------------------------------------------------------------------------- */


/* int a2gs_ToolBox_GetShortOpt(int argc, char **argv, a2gs_ToolBox_GetShortOptCTX_t *pr)
 *
 * Get parameters (and sub parameters) from argv[][]  simplest than Unix getopt().
 *
 * INPUT:
 *  argc - The argc
 *  argv - The argv
 *  pr - A ponter to preallocated (and started) a2gs_ToolBox_GetShortOptCTX_t
 * OUTPUT:
 *  The option letter or some of defines:
 *    a2gs_ToolBox_GetShortOpt_NO_PARAM           - No one parameters was wrote into line command
 *    a2gs_ToolBox_GetShortOpt_BAD_LINE           - Unknow/impossible to format line
 *    a2gs_ToolBox_GetShortOpt_NO_MORE_PARAMS     - End especified parameters. Need re-start.
 *    a2gs_ToolBox_GetShortOpt_NO_A_OPT_BUT_A_STR - The present parameter is a text, not a parameters like: -x
 */
int a2gs_ToolBox_GetShortOpt(int argc, char *argv[], a2gs_ToolBox_GetShortOptCTX_t *pr)
{
	if(argc == 1) /* Nenhum parametro */
		return(A2GS_TOOLBOX_GETSHORTOPT_NO_PARAM);

	if(pr->count >= argc){ /* Nao ha mais parametros */
		pr->opt = 0;
		pr->optParam[0] = '\0';
		return(A2GS_TOOLBOX_GETSHORTOPT_NO_MORE_PARAMS);
	}

	/* Se for um parametro na forma -x */
	if((argv[pr->count][0] == '-') && (isalnum(argv[pr->count][1]))){

		pr->opt = argv[pr->count][1];
		pr->count++;

		/* Se existir e se o proximo item da matrix **argv nao iniciar com '-',
		 * eh um sub parametro (string) do parametro capturado acima. Ex:
		 * program -x sub_param_text
		 */
		if((argv[pr->count] != NULL) && (argv[pr->count][0] != '-')){
			strncpy(pr->optParam, argv[pr->count], A2GS_TOOLBOX_GETSHORTOPT_SIZE_MAX_SUBPARAM);
			pr->count++;
		}else pr->optParam[0] = '\0'; /* Nao foi definido um sub parametro */

		return(pr->opt);
	}

	/* Nao eh um parametro na forma -x e sim uma string solta */
	if(argv[pr->count][0] != '\0'){
		pr->opt = 0;
		strncpy(pr->optParam, argv[pr->count], A2GS_TOOLBOX_GETSHORTOPT_SIZE_MAX_SUBPARAM);
		pr->count++;
		return(A2GS_TOOLBOX_GETSHORTOPT_NO_A_OPT_BUT_A_STR);
	}

	return(A2GS_TOOLBOX_GETSHORTOPT_BAD_LINE); /* Error na formatacao da linha */
}


/* void a2gs_ToolBox_StratParam(a2gs_ToolBox_GetShortOptCTX_t *pr)
 *
 * Start a preallocated a2gs_ToolBox_GetShortOptCTX_t variable.
 *
 * INPUT:
 *  pr - A ponter to preallocated a2gs_ToolBox_GetShortOptCTX_t
 * OUTPUT:
 *  None
 */
void a2gs_ToolBox_StratParam(a2gs_ToolBox_GetShortOptCTX_t *pr)
{
	memset(pr, 0, sizeof(a2gs_ToolBox_GetShortOptCTX_t));
	pr->count = 1;
}
