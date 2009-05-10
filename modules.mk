mod_rewrite_mapfunc_custom.la: mod_rewrite_mapfunc_custom.slo
	$(SH_LINK) -rpath $(libexecdir) -module -avoid-version  mod_rewrite_mapfunc_custom.lo
DISTCLEAN_TARGETS = modules.mk
shared =  mod_rewrite_mapfunc_custom.la
