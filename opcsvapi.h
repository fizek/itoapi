/* -*-C-*-
********************************************************************************
*
* File:         opcsvapi.h
* Description:  This file contains defines and includes to build the server
*               API header file opcsvapi.h
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

#ifdef __cplusplus
extern "C" {
#endif

#define OPCAPI    
#define OPCLIBAPI extern 



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

#define OPCSVIF_EXTAGT_MESSAGE            1
#define OPCSVIF_EXTAGT_ACTION_REQUEST     2
#define OPCSVIF_EXTAGT_ACTION_RESPONSE    3
#define OPCSVIF_EXTMSGPROC_READ           4
#define OPCSVIF_EXTMSGPROC_READWRITE      5
#define OPCSVIF_EXTMSGPROC_WRITE          6
#define OPCAGTIF_EXTMSGPROC_READ          7
#define OPCAGTIF_EXTMSGPROC_READWRITE     8
#define OPCAGTIF_EXTMSGPROC_WRITE         9

#define OPCSVIF_MSG_EVENTS                10
#define OPCSVIF_APPLIC_RESPONSE           11


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

#define OPCDTYPE_ANNOTATION               5
#define OPCDTYPE_MANAGED_NODE             7
#define OPCDTYPE_APPLIC                   8
#define OPCDTYPE_APPLIC_RESPONSE          9
#define OPCDTYPE_MESSAGE_EVENT            10
#define OPCDTYPE_NODE                  	  OPCDTYPE_MANAGED_NODE
#define OPCDTYPE_NODE_CONFIG              12
#define OPCDTYPE_NODE_GROUP               13
#define OPCDTYPE_TEMPLATE_INFO            14
#define OPCDTYPE_USER_CONFIG              15
#define OPCDTYPE_NODEHIER                 16
#define OPCDTYPE_LAYOUT_GROUP             17
#define OPCDTYPE_REGROUP_COND             18
#define OPCDTYPE_USER_RESP_ENTRY          19
#define OPCDTYPE_APPL_GROUP               20
#define OPCDTYPE_APPL_CONFIG              21
#define OPCDTYPE_INFORM_USER              22
#define OPCDTYPE_MESSAGE_GROUP            102

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

/* The name of the default node hierarchy, the so called node bank. */
#define OPC_NODEBANK_NAME "NodeBank"

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
#define OPC_LOCAL_NODE                  NULL

#define OPC_MSG_ACTIVE                  0
#define OPC_MSG_HISTORY                 1
#define OPC_MSG_BUFFERED                2

/* ITO mchine types for OPCDATA_MACHINE_TYPE in OPCDTYPE_NODE_CONFIG */
#define OPC_MACHINE_OTHER            	0
#define OPC_MACHINE_S700             	2
#define OPC_MACHINE_S800             	3
#define OPC_MACHINE_S900             	4
#define OPC_MACHINE_RS6000           	6
#define OPC_MACHINE_NCR              	7
#define OPC_MACHINE_SNI              	8
#define OPC_MACHINE_SGI              	9
#define OPC_MACHINE_SUN_SOLARIS      	10
#define OPC_MACHINE_WINNT            	11
#define OPC_MACHINE_WINNT_INTEL         OPC_MACHINE_WINNT
#define OPC_MACHINE_HP10_S700        	13
#define OPC_MACHINE_HP10_S800        	14
#define OPC_MACHINE_SCO              	15
#define OPC_MACHINE_DYNIX            	16
#define OPC_MACHINE_OSF              	17
#define OPC_MACHINE_DEC              	OPC_MACHINE_OSF
#define OPC_MACHINE_NON_IP           	20
#define OPC_MACHINE_OS2           	    21
#define OPC_MACHINE_OLIVETTI         	24
#define OPC_MACHINE_PYRAMID          	25
#define OPC_MACHINE_NETWARE          	26
#define OPC_MACHINE_HP11_PA_RISC        27
#define OPC_MACHINE_UNIXWARE          	28
#define OPC_MACHINE_WINNT_ALPHA         30
#define OPC_MACHINE_OS400            	31
#define OPC_MACHINE_UNSUPPORTED      	255
/* obsolete - do not use anymore */
#define OPC_MACHINE_S400             	1
#define OPC_MACHINE_SUN_SUNOS        	5
#define OPC_MACHINE_HP11_S800           OPC_MACHINE_HP11_PA_RISC
#define OPC_MACHINE_HP11_S700           OPC_MACHINE_HP11_PA_RISC
/* end */

#define OPC_AGT_VERS_UNKNOWN         	000
#define OPC_AGT_VERS_OPC_1X          	100
#define OPC_AGT_VERS_OPC_2X          	200
#define OPC_AGT_VERS_ITO_30          	300
#define OPC_AGT_VERS_ITO_30_LIGHT    	301
#define OPC_AGT_VERS_ITO_31          	310
#define OPC_AGT_VERS_ITO_40          	400

#define OPC_MAXUSHORT                	65536

#define OPC_AGT_VERS_ITO_3X_DCE     	(1 * OPC_MAXUSHORT + OPC_AGT_VERS_ITO_30)
#define OPC_AGT_VERS_ITO_3X_NCS     	(2 * OPC_MAXUSHORT + OPC_AGT_VERS_ITO_30)
				    
#define OPC_AGT_VERS_ITO_40_DCE     	(1 * OPC_MAXUSHORT + OPC_AGT_VERS_ITO_40)
#define OPC_AGT_VERS_ITO_40_NCS     	(2 * OPC_MAXUSHORT + OPC_AGT_VERS_ITO_40)
#define OPC_AGT_VERS_ITO_40_SUN     	(3 * OPC_MAXUSHORT + OPC_AGT_VERS_ITO_40)

#define OPC_HEARTBEAT_NONE              0x00 /* No Heatybeat polling */
#define OPC_HEARTBEAT_RPC_ONLY          0x01
#define OPC_HEARTBEAT_PING_ONLY         0x02 /* Don't use this */
#define OPC_HEARTBEAT_FROM_AGENT        0x04 /* Agent sends alive packages */
#define OPC_HEARTBEAT_RPC_AND_PING      (OPC_HEARTBEAT_RPC_ONLY | \
                                         OPC_HEARTBEAT_PING_ONLY) /* Normal */

#define OPC_NODE_DISABLED               1
#define OPC_NODE_CONTROLLED             2
#define OPC_NODE_MONITORED              3
#define OPC_NODE_MESSAGE_ALLOWED        4

#define OPC_TERM_HPTERM                 0
#define OPC_TERM_XTERM                  1
#define OPC_TERM_DTTERM                 2
#define OPC_TERM_NONE_TERM              3

#define OPC_CHARSET_ASCII               0
#define OPC_CHARSET_ISO88591            1
#define OPC_CHARSET_ROMAN8              2
#define OPC_CHARSET_EBCDIC              3
#define OPC_CHARSET_ACP1252             4
#define OPC_CHARSET_OEMCP850            6
#define OPC_CHARSET_OEMCP437            7
#define OPC_CHARSET_NT_ANSI_L1         	OPC_CHARSET_ACP1252
#define OPC_CHARSET_NT_OEM_L1          	OPC_CHARSET_OEMCP850
#define OPC_CHARSET_NT_OEM_US          	OPC_CHARSET_OEMCP437
#define OPC_CHARSET_ISO88592            8
#define OPC_CHARSET_ISO88595            9
#define OPC_CHARSET_ISO88596            10
#define OPC_CHARSET_ISO88597            11
#define OPC_CHARSET_ISO88598            12
#define OPC_CHARSET_ISO88599            13
#define OPC_CHARSET_TIS620              14
#define OPC_CHARSET_ACP1251             15
#define OPC_CHARSET_ACP1250             16

