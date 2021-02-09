#ifndef BL3MOD_H
#define BL3MOD_H 1

char* mod_header(char* name, char* author, char* comment, char* version);
char* table_hotfix(const char* hf_type, char* package, char* obj_name,
                char* row_name, char* attr_name, char* new_val,
                char* prev_val, int notificationFlag);

#endif
