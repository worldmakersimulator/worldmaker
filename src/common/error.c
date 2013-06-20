#include "common.h"
#include "error.h"

const char *program_name = NULL;

static void error (int exit_status, const char *mode,
                   const char *message);

static void
error (int exit_status, const char *mode, const char *message)
{
  fprintf (stderr, "%s: %s: %s.\n", program_name, mode, message);

  if (exit_status >= 0)
    exit (exit_status);
}

void
wm_sic_warning (const char *message)
{
  error (-1, "warning", message);
}

void
wm_sic_error (const char *message)
{
  error (-1, "ERROR", message);
}

void
wm_sic_fatal (const char *message)
{
  error (EXIT_FAILURE, "FATAL", message);
}

void
set_program_name (const char *path)
{
  if (!program_name)
    program_name = xstrdup (basename (path));
}