#define OPC_CHARSET_SJIS                64
#define OPC_CHARSET_EUCJP               65
#define OPC_CHARSET_EUC                	OPC_CHARSET_EUCJP
#define OPC_CHARSET_UCS2                67
#define OPC_CHARSET_ACP932              66
#define OPC_CHARSET_NT_ANSI_JP         	OPC_CHARSET_ACP932
#define OPC_CHARSET_NT_UNICODE_JP      	OPC_CHARSET_UCS2
#define OPC_CHARSET_NT_OEM_JP          	OPC_CHARSET_ACP932
#define OPC_CHARSET_UTF8                69
#define OPC_CHARSET_EUCKR               70
#define OPC_CHARSET_EUCTW               71
#define OPC_CHARSET_GB2312              72
#define OPC_CHARSET_BIG5                73
#define OPC_CHARSET_CCDC                74

/* installation methods */
#define OPC_INSTALL_OpC                 0
#define OPC_INSTALL_SD                  1
#define OPC_INSTALL_OpC_ASYNC           2
#define OPC_INSTALL_SD_ASYNC            3

/* network types */
#define OPC_NETWORK_NO_NODE             0
#define OPC_NETWORK_IP                  1
#define OPC_NETWORK_OTHER               5
#define OPC_NETWORK_UNKNOWN             6

/* pattern types */
#define OPC_NODE_PATTERN_IP_ADDR        253
#define OPC_NODE_PATTERN_IP_NAME        254
#define OPC_NODE_PATTERN_OTHER          255

#define OPC_MGDNODE_NETWORK_NO_NODE    	OPC_NETWORK_NO_NODE
#define OPC_MGDNODE_NETWORK_IP         	OPC_NETWORK_IP
#define OPC_MGDNODE_NETWORK_OTHER      	OPC_NETWORK_OTHER
#define OPC_MGDNODE_NETWORK_UNKNOWN    	OPC_NETWORK_UNKNOWN

/* communication types */
#define OPC_COMM_UNSPEC_COMM            0
#define OPC_COMM_RPC_NCS                1
#define OPC_COMM_RPC_DCE_TCP            2
#define OPC_COMM_RPC_DCE_UDP            3
#define OPC_COMM_RPC_SUN_TCP            4
#define OPC_COMM_RPC_SUN_UDP            5
#define OPC_COMM_SOCKET_TCP             6
#define OPC_COMM_SOCKET_UDP             7
#define OPC_COMM_OPC_INTERFACE          8
#define OPC_COMM_RPC_LOCAL_RPC          9

/* DCE security level */
#define OPC_AUTH_NONE                    0x0000
#define OPC_AUTH_AT_CONNECTION           0x0001
#define OPC_AUTH_EACH_CALL               0x0002
#define OPC_AUTH_EACH_PACKET             0x0003
#define OPC_AUTH_EACH_PACKET_CHECKSUM    0x0004
#define OPC_AUTH_EACH_PACKET_ENCRYPT     0x0005

/* security types */
#define OPC_SEC_NONE                     0
#define OPC_SEC_PUBLIC_KEY               1
#define OPC_SEC_SECRET_KEY               2

/* depot access mode */
#define OPC_DEPOT_FTP_METHOD             1
#define OPC_DEPOT_DEFAULT_METHOD         OPC_DEPOT_FTP_METHOD
#define OPC_DEPOT_SD_METHOD              2
#define OPC_DEPOT_RCP_METHOD             3

/* license types */
#define OPC_LICENSE_TYPE                 1
#define OPC_NO_LICENSE_TYPE              2
#define OPC_HP_LICENSE_TYPE              3

/* Template Types */
#define OPC_UNKNOWN_TEMPLATE             0x0000L
#define OPC_CONSOLE_TEMPLATE             0x0001L
#define OPC_OPCMSG_TEMPLATE              0x0002L
#define OPC_LOGFILE_TEMPLATE             0x0004L
#define OPC_MONITOR_TEMPLATE             0x0008L
#define OPC_SNMP_TEMPLATE                0x0010L
#define OPC_EC_TEMPLATE                  0x0020L
#define OPC_TEMPLATE_GROUP               0x0040L
#define OPC_SCHEDULE_TEMPLATE            0x0100L

/* User roles (out of CSM_C_XXX) */
#define OPC_ROLE_UNKNOWN                 -1
#define OPC_ROLE_OPERATOR                0
#define OPC_ROLE_ADMINISTRATOR           1
#define OPC_ROLE_TEMPLATE_ADMIN          3
#define OPC_ROLE_PROFILE                 4


/* Agent types */
#define OPC_AGTTYPE_ITO_AGT              0
#define OPC_AGTTYPE_MANAGEX_AGT          1
#define OPC_IS_MLM                       32768
#define OPC_AGTTYPE_MANAGEX_MLM_AGT      32769  /* (OPC_IS_MLM | OPC_AGTTYPE_MANAGEX_AGT) */



/* opcregconf message event flags */
#define OPC_MSG_EVENT_ACK                  0x00000001     /* 2^0 */
#define OPC_MSG_EVENT_UNACK                0x00000002
#define OPC_MSG_EVENT_OWN                  0x00000004
#define OPC_MSG_EVENT_DISOWN	           0x00000008
#define OPC_MSG_EVENT_ANNO                 0x00000010
#define OPC_MSG_EVENT_NO_ANNO 	           0x00000020
#define OPC_MSG_EVENT_ESCALATED	           0x00000040
#define OPC_MSG_EVENT_ESCALATED_FROM       0x00000080
#define OPC_MSG_EVENT_AA_START	           0x00000100
#define OPC_MSG_EVENT_AA_END	           0x00000200
#define OPC_MSG_EVENT_OA_START	           0x00000400
#define OPC_MSG_EVENT_OA_END	           0x00000800
#define OPC_MSG_EVENT_HIGHLIGHT	           0x00001000
#define OPC_MSG_EVENT_BUFFER               0x00002000
#define OPC_MSG_EVENT_UNBUFFER             0x00004000
#define OPC_MSG_EVENT_MODIFY               0x00008000
/* Event mask */
#define OPC_MSG_EVENT_ALL                  0x0000ffff


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

/* configuration distribution flags */
/*----------------------------------*/
#define OPC_DISTRIB_TEMPLATES          	   1
#define OPC_DISTRIB_ACTIONS            	   2
#define OPC_DISTRIB_MONITORS           	   4
#define OPC_DISTRIB_COMMANDS           	   8
#define OPC_DISTRIB_ALL                	   0x000fL

/* separator character in  layout group paths */
#define OPC_LAYOUTGRP_PATH_SEP             "/"

/* application defines */
/* constants for the terminal types of applications */
#define OPC_APPL_NOTERM      	      	   0
#define OPC_APPL_TERMINAL    	      	   1
#define OPC_APPL_TERMOUT     	      	   2

/* constants for application types */
#define OPC_APPL_INTERNAL      	     	   0
#define OPC_APPL_INTEGRATED    	     	   1
#define OPC_APPL_OV            	     	   2

/* constants for application actions */
#define OPC_APPL_INTERNAL_VIRTUAL          0
#define OPC_APPL_INTERNAL_PHYSICAL         1
#define OPC_APPL_INTERNAL_BROADCAST        2
#define OPC_APPL_INTERNAL_VIRTUAL_S        3

/* constants for start application targets */
#define OPC_APPL_START_ON_TARGET_NODES     0
#define OPC_APPL_START_ON_SELECTED_NODES   1
#define OPC_APPL_START_ON_MGMT_SRV         2
#define OPC_APPL_START_ON_LOCAL_CLNT       3
#define OPC_APPL_START_ON_WWW_BROWSER      4




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


/* Server Function prototypes. */
/*-----------------------------*/

/* ITO Connection API */
OPCLIBAPI int OPCAPI opc_connect ( 
				  const char      *operator_name,
				  const char      *operator_pwd,
				  opc_connection  *opc_conn );

OPCLIBAPI int OPCAPI opc_disconnect ( opc_connection *opc_conn );


OPCLIBAPI int OPCAPI opcconn_get_capability (
				  opc_connection   opc_conn,
				  int              attrib,
				  void            *value );

