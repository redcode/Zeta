/* Z Kit - Z/network/7/ED2K.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef _Z_network_7_ED2K_H_
#define _Z_network_7_ED2K_H_

#include <Z/types/base.h>

Z_DEFINE_STRICT_STRUCTURE (
	zuint8	protocol;
	zuint32 size;
	zuint8	opcode;
) ZED2KMessageHeader;

#define Z_ED2K_MESSAGE_HEADER_PROTOCOL_EDONKEY	0xE3
#define Z_ED2K_MESSAGE_HEADER_PROTOCOL_EMULE	0xC5

/* client <-> server (TCP) */

#define Z_ED2K_OPCODE_LOGINREQUEST		0x01 /* <HASH 16><ID 4><PORT 2><1 Tag_set> */
#define Z_ED2K_OPCODE_REJECT			0x05 /* (null) */
#define Z_ED2K_OPCODE_GETSERVERLIST		0x14 /* (null)client->server */
#define Z_ED2K_OPCODE_OFFERFILES		0x15 /* <count 4>(<HASH 16><ID 4><PORT 2><1 Tag_set>)[count] */
#define Z_ED2K_OPCODE_SEARCHREQUEST		0x16 /* <Query_Tree> */
#define Z_ED2K_OPCODE_DISCONNECT		0x18 /* (not verified) */
#define Z_ED2K_OPCODE_GETSOURCES		0x19 /* <HASH 16> */
#define Z_ED2K_OPCODE_SEARCH_USER		0x1A /* <Query_Tree> */
#define Z_ED2K_OPCODE_CALLBACKREQUEST		0x1C /* <ID 4> */
#define Z_ED2K_OPCODE_QUERY_CHATS		0x1D /* (deprecated not supported by server any longer) */
#define Z_ED2K_OPCODE_CHAT_MESSAGE		0x1E /* (deprecated not supported by server any longer) */
#define Z_ED2K_OPCODE_JOIN_ROOM			0x1F /* (deprecated not supported by server any longer) */
#define Z_ED2K_OPCODE_QUERY_MORE_RESULT		0x21 /* (null) */
#define Z_ED2K_OPCODE_GETSOURCES_OBFU		0x23
#define Z_ED2K_OPCODE_SERVERLIST		0x32 /* <count 1>(<IP 4><PORT 2>)[count] server->client */
#define Z_ED2K_OPCODE_SEARCHRESULT		0x33 /* <count 4>(<HASH 16><ID 4><PORT 2><1 Tag_set>)[count] */
#define Z_ED2K_OPCODE_SERVERSTATUS		0x34 /* <USER 4><FILES 4> */
#define Z_ED2K_OPCODE_CALLBACKREQUESTED		0x35 /* <IP 4><PORT 2> */
#define Z_ED2K_OPCODE_CALLBACK_FAIL		0x36 /* (null notverified) */
#define Z_ED2K_OPCODE_SERVERMESSAGE		0x38 /* <len 2><Message len> */
#define Z_ED2K_OPCODE_CHAT_ROOM_REQUEST		0x39 /* (deprecated not supported by server any longer) */
#define Z_ED2K_OPCODE_CHAT_BROADCAST		0x3A /* (deprecated not supported by server any longer) */
#define Z_ED2K_OPCODE_CHAT_USER_JOIN		0x3B /* (deprecated not supported by server any longer) */
#define Z_ED2K_OPCODE_CHAT_USER_LEAVE		0x3C /* (deprecated not supported by server any longer) */
#define Z_ED2K_OPCODE_CHAT_USER			0x3D /* (deprecated not supported by server any longer) */
#define Z_ED2K_OPCODE_IDCHANGE			0x40 /* <NEW_ID 4><server_flags 4><primary_tcp_port 4 (unused)><client_IP_address 4> */
#define Z_ED2K_OPCODE_SERVERIDENT		0x41 /* <HASH 16><IP 4><PORT 2>{1 TAG_SET} */
#define Z_ED2K_OPCODE_FOUNDSOURCES		0x42 /* <HASH 16><count 1>(<ID 4><PORT 2>)[count] */
#define Z_ED2K_OPCODE_USERS_LIST		0x43 /* <count 4>(<HASH 16><ID 4><PORT 2><1 Tag_set>)[count] */
#define Z_ED2K_OPCODE_FOUNDSOURCES_OBFU		0x44 /* <HASH 16><count 1>(<ID 4><PORT 2><obf settings 1>(UserHash16 if obf&0x08))[count] */

/* client <-> server (UDP) */

