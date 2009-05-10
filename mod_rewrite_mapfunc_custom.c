#include "httpd.h"
#include "http_config.h"
#include "apr_optional.h"

/* rewrite map function prototype from mod_rewrite.h */
typedef char *(rewrite_mapfunc_t)(request_rec *r, char *key);

/* optional function declaration from mod_rewrite.h */
APR_DECLARE_OPTIONAL_FN(void, ap_register_rewrite_mapfunc,
                        (char *name, rewrite_mapfunc_t *func));

static char *rewrite_mapfunc_custom(request_rec *req, char *key)
{
    /* key を元にごにょごにょして value を生成 */    
    return value;
}

/* from mod_rewrite.c */
static int pre_config(apr_pool_t *pconf,
                      apr_pool_t *plog,
                      apr_pool_t *ptemp)
{
    APR_OPTIONAL_FN_TYPE(ap_register_rewrite_mapfunc) *map_pfn_register;

    /* register int: rewritemap handlers */
    map_pfn_register = APR_RETRIEVE_OPTIONAL_FN(ap_register_rewrite_mapfunc);
    if (map_pfn_register) {
        map_pfn_register("custom", rewrite_mapfunc_custom);
    }
    return OK;
}

static void register_hooks(apr_pool_t *p)
{
    ap_hook_pre_config(pre_config, NULL, NULL, APR_HOOK_MIDDLE);
}

module AP_MODULE_DECLARE_DATA rewrite_mapfunc_custom_module = {
    STANDARD20_MODULE_STUFF,
    NULL,                  /* create per-dir    config structures */
    NULL,                  /* merge  per-dir    config structures */
    NULL,                  /* create per-server config structures */
    NULL,                  /* merge  per-server config structures */
    NULL,                  /* table of config file commands       */
    register_hooks  /* register hooks                      */
};