OPCLIBAPI int OPCAPI opcconn_set_capability (
				  opc_connection   opc_conn,
				  int              attrib,
				  void            *value );

/* ITO Server Message API */
OPCLIBAPI char * OPCAPI opcmsg_get_instructions (
				  const opc_connection  opc_conn,
				  const opcdata         msgid );

OPCLIBAPI int OPCAPI opcmsg_get (
				  const opc_connection  opc_conn,
				  const opcdata         message_id,
				  opcdata               message_data );

OPCLIBAPI int OPCAPI opcmsg_ack (
				  const opc_connection  opc_conn,
				  const opcdata         msgid );

OPCLIBAPI int OPCAPI opcmsg_own (
				  const opc_connection  opc_conn,
				  const opcdata         msgid );

OPCLIBAPI int OPCAPI opcmsg_disown (
				  const opc_connection  opc_conn,
				  const opcdata         msgid );

OPCLIBAPI int OPCAPI opcmsg_unack (
				  const opc_connection  opc_conn,
				  const opcdata         msgid );

OPCLIBAPI int OPCAPI opcmsg_escalate (
				  const opc_connection  opc_conn,
				  const opcdata         msgid );

OPCLIBAPI int OPCAPI opcmsg_start_op_action (
				  const opc_connection  opc_conn,
				  const opcdata         msgid );

OPCLIBAPI int OPCAPI opcmsg_start_auto_action (
				  const opc_connection  opc_conn,
				  const opcdata         msgid );

OPCLIBAPI int OPCAPI opcmsg_get_msgids (
				  const opc_connection  opc_conn,
				  const opcdata         msg_id,
				  opcdata               curr_msgids );

OPCLIBAPI int OPCAPI opcmsg_select (
				  const opc_connection  opc_conn,
				  const opcdata         msg_id,
				  const char*           operator_name );

OPCLIBAPI int OPCAPI opcmsg_unbuffer (
				  const opc_connection opc_conn,
				  const opcdata        msg_id );

OPCLIBAPI int OPCAPI opcmsg_modify (
				  const opc_connection opc_conn,
				  const opcdata        msg_id,
				  const opcdata        mod_msg );

/* ITO Annotation API */
OPCLIBAPI int OPCAPI opcanno_get_list (
				  const opc_connection  opc_conn,
				  const opcdata         msg_id,
				  opcdata               annotations );

OPCLIBAPI int OPCAPI opcanno_add (
				  const opc_connection  opc_conn,
				  const opcdata         msg_id,
				  opcdata               annotation );

OPCLIBAPI int OPCAPI opcanno_modify (
				  const opc_connection  opc_conn,
				  const opcdata         msg_id,
				  opcdata               annotation );

OPCLIBAPI int OPCAPI opcanno_delete (
				  const opc_connection  opc_conn,
				  const opcdata         msg_id,
				  opcdata               annotation );


/* Node Configuration */
OPCLIBAPI int OPCAPI opcnode_get (
				  const opc_connection  opc_conn,
				  const opcdata         mgd_node,
				  opcdata               node_conf);

OPCLIBAPI int OPCAPI opcnode_get_list (
				  const opc_connection  opc_conn,
				  opcdata               container );

OPCLIBAPI int OPCAPI opcnode_get_defaults (
				  const opc_connection  opc_conn,
				  const opcdata         mgd_node,
				  opcdata               node_conf );

OPCLIBAPI int OPCAPI opcnode_add (
				  const opc_connection  opc_conn,
				  opcdata               node_conf );

OPCLIBAPI int OPCAPI opcnode_modify (
				  const opc_connection  opc_conn,
				  const opcdata         mgd_node,
				  const opcdata         new_node_config );

OPCLIBAPI int OPCAPI opcnode_delete (
				  const opc_connection  opc_conn,
				  const opcdata         node );

OPCLIBAPI int OPCAPI opcnode_get_templates (
				  const opc_connection  opc_conn,
				  const opcdata         mgd_node,
				  opcdata               templates );

OPCLIBAPI int OPCAPI opcnode_assign_templates (
				  const opc_connection  opc_conn,
				  opcdata               managed_node,
				  opcdata               template_list ); 

OPCLIBAPI int OPCAPI opcnode_deassign_templates (
				  const opc_connection  opc_conn,
				  opcdata               managed_node,
				  opcdata               template_list ); 

/* Node group Configuration */
OPCLIBAPI int OPCAPI opcnodegrp_get (
				  const opc_connection  opc_conn,
				  const opcdata         node_group,
				  opcdata               nodegrp_conf );

OPCLIBAPI int OPCAPI opcnodegrp_get_list (
				  const opc_connection  opc_conn,
				  opcdata               container );

OPCLIBAPI int OPCAPI opcnodegrp_get_nodes (
				  const opc_connection  opc_conn,
				  const opcdata         node_group,
				  opcdata               managed_nodes);

OPCLIBAPI int OPCAPI opcnodegrp_add (
				  const opc_connection  opc_conn,
				  opcdata               node_group );

OPCLIBAPI int OPCAPI opcnodegrp_delete (
				  const opc_connection  opc_conn,
				  const opcdata         node_group );

OPCLIBAPI int OPCAPI opcnodegrp_modify (
				  const opc_connection  opc_conn,
				  const opcdata         node_grp,
				  const opcdata         new_node_group );

OPCLIBAPI int OPCAPI opcnodegrp_assign_nodes (
				  const opc_connection  opc_conn,
				  opcdata               node_group,
				  opcdata               nodes );

OPCLIBAPI int OPCAPI opcnodegrp_deassign_nodes (
				  const opc_connection  opc_conn,
				  opcdata               node_group,
				  opcdata               nodes );

OPCLIBAPI int OPCAPI opcnodegrp_get_templates (
				  const opc_connection  opc_conn,
				  opcdata               node_group,
				  opcdata               templates );

OPCLIBAPI int OPCAPI opcnodegrp_assign_templates (
				  const opc_connection  opc_conn,
				  opcdata               node_group,
				  opcdata               templates );

OPCLIBAPI int OPCAPI opcnodegrp_deassign_templates (
				  const opc_connection  opc_conn,
				  opcdata               node_group,
				  opcdata               templates );

/* Message Group Configuration */
OPCLIBAPI int OPCAPI opcmsggrp_get_list (
				  const opc_connection 	opc_conn,
				  opcdata              	groups );

OPCLIBAPI int OPCAPI opcmsggrp_get (
				  const opc_connection  opc_cconn,
				  opcdata               msg_group,
				  opcdata               group_conf );

OPCLIBAPI int OPCAPI opcmsggrp_add (
				  const opc_connection  opc_cconn,
				  opcdata               msg_group );

OPCLIBAPI int OPCAPI opcmsggrp_modify (
				  const opc_connection  opc_cconn,
				  const opcdata         msg_group,
				  opcdata               mod_msggrp );

OPCLIBAPI int OPCAPI opcmsggrp_delete (
				  const opc_connection  opc_cconn,
				  opcdata               msg_group );

/* Templates */
OPCLIBAPI int OPCAPI opctempl_get_list (
				  const opc_connection  opc_conn,
				  opcdata               templs );

OPCLIBAPI int OPCAPI opctempl_delete (
				  const opc_connection  opc_conn,
				  opcdata               templ );

/* Templatefile configuration */
OPCLIBAPI int OPCAPI opctemplfile_add (
				  const opc_connection  opc_conn,
				  const char *          file,
				  opcdata               templ_list );

OPCLIBAPI int OPCAPI opctemplfile_modify (
				  const opc_connection  opc_conn,
				  const char *          file,
				  opcdata               templ_list );

OPCLIBAPI int OPCAPI opctemplfile_get (
				  const opc_connection  opc_conn,
				  const opcdata         templ,
				  const char *          file );

/* Template group configuration */
OPCLIBAPI int OPCAPI opctemplgrp_get (
				  const opc_connection  opc_conn,
				  opcdata               templgrp,
				  opcdata               templgrp_conf);

