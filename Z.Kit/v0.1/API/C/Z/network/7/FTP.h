/* Z Kit C API - Z/network/7/FTP.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_network_7_FTP_H__
#define __Z_network_7_FTP_H__

#define Z_FTP_DEFAULT_SERVER_PORT 21

/* Connection Establishment */

/* Login */
#define Z_FTP_COMMAND_USER
#define Z_FTP_COMMAND_PASS
#define Z_FTP_COMMAND_ACCT
#define Z_FTP_COMMAND_CWD
#define Z_FTP_COMMAND_CDUP
#define Z_FTP_COMMAND_SMNT

/* Logout */
#define Z_FTP_COMMAND_REIN
#define Z_FTP_COMMAND_QUIT

/* Transfer parameters */
#define Z_FTP_COMMAND_PORT
#define Z_FTP_COMMAND_PASV
#define Z_FTP_COMMAND_MODE
#define Z_FTP_COMMAND_TYPE
#define Z_FTP_COMMAND_STRU

/* File action commands */
#define Z_FTP_COMMAND_ALLO
#define Z_FTP_COMMAND_REST
#define Z_FTP_COMMAND_STOR
#define Z_FTP_COMMAND_STOU
#define Z_FTP_COMMAND_RETR
#define Z_FTP_COMMAND_LIST
#define Z_FTP_COMMAND_NLST
#define Z_FTP_COMMAND_APPE
#define Z_FTP_COMMAND_RNFR
#define Z_FTP_COMMAND_RNTO
#define Z_FTP_COMMAND_DELE
#define Z_FTP_COMMAND_RMD
#define Z_FTP_COMMAND_MKD
#define Z_FTP_COMMAND_PWD
#define Z_FTP_COMMAND_ABOR

/* Informational commands */
#define Z_FTP_COMMAND_SYST
#define Z_FTP_COMMAND_STAT
#define Z_FTP_COMMAND_HELP

/* Miscellaneous commands */
#define Z_FTP_COMMAND_SITE
#define Z_FTP_COMMAND_NOOP

#endif /* __Z_network_7_FTP_H__ */
