
#include <list>
#include <vector>
#include <string.h>
#include <pthread.h>
#include <cstring>
#include <jni.h>
#include <unistd.h>
#include <fstream>
#include "Includes/obfuscate.h"
#include "KittyMemory/MemoryPatch.h"
#include "Includes/Logger.h"
#include "Includes/Utils.h"
#include "Menu.h"
#include "Toast.h"

#if defined(__aarch64__) 
#include <And64InlineHook/And64InlineHook.hpp>
#else

#include <Substrate/SubstrateHook.h>
#include <Substrate/CydiaSubstrate.h>

#endif

struct My_Patches {
    MemoryPatch AIMBOT;
    MemoryPatch AIMLOCK;
    MemoryPatch NORECOIL;
    MemoryPatch SMALLCROSS;
    MemoryPatch NOFOG;
    MemoryPatch VIOLATEFOG;
    MemoryPatch VIOLATEFOG1;
    MemoryPatch CAMVIEW;
    MemoryPatch BLACKBODY;
    MemoryPatch DARKMAP;
    MemoryPatch CHAMS;
    MemoryPatch FLASHWEP;
    MemoryPatch BYPASS;
    MemoryPatch BYPASS1;
    MemoryPatch BYPASS2;
    MemoryPatch BYPASS3;
    MemoryPatch BYPASS4;
    MemoryPatch BYPASS5;
    MemoryPatch AIMHEAD;
    MemoryPatch ANTENA;
    MemoryPatch ANTISHAKE;
    MemoryPatch ANTISHAKE1;
    MemoryPatch NIGHT;
    MemoryPatch NIGHT1;
    MemoryPatch SPEED;
    MemoryPatch SPEED1;
    MemoryPatch SPEED2;
    MemoryPatch SPEED3;
    MemoryPatch SPEED4;
    MemoryPatch SPEED5;
    MemoryPatch SPEEDCAR;
    MemoryPatch JUMPCAR;
} hexPatches;


bool AIMBOT = false;
bool AIMLOCK = false;
bool NORECOIL = false;
bool SMALLCROSS = false;
bool NOFOG = false;
bool VIOLATEFOG = false;
bool CAMVIEW = false;
bool BLACKBODY = false;
bool DARKMAP = false;
bool CHAMS = false;
bool FLASHWEP = false;
bool BYPASS = false;
bool AIMHEAD = false;
bool ANTENA = false;
bool ANTISHAKE = false;
bool NIGHT = false;
bool SPEED = false;
bool SPEEDCAR = false;
bool JUMPCAR = false;



//Target lib here
#define targetLibName OBFUSCATE("libUE4.so")