OPCLIBAPI int OPCAPI opctemplgrp_get_list (
				  const opc_connection  opc_conn,
				  opcdata               templgrps );

OPCLIBAPI int OPCAPI opctemplgrp_add (
				  const opc_connection  opc_conn,
				  opcdata               templgrp );

OPCLIBAPI int OPCAPI opctemplgrp_modify (
				  const opc_connection  opc_conn,
				  const opcdata         templgrp,
				  opcdata               mod_templgrp );

OPCLIBAPI int OPCAPI opctemplgrp_delete (
				  const opc_connection  opc_conn,
				  opcdata               templgrp );

OPCLIBAPI int OPCAPI opctemplgrp_get_templates ( 
				  const opc_connection  opc_conn,
				  opcdata               templgrp,
				  opcdata               template_list );

OPCLIBAPI int OPCAPI opctemplgrp_assign_templates ( 
				  const opc_connection  opc_conn,
				  opcdata               templgrp,
				  opcdata               template_list );

OPCLIBAPI int OPCAPI opctemplgrp_deassign_templates (
				  const opc_connection  opc_conn,
				  opcdata               templgrp,
				  opcdata               template_list );

/*@
 * Group:   opcnodehier
 *          This API group consists of functions to create an 
 *          modify ITO Node Hierarchies
 * ITOName: Node Hierarchy Configuration API
 * Related: opclayoutgrp opcnode
 * OPCDATA: OPCDTYPE_NODEHIER OPCDTYPE_LAYOUT_GROUP OPCDTYPE_NODE
 * Manual:  The node hierarchy API provides 
 *          a set of functions to configure ITO
 *          node hierarchies. To use these 
 *          functions, it is necessary to connect to 
 *          the management server as administrator, 
 *          (see opc_connect(3)).
 * 
 *          A node hierarchy is specified
 *          either by name or by the uuid. If the uuid
 *          is given, a specified name will be ignored.
 *
 *          Error information is written to the error 
 *          logfile /var/opt/OV/log/OpC/mgmt_sv/opcerror
 *          on the management server.
 *          Memory for the configuration data is allocated 
 *          on the heap. The caller is responsible for 
 *          allocating (see opcdata_create(3) or 
 *          opcdata_clear(3)) and freeing (see opcdata_free(3)) 
 *          the needed memory.
 */
OPCLIBAPI int OPCAPI opcnodehier_get (
				   opc_connection        opc_conn,
				   const opcdata         nodehier,
				   opcdata               nodehier_conf );

OPCLIBAPI int OPCAPI opcnodehier_get_list (
				   opc_connection        opc_conn,
				   opcdata               nodehier_list );

OPCLIBAPI int OPCAPI opcnodehier_add (
				   opc_connection        opc_conn,
				   opcdata               nodehier );

OPCLIBAPI int OPCAPI opcnodehier_delete (
				   opc_connection        opc_conn,
				   opcdata               nodehier );

OPCLIBAPI int OPCAPI opcnodehier_modify (
				   opc_connection        opc_conn,
				   const opcdata         nodehier,
				   opcdata               nodehier_conf);

OPCLIBAPI int OPCAPI opcnodehier_copy (
				   opc_connection        opc_conn,
				   const opcdata         src_nodehier,
				   opcdata               dst_nodehier);

OPCLIBAPI int OPCAPI opcnodehier_get_nodes (
				   opc_connection        opc_conn,
				   const opcdata         nodehier,
				   const opcdata         layoutgrp,
				   opcdata               nodes);

OPCLIBAPI int OPCAPI opcnodehier_get_all_nodes (
				   opc_connection        opc_conn,
				   const opcdata         nodehier,
				   opcdata               node_list);

OPCLIBAPI int OPCAPI opcnodehier_move_nodes (
				   opc_connection        opc_conn,
				   const opcdata         nodehier,
				   const opcdata         to_layoutgrp,
				   opcdata               nodes);

OPCLIBAPI int OPCAPI opcnodehier_add_layoutgrp (
				   opc_connection        opc_conn,
				   const opcdata         nodehier,
				   const opcdata         parentlayoutgrp,
				   opcdata               layoutgrp);

OPCLIBAPI int OPCAPI opcnodehier_get_layoutgrp (
				   opc_connection        opc_conn,
				   const opcdata         nodehier,
				   opcdata               layoutgrp);

OPCLIBAPI int OPCAPI opcnodehier_get_all_layoutgrps (
				   opc_connection        opc_conn,
				   const opcdata         nodehier,
				   opcdata               layoutgrp_list);

OPCLIBAPI int OPCAPI opcnodehier_modify_layoutgrp (
				   opc_connection        opc_conn,
				   const opcdata         nodehier,
				   opcdata               layoutgrp,
				   opcdata               layoutgrp_conf);

OPCLIBAPI int OPCAPI opcnodehier_move_layoutgrp (
				   opc_connection        opc_conn,
				   const opcdata         nodehier,
				   const opcdata         to_layoutgrp,
				   opcdata               layoutgrp);

OPCLIBAPI int OPCAPI opcnodehier_move_layoutgrps (
				   opc_connection        opc_conn,
				   const opcdata         nodehier,
				   const opcdata         to_layoutgrp,
				   opcdata               layoutgrp_list);

OPCLIBAPI int OPCAPI opcnodehier_delete_layoutgrp (
				   opc_connection        opc_conn,
				   const opcdata         nodehier,
				   opcdata               layoutgrp);

OPCLIBAPI int OPCAPI opcnodehier_get_layoutgrps(
                                   opc_connection        opc_conn,
				   const opcdata         nodehier,
				   const opcdata         layoutgroup, 
				   opcdata               layoutgroup_list);

OPCLIBAPI int OPCAPI opcnodehier_get_all_layoutgrps(
                                   opc_connection        opc_conn,
				   const opcdata         nodehier,
				   opcdata               layoutgroup_list);

OPCLIBAPI int OPCAPI opcnodehier_get_nodeparent(
                                   opc_connection        opc_conn,
				   const opcdata         nodehier,
				   opcdata               node,
                                   opcdata               parent_group);

/*@
 * Group:   opcmsgregrp
 *          This API group consists of functions to create an 
 *          modify ITO message regroup conditions
 * ITOName: Message Regroup Condition Configuration API
 * Related: 
 * OPCDATA: OPCDTYPE_REGROUP_COND
 * Manual:  The message regroup condition API provides 
 *          a set of functions to configure ITO
 *          message regroup conditions. To use these 
 *          functions, it is necessary to connect to 
 *          the management server as administrator, 
 *          (see opc_connect(3)).
 * 
 *          A message regroup condition is specified
 *          either by name or by the uuid. If the uuid
 *          is given, a specified name will be ignored.
 *
 *          Error information is written to the error 
 *          logfile /var/opt/OV/log/OpC/mgmt_sv/opcerror
 *          on the management server.
 *          Memory for the configuration data is allocated 
 *          on the heap. The caller is responsible for 
 *          allocating (see opcdata_create(3) or 
 *          opcdata_clear(3)) and freeing (see opcdata_free(3)) 
 *          the needed memory.
 */

OPCLIBAPI int OPCAPI opcmsgregrp_add(
 /* inout */                         opc_connection opc_conn,
 /* inout */                         opcdata     mcond);

OPCLIBAPI int OPCAPI opcmsgregrp_modify(
 /* inout */                         opc_connection opc_conn,
 /* in    */                         opcdata        mcond,
 /* inout */                         opcdata        mcond_conf);

OPCLIBAPI int OPCAPI opcmsgregrp_delete(
 /* inout */                         opc_connection opc_conn,
 /* inout */                         opcdata        mcond);

OPCLIBAPI int OPCAPI opcmsgregrp_get(
 /* inout */                         opc_connection opc_conn,
 /* in    */                         opcdata        mcond,
 /* out   */                         opcdata        mcond_conf);

OPCLIBAPI int OPCAPI opcmsgregrp_get_list(
 /* inout */                         opc_connection opc_conn,
 /* out   */                         opcdata     mcond_list);

