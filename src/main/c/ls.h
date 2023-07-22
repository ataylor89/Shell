typedef struct
{
    unsigned char type;
    short mode;
    int uid;
    int gid;
    long filesize;
    char username[256];
    char groupname[256];
    char atime[32];
    char mtime[32];
    char filename[256];
} Record;

typedef struct
{
    long max_filesize;
    int filesize_field_length;
    char filesize_format[10];
} Metadata;

typedef struct
{
    char* dirname;
    int num_records;
    Record** start;
    Metadata* metadata;
    char* buf;
    int length;
} DirectoryListing;

DirectoryListing* get_directory_listing(char* dirname);
void sort_directory_listing(DirectoryListing* dl);
void format_directory_listing(DirectoryListing* dl);