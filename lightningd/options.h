#ifndef LIGHTNING_LIGHTNINGD_OPTIONS_H
#define LIGHTNING_LIGHTNINGD_OPTIONS_H
#include "config.h"
#include <ccan/ccan/opt/opt.h>

struct lightningd;

/* After this, early config file and cmdline options parsed. */
void handle_early_opts(struct lightningd *ld, int argc, char *argv[]);

/* After this we're in the .lightning dir, and we've parsed all options */
void handle_opts(struct lightningd *ld, int argc, char *argv[]);

/* Derive default color and alias from the pubkey. */
void setup_color_and_alias(struct lightningd *ld);

enum opt_autobool {
	OPT_AUTOBOOL_FALSE = 0,
	OPT_AUTOBOOL_TRUE = 1,
	OPT_AUTOBOOL_AUTO = 2,
};
char *opt_set_autobool_arg(const char *arg, enum opt_autobool *b);
void opt_show_autobool(char buf[OPT_SHOW_LEN], const enum opt_autobool *b);

#endif /* LIGHTNING_LIGHTNINGD_OPTIONS_H */