OPCLIBAPI int OPCAPI opcmsgregrp_move(
 /* inout */                         opc_connection opc_conn,
 /* inout */                         opcdata        mcond,
 /* in    */                         unsigned int   to_pos);

/*@
 * Group:   opcappl
 *          The application API provides a set of functions
 *          to configure and start ITO applications.
 * ITOName: Application Configuration API
 * Related: opcuser opcprofile opcapplgrp
 * OPCDATA: OPCDTYPE_APPL_CONFIG
 * Manual:  The application API provides 
 *          a set of functions to configure ITO
 *          applications. To use these 
 *          functions, except for opcappl_start(), it is necessary to connect to 
 *          the management server as administrator 
 *          (see opc_connect(3)). opcappl_start() can be called with
 *          a connection of any valid user.
 *
 *          An application is specified
 *          either by name or by the uuid. If the uuid
 *          is given, a specified name will be ignored.
 *
 *          Error information is written to the error 
 *          logfile /var/opt/OV/log/OpC/mgmt_sv/opcerror
 *          on the management server.
 *          Memory for the configuration data is allocated 
 *          on the heap. The caller is responsible for 
 *          allocating (see opcdata_create(3) or 
 *          opcdata_clear(3)) and freeing (see opcdata_free(3)) 
 *          the needed memory.
 */

OPCLIBAPI int OPCAPI opcappl_add (
 /* inout */		 	opc_connection opc_conn, 
 /* in    */		 	opcdata        parentgrp,
 /* inout */		 	opcdata        appl_conf);

OPCLIBAPI int OPCAPI opcappl_modify (
 /* inout */               	opc_connection opc_conn,
 /* in    */               	const opcdata  appl,
 /* inout */               	opcdata        appl_conf);

OPCLIBAPI int OPCAPI opcappl_delete (
 /* inout */               	opc_connection opc_conn,
 /* inout */               	opcdata        appl);

OPCLIBAPI int OPCAPI opcappl_get (
 /* inout */            	opc_connection opc_conn,
 /* in    */            	const opcdata  appl,
 /* out   */            	opcdata        appl_conf);

OPCLIBAPI int OPCAPI opcappl_get_list (
 /* inout */            	opc_connection opc_conn,
 /* out   */            	opcdata        appl_list);

/* ITO Application API */
OPCLIBAPI int OPCAPI opcappl_start (
 /* inout */			const opc_connection  opc_conn,
 /* in    */			const opcdata         application,
 /* in    */			const opcdata         node_list,
 /* in    */			const char           *app_exec_id );

/*@
 * Group:   opcapplgrp
 *          The application group API provides a set of 
 *          functions to configure ITO application groups.
 * ITOName: Applicationgroup Configuration API
 * Related: opcuser opcprofile opcappl
 * OPCDATA: OPCDTYPE_APPL_CONF
 * Manual:  The application group API provides 
 *          a set of functions to configure ITO
 *          application groups. To use these 
 *          functions, it is necessary to connect to 
 *          the management server as administrator, 
 *          (see opc_connect(3)).
 * 
 *          An application group is specified
 *          either by name or by the uuid. If the uuid
 *          is given, a specified name will be ignored.
 *
 *          Error information is written to the error 
 *          logfile /var/opt/OV/log/OpC/mgmt_sv/opcerror
 *          on the management server.
 *          Memory for the configuration data is allocated 
 *          on the heap. The caller is responsible for 
 *          allocating (see opcdata_create(3) or 
 *          opcdata_clear(3)) and freeing (see opcdata_free(3)) 
 *          the needed memory.
 */

OPCLIBAPI int OPCAPI opcapplgrp_add  (
 /* inout */		 	   opc_connection opc_conn, 
 /* in    */                       opcdata        parentgrp,
 /* inout */		 	   opcdata        applgrp);

OPCLIBAPI int OPCAPI opcapplgrp_modify (
 /* inout */               	   opc_connection opc_conn,
 /* in    */               	   const opcdata  applgrp,
 /* inout */               	   opcdata        applgrp_conf);

OPCLIBAPI int OPCAPI opcapplgrp_delete (
 /* inout */               	   opc_connection opc_conn,
 /* inout */               	   opcdata        applgrp);

OPCLIBAPI int OPCAPI opcapplgrp_get (
 /* inout */            	   opc_connection opc_conn,
 /* in    */            	   const opcdata  applgrp,
 /* out   */            	   opcdata        applgrp_conf);

OPCLIBAPI int OPCAPI opcapplgrp_get_list (
 /* inout */            	   opc_connection opc_conn,
 /* out   */            	   opcdata        applgrp_list);

OPCLIBAPI int OPCAPI opcapplgrp_assign_appls (
 /* inout */            	   opc_connection opc_conn,
 /* in    */            	   const opcdata  applgrp,
 /* inout */            	   opcdata        appl_list);

OPCLIBAPI int OPCAPI opcapplgrp_deassign_appls (
 /* inout */            	   opc_connection opc_conn,
 /* in    */            	   const opcdata  applgrp,
 /* inout */            	   opcdata        appl_list);

OPCLIBAPI int OPCAPI opcapplgrp_assign_applgrps (
 /* inout */            	   opc_connection opc_conn,
 /* in    */            	   const opcdata  applgrp,
 /* inout */            	   opcdata        applgrp_list);

OPCLIBAPI int OPCAPI opcapplgrp_deassign_applgrps (
 /* inout */            	   opc_connection opc_conn,
 /* in    */            	   const opcdata  applgrp,
 /* inout */            	   opcdata        applgrp_list);

OPCLIBAPI int OPCAPI opcapplgrp_get_appls (
 /* inout */            	   opc_connection opc_conn,
 /* in    */            	   opcdata        applgrp,
 /* out   */            	   opcdata        appl_list);

OPCLIBAPI int OPCAPI opcapplgrp_get_applgrps (
 /* inout */            	   opc_connection opc_conn,
 /* in    */            	   opcdata        applgrp,
 /* out   */            	   opcdata        applgrp_list);

/*@ 
 * Group: opcuser 
 *          The user API provides a set of functions 
 *          to configure ITO users (an administrator, 
 *          operators and template administrators). 
 * ITOName: User Configuration API
 * Related: opcprofile opcappl opcapplgrp opcnodehier
 * OPCDATA: OPCDTYPE_USER_CONFIG
 * Manual:  The user API provides a set of functions 
 *          to configure ITO users (an administrator, 
 *          operators and template administrators). 
 *    
 *          To use these functions, it is necessary 
 *          to connect to the management server as 
 *          administrator (see opc_connect(3)).
 * 
 *          A user is specified either by name or by
 *          the uuid. If the uuid is given, a specified
 *          name will be ignored.
 *
 *          Error information is written to the error 
 *          logfile /var/opt/OV/log/OpC/mgmt_sv/opcerror
 *          on the management server.
 *          Memory for the configuration data is allocated 
 *          on the heap. The caller is responsible for 
 *          allocating (see opcdata_create(3) or 
 *          opcdata_clear(3)) and freeing (see opcdata_free(3)) 
 *          the needed memory.
 */

OPCLIBAPI int OPCAPI  opcuser_add (
 /* inout */            	   opc_connection opc_conn,
 /* inout */            	   opcdata        user);

OPCLIBAPI int OPCAPI  opcuser_delete (
 /* inout */            	   opc_connection opc_conn,
 /* inout */            	   opcdata        user);

OPCLIBAPI int OPCAPI  opcuser_get (
 /* inout */            	   opc_connection opc_conn,
 /* in    */            	   const opcdata  user,
 /* out   */            	   opcdata        user_conf);

OPCLIBAPI int OPCAPI  opcuser_modify (
 /* inout */            	   opc_connection opc_conn,
 /* in    */            	   const opcdata  user,
 /* inout */            	   opcdata        mod_user);

OPCLIBAPI int OPCAPI  opcuser_get_list (
 /* inout */            	   opc_connection opc_conn,
 /* out   */            	   opcdata        user_list);