extern "C" {
JNIEXPORT void JNICALL
Java_uk_lgl_modmenu_Preferences_Changes(JNIEnv *env, jclass clazz, jobject obj,
                                        jint feature, jint value, jboolean boolean, jstring str) {

    const char *featureName = env->GetStringUTFChars(str, 0);

    LOGD(OBFUSCATE("Feature name: %d - %s | Value: = %d | Bool: = %d"), feature, featureName, value,
         boolean);

    //!!! BE CAREFUL NOT TO ACCIDENTLY REMOVE break; !!!//

    switch (feature) {
        case 1:
            BYPASS = boolean;
            if (BYPASS) {
                hexPatches.BYPASS.Modify();
                hexPatches.BYPASS1.Modify();
                hexPatches.BYPASS2.Modify();
                hexPatches.BYPASS3.Modify();
                hexPatches.BYPASS4.Modify();
                hexPatches.BYPASS5.Modify();
            } else {
                hexPatches.BYPASS.Restore();
                hexPatches.BYPASS1.Restore();
                hexPatches.BYPASS2.Restore();
                hexPatches.BYPASS3.Restore();
                hexPatches.BYPASS4.Restore();
                hexPatches.BYPASS5.Restore();
            }
            break;
        case 2:
            AIMBOT = boolean;
            if (AIMBOT) {
                hexPatches.AIMBOT.Modify();
            } else {
                hexPatches.AIMBOT.Restore();
            }
            break;
        case 3:
            AIMLOCK = boolean;
            if (AIMLOCK) {
                hexPatches.AIMLOCK.Modify();
            } else {
                hexPatches.AIMLOCK.Restore();
            }
            break;
        case 4:
            AIMHEAD = boolean;
            if (AIMHEAD) {
                hexPatches.AIMHEAD.Modify();
            } else {
                hexPatches.AIMHEAD.Restore();
            }
            break;
        case 5:
            NORECOIL = boolean;
            if (NORECOIL) {
                hexPatches.NORECOIL.Modify();
            } else {
                hexPatches.NORECOIL.Restore();
            }
            break;
        case 6:
            NOFOG = boolean;
            if (NOFOG) {
                hexPatches.NOFOG.Modify();
            } else {
                hexPatches.NOFOG.Restore();
            }
            break;
        case 7:
            VIOLATEFOG = boolean;
            if (VIOLATEFOG) {
                hexPatches.VIOLATEFOG.Modify();
                hexPatches.VIOLATEFOG1.Modify();
            } else {
                hexPatches.VIOLATEFOG.Restore();
                hexPatches.VIOLATEFOG1.Restore();
            }
            break;
        case 8:
            CHAMS = boolean;
            if (CHAMS) {
                hexPatches.CHAMS.Modify();
            } else {
                hexPatches.CHAMS.Restore();
            }
            break;
        case 9:
            ANTENA = boolean;
            if (ANTENA) {
                hexPatches.ANTENA.Modify();
            } else {
                hexPatches.ANTENA.Restore();
            }
            break;
        case 10:
            SMALLCROSS = boolean;
            if (SMALLCROSS) {
                hexPatches.SMALLCROSS.Modify();
            } else {
                hexPatches.SMALLCROSS.Restore();
            }
            break;
        case 11:
            ANTISHAKE = boolean;
            if (ANTISHAKE) {
                hexPatches.ANTISHAKE.Modify();
                hexPatches.ANTISHAKE1.Modify();
            } else {
                hexPatches.ANTISHAKE.Restore();
                hexPatches.ANTISHAKE1.Restore();
            }
            break;
        case 12:
            NIGHT = boolean;
            if (NIGHT) {
                hexPatches.NIGHT.Modify();
                hexPatches.NIGHT1.Modify();
            } else {
                hexPatches.NIGHT.Restore();
                hexPatches.NIGHT1.Restore();
            }
            break;
        case 13:
            BLACKBODY = boolean;
            if (BLACKBODY) {
                hexPatches.BLACKBODY.Modify();
            } else {
                hexPatches.BLACKBODY.Restore();
            }
            break;
        case 14:
            DARKMAP = boolean;
            if (DARKMAP) {
                hexPatches.DARKMAP.Modify();
            } else {
                hexPatches.DARKMAP.Restore();
            }
            break;
        case 15:
            FLASHWEP = boolean;
            if (FLASHWEP) {
                hexPatches.FLASHWEP.Modify();
            } else {
                hexPatches.FLASHWEP.Restore();
            }
            break;
        case 16:
            switch (value) {
                case 0:
                    hexPatches.CAMVIEW = MemoryPatch::createWithHex(
                            targetLibName, string2Offset(
                                    OBFUSCATE_KEY("0x381FCB0", 't')),
                            OBFUSCATE(
                                    "00 00 92 43"));
                    hexPatches.CAMVIEW.Modify();
                    break;
                case 1:
                    hexPatches.CAMVIEW = MemoryPatch::createWithHex(
                            targetLibName, string2Offset(
                                    OBFUSCATE_KEY("0x381FCB0", 't')),
                            OBFUSCATE(
                                    "00 00 88 43"));
                    hexPatches.CAMVIEW.Modify();
                    break;
                case 2:
                    hexPatches.CAMVIEW = MemoryPatch::createWithHex(
                            targetLibName, string2Offset(
                                    OBFUSCATE_KEY("0x381FCB0", 't')),
                            OBFUSCATE(
                                    "00 00 85 43"));
                    hexPatches.CAMVIEW.Modify();
                case 3:
                    hexPatches.CAMVIEW = MemoryPatch::createWithHex(
                            targetLibName, string2Offset(
                                    OBFUSCATE_KEY("0x381FCB0", 't')),
                            OBFUSCATE(
                                    "00 00 81 43"));
                    hexPatches.CAMVIEW.Modify();
                case 4:
                    hexPatches.CAMVIEW = MemoryPatch::createWithHex(
                            targetLibName, string2Offset(
                                    OBFUSCATE_KEY("0x381FCB0", 't')),
                            OBFUSCATE(
                                    "00 00 79 43"));
                    hexPatches.CAMVIEW.Modify();
                case 5:
                    hexPatches.CAMVIEW = MemoryPatch::createWithHex(
                            targetLibName, string2Offset(
                                    OBFUSCATE_KEY("0x381FCB0", 't')),
                            OBFUSCATE(
                                    "00 00 75 43"));
                    hexPatches.CAMVIEW.Modify();
                case 6:
                    hexPatches.CAMVIEW = MemoryPatch::createWithHex(
                            targetLibName, string2Offset(
                                    OBFUSCATE_KEY("0x381FCB0", 't')),
                            OBFUSCATE(
                                    "00 00 73 43"));
                    hexPatches.CAMVIEW.Modify();
                case 7:
                    hexPatches.CAMVIEW = MemoryPatch::createWithHex(
                            targetLibName, string2Offset(
                                    OBFUSCATE_KEY("0x381FCB0", 't')),
                            OBFUSCATE(
                                    "00 00 70 43"));
                    hexPatches.CAMVIEW.Modify();
                case 8:
                    hexPatches.CAMVIEW = MemoryPatch::createWithHex(
                            targetLibName, string2Offset(
                                    OBFUSCATE_KEY("0x381FCB0", 't')),
                            OBFUSCATE(
                                    "00 00 68 43"));
                    hexPatches.CAMVIEW.Modify();
                case 9:
                    hexPatches.CAMVIEW = MemoryPatch::createWithHex(
                            targetLibName, string2Offset(
                                    OBFUSCATE_KEY("0x381FCB0", 't')),
                            OBFUSCATE(
                                    "00 00 65 43"));
                    hexPatches.CAMVIEW.Modify();
                case 10:
                    hexPatches.CAMVIEW = MemoryPatch::createWithHex(
                            targetLibName, string2Offset(
                                    OBFUSCATE_KEY("0x381FCB0", 't')),
                            OBFUSCATE(
                                    "00 00 63 43"));
                    hexPatches.CAMVIEW.Modify();
                    break;
            }
            break;
        case 17:
            SPEED = boolean;
            if (SPEED) {
                hexPatches.SPEED.Modify();
                hexPatches.SPEED1.Modify();
                hexPatches.SPEED2.Modify();
                hexPatches.SPEED3.Modify();
                hexPatches.SPEED4.Modify();
                hexPatches.SPEED5.Modify();
            } else {
                hexPatches.SPEED.Restore();
                hexPatches.SPEED1.Restore();
                hexPatches.SPEED2.Restore();
                hexPatches.SPEED3.Restore();
                hexPatches.SPEED4.Restore();
                hexPatches.SPEED5.Restore();
            }
            break;
        case 18:
            SPEEDCAR = boolean;
            if (SPEEDCAR) {
                hexPatches.SPEEDCAR.Modify();
            } else {
                hexPatches.SPEEDCAR.Restore();
            }
            break;
        case 19:
            JUMPCAR = boolean;
            if (JUMPCAR) {
                hexPatches.JUMPCAR.Modify();
            } else {
                hexPatches.JUMPCAR.Restore();
            }
            break;
        
    }
}
}


