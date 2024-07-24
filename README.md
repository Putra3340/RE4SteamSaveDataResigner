# RE4 Steam Save Data Resigner

## Instructions

1. **ORIGINAL_STEAM_SAVEDATA**
   - Copy your save data files from `Steam\userdata\<Your SteamID>\254700\remote\savegame00.sav` to this folder.
   - If the file doesn't exist, ensure you have created save data in RE4.

2. **EXTERNAL_SAVEDATA**
   - Copy your external save data or the save data you want to be patched to this folder.

3. **OUTPUT_SAVEDATA**
   - This save data is ready to replace `Steam\userdata\<Your SteamID>\254700\remote\savegame00.sav`.

## Method Explanation

- **Method 1**
  - Reads and writes offsets `0x00001E40` and `0x00001E50`.
  - Recommended for use. If this method doesn't work or the save data isn't loadable, try Method 2.

- **Method 2**
  - Reads and writes offsets `0x00001E50` and `0x00001E60`.

## Build Information

- Build using VS2022 C++14 Standard.