OPCLIBAPI int OPCAPI  opcuser_assign_appls (
 /* inout */            	   opc_connection opc_conn,
 /* in    */            	   const opcdata  user,
 /* inout */            	   opcdata        appl_list);

OPCLIBAPI int OPCAPI  opcuser_deassign_appls (
 /* inout */            	   opc_connection opc_conn,
 /* in    */            	   const opcdata  user,
 /* inout */            	   opcdata        appl_list);

OPCLIBAPI int OPCAPI  opcuser_assign_applgrps (
 /* inout */            	   opc_connection opc_conn,
 /* in    */            	   const opcdata  user,
 /* inout */            	   opcdata        applgrp_list);

OPCLIBAPI int OPCAPI  opcuser_deassign_applgrps (
 /* inout */            	   opc_connection opc_conn,
 /* in    */            	   const opcdata  user,
 /* inout */            	   opcdata        applgrp_list);

OPCLIBAPI int OPCAPI  opcuser_get_appls (
 /* inout */            	   opc_connection opc_conn,
 /* in    */            	   opcdata        user,
 /* inout */            	   opcdata        appl_list);

OPCLIBAPI int OPCAPI  opcuser_get_applgrps (
 /* inout */            	   opc_connection opc_conn,
 /* in    */            	   opcdata        user,
 /* out   */            	   opcdata        appl_list);

OPCLIBAPI int OPCAPI  opcuser_assign_resps (
 /* inout */            	   opc_connection opc_conn,
 /* in    */            	   const opcdata  user,
 /* inout */            	   opcdata        resp_list);

OPCLIBAPI int OPCAPI  opcuser_deassign_resps (
 /* inout */            	   opc_connection opc_conn,
 /* in    */            	   const opcdata  user,
 /* inout */            	   opcdata        resp_list);

OPCLIBAPI int OPCAPI  opcuser_get_resps (
 /* inout */            	   opc_connection opc_conn,
 /* in    */            	   opcdata        user,
 /* out   */            	   opcdata        resp_list);

OPCLIBAPI int OPCAPI  opcuser_assign_profiles (
 /* inout */            	   opc_connection opc_conn,
 /* in    */            	   const opcdata  user,
 /* inout */            	   opcdata        profile_list);

OPCLIBAPI int OPCAPI  opcuser_deassign_profiles (
 /* inout */            	   opc_connection opc_conn,
 /* in    */            	   const opcdata  user,
 /* inout */            	   opcdata        profile_list);

OPCLIBAPI int OPCAPI  opcuser_get_profiles (
 /* inout */            	   opc_connection opc_conn,
 /* in    */            	   opcdata        user,
 /* out   */            	   opcdata        profile_list);

OPCLIBAPI int OPCAPI  opcuser_assign_nodehier (
 /* inout */            	   opc_connection opc_conn,
 /* in    */            	   const opcdata  user,
 /* inout */            	   opcdata        nodehier);

OPCLIBAPI int OPCAPI  opcuser_get_nodehier (
 /* inout */            	   opc_connection opc_conn,
 /* in    */            	   const opcdata  user,
 /* inout */            	   opcdata        nodehier);

/*@ 
 * Group:  opcprofile
 *          The profile API provides 
 *          a set of functions to configure ITO
 *          profiles.
 * ITOName: User profile Configuration API
 * Related: opcuser opcappl opcapplgrp
 * OPCDATA: OPCDTYPE_USER_CONFIG
 * Manual:  The profile API provides 
 *          a set of functions to configure ITO
 *          profiles.
 *  
 *          To use these functions, it is necessary 
 *          to connect to the management server as 
 *          administrator, (see opc_connect(3)).
 * 
 *          A profile is specified
 *          either by name or by the uuid. If the uuid
 *          is given, a specified name will be ignored.
 *
 *          Error information is written to the error 
 *          logfile /var/opt/OV/log/OpC/mgmt_sv/opcerror
 *          on the management server.
 *          Memory for the configuration data is allocated 
 *          on the heap. The caller is responsible for 
 *          allocating (see opcdata_create(3) or 
 *          opcdata_clear(3)) and freeing (see opcdata_free(3)) 
 *          the needed memory.
 */

OPCLIBAPI int OPCAPI  opcprofile_add (
 /* inout */            	    opc_connection opc_conn,
 /* inout */            	    opcdata        profile);

OPCLIBAPI int OPCAPI  opcprofile_delete (
 /* inout */            	    opc_connection opc_conn,
 /* inout */            	    opcdata        profile);

OPCLIBAPI int OPCAPI  opcprofile_get (
 /* inout */            	    opc_connection opc_conn,
 /* in    */            	    const opcdata  profile,
 /* out   */            	    opcdata        profile_conf);

OPCLIBAPI int OPCAPI  opcprofile_modify (
 /* inout */            	    opc_connection opc_conn,
 /* in    */            	    const opcdata  profile,
 /* inout */            	    opcdata        mod_profile);

OPCLIBAPI int OPCAPI  opcprofile_get_list (
 /* inout */            	    opc_connection opc_conn,
 /* out   */            	    opcdata        profile_list);

OPCLIBAPI int OPCAPI  opcprofile_assign_appls (
 /* inout */            	    opc_connection opc_conn,
 /* in    */            	    const opcdata  profile,
 /* inout */            	    opcdata        appl_list);

OPCLIBAPI int OPCAPI  opcprofile_deassign_appls (
 /* inout */            	    opc_connection opc_conn,
 /* in    */            	    const opcdata  profile,
 /* inout */            	    opcdata        appl_list);

OPCLIBAPI int OPCAPI  opcprofile_assign_applgrps (
 /* inout */            	    opc_connection opc_conn,
 /* in    */            	    const opcdata  profile,
 /* inout */            	    opcdata        applgrp_list);

OPCLIBAPI int OPCAPI  opcprofile_deassign_applgrps (
 /* inout */            	    opc_connection opc_conn,
 /* in    */            	    const opcdata  profile,
 /* inout */            	    opcdata        applgrp_list);

OPCLIBAPI int OPCAPI  opcprofile_get_appls (
 /* inout */            	    opc_connection opc_conn,
 /* in    */            	    opcdata        profile,
 /* out   */            	    opcdata        appl_list);

OPCLIBAPI int OPCAPI  opcprofile_get_applgrps (
 /* inout */            	    opc_connection opc_conn,
 /* in    */            	    opcdata        profile,
 /* out   */            	    opcdata        applgrp_list);

OPCLIBAPI int OPCAPI  opcprofile_assign_resps (
 /* inout */            	    opc_connection opc_conn,
 /* in    */            	    const opcdata  profile,
 /* inout */            	    opcdata        resp_list);

OPCLIBAPI int OPCAPI  opcprofile_deassign_resps (
 /* inout */            	    opc_connection opc_conn,
 /* in    */            	    const opcdata  profile,
 /* inout */            	    opcdata        resp_list);

OPCLIBAPI int OPCAPI  opcprofile_get_resps (
 /* inout */            	    opc_connection opc_conn,
 /* in    */            	    opcdata        profile,
 /* out   */            	    opcdata        resp_list);

OPCLIBAPI int OPCAPI  opcprofile_assign_profiles (
 /* inout */            	    opc_connection opc_conn,
 /* in    */            	    const opcdata  profile,
 /* inout */            	    opcdata        profile_list);

OPCLIBAPI int OPCAPI  opcprofile_deassign_profiles (
 /* inout */            	    opc_connection opc_conn,
 /* in    */            	    const opcdata  profile,
 /* inout */            	    opcdata        profile_list);

OPCLIBAPI int OPCAPI  opcprofile_get_profiles (
 /* inout */            	    opc_connection opc_conn,
 /* in    */            	    opcdata        profile,
 /* out   */            	    opcdata        profile_list);

