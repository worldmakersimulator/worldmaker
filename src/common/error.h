/*
 * error.h
 *
 *  Created on: 20/06/2013
 *      Author: Raul
 */

#ifndef COMMON_ERROR_H_
#define COMMON_ERROR_H_


static void error (int exit_status, const char *mode,
                   const char *message);

void wm_warning (const char *message);

void wm_error (const char *message);

void wm_sic_fatal (const char *message);

void set_program_name (const char *path);

#endif /* COMMON_ERROR_H_ */
