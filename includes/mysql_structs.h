/*
 * Copyright (c) 2014-2016 Joris Vink <joris@coders.se>
 * Copyright (c) 2016 Angel Gonzalez <aglezabad@gmail.com>
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#ifndef _H_KORE_PGSQL_STRUCTS
#define _H_KORE_PGSQL_STRUCTS

#include <my_config.h>
#include <mysql.h>
#include "sql.h"

#if defined(__cplusplus)
extern "C" {
#endif

typedef struct MYSQLconn {
  SQLconn     super;
	MYSQL				*db;
} MYSQLconn;

typedef struct MYSQLdb {
  SQLdb     super;
	char			*name;
	char			*conn_string;
} MYSQLdb;

typedef struct MYSQLKore {
	SQLKore     super;
	MYSQL_RES		*result;
} MYSQLKore;

// TODO Same as sql.h comment.
extern u_int16_t	mysql_conn_max;

#if defined(__cplusplus)
}
#endif

#endif
