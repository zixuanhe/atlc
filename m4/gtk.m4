# AC_MSG_ERROR(ERROR, [EXIT-STATUS = 1])
# --------------------------------------
AC_DEFUN([AC_MSG_ERROR2],
[{ AC_MSG_WARN([configure: error: $1], 2); exit m4_default([$2], 1); }])


# This macro is copied from the wxWindows distribution. 

# ---------------------------------------------------------------------------
# AC_PATH_GTK([MINIMUM-VERSION, [ACTION-IF-FOUND [, ACTION-IF-NOT-FOUND]]])
# Test for GTK, and define GTK_CFLAGS and GTK_LIBS. Uses variables
# gtk_config_prefix and/or gtk_config_exec_prefix if defined.
# ---------------------------------------------------------------------------
#
AC_DEFUN([AC_PATH_GTK],
[
  if test x$gtk_config_exec_prefix != x ; then
     gtk_config_args="$gtk_config_args --exec-prefix=$gtk_config_exec_prefix"
     if test x${GTK_CONFIG+set} != xset ; then
        GTK_CONFIG=$gtk_config_exec_prefix/bin/gtk-config
     fi
  fi
  if test x$gtk_config_prefix != x ; then
     gtk_config_args="$gtk_config_args --prefix=$gtk_config_prefix"
     if test x${GTK_CONFIG+set} != xset ; then
        GTK_CONFIG=$gtk_config_prefix/bin/gtk-config
     fi
  fi

  AC_PATH_PROG(GTK_CONFIG, gtk-config, no)
  min_gtk_version=ifelse([$1], ,0.99.7,$1)
  AC_MSG_CHECKING(for GTK - version >= $min_gtk_version)
  no_gtk=""
  if test "$GTK_CONFIG" != "no" ; then
    GTK_CFLAGS=`$GTK_CONFIG --cflags`
    GTK_LIBS=`$GTK_CONFIG --libs gthread`
    ac_save_CFLAGS="$CFLAGS"
    ac_save_LIBS="$LIBS"
    CFLAGS="$CFLAGS $GTK_CFLAGS"
    LIBS="$LIBS $GTK_LIBS"
#
# Now check if the installed GTK is sufficiently new. (Also sanity
# checks the results of gtk-config to some extent)
#
    AC_TRY_RUN([
#include <gtk/gtk.h>
#include <gtk/gtkfeatures.h>
#include <stdio.h>
#include <stdlib.h>

int
main ()
{
  int major, minor, micro;

  if (sscanf("$min_gtk_version", "%d.%d.%d", &major, &minor, &micro) != 3) {
     printf("%s, bad version string\n", "$min_gtk_version");
     exit(1);
   }

   if ((GTK_MAJOR_VERSION != gtk_major_version) ||
       (GTK_MINOR_VERSION != gtk_minor_version) ||
       (GTK_MICRO_VERSION != gtk_micro_version)) {
     printf("Headers vs. library version mismatch!\n");
     exit(1);
   }

   if (gtk_minor_version == 1) return FALSE;

   return !((gtk_major_version > major) ||
    ((gtk_major_version == major) && (gtk_minor_version > minor)) ||
    ((gtk_major_version == major) && (gtk_minor_version == minor) && (gtk_micro_version >= micro)));
}
],, no_gtk=yes,[echo $ac_n "cross compiling; assumed OK... $ac_c"])
     CFLAGS="$ac_save_CFLAGS"
     LIBS="$ac_save_LIBS"
  else
     no_gtk=yes
  fi
  if test "x$no_gtk" = x ; then
     AC_MSG_RESULT(yes)
     ifelse([$2], , :, [$2])
  else
     AC_MSG_RESULT(no)
     GTK_CFLAGS=""
     GTK_LIBS=""
     ifelse([$3], , :, [$3])
  fi
  AC_SUBST(GTK_CFLAGS)
  AC_SUBST(GTK_LIBS)
])




