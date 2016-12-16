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

#ifndef _H_KORE_SQL
#define _H_KORE_SQL

#define KORE_SQL_FORMAT_TEXT		0
#define KORE_SQL_FORMAT_BINARY	1

#define KORE_SQL_SYNC			0x0001
#define KORE_SQL_ASYNC		0x0002

#define POSTGRESQL 10
#define MYSQL 11

#if defined(__cplusplus)
extern "C" {
#endif

typedef struct SQLconn {
	u_int8_t			engine;
	u_int8_t			type;
	u_int8_t			flags;
	char				*name;
	struct sql_job		*job;
	TAILQ_ENTRY(SQLconn)		list;
} SQLconn;

typedef struct SQLdb {
	u_int8_t			engine;

	LIST_ENTRY(SQLdb)	rlist;
} SQLdb;

typedef struct SQLKore {
	u_int8_t		engine;
	u_int8_t		state;
	int			flags;
	char			*error;
	SQLconn		*conn;

	LIST_ENTRY(SQLKore)	rlist;
} SQLKore;

// TODO How to set different value for each engine ?
extern u_int16_t	sql_conn_max;

void	kore_sql_init(void);
int	kore_sql_query_init(SQLKore *, struct http_request *,
	    const char *, int);
void	kore_sql_handle(void *, int);
void	kore_sql_cleanup(SQLKore *);
void	kore_sql_continue(struct http_request *, SQLKore *);
int	kore_sql_query(SQLKore *, const char *);
int	kore_sql_query_params(SQLKore *,
	    const char *, int, int, ...);
int	kore_sql_v_query_params(SQLKore *,
	    const char *, int, int, va_list);
int	kore_sql_register(const char *, const char *);
int	kore_sql_ntuples(SQLKore *);
void	kore_sql_logerror(SQLKore *);
void	kore_sql_queue_remove(struct http_request *);
char	*kore_sql_getvalue(SQLKore *, int, int);
int	kore_sql_getlength(SQLKore *, int, int);

#if defined(__cplusplus)
}
#endif

#define KORE_SQL_STATE_INIT		1
#define KORE_SQL_STATE_WAIT		2
#define KORE_SQL_STATE_RESULT		3
#define KORE_SQL_STATE_ERROR		4
#define KORE_SQL_STATE_DONE		5
#define KORE_SQL_STATE_COMPLETE	6

#endif
