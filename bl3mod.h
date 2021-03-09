#ifndef BL3MOD_H
#define BL3MOD_H 1

char* mod_header(char* name, char* author, char* comment, char* version);
char* table_hotfix(const char* hf_type, char* object,
                char* row_name, char* attr_name,
                char* from_val, char* to_val, int notificationFlag);
char* regular_hotfix(const char* hf_type, char* pakFile, char* object,
                char* attr_name, char* from_val, char* to_val,
                int notificationFlag);
char* mesh_hotfix(const char* hf_type, char* pakFile, char* object,
                char* attr_name, char* piece, char* to_val, int visible,
                int notificationFlag);
char* mesh_coord(char* x, char* y, char* z, char* rx,
                char* ry, char* rz, char* sx, char* sy, char* sz);
#endif
