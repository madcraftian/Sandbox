############################################################
#
# @file    reset.sh 
#
# @brief   this script resets the sandbox by removing
#          all of the user made headers and source files;
#          And then, it copies the default template unto
#          the src directory
#
# @author  Jerico G. Despe
#
############################################################

#!/bin/bash

source .reset.d/lib.sh
source .reset.d/config.sh

log "STATUS" "Resetting sandbox"

if [[ -d ${SRC_DIR} ]]; then
	log_message "Process recreating ${SRC_DIR} directory"
	rm -rf "${SRC_DIR}"
fi

mkdir ${SRC_DIR}
log_message "${SRC_DIR} directory created"

if [[ -f ${OUT_BUILD} ]]; then
	log_message "Process resetting ${OUT_DIR} build system"
	rm -rf ${OUT_BUILD}
fi

cp ${TEMPLATE_BUILD} ${OUT_BUILD}
log_message "${OUT_BUILD} has been resetted"

cp "${TEMPLATE_SRC}" "${SRC_DIR}/${OUT}${EXT}"
log "RESETTING COMPLETE!"
