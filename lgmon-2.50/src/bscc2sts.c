/*  Canon Bubble Jet Print Filter.
 *  Copyright CANON INC. 2001-2005
 *  All Rights Reserved.
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

/*
 * bscc2sts.c 
 *
 * bscc2sts library main source.
 *
 * BSCC which is the response from a printer is changed 
 * into the command corresponding to the status monitor.
 */
 
 
/*
 * include necessary headers ...
 */
#include "bscc2sts.h"
#include "commonfunc.h"


/*
 * prototypes ...
 */
static int processofeachmodel(ST_BSCCBUF *p_bscc, bscc2sts_tbl *p_tbl);
static int firstsetsts(char *p_name, output_dev *p_dev, bscc2sts_tbl *p_tbl);
static int parsebscc(char *p_s, ST_BSCCBUF *p_bsccbuf);
static int setbsccsts(char *p, char *p_buf, ST_BSCCBUF *p_bsccbuf);


/*
 * The structure object for BSCC status storing.
 */
ST_BSCCBUF bsccbuf[]={
  {"BST",NULL},
  {"DBS",NULL},
  {"DJS",NULL},
  {"CHD",NULL},
  {"CIL",NULL},
  {"LVR",NULL},
  {"DWS",NULL},
  {"DOC",NULL},
  {"DSC",NULL},
  {"CIR",NULL},
};


int bscc2sts(char *printer, char *bscc, output_dev *Odev, bscc2sts_tbl *Pr_sts)
{
  int i,ret;
  char *p_bscc;

  /* 2 bytes of the beginning which is command length are skipped. */
  bscc+=2;
  if(*bscc == '\0'){
    ret=ERR_BSCCNON;
    return(ret);
  }
  while(1){
    /* init, The structure object for bscc string.*/
    for(i=0; i<MAXBSCCCOM; i++){
      bsccbuf[i].p_bsccsts=NULL;
    }
    memset(Pr_sts, INIT, sizeof(bscc2sts_tbl));
    p_bscc = (char *)malloc( (strlen(bscc)) +1 );
	
    if(p_bscc == NULL){
      ret=ERR_MEMORY;
      break;
    }
	memset (p_bscc, 0, (strlen(bscc)) +1);
    strncpy(p_bscc, bscc, strlen(bscc));
    
    /* BSCC is divided into a command and status and it stores in a structure object.*/
    ret = parsebscc(p_bscc, &bsccbuf[0]);
    if( ret != OK){
      break;
    }
    /* 
     * A table header, device information, and a printer name 
     * are stored in a bscc2sts_tbl.
     */
    ret = firstsetsts(printer, Odev, Pr_sts);
    if( ret != OK){
      break;
    }
    /* To the bscc2sts_tbl string processing for every model. */
    ret = processofeachmodel(bsccbuf, Pr_sts );
    if( ret != OK){
      break;
    }
    Pr_sts->cr=CR;
    break;
  }
  for(i=0; i<MAXBSCCCOM; i++ ){
    if(bsccbuf[i].p_bsccsts != NULL){
      free(bsccbuf[i].p_bsccsts);
    }
  }
  free(p_bscc);
  return(ret);
}

/*
 * The structure object which stored the function corresponding to each model.
 */
static const
ST_FUNCMODEL modeltable[]={
   {"BJF900",		processforf9xx}
  ,{"BJF9000",		processforf9xx}
  ,{"BJS300",		processfors300}
  ,{"BJS500",		processfors500}
  ,{"PIXUS950I",	processfor950i}
  ,{"PIXUS850I",	processfor850i}
  ,{"PIXUS550I",	processfor550i}
  ,{"I250",			processfors300}
  ,{"I255",			processfors300}
  ,{"PIXUS560I",	processfor560i}
  ,{"PIXUS860I",	processfor860i}
  ,{"PIXUS990I",	processfor990i}
  ,{"PIXMAIP1000",	processforip1000}
  ,{"PIXMAIP1500",	processforip1000}
  ,{"PIXUSIP3100",	processforip3100}
  ,{"PIXUSIP4100",	processforip4100}
  ,{"PIXUSIP8600",	processforip8600}
};


