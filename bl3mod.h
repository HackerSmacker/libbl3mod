#ifndef BL3MOD_H
#define BL3MOD_H 1

/* LIBBL3MOD SYSTEM CODE: LICENSED UNDER THE TERMS OF THE GPLV3 LICENSE. */
/* FAILURE TO COMPLY WITH THE LICENSE TERMS */
/* SPECIFIED WILL RESULT IN CONSEQUENCES. */

/* Common library declarations for those that might forget them */

#define MOD_TYPE_PATCH "SparkPatchEntry"
#define MOD_TYPE_LEVEL "SparkLevelPatchEntry"
#define MOD_TYPE_EARLYLEVEL "SparkEarlyLevelPatchEntry"
#define MOD_TYPE_CHAR "SparkCharacterLoadedEntry"
#define MOD_TYPE_PACKAGE "SparkStreamedPackageEntry"
#define MOD_TYPE_POST "SparkPostLoadedEntry"

/* Type definitions for some functions */

/* This is for the variable argument list system. */
/* I recommend you don't use it on big-endian systems */
struct array_entry {
    char* name;
    char* value;
};

/* Common library functions */

char* mod_header(char* name,
    char* author,
    char* comment,
    char* version);

char* mod_header_contact(char* type,
    char* address);

char* mod_header_tags(char* tags);

/* Standard table hotfix (all params specified).    */
/* hf_type: Hotfix type, like SparkPathEntry        */
/* object: Path to UE4 object in question           */
/* row_name: Row in the export.                     */
/* attr_name: Attribute in the row.                 */
/* from_val: From value.                            */
/* to_val: To value.                                */

char* table_hotfix_adv(const char* hf_type, char* pakFile, char* object,
                char* row_name, char* attr_name,
                char* from_val, char* to_val, int notificationFlag);

/* Table hotfix.                                    */
/* hf_type: Hotfix type, like SparkPathEntry        */
/* object: Path to UE4 object in question           */
/* row_name: Row in the export.                     */
/* attr_name: Attribute in the row.                 */
/* to_val: To value.                                */

char* table_hotfix(const char* hf_type, char* object,
                char* row_name, char* attr_name,
                char* to_val, int notificationFlag);

/* Table hotfix (match all packages).               */
/* hf_type: Hotfix type, like SparkPathEntry        */
/* object: Path to UE4 object in question           */
/* row_name: Row in the export.                 `   */
/* attr_name: Attribute in the row.                 */
/* to_val: To value.                                */

char* table_hotfix_matchall(const char* hf_type, char* object,
                char* row_name, char* attr_name,
                char* to_val, int notificationFlag);

/* NOTE ON notificationFlag, what it is and what it does            */
/* The Notification Flag is something you can ignore. Just set it   */
/* to 0 unless you have a reason otherwise.                         */

/* Simple regular hotfix.                               */
/* hf_type: Hotfix type, for instance, SparkPatchEntry  */
/* object: path to the object you are modifying         */
/* attr: attribute you are editing                      */
/* to_val: replacement for attr's content               */

char* regular_hotfix(const char* hf_type, char* object,
                char* attr, char* to_val,
                int notificationFlag);

/* Simple regular hotfix, but MatchAll                      */  
/* Note - only really useful for SparkEarlyLevelPatchEntry  */
/* hf_type: Hotfix type, for instance, SparkPatchEntry      */
/* object: path to the object you are modifying             */
/* attr: attribute you are editing                          */ 
/* to_val: replacement for attr's content                   */

char* regular_hotfix_ma(const char* hf_type, char* object,
                char* attr, char* to_val,
                int notificationFlag);

/* Simple regular hotfix but you specify a level.                   */
/* hf_type: Hotfix type, for instance, SparkPatchEntry              */
/* pakFile: Level package name                                      */
/* object: path to the object you are modifying                     */
/* attr: attribute you are editing                                  */
/* to_val: replacement for attr's content                           */
/* Note: this is really only used for SparkEarlyLevelPatchEntry     */

char* regular_hotfix_level(const char* hf_type, 
                char* pakFile, char* object,
                char* attr, char* to_val,
                int notificationFlag);

/* Regular hotfix but with variable arguments.                          */
/* hf_type: Hotfix type, for instance, SparkPatchEntry                  */
/* object: path to the object you are modifying                         */
/* attr: attribute you are editing                                      */
/* count: (VERY IMPORTANT) the number of "struct array_entry" objects   */

char* regular_hotfix_va(const char* hf_type, char* object,
                char* attr, int notificationFlag, 
                int count, ...);

