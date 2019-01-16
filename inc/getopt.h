#ifndef __A2GS_TOOLBOX_GETOPT_H__
#define __A2GS_TOOLBOX_GETOPT_H__


/* *** INCLUDES *** */


/* *** DEFINES *** */
	#define A2GS_TOOLBOX_GETSHORTOPT_NO_PARAM           -1
	#define A2GS_TOOLBOX_GETSHORTOPT_BAD_LINE           -2
	#define A2GS_TOOLBOX_GETSHORTOPT_NO_MORE_PARAMS     -3
	#define A2GS_TOOLBOX_GETSHORTOPT_NO_A_OPT_BUT_A_STR -4
	#define A2GS_TOOLBOX_GETSHORTOPT_SIZE_MAX_SUBPARAM  1024


/* *** DATA TYPES *** */
	typedef struct _a2gs_ToolBox_GetShortOptCTX_t{
		int count;
		int opt;
		char optParam[A2GS_TOOLBOX_GETSHORTOPT_SIZE_MAX_SUBPARAM + 1];
	}a2gs_ToolBox_GetShortOptCTX_t;


/* *** INTERFACES / PROTOTYPES *** */
	/* void a2gs_ToolBox_StratParam(a2gs_ToolBox_GetShortOptCTX_t *pr){
	 *
	 * Start a preallocated a2gs_ToolBox_GetShortOptCTX_t variable.
	 *
	 * INPUT:
	 *  pr - A ponter to preallocated a2gs_ToolBox_GetShortOptCTX_t
	 * OUTPUT:
	 *  None
	 */
	void a2gs_ToolBox_StratParam(a2gs_ToolBox_GetShortOptCTX_t *pr);

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
	 *    A2GS_TOOLBOX_GETSHORTOPT_NO_PARAM           - No one parameters was wrote into line command
	 *    A2GS_TOOLBOX_GETSHORTOPT_BAD_LINE           - Unknow/impossible to format line
	 *    A2GS_TOOLBOX_GETSHORTOPT_NO_MORE_PARAMS     - End especified parameters. Need re-start.
	 *    A2GS_TOOLBOX_GETSHORTOPT_NO_A_OPT_BUT_A_STR - The present parameter is a text, not a parameters like: -x
	 */
	int a2gs_ToolBox_GetShortOpt(int argc, char **argv, a2gs_ToolBox_GetShortOptCTX_t *pr);


#if 0 /* EXAMPLE. Run as: ./program -a atesta -b btestb ntestn -d dtestd -c */
int main(int argc, char **argv){
   a2gs_ToolBox_GetShortOptCTX_t a;
   int endLoop = 0;

   stratParam(&a);

   do{
      switch(a2gs_ToolBox_GetShortOpt(argc, argv, &a)){
         case 'a':
            printf("Selecionada opcao A com parametro: [%s]\n", a.optParam);
            break;
         case 'b':
            printf("Selecionada opcao B com parametro: [%s]\n", a.optParam);
            break;
         case 'c':
            printf("Selecionada opcao C com parametro: [%s]\n", a.optParam);
            break;
         case NO_MORE_PARAMS:
            printf("Fim dos parametros\n");
            endLoop = 1;
            break;
         case NO_PARAM:
            printf("Nenhum parametro informado\n");
            endLoop = 1;
            break;
         case BAD_LINE:
            printf("Erro na formatacao da linha\n");
            endLoop = 1;
            break;
         case NO_A_OPT_BUT_A_STR:
            printf("Nao eh um parametro, mas uma string: [%s]\n", a.optParam);
            break;
         default:
            printf("Parametro nao definido [%c][%s]\n", x, a.optParam);
            break;
      }
   }while(endLoop != 1);

   return(0);
}
#endif

#endif