/*@
 * Group:   opctransaction
 *          This API group consists of functions to start,
 *          commit and rollback a user transaction.
 * ITOName: User Transaction API
 * Related: opcsync
 * OPCDATA:
 * Manual:  The transaction API provides a set of functions
 *          to start, commit and rollback a user transaction.
 *          
 *          If no user transaction is started, ITO works as
 *          with previous releases. The ITO API functions use
 *          their own transaction that finish within the
 *          API function.
 *
 *          opctransaction_start() starts a user transaction.
 *          During the user transaction, the locks are cumulated.
 *
 *          opctransaction_commit() finishes the current user transaction,
 *          all changes of this transaction are committed (made permanent),
 *          and the accumulated locks are released.
 *
 *          opctransaction_rollback() finishes the current user
 *          transaction, all changes of this transaction are rolled back
 *          (undo of all changes), and the accumulated locks are released.
 *          
 *          Error information is written to the error 
 *          logfile /var/opt/OV/log/OpC/mgmt_sv/opcerror
 *          on the management server.
 */

/* ITO Transaction API */
OPCLIBAPI int OPCAPI opctransaction_start ( opc_connection opc_conn );

OPCLIBAPI int OPCAPI opctransaction_commit ( opc_connection opc_conn );

OPCLIBAPI int OPCAPI opctransaction_rollback ( opc_connection opc_conn );

/*@
 * Group:   opcsync
 *          This API group consists of functions to inform
 *          ITO components about configuration changes, they are concerned of.
 * ITOName: config-change synchronisation API
 * Related:  opcconn_set_capability opctransaction
 * OPCDATA:
 * Manual:  The config-change synchronisation API provides a set of
 *          routines to actively inform other ITO components about changes
 *          they should know about.
 *          
 *          opcsync_inform_server() informs the ITO management server
 *          processes about configuration changes since the previous sync-
 *          call or session-begin.
 *          
 *          opcsync_inform_user() informs the ITO operator and administrator
 *          GUIs about configuration changes since the previous sync-
 *          call or session-begin.
 *          
 *          Error information is written to the error 
 *          logfile /var/opt/OV/log/OpC/mgmt_sv/opcerror
 *          on the management server.
 */

/* config change synchronisation */
OPCLIBAPI int OPCAPI opcsync_inform_server ( opc_connection  opc_conn );

OPCLIBAPI int OPCAPI opcsync_inform_user ( opc_connection  opc_conn );

/*@
 * Group:   opc_inform
 *          This API group consists of functions which allow
 *          an ITO user to pass messages to other users.
 * ITOName: inform-user API
 * Related:
 * OPCDATA: OPCDTYPE_INFORM_USER
 * Manual:  The inform user API provides routines to send text messages
 *          to specific ITO users.
 *          
 *          opc_inform_user() forwards a text message to specified
 *          ITO users.
 *          
 *          Error information is written to the error 
 *          logfile /var/opt/OV/log/OpC/mgmt_sv/opcerror
 *          on the management server.
 */

/* send informal message to ITO user(s) */
OPCLIBAPI int OPCAPI opc_inform_user (
				    opc_connection  opc_conn,
				    const opcdata   info );

/* Distribution API */
OPCLIBAPI int OPCAPI opc_distrib (
				    const opc_connection  opc_conn,
				    const int             components,
				    const int             force_update,
				    opcdata               container ); 
				   
/***********************************/
/* Obsolete functions with ITO 5.x */
/***********************************/

/* Obsolete Message functions. Use opcanno_*() instead! */
OPCLIBAPI int OPCAPI opcmsg_add_annotation ( 
				  const opc_connection  opc_conn,
				  const opcdata         msgid,
				  const char           *annotation );

OPCLIBAPI int OPCAPI opcmsg_get_annotations (
				  const opc_connection  opc_conn,
				  const opcdata         msgid,
				  opcdata             **annotations,
				  int                  *anno_count );

/* ITO Configuration Interface (obsoleted by the Config API) */
OPCLIBAPI int OPCAPI opcconf_get_nodes (
				  const opc_connection  opc_conn,
				  opcdata               nodes );

OPCLIBAPI int OPCAPI opcconf_get_msggrps (
				  const opc_connection  opc_conn,
				  opcdata               groups );


/* ITO Application API */
OPCLIBAPI int OPCAPI opcapp_start (
				  const opc_connection  opc_conn,
				  const opcdata         application,
				  const opcdata         node_list,
				  const char           *app_exec_id );

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

/* ITO Server APIs */
/*-----------------*/

/* ITO Connection API */
OPCLIBAPI int     OPCAPI opc_connect();
OPCLIBAPI int     OPCAPI opc_disconnect();
OPCLIBAPI int     OPCAPI opcconn_get_capability();
OPCLIBAPI int     OPCAPI opcconn_set_capability();

/* ITO Server Message API */
OPCLIBAPI int     OPCAPI opcmsg_get();
OPCLIBAPI char *  OPCAPI opcmsg_get_instructions();
OPCLIBAPI int     OPCAPI opcmsg_ack();
OPCLIBAPI int     OPCAPI opcmsg_unack();
OPCLIBAPI int     OPCAPI opcmsg_own();
OPCLIBAPI int     OPCAPI opcmsg_disown();
OPCLIBAPI int     OPCAPI opcmsg_escalate();
OPCLIBAPI int     OPCAPI opcmsg_start_op_action();
OPCLIBAPI int     OPCAPI opcmsg_start_auto_action();
OPCLIBAPI int     OPCAPI opcmsg_select();
OPCLIBAPI int     OPCAPI opcmsg_get_msgids();
OPCLIBAPI int     OPCAPI opcmsg_unbuffer();
OPCLIBAPI int     OPCAPI opcmsg_modify();

/* Annotation API */
OPCLIBAPI int     OPCAPI opcanno_get_list();
OPCLIBAPI int     OPCAPI opcanno_add();
OPCLIBAPI int     OPCAPI opcanno_modify();
OPCLIBAPI int     OPCAPI opcanno_delete();


/* Node Configuration */
OPCLIBAPI int     OPCAPI opcnode_get_list();
OPCLIBAPI int     OPCAPI opcnode_get_defaults();
OPCLIBAPI int     OPCAPI opcnode_add();
OPCLIBAPI int     OPCAPI opcnode_modify();
OPCLIBAPI int     OPCAPI opcnode_delete();
OPCLIBAPI int     OPCAPI opcnode_get_templates();
OPCLIBAPI int     OPCAPI opcnode_assign_templates();
OPCLIBAPI int     OPCAPI opcnode_deassign_templates();

/* Node group Configuration */
OPCLIBAPI int     OPCAPI opcnodegrp_get();
OPCLIBAPI int     OPCAPI opcnodegrp_get_list();
OPCLIBAPI int     OPCAPI opcnodegrp_get_nodes();
OPCLIBAPI int     OPCAPI opcnodegrp_add();
OPCLIBAPI int     OPCAPI opcnodegrp_modify();
OPCLIBAPI int     OPCAPI opcnodegrp_delete();
OPCLIBAPI int     OPCAPI opcnodegrp_assign_nodes();
OPCLIBAPI int     OPCAPI opcnodegrp_deassign_nodes();
OPCLIBAPI int     OPCAPI opcnodegrp_get_templates();
OPCLIBAPI int     OPCAPI opcnodegrp_assign_templates();
OPCLIBAPI int     OPCAPI opcnodegrp_deassign_templates();

/* Message Group Configuration */
OPCLIBAPI int     OPCAPI opcmsggrp_get_list();
OPCLIBAPI int     OPCAPI opcmsggrp_get();
OPCLIBAPI int     OPCAPI opcmsggrp_add();
OPCLIBAPI int     OPCAPI opcmsggrp_modify();
OPCLIBAPI int     OPCAPI opcmsggrp_delete();

  /* Templates */
OPCLIBAPI int 	  OPCAPI opctempl_get_list ();
OPCLIBAPI int 	  OPCAPI opctempl_delete ();

  /* Templatefile configuration */
OPCLIBAPI int 	  OPCAPI opctemplfile_add();
OPCLIBAPI int 	  OPCAPI opctemplfile_modify();
OPCLIBAPI int 	  OPCAPI opctemplfile_get();

  /* Template group configuration */