/* Simple regular hotfix, but for assets that feature multiple exports. */
/* hf_type: Hotfix type, for instance, SparkPatchEntry                  */
/* object: path to the object you are modifying                         */
/* which: export in the object you are modifying                        */
/* attr: attribute you are editing                                      */
/* to_val: replacement for attr's content                               */

char* regular_hotfix_multi(const char* hf_type, char* object, 
                char* which, char* attr, char* to_val,
                int notificationFlag);

/* Simple regular hotfix, but you can set any value field.  */
/* hf_type: Hotfix type, for instance, SparkPatchEntry      */
/* object: path to the object you are modifying             */
/* attr: attribute you are editing                          */
/* to_val: replacement for attr's content                   */

char* regular_hotfix_field(const char* hf_type, char* object,
                char* attr, char* field, char* to_val,
                int notificationFlag);

/* Simple regular hotfix, but for assets that feature multiple exports.     */
/* Works like regular_hotfix_field (as in, you can set any field you want). */
/* hf_type: Hotfix type, for instance, SparkPatchEntry                      */
/* object: path to the object you are modifying                             */
/* which: export in the object you are modifying                            */
/* attr: attribute you are editing                                          */
/* to_val: replacement for attr's content                                   */

char* regular_hotfix_field_multi(const char* hf_type, char* object, 
                char* which, char* attr, char* field, char* to_val,
                int notificationFlag);

/* Advanced regular hotfix.                                     */
/* pakFile: UE4 Pakfile that holds the object you are editing   */
/* hf_type: Hotfix type, for instance, SparkPatchEntry          */
/* object: path to the object you are modifying                 */
/* attr: attribute you are editing                              */
/* from_val: original value for attr                            */
/* to_val: replacement for attr's content                       */

char* regular_hotfix_adv(const char* hf_type, char* pakFile, char* object,
                char* attr, char* from_val, char* to_val,
                int notificationFlag);

/* Mesh hotfix.                                                             */
/* hf_type: Hotfix type (SparkLevelPatchEntry is good)                      */
/* pakFile: Pakfile, like Cartels_P (this is the map you are modifying)     */
/* map: UE4 asset path to object you are going to put on the map.           */
/* objClass: object that has pointers to meshes you can place               */
/* obj: object to place on map                                              */
/* to_val: "to value" - see mesh_coord(...)                                 */
/* visible: visible or not NOTE: THIS VALUE IS INVERTED                     */

char* mesh_hotfix(const char* hf_type, char* pakFile, char* map,  
		char* objClass, char* obj, char* to_val, int visible,
        int notificationFlag);

/* Mesh coordinate string generator.    */
/* x, y, z: object position.            */
/* rx, ry, rz: object rotation.         */
/* sx, sy, sz: object scale.            */

char* mesh_coord(char* x, char* y, char* z, char* rx,
                char* ry, char* rz, char* sx, char* sy, char* sz);

/* Convert /Path/To/Some/Object to /Path/To/Some/Object.Object  */
/* object: path to object                                       */

char* extract_object(char* object);

/* Convert /Path/To/Some/Object to /Path/To/Some/Object.Object_C  */  
/* object: path to object                                         */

char* extract_object_c(char* object);

/* Pull out the "end" of an object path.                */
/* /Game/Object/SomeObject -> SomeObject.SomeObject     */
/* object: path to object                               */

char* end_object(char* object);

/* Pull out the "end" of an object path.                */
/* This time, tack on a _C at the end.                  */
/* /Game/Object/SomeObject -> SomeObject.SomeObject_C   */
/* object: path to object                               */

char* end_object_c(char* object);


/* Subject-specific library functions */

/* Set the name for a unique.                                   */
/* object: path to a "Name" object, like "Name_JAK_PS_TheDuc"   */
/* to_val: new name                                             */

char* set_unique_name(char* object, char* to_val);

/* Change an object's red text.                                     */
/* object: path to a UIStat object, like "UIStat_RedText_TheDuc"    */
/* to_val: red text (will be automatically markdown-formatted)      */

char* set_unique_flavortext(char* object, char* to_val);

/* Set the global scale value.      */
/* newScale: the new scaling value  */

char* global_value_scale(char* newScale);

/* Set enemy health scale values.                      */
/* overall: Enemy health increase per level.           */
/* nvhm: NVHM enemy health increase (base game)        */
/* tvhm: TVHM enemy health increase (playthrough 2)    */

char* global_enemy_health(char* overall, char* nvhm, char* tvhm);

#endif
