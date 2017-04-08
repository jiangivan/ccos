#ifndef __VIOLET_FILESYETEM_FILE_H__
#define __VIOLET_FILESYETEM_FILE_H__

#define INVALID_FILE		(FileDesc*)(-1)
#define INVALID_FILE_LIST	(FileList*)(-1)

#define ADF_USIM_AID		"A0000000871002FF86FFFF89FFFFFFFF"
#define ARA_M_AID		"A00000015141434C00"

typedef enum FileType {
        MF,
        ADF,
        DF,
        EF
}FileType;

typedef enum FileStructure {
        TRANSPARENT,
        LINEAR_FIXED,
        CYCLE
}FileStructure;

typedef enum FileAccess {
        NOT_SHAREABLE,
        SHAREABLE
}FileAccess;

typedef enum LifeCycleStatus {
        CREATED,
        INITIALIZED,
        DEACTIVATED,
        ACTIVATED,
        TERMINATED
}LifeCycleStatus;

typedef struct AIDFileDesc {
        uint8* aid;
        uint8 aidlen;
        struct FileDesc* file;
}AIDFileDesc;

typedef struct ArrRef {
        uint16 arr_fid;
        uint8 arr_record_num;
}ArrRef;

typedef struct FileList {
        struct FileDesc* me;
        struct FileList* next;
}FileList;

typedef struct FileDesc{
        uint16 fid;
        uint8 sfi;
        uint8 shareble;
        FileType file_type;
        FileStructure ef_type;
        struct ArrRef arr_ref;
        struct FileDesc* parent;
        struct FileList* child_ef;
        struct FileList* child_df;
        uint8* data;
        uint16 file_len;
        uint8 record_len;
        uint8 record_cnt;
        uint8 record_pointer;

}FileDesc;

#endif /* __VIOLET_FILESYSTEM_FILE_H__ */
