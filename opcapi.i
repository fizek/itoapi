%module opc 
%{

/* -*-C-*-
********************************************************************************
*
* File:         opcapi.h
* Description:  This file contains constants and function prototypes to use the
*               ITO APIs.
* Language:     ANSI C
*
* (c) Copyright Hewlett-Packard Co. 1993 - 1999
*
********************************************************************************
*/

#ifndef __OPCAPI_H
#define __OPCAPI_H

#undef OPCLIBAPI
#undef OPCAPI

#define OPCAPI    
#define OPCLIBAPI extern 


#ifdef __cplusplus
extern "C" {
#endif



/* Types */
/*-------*/

typedef void * opcdata;
typedef void * opcregcond;
typedef void * opc_connection;
typedef void * opc_iterator;

typedef int	pipe_handle;

typedef pipe_handle *p_pipe_handle;

/* ITO Interfaces */
/*----------------*/

/* Interface types */
/*-----------------*/

#define OPCAGTIF_EXTMSGPROC_READ          7
#define OPCAGTIF_EXTMSGPROC_READWRITE     8
#define OPCAGTIF_EXTMSGPROC_WRITE         9


/* Interface Modes */
/*-----------------*/

#define OPCIF_ALWAYS                  	  1
#define OPCIF_SV_RUNNING              	  2
#define OPCIF_AGT_RUNNING             	  2
#define OPCIF_READ_WAIT               	  4
#define OPCIF_READ_NOWAIT             	  8
#define OPCIF_CLOSE_FORWARD           	  16
#define OPCIF_CLOSE_DISCARD           	  32
#define OPCIF_CLOSE_NO_DESTROY        	  1024
#define OPCIF_IGNORE_MSI_ALREADY_EXISTS   2048

/* ITO Data Types */
/*----------------*/

/* Opcdata datatypes  */
/*--------------------*/

#define OPCDTYPE_EMPTY                    0
#define OPCDTYPE_MESSAGE                  1
#define OPCDTYPE_ACTION_REQUEST           2
#define OPCDTYPE_ACTION_RESPONSE          3
#define OPCDTYPE_MESSAGE_ID               4
#define OPCDTYPE_CONTAINER                6
#define OPCDTYPE_MONITOR_MESSAGE          11


/* Opcregcond attributes */
/*-----------------------*/

#define OPCREG_APPLICATION             	  1 /* str */
#define OPCREG_GROUP                   	  2 /* str */
#define OPCREG_MSGTYPE                 	  3 /* str */
#define OPCREG_NODENAME                	  4 /* str */
#define OPCREG_OBJECT                  	  5 /* str */
#define OPCREG_SEVERITY                	  6 /* long */
#define OPCREG_MSG_EVENT_MASK          	  7 /* long */
#define OPCREG_OPERATOR                	  8 /* str */
#define OPCREG_APP_RESPONSE_ID         	  9 /* str */


/* Data attributes  */
/*------------------*/

#define OPCDATA_DATATYPE                  1 /* long */

/* Message */
#define OPCDATA_SEVERITY              	  10 /* long */
#define OPCDATA_CREATION_TIME         	  11 /* long */
#define OPCDATA_RECEIVE_TIME          	  12 /* long */
#define OPCDATA_AACTION_ACK           	  13 /* long */
#define OPCDATA_AACTION_ANNOTATE      	  14 /* long */
#define OPCDATA_OPACTION_ACK          	  15 /* long */
#define OPCDATA_OPACTION_ANNOTATE     	  16 /* long */
#define OPCDATA_NOTIFICATION          	  17 /* long */
#define OPCDATA_TROUBLETICKET         	  18 /* long */
#define OPCDATA_MSG_LOG_ONLY          	  19 /* long */
#define OPCDATA_TROUBLETICKET_ACK     	  20 /* long */
#define OPCDATA_ACTION_TYPE           	  21 /* long */
#define OPCDATA_ACTION_ANNOTATE       	  22 /* long */
#define OPCDATA_ACTION_ACK            	  23 /* long */
#define OPCDATA_ACTION_RESULT         	  25 /* long */
#define OPCDATA_ACTION_TIME           	  26 /* long */
#define OPCDATA_MSI_OUTPUT            	  27 /* long */
#define OPCDATA_AACTION_STATUS        	  28 /* long */
#define OPCDATA_OPACTION_STATUS       	  29 /* long */
#define OPCDATA_INSTR_IF_TYPE         	  30 /* long */
#define OPCDATA_TIME                  	  31 /* long */
#define OPCDATA_UNMATCHED             	  33 /* long */
#define OPCDATA_ESCALATED             	  34 /* long */
#define OPCDATA_TIME_OWNED            	  35 /* long */
#define OPCDATA_DATA_INFO             	  36 /* long */
#define OPCDATA_MSG_STATUS            	  37 /* long */
#define OPCDATA_ACKNOWLEDGE_TIME      	  38 /* long */
#define OPCDATA_MSGSRC_TYPE           	  39 /* long */
#define OPCDATA_TIME_ZONE_DIFF        	  40 /* long */

#define OPCDATA_FORW_INFO              	  60 /* long */
#define OPCDATA_FORWARDED_FROM         	  61 /* long */
#define OPCDATA_IS_READONLY           	  62 /* long */

/* MESSAGE_EVENT */
#define OPCDATA_EVENT_FLAG            	  90 /* long */

/* Message */
#define OPCDATA_APPLICATION        	  100 /* str */
#define OPCDATA_MESSAGE_GROUP      	  101 /* str */
#define OPCDATA_GROUP              	  OPCDATA_MESSAGE_GROUP
#define OPCDATA_MESSAGE_TEXT       	  102 /* str */
#define OPCDATA_MSGTEXT            	  OPCDATA_MESSAGE_TEXT
#define OPCDATA_ORIG_MESSAGE_TEXT  	  103 /* str */
#define OPCDATA_ORIGMSGTEXT        	  OPCDATA_ORIG_MESSAGE_TEXT
#define OPCDATA_MSGTYPE            	  104 /* str */
#define OPCDATA_NODENAME           	  105 /* str */
#define OPCDATA_OBJECT             	  106 /* str */
#define OPCDATA_MSGSRC             	  107 /* str */
#define OPCDATA_AACTION_NODE       	  108 /* str */
#define OPCDATA_AACTION_CALL       	  109 /* str */
#define OPCDATA_OPACTION_NODE      	  110 /* str */
#define OPCDATA_OPACTION_CALL      	  111 /* str */
#define OPCDATA_MSGID              	  112 /* str */
#define OPCDATA_ORIGMSGID          	  113 /* str */
#define OPCDATA_ACTION_CALL        	  115 /* str */
#define OPCDATA_ACTION_USER        	  116 /* str */
#define OPCDATA_ACTION_PWD         	  117 /* str */
#define OPCDATA_DISPLAY            	  118 /* str */
#define OPCDATA_ACTION_OUTPUT      	  119 /* str */
#define OPCDATA_INSTR_IF           	  120 /* str */
#define OPCDATA_INSTR_PAR          	  121 /* str */
#define OPCDATA_AUTHOR             	  122 /* str */
#define OPCDATA_ANNOTATION_TEXT    	  123 /* str */
#define OPCDATA_OWNED_BY           	  124 /* str */
#define OPCDATA_ESCALATION_SERVER  	  125 /* str */
#define OPCDATA_ANNOTATION_ID      	  126 /* str */
#define OPCDATA_SERVICE_NAME       	  127 /* str */
#define OPCDATA_ACKNOWLEDGE_OP     	  128 /* str */
#define OPCDATA_NUM_ANNOTATIONS           129 /* str */
#define OPCDATA_MSG_KEY                   130 /* str */
#define OPCDATA_ESCALATED_BY              131 /* str */
#define OPCDATA_MAP_COLORING              132 /* str */


/* fields for OPCDATA_MONITOR_MESSAGE */
#define OPCDATA_MON_VAR	               	  160 /* str */
#define OPCDATA_MON_VALUE              	  161 /* double */

/* new field for opcagtmsg_send and opcagtmon_send */
#define OPCDATA_OPTION_VAR             	  162 /* str */

/* possible return value for opcdata_get_double */
#define OPC_DOUBLE_UNDEF               	  0.0

/* OPCDTYPE_APPLIC(_RESPONSE) attributes */
/*---------------------------------------*/
#define OPCDATA_APP_NAME               	  200 /* str */
#define OPCDATA_APP_GROUP              	  201 /* str */
#define OPCDATA_APP_NODENAME           	  202 /* str */
#define OPCDATA_APP_IP_ADDRESS         	  203 /* long */
#define OPCDATA_APP_RESPONSE_ID        	  204 /* str */
#define OPCDATA_APP_RESPONSE           	  205 /* str */
#define OPCDATA_APP_STATUS             	  206 /* long */
#define OPCDATA_APP_PARAMETER          	  207 /* str */
#define OPCDATA_PARAMETER          	  OPCDATA_APP_PARAMETER
#define OPCDATA_APP_USER               	  208 /* str */
#define OPCDATA_USER               	  OPCDATA_APP_USER
#define OPCDATA_APP_PASSWORD           	  209 /* str */

/* Operator capabilities */
/*-----------------------*/
#define OPCDATA_ACKNOWLEDGE         	  220  /* int */
#define OPCDATA_PERFORM_ACTION      	  221  /* int */
#define OPCDATA_NODEHIER_CHANGE     	  222  /* int */
#define OPCDATA_APPL_DESK_CHANGE    	  223  /* int */
#define OPCDATA_RESP_CHANGE         	  224  /* int */
#define OPCDATA_USER_ROLE           	  225  /* int */
#define OPCDATA_PASSWORD            	  226  /* str */
#define OPCDATA_REAL_NAME           	  227  /* str */
#define OPCDATA_DM_CONNECTED        	  228  /* int */
#define OPCDATA_CHANGE_MSG          	  229  /* int */
#define OPCDATA_OWN                 	  230  /* int */
#define OPCDATA_AUDIT_LEVEL         	  231  /* int */
#define OPCDATA_IMMEDIATE_SYNC            232  /* int */

/* node, node_config, node_group */
/*-------------------------------*/

#define OPCDATA_NETWORK_TYPE           	  250  /* long */
#define OPCDATA_IP_ADDRESS             	  251  /* long */
#define OPCDATA_CONTROL                	  252  /* long */
#define OPCDATA_HEARTBEAT_POLL_TYPE    	  253  /* long */
#define OPCDATA_HEARTBEAT_POLL_ENABLE  	  254  /* long */
#define OPCDATA_AUTO_INSTALL           	  255  /* long */
#define OPCDATA_AUTO_UPDATE            	  256  /* long */
#define OPCDATA_TERMINAL               	  257  /* long */
#define OPCDATA_CHARSET                	  258  /* long */
#define OPCDATA_MSI_ENABLE_OUTPUT      	  259  /* long */
#define OPCDATA_MSI_ALLOW_AACTIONS     	  260  /* long */
#define OPCDATA_MSI_ALLOW_OPACTIONS    	  261  /* long */
#define OPCDATA_INSTALL_METHOD         	  262  /* long */
#define OPCDATA_COMM_TYPE              	  263  /* long */
#define OPCDATA_DCE_SECURITY_LEVEL     	  264  /* long */
#define OPCDATA_LOG_SIZE               	  265  /* long */
#define OPCDATA_SECURITY_TYPE          	  266  /* long */
#define OPCDATA_COMPRESSED_PKG_TRANS   	  267  /* long */
#define OPCDATA_DEPOT_ACCESS_METHOD    	  268  /* long */
#define OPCDATA_LICENSE_TYPE           	  269  /* long */
#define OPCDATA_DEPOT_NODE_IP             270  /* long */
#define OPCDATA_DEPOT_NET_TYPE            271  /* long */
#define OPCDATA_MACHINE_TYPE              272  /* long */
#define OPCDATA_AGENT_VERSION             273  /* long */
#define OPCDATA_RPC_VERSION               274  /* long */

#define OPCDATA_NAME                   	  290  /* str  */
#define OPCDATA_DESCRIPTION            	  291  /* str  */
#define OPCDATA_LABEL                  	  292  /* str  */
#define OPCDATA_SYMBOL                 	  293  /* str  */
#define OPCDATA_ID                     	  294  /* str  */
#define OPCDATA_HEARTBEAT_POLL_INTERVAL   295  /* str  */
#define OPCDATA_INSTALL_USER              296  /* str  */
#define OPCDATA_CONSOLE_COMMAND           297  /* str  */
#define OPCDATA_CONSOLE_OPT1              298  /* str  */
#define OPCDATA_CONSOLE_OPT2              299  /* str  */
#define OPCDATA_CONSOLE_OPT3              300  /* str  */
#define OPCDATA_VTERM_FONT                301  /* str  */
#define OPCDATA_DEPOT_NAME                302  /* str  */
#define OPCDATA_DEPOT_NODE_NAME           303  /* str  */
#define OPCDATA_PACKAGE_NAME              304  /* str  */
#define OPCDATA_LOG_DIR                   305  /* str  */
#define OPCDATA_MPE_STREAM_COMMAND        306  /* str  */
#define OPCDATA_PORT_RANGE                307  /* str  */

#define OPCDATA_NEW_MESSAGE_GROUP         308  /* str  */
#define OPCDATA_DEPOT_NODE_ID             309  /* str  */
#define OPCDATA_CASE_SENSITIVE_CHECK      311  /* long */
#define OPCDATA_FIELD_SEPARATORS          312  /* str  */
#define OPCDATA_NODE                      313  /* str  */
#define OPCDATA_COND_ID                   314  /* str  */

#define OPCDATA_PARENT_ID                 315  /* str  */
#define OPCDATA_CONSOLE                   316  /* str  */
#define OPCDATA_NODE_TYPE                 317  /* long */
#define OPCDATA_PATH                      318  /* str  */
#define OPCDATA_SUBMAP_TITLE              319  /* str  */
#define OPCDATA_LAYOUTGRP_ID              320  /* str  */
#define OPCDATA_HOLDING_AREA_ID           321  /* str  */
#define OPCDATA_TEXT                      322  /* str  */

#define OPCDATA_CALL                      323  /* str  */
#define OPCDATA_NODES                     324  /* str  */
#define OPCDATA_REGISTERED_NAME           325  /* str  */
#define OPCDATA_ACTION_IDENTIFIER         326  /* str  */
#define OPCDATA_GROUP_ID                  327  /* str  */
#define OPCDATA_APP_SELECT                328  /* long */
#define OPCDATA_APP_TYPE                  329  /* long */
#define OPCDATA_APP_START_IN_TERM         330  /* long */
#define OPCDATA_APP_ACTION                331  /* long */

#define OPCDATA_MSGGROUP_NAME             332  /* str  */
#define OPCDATA_NODEGROUP_NAME            333  /* str  */
#define OPCDATA_NODEGROUP_ID              334  /* str  */

#define OPCDATA_CHANGE_MSG_ATTR           335  /* long */
#define OPCDATA_OWN_FLAG                  336  /* long */
#define OPCDATA_TARGET                    337  /* long */
#define OPCDATA_FAMILY_NAME               338  /* str  */
#define OPCDATA_USER_NAME                 339  /* str  */
#define OPCDATA_PLTFRM_LOGINS             340  /* str  */
#define OPCDATA_NODE_LIST                 341  /* str  */

#define OPCDATA_MLM_NAME                  342  /* str  */
#define OPCDATA_AGENT_TYPE                343  /* long */

/* Misc of several types */
#define OPCDATA_TYPE                      350  /* long */
#define OPCDATA_STATUS                    351  /* long */

/* !!!!!!!!!!!!!!!!!!!!!!!!!! */
/* !! Obsolete definitions !! */
/* !!!!!!!!!!!!!!!!!!!!!!!!!! */

/* !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! */
/* !!   Old opcdata types    !!     This is obsolete    !! */
/* !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! */
#define OPCDATA_EMPTY             	  0 /* obsolete */
#define OPCDATA_MSG               	  1 /* obsolete */
#define OPCDATA_ACTION_REQUEST    	  2 /* obsolete */
#define OPCDATA_ACTION_RESPONSE   	  3 /* obsolete */
#define OPCDATA_MESSAGE_ID        	  4 /* obsolete */
#define OPCDATA_ANNOTATION        	  5 /* obsolete */
#define OPCDATA_CONTAINER         	  6 /* obsolete */
#define OPCDATA_MGDNODE           	  7 /* obsolete */
#define OPCDATA_APPLIC            	  8 /* obsolete */
#define OPCDATA_APPLIC_RESPONSE   	  9 /* obsolete */
#define OPCDATA_MSG_EVENT         	  10 /* obsolete */
#define OPCDATA_MON_MSG		  	  11 /* obsolete */


#define OPC_ERR_WRONG_MPITYPE     	  OPC_ERR_WRONG_MSITYPE /* obsolete */
#define OPC_ERR_MPI_BUF_FULL      	  OPC_ERR_MSI_BUF_FULL  /* obsolete */
#define OPCDATA_MPI_OUTPUT        	  OPCDATA_MSI_OUTPUT    /* obsolete */
#define OPC_MPI_SV_NO_OUTPUT      	  OPC_SV_MSI_NO_OUTPUT  /* obsolete */
#define OPC_MPI_SV_DIVERT         	  OPC_SV_MSI_DIVERT     /* obsolete */
#define OPC_MPI_SV_COPY           	  OPC_SV_MSI_COPY       /* obsolete */
#define OPC_MPI_AGT_NO_OUTPUT     	  OPC_AGT_MSI_NO_OUTPUT /* obsolete */
#define OPC_MPI_AGT_DIVERT        	  OPC_AGT_MSI_DIVERT    /* obsolete */
#define OPC_MPI_AGT_COPY          	  OPC_AGT_MSI_COPY      /* obsolete */
/* !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! */
/* !! End of Obsolete definitions !! */
/* !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! */


/* Attribute Values */
/*------------------*/

/* definition of the empty uuid */
#define OPC_EMPTY_UUID "000000000000000000000000000000000000"


/* Severity values to be passed in the OPCDATA_SEVERITY */
#define OPC_SEV_UNCHANGED    	        0
#define OPC_SEV_UNKNOWN      	        4
#define OPC_SEV_NORMAL       	        8
#define OPC_SEV_WARNING      	        16
#define OPC_SEV_CRITICAL     	        32
#define OPC_SEV_MINOR        	        64
#define OPC_SEV_MAJOR        	        128

/* types of instruction interfaces used in messages */
#define OPC_INSTR_NOT_SET    	        0
#define OPC_INSTR_FROM_OPC   	        1
#define OPC_INSTR_FROM_OTHER 	        2
#define OPC_INSTR_FROM_INTERNAL         3

/* types of action requests and action responses */
#define OPC_AUTOMATIC_ACTION            0
#define OPC_OPERATOR_INIT_ACTION        1
#define OPC_NO_TERMINAL_APPLICATION     2
#define OPC_TERMINAL_APPLICATION        3
#define OPC_GET_INSTRUCTION_TEXT        4

/* values for OPCDATA_MSI_OUTPUT */
#define OPC_SV_MSI_NO_OUTPUT            0
#define OPC_SV_MSI_DIVERT               1
#define OPC_SV_MSI_COPY                 2
#define OPC_AGT_MSI_NO_OUTPUT           0
#define OPC_AGT_MSI_DIVERT              4
#define OPC_AGT_MSI_COPY                8

/* values for AACTION_STATUS and OPACTION_STATUS */
#define OPC_ACTION_UNDEF       	        0
#define OPC_ACTION_DEF         	        1
#define OPC_ACTION_STARTED     	        2
#define OPC_ACTION_FINISHED    	        3
#define OPC_ACTION_FAILED      	        4

/* values for OPCDATA_ESCALATED */
#define OPC_ESCALATED_TO                1
#define OPC_ESCALATED_FROM              2

/* The local node to be used in the node parameter. */
#define OPC_LOCAL_NODE                  ((char *) 0)

#define OPC_MSG_ACTIVE                  0
#define OPC_MSG_HISTORY                 1
#define OPC_MSG_BUFFERED                2




/* OPCDATA_ON_OWNERSHIP */
#define OPC_MSG_NOT_OWNED                  1
#define OPC_MSG_OWNED_BY_ME                2
#define OPC_MSG_OWNED_BY_OTHER             4

/* OPCDATA_MSGSRC_TYPE                                                     */
/* -------------------                                                     */
/* the message source type is represented as one bit per source, i.e.      */
/* a message that was generated by the logfile encapsulator and then       */
/* modified at the AgentMSI will have OPC_LOGFILE_SRC | OPC_AGTMSI_SRC set */

#define OPC_CONSOLE_SRC                    0x0001L
#define OPC_OPCMSG_SRC                     0x0002L
#define OPC_LOGFILE_SRC                    0x0004L
#define OPC_MONITOR_SRC                    0x0008L
#define OPC_SNMPTRAP_SRC                   0x0010L
#define OPC_SVMSI_SRC                      0x0020L
#define OPC_AGTMSI_SRC                     0x0040L
#define OPC_LEGLINK_SRC                    0x0080L
#define OPC_SCHEDULE_SRC                   0x0100L

/* message data info flags */
/*-------------------------*/
#define OPC_REMARK_FOR_ACK                 0x00000100L





/*--------------------------------------------*/
/* ERRORS                                     */
/*--------------------------------------------*/
/* return codes which match the following     */
/* condition are considered as an error       */
/*                                            */
/* OPC_WARN < error_code < OPC_ERR_OK         */
/*--------------------------------------------*/

#define OPC_ERR_OK                  	      0

/* Parameter errors. */
#define OPC_ERR_APPL_REQUIRED       	     -1
#define OPC_ERR_OBJ_REQUIRED        	     -2
#define OPC_ERR_TEXT_REQUIRED       	     -3
#define OPC_ERR_INVAL_SEVERITY      	     -4
#define OPC_ERR_OBJNAME_REQUIRED    	     -5
#define OPC_ERR_MISC_NOT_ALLOWED    	     -6
#define OPC_ERR_INVAL_NODE          	     -7
#define OPC_ERR_INVALID_NODE                OPC_ERR_INVAL_NODE

/* Runtime errors. */
#define OPC_ERR_NO_MEMORY           	     -8
#define OPC_ERR_NO_AGENT            	     -9

/* OpC errors. */
#define OPC_ERR_CANT_INIT           	     -10
#define OPC_ERR_NO_QUEUE_NAME       	     -11
#define OPC_ERR_CANT_OPEN_QUEUE     	     -12
#define OPC_ERR_CANT_WRITE_QUEUE    	     -13
#define OPC_ERR_NO_PIPE_NAME        	     -14
#define OPC_ERR_CANT_OPEN_PIPE      	     -15
#define OPC_ERR_CANT_GET_LOCAL_ADDR 	     -16
#define OPC_ERR_CANT_INIT_MUTEX     	     -17
#define OPC_ERR_CANT_LOCK_MUTEX     	     -18
#define OPC_ERR_CANT_READ_QUEUE     	     -19
/* opcdata / opcregcond */
#define OPC_ERR_INVALID_INPARAM     	     -20
#define OPC_ERR_INVALID_OUTPARAM    	     -21
#define OPC_ERR_INVALID_FIELD       	     -22
#define OPC_ERR_NO_ELEMENT          	     -23
#define OPC_ERR_INCOMPLETE_PARAM    	     -24
  
/* Server / Agent Interfaces */
#define OPC_ERR_INVALID_INTERFACE_TYPE       -30
#define OPC_ERR_INVALID_INTERFACE_INSTANCE   -31
#define OPC_ERR_INVALID_INTERFACE_ID         -32
#define OPC_ERR_INVALID_OPCDATA_TYPE         -33
#define OPC_ERR_CANT_OPEN_READQUEUE          -34
#define OPC_ERR_CANT_OPEN_WRITEQUEUE         -35
#define OPC_ERR_CANT_INFORM_MSGM             -36
#define OPC_ERR_CANT_INFORM_MSGA             -36
#define OPC_ERR_CANT_READ_MSG                -37
#define OPC_ERR_CANT_WRITE_MSG               -38
#define OPC_ERR_WRONG_MSITYPE                -39
#define OPC_ERR_NO_DATA                      -40
#define OPC_ERR_EINTR                        -41
#define OPC_ERR_MSI_BUF_FULL                 -42
#define OPC_ERR_SV_NOT_RUNNING               -43
#define OPC_ERR_ACCESS_DENIED                -44

#define OPC_ERR_NO_LOGIN                     -50
#define OPC_ERR_CANT_CONNECT_DB              -53
#define OPC_ERR_NO_OPERATOR_DEF              -54
#define OPC_ERR_CANT_DISCONNECT              -55
#define OPC_ERR_INVALID_ID                   -56
#define OPC_ERR_NO_ANNOTATIONS               -57
#define OPC_ERR_ALREADY_DONE                 -58
#define OPC_ERR_NOT_ACKNOWLEDGED             -59
#define OPC_ERR_DATABASE_ERROR               -60
#define OPC_ERR_CANT_INFORM_UI               -61  
#define OPC_ERR_CANT_CONNECT_DM              -62
#define OPC_ERR_MSG_OWNED_BY_ANOTHER_USER    -63
#define OPC_ERR_NO_ESCALATION_DEFINED        -64
#define OPC_ERR_ESCALATION_FAILED            -65
#define OPC_ERR_ACTION_RUNNING               -66
#define OPC_ERR_NO_ACTION_DEFINED            -67
#define OPC_ERR_ACTION_FAILED                -68
#define OPC_ERR_OBJECT_NOT_FOUND             -69
#define OPC_ERR_OBJECT_NOT_UNIQUE            -70
#define OPC_ERR_OBJECT_ALREADY_EXISTS        -71
#define OPC_ERR_OUT_OF_RANGE                 -72
#define OPC_ERR_DB_WARNING                   -73
#define OPC_ERR_DB_INCONSISTENT              -74
#define OPC_ERR_INVALID_NODE_GROUP           -75
#define OPC_ERR_INVALID_MESSAGE_GROUP        -76
#define OPC_ERR_NOT_COMPLETELY_DONE          -77
#define OPC_ERR_CANT_OPEN_FILE               -78
#define OPC_ERR_CANT_ADD_TEMPLATE            -79
#define OPC_ERR_WRONG_OPTION_VARS            -80
#define OPC_ERR_SYNTAX_ERROR                 -81
#define OPC_ERR_CANT_WRITE_FILE              -82
#define OPC_ERR_INVALID_USER                 -83
#define OPC_ERR_TRANSACTION_ALREADY_OPEN     -84
#define OPC_ERR_NO_TRANSACTION               -85
#define OPC_ERR_STRING_TOO_LONG              -86
#define OPC_ERR_NAME_EXISTS                  -87
#define OPC_ERR_GROUP_NAME_EXISTS            -88
#define OPC_ERR_MSG_NOT_ACTIVE               -89

#define OPC_ERR_INVALID_NAME                 -98
#define OPC_ERR_INVALID_ANNOTATION           -99

#define OPC_ERR_INVALID_APPLICATION          -100
#define OPC_ERR_INVALID_PARAM                -101
#define OPC_ERR_INVALID_APP_PARAM            OPC_ERR_INVALID_PARAM
#define OPC_ERR_LOCKED_BY_OTHER              -102
#define OPC_ERR_DEADLOCK                     -103
#define OPC_ERR_OBJECT_ALREADY_ASSIGNED      -104
#define OPC_ERR_OBJECT_NOT_ASSIGNED          -105

#define OPC_ERR_NODEHIER_NOT_FOUND           -106
#define OPC_ERR_LAYOUTGROUP_NOT_FOUND        -107
#define OPC_ERR_NODE_NOT_FOUND               -108
#define OPC_ERR_USER_NOT_FOUND               -109
#define OPC_ERR_PROFILE_NOT_FOUND            -110
#define OPC_ERR_APPL_NOT_FOUND               -111
#define OPC_ERR_APPLGROUP_NOT_FOUND          -112

#define OPC_ERR_LAYOUTGROUP_NOT_EMPTY        -113
#define OPC_ERR_LAYOUTGROUP_IS_HOLDING_AREA  -114
#define OPC_ERR_LAST_REFERENCE               -115

/* distribution API errors */
#define OPC_ERR_CANT_GET_MGMTSV_ADDRESS      -150

/* error if agent type needs MLM name, but */
/* MLM name is not set                     */
#define OPC_ERR_MLM_NAME_REQUIRED            -155

/* return value for API's under development */
#define OPC_ERR_FUNC_NOT_IMPL_YET            -254

/* return value if the function was */
/* called from the dummy library    */
#define OPC_ERR_DUMMY_FUNCTION_CALLED        -255

/*--------------------------------------------*/
/* WARNINGS                                   */
/*--------------------------------------------*/
/* return codes which match the following     */
/* condition are considered as an warning     */
/* and can be ignored safely                  */
/*                                            */
/* OPC_NOTE < warning_code < OPC_WARN         */
/*--------------------------------------------*/

#define OPC_WARN                             -10000

#define OPC_WARN_EMPTY_CONTAINER             -10001
#define OPC_WARN_DIFFERENT_NAMES             -10002
#define OPC_WARN_NO_OBJECTS_FOUND            -10003
#define OPC_WARN_CANT_WRITE_FILE             -10004
#define OPC_WARN_USER_NOT_LOGGED_ON          -10005

/*--------------------------------------------*/
/* NOTES                                      */
/*--------------------------------------------*/
/* return codes which match the following     */
/* condition are considered as a note         */
/* and can be ignored safely                  */
/*                                            */
/* min_int < note_code < OPC_NOTE             */
/*--------------------------------------------*/

#define OPC_NOTE                             -20000

#if defined (__STDC__) || defined (__cplusplus)

/*
 *******************************************************************************
 * IT/Operations API function prototypes
 * -------------------------------------
 *******************************************************************************
 */

/* Agent Function prototypes. */
/*----------------------------*/

/* Misc API */
OPCLIBAPI char * OPCAPI opc_version ();

/* ITO Agent Message API */
OPCLIBAPI int OPCAPI opcmsg (
			      const int    severity,
			      const char  *application,
			      const char  *object,
			      const char  *msg_text,
			      const char  *msg_group,
			      const char  *node );

OPCLIBAPI int OPCAPI opcagtmsg_send (
			      opcdata  message );

OPCLIBAPI int OPCAPI opcagtmsg_ack (
			      const opcdata  msg_id );

/* ITO Agent Monitor API */
OPCLIBAPI int OPCAPI opcmon (
			      const char   *objname,
			      const double  monval );

OPCLIBAPI int OPCAPI opcagtmon_send (
			      const opcdata  mon_msg );

/* ITO Interface API */
OPCLIBAPI int OPCAPI opcif_open (
			      int         interface_type,
			      const char *instance,
			      int         mode,
			      int         max_entries,
			      int        *interface_id );

OPCLIBAPI int OPCAPI opcif_close (
			      int  interface_id );

OPCLIBAPI int OPCAPI opcif_get_pipe (
			      int           interface_id,
			      pipe_handle  *pipefd );

OPCLIBAPI int OPCAPI opcif_register (
			      int               interface_id,
			      const opcregcond  reg_cond,
			      long             *condition_id );

OPCLIBAPI int OPCAPI opcif_unregister (
			      int   interface_id,
			      long  condition_id );

OPCLIBAPI int OPCAPI opcif_read (
			      int      interface_id,
			      opcdata  data );

OPCLIBAPI int OPCAPI opcif_write (
			      int            interface_id,
			      const opcdata  data );

/* ITO Data API */
/*@
 * Group:   opcdata
 *          The opcdata functions are used to handle OPCDATA 
 *          data structures.
 * ITOName: ITO Datastructure API
 * Related: opclayoutgrp opcnode
 * OPCDATA: 
 * Manual:  The opcdata functions are used to handle OPCDATA 
 *          data structures, which contain a wide range of 
 *          information about the configuration of ITO and
 *          the ITO working data.
 *          
 *          A detailed description of the OPCDATA data structures 
 *          is provided in the man page \fIopcdata\fR(3).
 */

OPCLIBAPI int OPCAPI opcdata_create (
			      int       data_type,
			      opcdata  *data );

OPCLIBAPI int OPCAPI opcdata_free (
			      opcdata  *data );

OPCLIBAPI int OPCAPI opcdata_clear (
			      opcdata  *data );

OPCLIBAPI int OPCAPI opcdata_type (
			      opcdata  data );

OPCLIBAPI int OPCAPI opcdata_copy (
			      const opcdata  data,
			      opcdata       *copy );

OPCLIBAPI int OPCAPI opcdata_copy_info_to_actresp (
			      const opcdata  data,
			      opcdata        copy );

OPCLIBAPI long OPCAPI opcdata_get_long (
			      const opcdata  data,
			      int            attribute );

OPCLIBAPI double OPCAPI opcdata_get_double (
			      const opcdata  data,
			      int            attribute );

OPCLIBAPI char * OPCAPI opcdata_get_str (
			      const opcdata  data,
			      int            attribute );

OPCLIBAPI int OPCAPI opcdata_set_long (
			      opcdata  data,
			      int      attribute,
			      long     value );

OPCLIBAPI int OPCAPI opcdata_set_double (
			      opcdata  data,
			      int      attribute,
			      double   value );

OPCLIBAPI int OPCAPI opcdata_set_str (
			      opcdata      data,
			      int          attribute,
			      const char  *value );

/* Lists in opcdata */
OPCLIBAPI long OPCAPI opcdata_lget_len (
			      const opcdata  data,
			      const int      list );

OPCLIBAPI long OPCAPI opcdata_ladd (
			      const opcdata  data,
			      const int      list );

OPCLIBAPI long OPCAPI opcdata_ldel (
			      const opcdata  data,
			      const int      list,
			      const long     index );

OPCLIBAPI long OPCAPI opcdata_lget_long (
			      const opcdata  data,
			      const int      list,
			      const int      attribute,
			      const long     index );

OPCLIBAPI int OPCAPI opcdata_lset_long (
			      const opcdata  data,
			      const int      list,
			      const int      attribute,
			      const long     index,
			      const long     value );

OPCLIBAPI char * OPCAPI opcdata_lget_str (
			      const opcdata  data,
			      const int      list,
			      const int      attribute,
			      const long     index );

OPCLIBAPI int OPCAPI opcdata_lset_str (
			      const opcdata  data,
			      const int      list,
			      const int      attribute,
			      const long     index,
			      const char *   value );

/* Container */
OPCLIBAPI long OPCAPI opcdata_num_elements (
			      const opcdata  container );

OPCLIBAPI int  OPCAPI opcdata_get_element (
			      const opcdata  container,
			      opcdata       *element,
			      long           index );

OPCLIBAPI int OPCAPI opcdata_append_element (
			      opcdata  container,
			      opcdata  element );

OPCLIBAPI int OPCAPI opcdata_insert_element (
			      opcdata  container,
			      opcdata  element,
			      long     index );

OPCLIBAPI int OPCAPI opcdata_delete_element (
			      opcdata  container,
			      long     index );

OPCLIBAPI int OPCAPI opcdata_generate_id (
			      opcdata    data,
			      const int  attribute );

/* ITO registration functions */
OPCLIBAPI int OPCAPI opcreg_create (
			      opcregcond *reg_cond );

OPCLIBAPI int OPCAPI opcreg_free (
			      opcregcond *reg_cond );

OPCLIBAPI int OPCAPI opcreg_copy (
			      const opcregcond   reg_cond,
			      opcregcond        *copy );

OPCLIBAPI long OPCAPI opcreg_get_long (
			      const opcregcond  reg_cond,
			      int 	      	field );

OPCLIBAPI char * OPCAPI opcreg_get_str (
			      const opcregcond  reg_cond,
			      int               field );

OPCLIBAPI int OPCAPI opcreg_set_long (
			      opcregcond  reg_cond,
			      int         field,
			      long        value );

OPCLIBAPI int OPCAPI opcreg_set_str (
			      opcregcond  reg_cond,
			      int         field,
			      const char *value );

/* ITO iterator functions */
OPCLIBAPI int OPCAPI opciter_create (
			      opc_iterator *iter,
			      opcdata       container );
                                 
OPCLIBAPI int OPCAPI opciter_free (
			      opc_iterator *iter );
                                 
OPCLIBAPI opcdata OPCAPI opciter_begin (
			      opc_iterator  iter );
                                 
OPCLIBAPI opcdata OPCAPI opciter_end (
			      opc_iterator  iter );
                                 
OPCLIBAPI opcdata OPCAPI opciter_next (
			      opc_iterator  iter );

OPCLIBAPI opcdata OPCAPI opciter_prev (
			      opc_iterator  iter );
                                 
OPCLIBAPI opcdata OPCAPI opciter_nth (
			      opc_iterator  iter,
			      long          index );
                                 
OPCLIBAPI long OPCAPI opciter_get_pos (
			      opc_iterator  iter );
                                 
OPCLIBAPI int OPCAPI opciter_set_pos (
			      opc_iterator  iter,
			      long          index );

OPCLIBAPI char* OPCAPI opcdata_get_error_msg(
                                             const int err_code,
                                             char**    p_error_msg,
                                             int*      p_error_msg_size);
/* Unsupported utility function */
OPCLIBAPI char * OPCAPI opcdata_report_error ( const int  err_code );


#else /* __STDC__ */


/**********************************/
/* Non ANSI-C function prototypes */
/**********************************/

/* Agent Function prototypes. */
/*----------------------------*/

OPCLIBAPI char *  OPCAPI opc_version();
OPCLIBAPI int     OPCAPI opcmsg();
OPCLIBAPI int     OPCAPI opcmon();
OPCLIBAPI int     OPCAPI opcagtmsg_send();
OPCLIBAPI int     OPCAPI opcagtmsg_ack();
OPCLIBAPI int     OPCAPI opcagtmon_send();
OPCLIBAPI int     OPCAPI opcif_open();
OPCLIBAPI int     OPCAPI opcif_close();
OPCLIBAPI int     OPCAPI opcif_get_pipe();
OPCLIBAPI int     OPCAPI opcif_register();
OPCLIBAPI int     OPCAPI opcif_unregister();
OPCLIBAPI int     OPCAPI opcif_read();
OPCLIBAPI int     OPCAPI opcif_write();
                  
OPCLIBAPI int     OPCAPI opcdata_create();
OPCLIBAPI int     OPCAPI opcdata_free();
OPCLIBAPI int     OPCAPI opcdata_clear();
OPCLIBAPI int     OPCAPI opcdata_copy();
OPCLIBAPI long    OPCAPI opcdata_get_long();
OPCLIBAPI char *  OPCAPI opcdata_get_str();
OPCLIBAPI double  OPCAPI opcdata_get_double();
OPCLIBAPI int     OPCAPI opcdata_set_long();
OPCLIBAPI int     OPCAPI opcdata_set_str();
OPCLIBAPI int     OPCAPI opcdata_set_double();

OPCLIBAPI long    OPCAPI opcdata_lget_len();
OPCLIBAPI long    OPCAPI opcdata_ladd();
OPCLIBAPI long    OPCAPI opcdata_ldel();
OPCLIBAPI long    OPCAPI opcdata_lget_long();
OPCLIBAPI int     OPCAPI opcdata_lset_long();
OPCLIBAPI char *  OPCAPI opcdata_lget_str();
OPCLIBAPI int     OPCAPI opcdata_lset_str();
                  
OPCLIBAPI int     OPCAPI opcreg_create();
OPCLIBAPI int     OPCAPI opcreg_free();
OPCLIBAPI int     OPCAPI opcreg_copy();
OPCLIBAPI long    OPCAPI opcreg_get_long();
OPCLIBAPI char *  OPCAPI opcreg_get_str();
OPCLIBAPI int     OPCAPI opcreg_set_long();
OPCLIBAPI int     OPCAPI opcreg_set_str();
                  
OPCLIBAPI long    OPCAPI opcdata_num_elements();
OPCLIBAPI int     OPCAPI opcdata_get_element();
OPCLIBAPI int     OPCAPI opcdata_append_element();
OPCLIBAPI int     OPCAPI opcdata_insert_element();
OPCLIBAPI int     OPCAPI opcdata_delete_element();
OPCLIBAPI int     OPCAPI opciter_create(); 
OPCLIBAPI int     OPCAPI opciter_free();
OPCLIBAPI opcdata OPCAPI opciter_begin();
OPCLIBAPI opcdata OPCAPI opciter_end();
OPCLIBAPI opcdata OPCAPI opciter_next();
OPCLIBAPI opcdata OPCAPI opciter_prev();
OPCLIBAPI opcdata OPCAPI opciter_nth();
OPCLIBAPI long    OPCAPI opciter_get_pos();
OPCLIBAPI int     OPCAPI opciter_set_pos();

/* Not supported utility function */
OPCLIBAPI char *  OPCAPI opcdata_report_error();


#endif /* __STDC__ */


#ifdef __cplusplus
}
#endif

#endif  /* __OPCAPI_H */

/*
********************************************************************************
* end of opcapi.h
********************************************************************************
*/

%}
