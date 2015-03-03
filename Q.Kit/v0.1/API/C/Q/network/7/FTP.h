/* Q Kit API - Q/network/7/FTP.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Q_network_7_FTP_H__
#define __Q_network_7_FTP_H__

#define Q_FTP_DEFAULT_SERVER_PORT	21

/* Connection Establishment */

/* Login */
#define Q_FTP_COMMAND_USER
#define Q_FTP_COMMAND_PASS
#define Q_FTP_COMMAND_ACCT
#define Q_FTP_COMMAND_CWD
#define Q_FTP_COMMAND_CDUP
#define Q_FTP_COMMAND_SMNT

/* Logout */
#define Q_FTP_COMMAND_REIN
#define Q_FTP_COMMAND_QUIT

/* Transfer parameters */
#define Q_FTP_COMMAND_PORT
#define Q_FTP_COMMAND_PASV
#define Q_FTP_COMMAND_MODE
#define Q_FTP_COMMAND_TYPE
#define Q_FTP_COMMAND_STRU

/* File action commands */
#define Q_FTP_COMMAND_ALLO
#define Q_FTP_COMMAND_REST
#define Q_FTP_COMMAND_STOR
#define Q_FTP_COMMAND_STOU
#define Q_FTP_COMMAND_RETR
#define Q_FTP_COMMAND_LIST
#define Q_FTP_COMMAND_NLST
#define Q_FTP_COMMAND_APPE
#define Q_FTP_COMMAND_RNFR
#define Q_FTP_COMMAND_RNTO
#define Q_FTP_COMMAND_DELE
#define Q_FTP_COMMAND_RMD
#define Q_FTP_COMMAND_MKD
#define Q_FTP_COMMAND_PWD
#define Q_FTP_COMMAND_ABOR

/* Informational commands */
#define Q_FTP_COMMAND_SYST
#define Q_FTP_COMMAND_STAT
#define Q_FTP_COMMAND_HELP

/* Miscellaneous commands */
#define Q_FTP_COMMAND_SITE
#define Q_FTP_COMMAND_NOOP

#endif /* __Q_network_7_FTP_H__ */