#define Z_ED2K_OPCODE_GLOBSEARCHREQ3		0x90 /* <1 tag set><search_tree> */
#define Z_ED2K_OPCODE_GLOBSEARCHREQ2		0x92 /* <search_tree> */
#define Z_ED2K_OPCODE_GLOBSERVSTATREQ		0x96 /* (null) */
#define Z_ED2K_OPCODE_GLOBSERVSTATRES		0x97 /* <USER 4><FILES 4> */
#define Z_ED2K_OPCODE_GLOBSEARCHREQ		0x98 /* <search_tree> */
#define Z_ED2K_OPCODE_GLOBSEARCHRES		0x99
#define Z_ED2K_OPCODE_GLOBGETSOURCES		0x9A /* <HASH 16> */
#define Z_ED2K_OPCODE_GLOBGETSOURCES2		0x94 /* <HASH 16><FILESIZE 4> */
#define Z_ED2K_OPCODE_GLOBFOUNDSOURCES		0x9B
#define Z_ED2K_OPCODE_GLOBCALLBACKREQ		0x9C /* <IP 4><PORT 2><client_ID 4> */
#define Z_ED2K_OPCODE_INVALID_LOWID		0x9E /* <ID 4> */
#define Z_ED2K_OPCODE_SERVER_LIST_REQ		0xA0 /* <IP 4><PORT 2> */
#define Z_ED2K_OPCODE_SERVER_LIST_RES		0xA1 /* <count 1> (<ip 4><port 2>)[count] */
#define Z_ED2K_OPCODE_SERVER_DESC_REQ		0xA2 /* (null) */
#define Z_ED2K_OPCODE_SERVER_DESC_RES		0xA3 /* <name_len 2><name name_len><desc_len 2 desc_en> */
#define Z_ED2K_OPCODE_SERVER_LIST_REQ2		0xA4 /* (null) */

/* client <-> client (TCP)*/

#define Z_ED2K_OPCODE_HELLO			0x01 /* 0x10<HASH 16><ID 4><PORT 2><1 Tag_set> */
#define Z_ED2K_OPCODE_SENDINGPART		0x46 /* <HASH 16><von 4><bis 4><Daten len:(von-bis)> */
#define Z_ED2K_OPCODE_REQUESTPARTS		0x47 /* <HASH 16><von[3] 4*3><bis[3] 4*3> */
#define Z_ED2K_OPCODE_FILEREQANSNOFIL		0x48 /* <HASH 16> */
#define Z_ED2K_OPCODE_END_OF_DOWNLOAD		0x49 /* <HASH 16> */
#define Z_ED2K_OPCODE_ASKSHAREDFILES		0x4A /* (null) */
#define Z_ED2K_OPCODE_ASKSHAREDFILESANSWER	0x4B /* <count 4>(<HASH 16><ID 4><PORT 2><1 Tag_set>)[count] */
#define Z_ED2K_OPCODE_HELLOANSWER		0x4C /* <HASH 16><ID 4><PORT 2><1 Tag_set><SERVER_IP 4><SERVER_PORT 2> */
#define Z_ED2K_OPCODE_CHANGE_CLIENT_ID		0x4D /* <ID_old 4><ID_new 4> */
#define Z_ED2K_OPCODE_MESSAGE			0x4E /* <len 2><Message len> */
#define Z_ED2K_OPCODE_SETREQFILEID		0x4F /* <HASH 16> */
#define Z_ED2K_OPCODE_FILESTATUS		0x50 /* <HASH 16><count 2><status(bit array) len:((count+7)/8)> */
#define Z_ED2K_OPCODE_HASHSETREQUEST		0x51 /* <HASH 16> */
#define Z_ED2K_OPCODE_HASHSETANSWER		0x52 /* <count 2><HASH[count] 16*count> */
#define Z_ED2K_OPCODE_STARTUPLOADREQ		0x54 /* <HASH 16> */
#define Z_ED2K_OPCODE_ACCEPTUPLOADREQ		0x55 /* (null) */
#define Z_ED2K_OPCODE_CANCELTRANSFER		0x56 /* (null) */
#define Z_ED2K_OPCODE_OUTOFPARTREQS		0x57 /* (null) */
#define Z_ED2K_OPCODE_REQUESTFILENAME		0x58 /* <HASH 16> (more correctly file_name_request) */
#define Z_ED2K_OPCODE_REQFILENAMEANSWER		0x59 /* <HASH 16><len 4><NAME len> */
#define Z_ED2K_OPCODE_CHANGE_SLOT		0x5B /* <HASH 16> */
#define Z_ED2K_OPCODE_QUEUERANK			0x5C /* <wert  4> (slot index of the request) */
#define Z_ED2K_OPCODE_ASKSHAREDDIRS		0x5D /* (null) */
#define Z_ED2K_OPCODE_ASKSHAREDFILESDIR		0x5E /* <len 2><Directory len> */
#define Z_ED2K_OPCODE_ASKSHAREDDIRSANS		0x5F /* <count 4>(<len 2><Directory len>)[count] */
#define Z_ED2K_OPCODE_ASKSHAREDFILESDIRANS	0x60 /* <len 2><Directory len><count 4>(<HASH 16><ID 4><PORT 2><1 Tag_set>)[count] */
#define Z_ED2K_OPCODE_ASKSHAREDDENIEDANS	0x61 /* (null) */

#endif /* _Z_network_7_ED2K_H_ */