static
int processofeachmodel(ST_BSCCBUF *p_bsccbuf, bscc2sts_tbl *p_tbl)
{
  int i;
  int ret;

ST_STORESET storeset[]={
  {&p_tbl->base_stat[0],     sizeof(p_tbl->base_stat),      (p_bsccbuf+BST)->p_bsccsts},
  {&p_tbl->busy_stat,        sizeof(p_tbl->busy_stat),      (p_bsccbuf+DBS)->p_bsccsts},
  {&p_tbl->job_stat,         sizeof(p_tbl->job_stat),       (p_bsccbuf+DJS)->p_bsccsts},
  {&p_tbl->ink_check,        sizeof(p_tbl->ink_check),      (p_bsccbuf+CIL)->p_bsccsts},
  {NULL,                     sizeof(p_tbl->cartridge),      (p_bsccbuf+CHD)->p_bsccsts},
  {NULL,                     sizeof(p_tbl->cartridge),      p_tbl->pr_name},
  {&p_tbl->lever_position,   sizeof(p_tbl->lever_position), (p_bsccbuf+LVR)->p_bsccsts},
  {&p_tbl->warning[0],       sizeof(p_tbl->warning),        (p_bsccbuf+DWS)->p_bsccsts},
  {&p_tbl->operator_call[0], sizeof(p_tbl->operator_call),  (p_bsccbuf+DOC)->p_bsccsts},
  {&p_tbl->service_call[0],  sizeof(p_tbl->service_call),   (p_bsccbuf+DSC)->p_bsccsts},
  {NULL,                     sizeof(p_tbl->ink),            (p_bsccbuf+CIR)->p_bsccsts},
};

  for(i=0; i<MAXMODELNUM; i++){
	if( strncmp(p_tbl->pr_name, modeltable[i].prnname, strlen(modeltable[i].prnname))==0 ){
	  ret = (*modeltable[i].model)(&storeset[0], p_tbl, p_bsccbuf);
	  return(ret);
	}
  }
  return(ERR_NOSUPPORTEDMODEL);
}


/*
 * The structure object which stored the character sequence corresponding to each device ID.
 */
static const
ST_DEVTYPE devtype[]={
  {0,"PAR"},
  {1,"USB"},
  {2,"1394"}
};


static
int firstsetsts(char *p_name, output_dev *p_dev,bscc2sts_tbl *p_tbl)
{
  int i;

  strncpy(p_tbl->header, HEADER, strlen(HEADER));
  for(i=0; i < MAXDEVTYPE; i++){
    if( p_dev->dev == devtype[i].devno ){
      strncpy(p_tbl->dev, devtype[i].type, strlen(devtype[i].type));
      break;
    }
  }
  if(strlen(p_name) > MAXPRINTERNAME ){
    return(ERR_PRINTERNAME);
  }
  for(i=0; *(p_name+i)!='\0'; i++){
    p_tbl->pr_name[i] = toupper(*(p_name+i));
  }
  return(OK);
}


static
int parsebscc(char *p_s, ST_BSCCBUF *p_bsccbuf)
{
  int ret;
  char *p_tok;
  char *p_temp;
  char bscccom_tmp[1024];

  memset (&bscccom_tmp[0], 0, 1024);
  
  p_temp=(char *)malloc( strlen(p_s) + 1 );
  if(p_temp == NULL){
    return(ERR_MEMORY);
  }
  memset (p_temp, 0, strlen(p_s) + 1);
  strncpy(p_temp, p_s, strlen(p_s));
  p_tok = strtok(p_temp, ":");
  if(p_tok == NULL){
    return(ERR_BSCCNON);
  }
  strncpy(&bscccom_tmp[0], p_tok, 1023);

  while( (p_tok=strtok(NULL,";")) != NULL ){
    ret=setbsccsts(p_tok, &bscccom_tmp[0], p_bsccbuf);
    if (ret != OK){
      free(p_temp);
      return(ret);
    }
    if( (p_tok=strtok(NULL,":")) == NULL){
      break;
    }
    strncpy(&bscccom_tmp[0], p_tok, (1023>strlen(p_tok))? strlen(p_tok):1023);
  }
  free(p_temp);
  return(OK);
}


/* A domain is secured and bscc status is stored. */
static
int setbsccsts(char *p, char *p_buf, ST_BSCCBUF *p_bsccbuf)
{
  int i;

  for(i=0; i < MAXBSCCCOM; i++){
    if( strcmp(p_buf, (p_bsccbuf+i)->p_bscccom) == 0 ){
      (p_bsccbuf+i)->p_bsccsts = (char *)malloc(strlen(p)+1);
	  
      if((p_bsccbuf+i)->p_bsccsts == NULL){
    	return(ERR_MEMORY);
      }
	  memset ((p_bsccbuf+i)->p_bsccsts, 0, strlen(p)+1);
      strncpy((p_bsccbuf+i)->p_bsccsts, p, strlen(p));
    }
  }
  return(OK);
}
