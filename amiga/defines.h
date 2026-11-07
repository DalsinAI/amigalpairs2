/* LPairs2 for AmigaOS: what configure would have put in its config.h,
 * included before every file (-include). No gettext: English. The AmiCradle Team. GPL 3 or later,
 * like LPairs2. */
#define PACKAGE "lpairs2"
#define PACKAGE_NAME "lpairs2"
#define PACKAGE_VERSION "2.3.2"
#define VERSION "2.3.2"
#define HAVE_STDLIB_H 1
#define HAVE_STRING_H 1
#define HAVE_UNISTD_H 1
#define HAVE_SYS_STAT_H 1
/* time() for src/main.cpp's srand(): glibc's headers bring <time.h> in
 * on the way, libnix's do not */
#include <time.h>
/* libnix has vasprintf() (src/tools.cpp's strprintf) but its <stdio.h>
 * does not declare it */
#include <stdarg.h>
#ifdef __cplusplus
extern "C"
#endif
int vasprintf(char **, const char *, va_list);