OPCLIBAPI int 	  OPCAPI opctemplgrp_get_list();
OPCLIBAPI int 	  OPCAPI opctemplgrp_add();
OPCLIBAPI int 	  OPCAPI opctemplgrp_modify();
OPCLIBAPI int 	  OPCAPI opctemplgrp_delete();
OPCLIBAPI int 	  OPCAPI opctemplgrp_get_templates();
OPCLIBAPI int 	  OPCAPI opctemplgrp_assign_templates();
OPCLIBAPI int 	  OPCAPI opctemplgrp_deassign_templates();

  /* Message regroup condition configuration  */
OPCLIBAPI int 	  OPCAPI opcmsgregrp_add();
OPCLIBAPI int 	  OPCAPI opcmsgregrp_modify();
OPCLIBAPI int 	  OPCAPI opcmsgregrp_delete();
OPCLIBAPI int 	  OPCAPI opcmsgregrp_get();
OPCLIBAPI int 	  OPCAPI opcmsgregrp_get_list();
OPCLIBAPI int 	  OPCAPI opcmsgregrp_move();

 /*  Node hierarchy configuration */
OPCLIBAPI int 	  OPCAPI opcnodehier_get();
OPCLIBAPI int 	  OPCAPI opcnodehier_get_list();
OPCLIBAPI int 	  OPCAPI opcnodehier_add();
OPCLIBAPI int 	  OPCAPI opcnodehier_delete();
OPCLIBAPI int 	  OPCAPI opcnodehier_modify();
OPCLIBAPI int 	  OPCAPI opcnodehier_get_nodes();
OPCLIBAPI int 	  OPCAPI opcnodehier_get_all_nodes();
OPCLIBAPI int 	  OPCAPI opcnodehier_move_nodes();
OPCLIBAPI int 	  OPCAPI opcnodehier_add_layoutgrp();
OPCLIBAPI int 	  OPCAPI opcnodehier_get_layoutgrp();
OPCLIBAPI int 	  OPCAPI opcnodehier_modify_layoutgrp();
OPCLIBAPI int 	  OPCAPI opcnodehier_move_layoutgrp();
OPCLIBAPI int 	  OPCAPI opcnodehier_delete_layoutgrp();
OPCLIBAPI int 	  OPCAPI opcnodehier_get_all_layoutgrps();
OPCLIBAPI int 	  OPCAPI opcnodehier_get_layoutgrps();
OPCLIBAPI int 	  OPCAPI opcnodehier_get_all_layoutgrps();

/* Application and Application groups */
OPCLIBAPI int 	  OPCAPI opcappl_get();
OPCLIBAPI int 	  OPCAPI opcappl_get_list();
OPCLIBAPI int 	  OPCAPI opcappl_add();
OPCLIBAPI int 	  OPCAPI opcappl_delete();
OPCLIBAPI int 	  OPCAPI opcappl_modify();
OPCLIBAPI int 	  OPCAPI opcappl_start();

OPCLIBAPI int 	  OPCAPI opcapplgrp_get();
OPCLIBAPI int 	  OPCAPI opcapplgrp_get_list();
OPCLIBAPI int 	  OPCAPI opcapplgrp_add();
OPCLIBAPI int 	  OPCAPI opcapplgrp_delete();
OPCLIBAPI int 	  OPCAPI opcapplgrp_modify();
OPCLIBAPI int 	  OPCAPI opcapplgrp_assign_appls();
OPCLIBAPI int 	  OPCAPI opcapplgrp_deassign_appls();
OPCLIBAPI int 	  OPCAPI opcapplgrp_assign_applgrps();
OPCLIBAPI int 	  OPCAPI opcapplgrp_deassign_applgrps();
OPCLIBAPI int 	  OPCAPI opcapplgrp_get_appls();
OPCLIBAPI int 	  OPCAPI opcapplgrp_get_applgrps();

  /* User and Profiles */
OPCLIBAPI int 	  OPCAPI  opcuser_add ();
OPCLIBAPI int 	  OPCAPI  opcuser_delete();
OPCLIBAPI int 	  OPCAPI  opcuser_get();
OPCLIBAPI int 	  OPCAPI  opcuser_modify();
OPCLIBAPI int 	  OPCAPI  opcuser_get_list();
OPCLIBAPI int 	  OPCAPI  opcuser_assign_appls();
OPCLIBAPI int 	  OPCAPI  opcuser_deassign_appls();
OPCLIBAPI int 	  OPCAPI  opcuser_assign_applgrps();
OPCLIBAPI int 	  OPCAPI  opcuser_deassign_applgrps();
OPCLIBAPI int 	  OPCAPI  opcuser_get_appls();
OPCLIBAPI int 	  OPCAPI  opcuser_get_applgrps();
OPCLIBAPI int 	  OPCAPI  opcuser_assign_resps();
OPCLIBAPI int 	  OPCAPI  opcuser_deassign_resps();
OPCLIBAPI int 	  OPCAPI  opcuser_get_resps();
OPCLIBAPI int 	  OPCAPI  opcuser_assign_profiles();
OPCLIBAPI int 	  OPCAPI  opcuser_deassign_profiles();
OPCLIBAPI int 	  OPCAPI  opcuser_get_profiles();
OPCLIBAPI int 	  OPCAPI  opcuser_assign_nodehier();
OPCLIBAPI int 	  OPCAPI  opcuser_get_nodehier();

OPCLIBAPI int 	  OPCAPI  opcprofile_add();
OPCLIBAPI int 	  OPCAPI  opcprofile_delete();
OPCLIBAPI int 	  OPCAPI  opcprofile_get();
OPCLIBAPI int 	  OPCAPI  opcprofile_modify();
OPCLIBAPI int 	  OPCAPI  opcprofile_get_list();
OPCLIBAPI int 	  OPCAPI  opcprofile_assign_appls();
OPCLIBAPI int 	  OPCAPI  opcprofile_deassign_appls();
OPCLIBAPI int 	  OPCAPI  opcprofile_assign_applgrps();
OPCLIBAPI int 	  OPCAPI  opcprofile_deassign_applgrps();
OPCLIBAPI int 	  OPCAPI  opcprofile_get_applgrps();
OPCLIBAPI int 	  OPCAPI  opcprofile_assign_resps();
OPCLIBAPI int 	  OPCAPI  opcprofile_deassign_resps();
OPCLIBAPI int 	  OPCAPI  opcprofile_get_resps();
OPCLIBAPI int 	  OPCAPI  opcprofile_assign_profiles();
OPCLIBAPI int 	  OPCAPI  opcprofile_deassign_profiles();
OPCLIBAPI int 	  OPCAPI  opcprofile_get_profiles();

/* Transaction API */
OPCLIBAPI int 	  OPCAPI opctransaction_start();
OPCLIBAPI int 	  OPCAPI opctransaction_commit();
OPCLIBAPI int 	  OPCAPI opctransaction_rollback();

/* config change synchronisation */
OPCLIBAPI int 	  OPCAPI opcsync_inform_server();
OPCLIBAPI int 	  OPCAPI opcsync_inform_user();

/* send informal message to ITO user(s) */
OPCLIBAPI int 	  OPCAPI opc_inform_user();

/* Distribution API */
OPCLIBAPI int 	  OPCAPI opc_distrib();

/***********************************/
/* Obsolete functions with ITO 5.x */
/***********************************/

OPCLIBAPI int     OPCAPI opcmsg_get_annotations();
OPCLIBAPI int     OPCAPI opcmsg_add_annotation();
OPCLIBAPI int     OPCAPI opcconf_get_nodes();
OPCLIBAPI int     OPCAPI opcconf_get_msggrps();
OPCLIBAPI int     OPCAPI opcapp_start();


#endif /* __STDC__ */


#ifdef __cplusplus
}
#endif

#endif  /* __OPCAPI_H */

/*
********************************************************************************
* end of opcsvapi.h
********************************************************************************
*/
