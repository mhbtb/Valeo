/***********************************************
 *      VectorCAST Test Harness Component      *
 *     Copyright 2020 Vector Software, Inc.    *
 *               6.4t (05/31/17)               *
 ***********************************************/
#ifndef S3_SWITCH_H
#define S3_SWITCH_H   

void vcast_S3_switch( int, int, char *, char * );

#ifdef VCAST_SBF_UNITS_AVAILABLE
void vcast_initialize_sbf_flag( int, int );
#endif /* VCAST_SBF_UNITS_AVAILABLE */

#endif /* S3_SWITCH_H */
