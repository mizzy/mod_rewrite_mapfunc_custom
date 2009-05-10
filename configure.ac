#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

VERSION="`cat VERSION`"
AC_PREREQ(2.59)
AC_INIT(mod_rewrite_mapfunc_custom)
AC_CONFIG_SRCDIR([mod_rewrite_mapfunc_custom.c])

# Checks for programs.
AC_PROG_CC

AC_ARG_WITH(apxs, AC_HELP_STRING([--with-apxs=NAME],
        [name of the apxs executable [[apxs]]]),
        [APXS="$with_apxs"])

if test -z "${APXS}"; then
        AC_PATH_PROGS(APXS, apxs2 apxs, [apxs], [$PATH:/usr/local/apache/bin:/usr/sbin])
fi

# Checks for libraries.

# Checks for header files.

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
