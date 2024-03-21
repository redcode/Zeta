/* Zeta API - Z/Z/protocols/network/7/HTTP.h
 ______  ______________  ___
|__   / |  ___|___  ___|/   \
  /  /__|  __|   |  |  /  -  \
 /______|_____|  |__| /__/ \__\
Copyright (C) 2006-2024 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_protocols_network_7_HTTP_H
#define Z_protocols_network_7_HTTP_H

/* MARK: - Ports */

#define Z_HTTP_DEFAULT_SERVER_PORT			   80

/* MARK: - Status: Informational */

#define Z_HTTP_STATUS_CONTINUE				   100
#define Z_HTTP_STATUS_SWITCHING_PROTOCOLS		   101
#define Z_HTTP_STATUS_PROCESSING			   102 /* WebDAV, RFC 2518 */

/* MARK: - Status: Success */

#define Z_HTTP_STATUS_OK				   200
#define Z_HTTP_STATUS_CREATED				   201
#define Z_HTTP_STATUS_ACCEPTED				   202
#define Z_HTTP_STATUS_NON_AUTHORITATIVE_INFO		   203
#define Z_HTTP_STATUS_NO_CONTENT			   204
#define Z_HTTP_STATUS_RESET_CONTENT			   205
#define Z_HTTP_STATUS_PARTIAL_CONTENT			   206
#define Z_HTTP_STATUS_MULTI_STATUS			   207 /* WebDAV, RFC 4918 */
#define Z_HTTP_STATUS_ALREADY_REPORTED			   208 /* WebDAV, RFC 5842 */
#define Z_HTTP_STATUS_IM_USED				   226 /* RFC 3229 */

/* MARK: - Status: Redirection */

#define Z_HTTP_STATUS_MULTIPLE_CHOICES			   300
#define Z_HTTP_STATUS_MOVED_PERMANENTLY			   301
#define Z_HTTP_STATUS_FOUND				   302
#define Z_HTTP_STATUS_SEE_OTHER				   303 /* v1.1 */
#define Z_HTTP_STATUS_NOT_MODIFIED			   304
#define Z_HTTP_STATUS_USE_PROXY				   305 /* v1.1 */
#define Z_HTTP_STATUS_SWITCH_PROXY			   306
#define Z_HTTP_STATUS_TEMPORARY_REDIRECT		   307 /* v1.1 */
#define Z_HTTP_STATUS_PERMANENT_REDIRECT		   308 /* Experimental Internet draft */

/* MARK: - Status: Client error */

#define Z_HTTP_STATUS_BAD_REQUEST			   400
#define Z_HTTP_STATUS_UNAUTHORIZED			   401
#define Z_HTTP_STATUS_PAYMENT_REQUIRED			   402 /* Reserved for future use by the forces of the dark side */
#define Z_HTTP_STATUS_FORBIDDEN				   403
#define Z_HTTP_STATUS_NOT_FOUND				   404
#define Z_HTTP_STATUS_METHOD_NOT_ALLOWED		   405
#define Z_HTTP_STATUS_NOT_ACCEPTABLE			   406
#define Z_HTTP_STATUS_PROXY_AUTHENTICATION_REQUIRED	   407
#define Z_HTTP_STATUS_REQUEST_TIME_OUT			   408
#define Z_HTTP_STATUS_CONFLICT				   409
#define Z_HTTP_STATUS_GONE				   410
#define Z_HTTP_STATUS_LENGTH_REQUIRED			   411
#define Z_HTTP_STATUS_PRECONDITION_FAILED		   412
#define Z_HTTP_STATUS_REQUEST_ENTITY_TOO_LARGE		   413
#define Z_HTTP_STATUS_REQUEST_URI_TOO_LONG		   414
#define Z_HTTP_STATUS_UNSUPPORTED_MEDIA_TYPE		   415
#define Z_HTTP_STATUS_REQUESTED_RANGE_NOT_SATISFIABLE	   416
#define Z_HTTP_STATUS_EXPECTATION_FAILED		   417
#define Z_HTTP_STATUS_I_AM_A_TEAPOT			   418 /* RFC 2324 */
#define Z_HTTP_STATUS_ENHANCE_YOUR_CALM			   420 /* Twitter */
#define Z_HTTP_STATUS_UNPROCESSABLE_ENTITY		   422 /* WebDAV, RFC 4918 */
#define Z_HTTP_STATUS_LOCKED				   423 /* WebDAV, RFC 4918 */
#define Z_HTTP_STATUS_FAILED_DEPENDENCY			   424 /* WebDAV, RFC 4918 */
#define Z_HTTP_STATUS_METHOD_FAILURE			   424 /* WebDAV */
#define Z_HTTP_STATUS_UNORDERED_COLLECTION		   425 /* WebDAV Internet draft */
#define Z_HTTP_STATUS_UPGRADE_REQUIRED			   426 /* RFC 2817 */
#define Z_HTTP_STATUS_PRECONDITION_REQUIRED		   428 /* RFC 6585 */
#define Z_HTTP_STATUS_TOO_MANY_REQUESTS			   429 /* RFC 6585 */
#define Z_HTTP_STATUS_REQUEST_HEADER_FIELDS_TOO_LARGE	   431 /* RFC 6585 */
#define Z_HTTP_STATUS_NO_RESPONSE			   444 /* Nginx */
#define Z_HTTP_STATUS_RETRY_WITH			   449 /* Microsoft */
#define Z_HTTP_STATUS_BLOCKED_BY_WINDOWS_PARENTAL_CONTROLS 450 /* Microsoft */
#define Z_HTTP_STATUS_UNAVAILABLE_FOR_LEGAL_REASONS	   451 /* Internet draft */
#define Z_HTTP_STATUS_CLIENT_CLOSED_REQUEST		   499 /* Nginx */

/* MARK: - Status: Server error */

#define Z_HTTP_STATUS_INTERNAL_SERVER_ERROR		   500
#define Z_HTTP_STATUS_NOT_IMPLEMENTED			   501
#define Z_HTTP_STATUS_BAD_GATEWAY			   502
#define Z_HTTP_STATUS_SERVICE_UNAVAILABLE		   503
#define Z_HTTP_STATUS_GATEWAY_TIME_OUT			   504
#define Z_HTTP_STATUS_HTTP_VERSION_NOT_SUPPORTED	   505
#define Z_HTTP_STATUS_VARIANT_ALSO_NEGOTIATES		   506 /* RFC 2295 */
#define Z_HTTP_STATUS_INSUFICIENT_STORAGE		   507 /* WebDAV, RFC 4918 */
#define Z_HTTP_STATUS_LOOP_DETECTED			   508 /* WebDAV, RFC 5842 */
#define Z_HTTP_STATUS_BANDWIDTH_LIMIT_EXCEEDED		   509 /* Apache bw/limited extension */
#define Z_HTTP_STATUS_NOT_EXTENDED			   510 /* RFC 2774 */
#define Z_HTTP_STATUS_NETWORK_AUTHENTICATION_REQUIRED	   511 /* RFC 6585 */
#define Z_HTTP_STATUS_NETWORK_READ_TIME_OUT_ERROR	   598 /* Microsoft HTTP proxies */
#define Z_HTTP_STATUS_NETWORK_CONNECT_TIME_OUT_ERROR	   599 /* Microsoft HTTP proxies */

#endif /* Z_protocols_network_7_HTTP_H */
