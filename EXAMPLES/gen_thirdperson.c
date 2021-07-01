#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bl3mod.h"

/* libbl3mod example - generate 3rd person mod. */
/* BASED ON TECHNOLOGY DEVELOPED BY screen_names */

FILE* outFile;

char* tpcameraobj = "/Game/GameData/Camera/CameraMode_ThirdPerson.CameraMode_ThirdPerson:CameraBehavior_OffsetCameraRelative_0";
char* tpcameramode = "/Game/GameData/Camera/CameraMode_ThirdPerson.CameraMode_ThirdPerson";
char* defcameramode = "/Game/GameData/Camera/CameraMode_Default.CameraMode_Default";

char* patch = "SparkPatchEntry,(1,1,0,),/Game/GameData/Camera/CameraModeSet_Default.CameraModeSet_Default,Modes,0,,(CameraMode_Default'\"/Game/GameData/Camera/CameraMode_Default\"',CameraMode_ThirdPerson'\"/Game/GameData/Camera/CameraMode_ThirdPerson\"',CameraMode_Fixed'\"/Game/GameData/Camera/CameraMode_Fixed\"',CameraMode_Orbit'\"/Game/GameData/Camera/CameraMode_Orbit\"',CameraMode_ThirdPersonViewModel'\"/Game/GameData/Camera/CameraMode_ThirdPersonViewModel\"',CameraMode_DownState'\"/Game/GameData/Camera/CameraMode_DownState\"',CameraMode_ThirdPersonNoInput'\"/Game/GameData/Camera/CameraMode_ThirdPersonNoInput\"',CameraMode_VehicleTransitionIn'\"/Game/GameData/Camera/Vehicle/CameraMode_VehicleTransitionIn\"',CameraMode_VehicleTransitionOut'\"/Game/GameData/Camera/Vehicle/CameraMode_VehicleTransitionOut\"',CameraMode_StatusMenu'\"/Game/GameData/Camera/CameraMode_StatusMenu\"',CameraMode_AIO'\"/Game/GameData/Camera/CameraMode_AIO\"',CameraMode_AIONoTranslucency'\"/Game/GameData/Camera/CameraMode_AIONoTranslucency\"',CameraMode_PhotoMode_Offset'\"/Game/GameData/Camera/CameraMode_PhotoMode_Offset\"',CameraMode_PhotoMode'\"/Game/GameData/Camera/CameraMode_PhotoMode\"',CameraMode_Mission1_CameraStart'\"/Game/Missions/Plot/EP01_ChildrenOfTheVault/CameraMode_Mission1_CameraStart\"',CameraMode_Mission1_EchoDevice'\"/Game/Missions/Plot/EP01_ChildrenOfTheVault/CameraMode_Mission1_EchoDevice\"',CameraMode_Mission1_EULA'\"/Game/Missions/Plot/EP01_ChildrenOfTheVault/CameraMode_Mission1_EULA\"',CamMode_Shared_Teleport'\"/Game/PlayerCharacters/_Shared/_Design/PlayerTeleport/CamMode_Shared_Teleport\"',CameraMode_RaidSpectator'\"/Game/GameData/Camera/CameraMode_RaidSpectator\"',CameraMode_Mission1_CameraStart'\"/Game/Missions/Plot/EP01_ChildrenOfTheVault/CameraMode_Mission1_CameraStart\"')\n";

int main() {
    char* header;
    char* currentLine;
    char playerChoice[8];
    char xyz[64];
    char coordX[8];
    char coordY[8];
    char coordZ[8];
    int i;
    int j;
    printf("(B3MT module/libbl3mod test program) Standalone third person by screen_names.\n");
    outFile = fopen("3p.bl3hotfix", "w");
    if(!outFile) {
        printf("Failed to open output file!\n");
        exit(1);
    }
    /* Generate header(s) */
    header = mod_header("Standalone Third Person", "screen_names, HackerSmacker (this generator)", "Enable third person", "1.0");
    fwrite(header, sizeof(char), strlen(header), outFile);
    header = mod_header_contact("Discord", "screen_names");
    fwrite(header, sizeof(char), strlen(header), outFile);
    header = mod_header_category("qol, resource, gameplay, bugfix");
    fwrite(header, sizeof(char), strlen(header), outFile);
    /* Ask user for the camera offset. */
    printf("You will now be prompted to enter the camera offset values.\n");
    printf("The default is:\nX: -150\nY: 100\nZ: 0\nSpecify values now.\n");
    printf("X: ");
    /* Yes, I know it's bad to use gets(). */
    gets(coordX);
    printf("Y: ");
    gets(coordY);
    printf("Z: ");
    gets(coordZ);
    /* Construct to-val. */
    sprintf(xyz, "(x=%s,y=%s,z=%s)", coordX, coordY, coordZ);
    /* Write camera position XYZ. */
    currentLine = regular_hotfix(MOD_TYPE_PATCH, tpcameraobj, "LocationOffset", xyz, 0);
    fwrite(currentLine, sizeof(char), strlen(currentLine), outFile);
    /* Set the third person camera to be the default camera mode. */
    currentLine = regular_hotfix(MOD_TYPE_PATCH, tpcameramode, "ModeName", "Default", 0);
    fwrite(currentLine, sizeof(char), strlen(currentLine), outFile);
    /* Change the default camera mode to actually be the third person camera. */
    currentLine = regular_hotfix(MOD_TYPE_PATCH, defcameramode, "ModeName", "ThirdPerson", 0);
    fwrite(currentLine, sizeof(char), strlen(currentLine), outFile);
    /* Write pre-defined patch data. */
    /* This is being written as a blob to streamline the updating of this mod. */
    fwrite(patch, sizeof(char), strlen(patch), outFile);
    fclose(outFile);
    return 0;
}
