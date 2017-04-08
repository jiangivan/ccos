#include "../include/types.h"
#include "../include/log.h"
#include "violet_filesystem_channel.h"

ChannelInfo channels[CHANNEL_NUM];

void init_channel() {
        uint8 i;
        LOGD_FUNC();

        for (i = 0; i < 4; i ++) {
                close_channelID(i);
                channels[i].currentEF = INVALID_FILE;
                channels[i].currentDF = INVALID_FILE;
                channels[i].currentADF = INVALID_FILE;
        }
}