void *hack_thread(void *) {
    LOGI(OBFUSCATE("pthread called"));

    //Check if target lib is loaded
    do {
        sleep(1);
    } while (!isLibraryLoaded(targetLibName));

    LOGI(OBFUSCATE("%s has been loaded"), (const char *) targetLibName);

#if defined(__aarch64__)
#else

    //AIM
    hexPatches.AIMBOT = MemoryPatch::createWithHex(targetLibName,
                                                    string2Offset(OBFUSCATE_KEY("0x258B740", '-')),
                                                    OBFUSCATE("00 00 00 00"));
    hexPatches.AIMLOCK = MemoryPatch::createWithHex(targetLibName,
                                                   string2Offset(OBFUSCATE_KEY("0x258B74C", '-')),
                                                   OBFUSCATE("00 00 00 00"));
    hexPatches.AIMHEAD = MemoryPatch::createWithHex(targetLibName,
                                                    string2Offset(OBFUSCATE_KEY("0x2EC6F30", '-')),
                                                    OBFUSCATE("2A 00 00 00"));

    //MORE
    hexPatches.NORECOIL = MemoryPatch::createWithHex(targetLibName,
                                                   string2Offset(OBFUSCATE_KEY("0x136D4F8", '-')),
                                                   OBFUSCATE("00 00 00 00"));
    hexPatches.SMALLCROSS = MemoryPatch::createWithHex(targetLibName,
                                                   string2Offset(OBFUSCATE_KEY("0x1C113E8", '-')),
                                                   OBFUSCATE("01 00 00 00"));
    hexPatches.FLASHWEP = MemoryPatch::createWithHex(targetLibName,
                                                   string2Offset(OBFUSCATE_KEY("0x367EC84", '-')),
                                                   OBFUSCATE("00 00 00 00"));
    hexPatches.BLACKBODY = MemoryPatch::createWithHex(targetLibName,
                                                      string2Offset(OBFUSCATE_KEY("0x2D96C18", '-')),
                                                      OBFUSCATE("00 00 60 41 00 00 00 00"));

    //FOG
    hexPatches.NOFOG = MemoryPatch::createWithHex(targetLibName,
                                                     string2Offset(OBFUSCATE_KEY("0x2D0DA34", '-')),
                                                     OBFUSCATE("00 00 00 00"));
    hexPatches.VIOLATEFOG = MemoryPatch::createWithHex(targetLibName,
                                                  string2Offset(OBFUSCATE_KEY("0x2D0DA2C", '-')),
                                                  OBFUSCATE("00 00 80 3F"));
    hexPatches.VIOLATEFOG1 = MemoryPatch::createWithHex(targetLibName,
                                                       string2Offset(OBFUSCATE_KEY("0x2D0DA3C", '-')),
                                                       OBFUSCATE("00 00 80 3F"));

    //WALLHACK
    hexPatches.CHAMS = MemoryPatch::createWithHex(targetLibName,
                                                      string2Offset(OBFUSCATE_KEY("0x2EC6F30", '-')),
                                                      OBFUSCATE("E5 15 A0 E3 00 03 8D E8"));

    //NIGHT
    hexPatches.NIGHT = MemoryPatch::createWithHex(targetLibName,
                                                    string2Offset(OBFUSCATE_KEY("0x2EFA72C", '-')),
                                                    OBFUSCATE("00 00 00 00"));
    hexPatches.NIGHT1 = MemoryPatch::createWithHex(targetLibName,
                                                  string2Offset(OBFUSCATE_KEY("0x6BBFB20", '-')),
                                                  OBFUSCATE("00 00 00 00"));
    hexPatches.DARKMAP = MemoryPatch::createWithHex(targetLibName,
                                                    string2Offset(OBFUSCATE_KEY("0x2EFA724", '-')),
                                                    OBFUSCATE("00 00 00 00"));

    //SHAKE
    hexPatches.ANTISHAKE = MemoryPatch::createWithHex(targetLibName,
                                                  string2Offset(OBFUSCATE_KEY("0x2C344C8", '-')),
                                                  OBFUSCATE("00 00 00 00"));
    hexPatches.ANTISHAKE1 = MemoryPatch::createWithHex(targetLibName,
                                                   string2Offset(OBFUSCATE_KEY("0x376E57C", '-')),
                                                   OBFUSCATE("00 00 00 00"));

    //BYPASS
    hexPatches.BYPASS = MemoryPatch::createWithHex(targetLibName,
                                                       string2Offset(OBFUSCATE_KEY("0x62AD0A4", '-')),
                                                       OBFUSCATE("00 00 00 00"));
    hexPatches.BYPASS1 = MemoryPatch::createWithHex(targetLibName,
                                                   string2Offset(OBFUSCATE_KEY("0x3E30524", '-')),
                                                   OBFUSCATE("00 00 00 00"));
    hexPatches.BYPASS2 = MemoryPatch::createWithHex(targetLibName,
                                                    string2Offset(OBFUSCATE_KEY("0x3E31030", '-')),
                                                    OBFUSCATE("00 00 00 00"));
    hexPatches.BYPASS3 = MemoryPatch::createWithHex(targetLibName,
                                                    string2Offset(OBFUSCATE_KEY("0x3E31238", '-')),
                                                    OBFUSCATE("00 00 00 00"));
    hexPatches.BYPASS4 = MemoryPatch::createWithHex(targetLibName,
                                                    string2Offset(OBFUSCATE_KEY("0x0", '-')),
                                                    OBFUSCATE("7F 00 00 00 00 00 00 00"));
    hexPatches.BYPASS5 = MemoryPatch::createWithHex("libtersafe.so",
                                                     string2Offset(OBFUSCATE_KEY("0x0", 'g')),
                                                     OBFUSCATE("7F 00 00 00 00 00 00 00"));

    //SPEED RUN
    hexPatches.SPEED = MemoryPatch::createWithHex(targetLibName,
                                                   string2Offset(OBFUSCATE_KEY("0x130DF0C", '-')),
                                                   OBFUSCATE("00 00 00 00"));
    hexPatches.SPEED1 = MemoryPatch::createWithHex(targetLibName,
                                                    string2Offset(OBFUSCATE_KEY("0x3878E8C", '-')),
                                                    OBFUSCATE("00 00 00 00"));
    hexPatches.SPEED2 = MemoryPatch::createWithHex(targetLibName,
                                                    string2Offset(OBFUSCATE_KEY("0x3878E90", '-')),
                                                    OBFUSCATE("00 00 00 00"));
    hexPatches.SPEED3 = MemoryPatch::createWithHex(targetLibName,
                                                    string2Offset(OBFUSCATE_KEY("0x3878FB4", '-')),
                                                    OBFUSCATE("00 00 00 00"));
    hexPatches.SPEED4 = MemoryPatch::createWithHex(targetLibName,
                                                   string2Offset(OBFUSCATE_KEY("0x39E9B08", '-')),
                                                   OBFUSCATE("00 00 00 00"));
    hexPatches.SPEED5 = MemoryPatch::createWithHex(targetLibName,
                                                   string2Offset(OBFUSCATE_KEY("0x39E9B10", '-')),
                                                   OBFUSCATE("00 00 00 00"));

    //SPEED MORE
    hexPatches.SPEEDCAR = MemoryPatch::createWithHex(targetLibName,
                                                  string2Offset(OBFUSCATE_KEY("0x3F109B0", '-')),
                                                  OBFUSCATE("00 00 00 00"));
    hexPatches.JUMPCAR = MemoryPatch::createWithHex(targetLibName,
                                                   string2Offset(OBFUSCATE_KEY("0x47774F8", '-')),
                                                   OBFUSCATE("00 00 00 00"));

    //ANTENA
    hexPatches.ANTENA = MemoryPatch::createWithHex(targetLibName,
                                                     string2Offset(OBFUSCATE_KEY("0x25834D8", '-')),
                                                     OBFUSCATE("00 00 00 00"));
#endif

    return NULL;
}

__attribute__((constructor))
void lib_main() {
    pthread_t ptid;
    pthread_create(&ptid, NULL, hack_thread, NULL);
}


