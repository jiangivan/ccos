#ifndef __VIOLET_FILESYSTEM_CHANNEL_H__
#define __VIOLET_FILESYETEM_CHANNEL_H__

#include "violet_filesystem_file.h"

#define CHANNEL_NUM 		4
#define CHANNEL_OPENNED		1
#define CHANNEL_CLOSED		0
#define CHANNEL_0		0
#define CHANNEL_1		1
#define CHANNEL_2		2
#define CHANNEL_3		3
#define INVALID_CHANNEL_ID	(uint8)(-1)

typedef struct ChannelInfo {
        uint8 isOpen;
        FileDesc* currentEF;
        FileDesc* currentDF;
        FileDesc* currentADF;
}ChannelInfo;

extern ChannelInfo channels[CHANNEL_NUM];

#endif /* __VIOLET_FILESYSTEM_CHANNEL_H__ */
