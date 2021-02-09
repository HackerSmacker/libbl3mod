#ifndef BL3MOD_H
#define BL3MOD_H 1

char* mod_header(char* name, char* author, char* comment, char* version);
char* table_hotfix(const char* hf_type, char* package,
                char* row_name, char* attr_name,
                char* from_val, char* to_val, int notificationFlag);
char* regular_hotfix(const char* hf_type, char* pakFile, char* package,
                char* attr_name, char* from_val, char* to_val,
                int notificationFlag);
char* mesh_hotfix(const char* hf_type, char* pakFile, char* package,
                char* attr_name, char* object, char* to_val, int visible,
                int notificationFlag);
#endif
