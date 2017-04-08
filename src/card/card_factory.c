#include "studio.h"
#include "../include/type.h"
#include "../include/log.h"

int create_card(CardProfile profile) {
        
        LOGD_FUNC();
        init_adf();
        build_uicc();
        build_usim();
        build_csim();
        init_channel();
        return success;
}

int card_impl() {
        
}

int remove_card() {
        free_filesystem();
        free_profile();
}

uint16 reset_card(uint8* apdu_rsp_data, uint32 apdu_rsp_size) {
        if(sizeof(ATR) > sizeof(apdu_rsp_data)) {
                return ERR;
        }
        apdu_rsp_size = sizeof(ATR);
        memcpy(apdu_rsp_data, ATR, apdu_rsp_size);
        return OK;
}

uint16 transmit_apdu(uint8* apdu_req_data, uint32 apdu_req_size, uint8* apdu_rsp_data, uint32 apdu_rsp_size) {
        uint32 command_rsp_size;
        
        LOGD_FUNC();
        
}

