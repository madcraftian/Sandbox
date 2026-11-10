############################################################
#
# @file    lib.sh
#
# @brief   this script contains functions to be used
#          such as log messages, etc.
#
# @author  Jerico G. Despe
#
############################################################

#!/bin/bash

# Message functions
log() {
	if [[ ! -z $2 ]]; then
		echo -e "$1 $2"
	else
		echo -e "$1"
	fi
}

log_error() {
	log "ERROR: $1" >&2
}

log_message() {
	log "LOG: $1"
}
