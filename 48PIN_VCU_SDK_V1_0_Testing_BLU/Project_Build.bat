@ECHO OFF
setlocal enabledelayedexpansion
@REM setlocal enableextensions disabledelayedexpansion
cls
if exist "Build\" (
    @REM echo created Build\
) else (
    MD Build\
)
if exist "Build\asm" (
    @REM echo "!FOLDER_PATH!"
) else (
    MD Build\asm\
)
if exist "Build\obj" (
    @REM echo "!FOLDER_PATH!"
) else (
    MD Build\obj\
)
if exist "Build\Output" (
    @REM echo "!FOLDER_PATH!"
) else (
    MD Build\Output\
)
cd Build/Output
for /r %%a in (*) do (
    if "%%~nxa"=="Compiler_inputFile.txt" (
    Del "Compiler_inputFile.txt"
    )
    if "%%~xa"==".hex" (
        Del %%~nxa
        )
    if "%%~xa"==".map" (
        Del %%~nxa
        )
    if "%%~xa"==".abs" (
        Del %%~nxa
        )
    if "%%~xa"==".sni" (
        Del %%~nxa
        )
    if "%%~xa"==".xml" (
        Del %%~nxa
        )
)

cd ..
cd ..
echo -c>> Build/Output/Compiler_inputFile.txt
@REM echo %cd%



set "var=%cd%"
cd ..
set "var1=%cd%"
cd %var%
for /F %%a in ("!var1!") do set "Project_Name=!var:%%a=!"
set Project_Name=%Project_Name:*\=%
@REM echo %Project_Name%

ECHO ------ Start build(%Project_Name%) ------
SET FOLDER_PATH=%CD%
SET FOLDER_C_PATH=%CD..%
SET FOLDER_H_PATH=%CD..%
SET FOLDER_ASM_PATH=%CD..%
for /R  %%f in (*) do (
    for %%I in ("%%~dp$PATH:f.") do (
        SET FOLDER_PATH=%%~fI
        @REM echo "!FOLDER_PATH!"
    )
    if "%%~xf"==".h" (
        if "!FOLDER_H_PATH!" EQU  "!FOLDER_PATH!" (
        @REM echo "%%~dp$PATH:f"
        ) else (
            for %%K in ("%%~dp$PATH:f.") do (
                SET FOLDER_H_PATH=%%~fK
                @REM echo "!FOLDER_H_PATH!"

                if "%CD%" EQU  "%%~fK" (
                    @REM Set p=%%~fK
                    Echo -I.>> Build/Output/Compiler_inputFile.txt
                ) else (
                    Set p=%%~fK
                    Echo -I!p:%__CD__%=!>> Build/Output/Compiler_inputFile.txt 
                )

                @REM echo -I%%~fK>> Build/Output/Compiler_inputFile.txt
            )
        )
    )
    if "%%~xf"==".c" (
        if "!FOLDER_C_PATH!" EQU  "!FOLDER_PATH!" (
        @REM echo "%%~dp$PATH:f"
        ) else (
            for %%K in ("%%~dp$PATH:f.") do (
                SET FOLDER_C_PATH=%%~fK
                @REM echo "!FOLDER_C_PATH!"

                if "%CD%" EQU  "%%~fK" (
                    @REM Set p=%%~fK
                    Echo *.c>> Build/Output/Compiler_inputFile.txt
                ) else (
                    Set p=%%~fK
                    Echo !p:%__CD__%=!\*.c>> Build/Output/Compiler_inputFile.txt 
                )
                @REM Set p=%%~fK
                @REM echo %%~fK
                @REM Echo !p:%__CD__%=!\*.c>> Build/Output/Compiler_inputFile.txt

                @REM echo %%~fK\*.c>> Build/Output/Compiler_inputFile.txt
                @REM Set p=%%~fK
                @REM Echo ^>!p:%__CD__%=!
            )
        )
        Set p=%%~f
        Echo ^>!p:%__CD__%=!
    )
    if "%%~xf"==".asm" (
        if "!FOLDER_ASM_PATH!" EQU  "!FOLDER_PATH!" (
        @REM echo "%%~dp$PATH:f"
        ) else (
            for %%K in ("%%~dp$PATH:f.") do (
                SET FOLDER_ASM_PATH=%%~fK
                @REM echo "!FOLDER_ASM_PATH!"

                if "%CD%" EQU  "%%~fK" (
                    @REM Set p=%%~fK
                    Echo *.asm>> Build/Output/Compiler_inputFile.txt
                ) else (
                    Set p=%%~fK
                    Echo !p:%__CD__%=!\*.asm>> Build/Output/Compiler_inputFile.txt 
                )
                @REM Set p=%%~fK
                @REM Echo !p:%__CD__%=!\*.asm>> Build/Output/Compiler_inputFile.txt

                @REM echo %%~fK\*.asm>> Build/Output/Compiler_inputFile.txt
            )
        )
        Set p=%%f
        Echo ^>!p:%__CD__%=!
    )
)
@REM ECHO ------ Start build(VCU_ASW_V1) ------
@REM SET FOLDER_PATH=%CD%
@REM SET FOLDER1_PATH=%CD..%
@REM for /R  %%f in (*.asm) do (
@REM     for %%I in ("%%~dp$PATH:f.") do (
@REM         SET FOLDER_PATH=%%~fI
@REM         @REM echo "!FOLDER_PATH!"
@REM     )
@REM     if "!FOLDER1_PATH!" EQU  "!FOLDER_PATH!" (
@REM         @REM echo "%%~dp$PATH:f"
@REM     ) else (
@REM             for %%K in ("%%~dp$PATH:f.") do (
@REM         SET FOLDER1_PATH=%%~fK
@REM         @REM echo "!FOLDER1_PATH!"
@REM         echo %%~fK\*.asm>> Build/Output/Compiler_inputFile.txt
@REM         @REM echo %%~fK\*.asm
@REM         )
@REM     )
@REM     Set p=%%f
@REM     Echo ^>!p:%__CD__%=!
@REM )
@REM SET FOLDER_PATH=%CD%
@REM SET FOLDER1_PATH=%CD..%
@REM for /R  %%f in (*.c) do (
@REM     for %%I in ("%%~dp$PATH:f.") do (
@REM         SET FOLDER_PATH=%%~fI
@REM         @REM echo "!FOLDER_PATH!"
@REM     )
@REM     if "!FOLDER1_PATH!" EQU  "!FOLDER_PATH!" (
@REM         echo "%%~dp$PATH:f"
@REM     ) else (
@REM             for %%K in ("%%~dp$PATH:f.") do (
@REM         SET FOLDER1_PATH=%%~fK
@REM         @REM echo "!FOLDER1_PATH!"
@REM         echo %%~fK\*.c>> Build/Output/Compiler_inputFile.txt
@REM         @REM echo %%~fK\*.c
@REM         )
@REM     )
@REM     Set p=%%f
@REM     Echo ^>!p:%__CD__%=!
@REM )
@REM SET FOLDER_PATH=%CD%
@REM SET FOLDER1_PATH=%CD..%
@REM for /R  %%f in (*.h) do (
@REM     for %%I in ("%%~dp$PATH:f.") do (
@REM         SET FOLDER_PATH=%%~fI
@REM         @REM echo "!FOLDER_PATH!"
@REM     )
@REM     if "!FOLDER1_PATH!" EQU  "!FOLDER_PATH!" (
@REM         @REM echo "%%~dp$PATH:f"
@REM     ) else (
@REM             for %%K in ("%%~dp$PATH:f.") do (
@REM         SET FOLDER1_PATH=%%~fK
@REM         @REM echo "!FOLDER1_PATH!"
@REM         echo -I%%~fK>> Build/Output/Compiler_inputFile.txt
@REM         @REM echo -I%%~fK
@REM         )
@REM     )
@REM ) 
echo -Xobj_path=.\Build\obj>> Build/Output/Compiler_inputFile.txt
echo -Xasm_option=-Xprn_path=.\Build\asm>> Build/Output/Compiler_inputFile.txt
echo -Xcommon=rh850>> Build/Output/Compiler_inputFile.txt
SET COMPILER_PATH=Setting\COMPILER\V2.03.00\bin
cd Build/asm
for %%i in ("*.prn") do (
    Del "*.prn"
)
cd ..
cd obj
for %%i in ("*.obj") do (
    Del "*.obj"
)
cd ..
cd ..
%COMPILER_PATH%\ccrh @./Build/Output/Compiler_inputFile.txt
@REM cls
cd Build/Output
for /r %%a in (*) do (
    if "%%~nxa"=="Compiler_inputFile.txt" (
    Del "Compiler_inputFile.txt"
    )
)
cd ..
cd obj
for %%y in ("*.obj") do (
    cd ..
    cd Output
    echo -input=Build/obj/%%y>> Compiler_inputFile.txt
    cd ..
    cd obj
)
cd ..
cd ..
cd Lib
for /r %%a in (*) do (
    if "%%~xa"==".lib" (
        cd ..
        echo -library=%%a>> Build/Output/Compiler_inputFile.txt
        cd Lib
        @REM echo %%a
    ) 
)

@REM for /r %%a in (*) do (
@REM     if "%%~xa"==".lib" (
@REM         cd ..
@REM         @REM for %%K in ("%%~dp$PATH:a.") do (
@REM         @REM     Set p=%%~aK
@REM         @REM     Echo -library=!p:%__CD__%=!>> Build/Output/Compiler_inputFile.txt 
@REM         @REM     Echo -library=!p:%__CD__%=!
@REM         @REM )
@REM         echo -library=%%a>> Build/Output/Compiler_inputFile.txt
@REM         @REM echo -library=%%a
@REM         cd Lib
@REM     ) 
@REM )
cd ..
@REM echo -Xno_warning=61017>> Build/Output/Compiler_inputFile.txt
echo -nocompress>> Build/Output/Compiler_inputFile.txt
echo -NOOPtimize>> Build/Output/Compiler_inputFile.txt
echo -output=Build/Output/%Project_Name%.abs>> Build/Output/Compiler_inputFile.txt
echo -list=Build/Output/%Project_Name%.map>> Build/Output/Compiler_inputFile.txt
echo -library=Setting/COMPILER/V2.03.00/lib/v850e3v5/rhf4n.lib>> Build/Output/Compiler_inputFile.txt
echo -library=Setting/COMPILER/V2.03.00/lib/v850e3v5/libmalloc.lib>> Build/Output/Compiler_inputFile.txt
setlocal enableextensions disabledelayedexpansion
set "var="
for /f "usebackq delims=" %%a in ("Setting/Linker_File.txt") do (
    setlocal enabledelayedexpansion   
    for /f "tokens=* delims=¬" %%b in ("¬!var!") do endlocal & set "var=%%b%%a"
)
@REM echo %var%
echo -start=%var%>> Build/Output/Compiler_inputFile.txt
@REM echo -start=RESET/e000,EIINTTBL.const/0000E400,.text,.const,.INIT_DSEC.const,.INIT_BSEC.const,.data,R_FDL_Text.text,R_FDL_Const.const,R_FCL_CODE_ROM.text,R_FCL_CONST.const,R_FCL_CODE_USRINT.text,R_FCL_CODE_USR.text,R_FCL_CODE_RAM.text,R_FCL_CODE_ROMRAM.text,R_FCL_CODE_RAM_EX_PROT.text/0000FF70,FCL_RESERVED.bss/FEBE0000,.data.R,.bss,R_FCL_DATA.bss,.stack.bss,R_FDL_Data.bss,R_FDL_CodeRam.bss/FEDE8000>> Build/Output/Compiler_inputFile.txt
@REM echo -start=RESET/0,EIINTTBL.const/00000200,.const,.INIT_DSEC.const,.INIT_BSEC.const,.text,.data,R_FDL_Text.text,R_FDL_Const.const/00008000,.data.R,.bss,.stack.bss,R_FDL_Data.bss,R_FDL_CodeRam.bss/FEDE8000>> Build/Output/Compiler_inputFile.txt
echo -rom=.data=.data.R>> Build/Output/Compiler_inputFile.txt
echo -stack>> Build/Output/Compiler_inputFile.txt
echo -total_size>> Build/Output/Compiler_inputFile.txt
echo -nologo>> Build/Output/Compiler_inputFile.txt
echo -output=Build/Output/%Project_Name%.hex>> Build/Output/Compiler_inputFile.txt
@REM echo -byte_count=1>> Build/Output/Compiler_inputFile.txt
echo -form=hexadecimal>> Build/Output/Compiler_inputFile.txt
@REM echo -FIX_RECORD_LENGTH_AND_ALIGN=10>> Build/Output/Compiler_inputFile.txt
echo byte_count=10>> Build/Output/Compiler_inputFile.txt
echo -exit>> Build/Output/Compiler_inputFile.txt
%COMPILER_PATH%\rlink -subcommand=./Build/Output/Compiler_inputFile.txt
cd Build/Output
for /r %%a in (*) do (
    if "%%~nxa"=="Compiler_inputFile.txt" (
    Del "Compiler_inputFile.txt"
    )
)
cd ..
@REM to keep obj file .prn file comment below line till END... is thire 
cd asm
for %%i in ("*.prn") do (
    Del "*.prn"
)
cd ..
cd obj
for %%i in ("*.obj") do (
    Del "*.obj"
)
cd ..
@REM PAUSE
cd Output
for %%i in ("*.abs") do (
    Del "*.abs"
)
for %%i in ("*.map") do (
    Del "*.map"
)
for %%i in ("*.sni") do (
    Del "*.sni"
)

@REM echo ^<?xml version="1.0" encoding="UTF-8"?^> >sFlasher_config.xml
@REM echo ^<ECU_NAME^> >>sFlasher_config.xml
@REM echo   ^<PROGRAMMER^>VCU^</PROGRAMMER^> >>sFlasher_config.xml
@REM echo   ^<TOTAL_BLOCKS^>3^</TOTAL_BLOCKS^> >>sFlasher_config.xml
@REM echo   ^<DEFAULT_BAUDRATE^>500^</DEFAULT_BAUDRATE^> >>sFlasher_config.xml
@REM     echo   ^<MEM_BLOCKS^> >>sFlasher_config.xml
@REM     echo        ^<LOGICAL_BLOCK name="ASW"^> >>sFlasher_config.xml
@REM     echo            ^<PHY_BLOCK^> >>sFlasher_config.xml
@REM 	echo	            ^<BLOCK_NAME^>ASW1^</BLOCK_NAME^> >>sFlasher_config.xml
@REM 	echo	            ^<BLOCK_ID^>0xB101^</BLOCK_ID^> >>sFlasher_config.xml
@REM 	echo	            ^<BLOCK_STARTING_ADDRESS^>0x0000E000^</BLOCK_STARTING_ADDRESS^> >>sFlasher_config.xml
@REM 	echo	            ^<BLOCK_SIZE^>0x00002000^</BLOCK_SIZE^> >>sFlasher_config.xml
@REM     echo            ^</PHY_BLOCK^> >>sFlasher_config.xml
@REM     echo        ^</LOGICAL_BLOCK^> >>sFlasher_config.xml
@REM     echo   ^</MEM_BLOCKS^> >>sFlasher_config.xml
@REM for /f "tokens=*" %%a in (%Project_Name%.hex) do (
@REM   if "%%a" == ":020000021000EC" (
@REM     echo   ^<MEM_BLOCKS^> >>sFlasher_config.xml
@REM     echo        ^<LOGICAL_BLOCK name="ASW"^> >>sFlasher_config.xml
@REM     echo            ^<PHY_BLOCK^> >>sFlasher_config.xml
@REM 	echo	            ^<BLOCK_NAME^>ASW2^</BLOCK_NAME^> >>sFlasher_config.xml
@REM 	echo	            ^<BLOCK_ID^>0xB102^</BLOCK_ID^> >>sFlasher_config.xml
@REM 	echo	            ^<BLOCK_STARTING_ADDRESS^>0x00010000^</BLOCK_STARTING_ADDRESS^> >>sFlasher_config.xml
@REM 	echo	            ^<BLOCK_SIZE^>0x00010000^</BLOCK_SIZE^> >>sFlasher_config.xml
@REM     echo            ^</PHY_BLOCK^> >>sFlasher_config.xml
@REM     echo        ^</LOGICAL_BLOCK^> >>sFlasher_config.xml
@REM     echo   ^</MEM_BLOCKS^> >>sFlasher_config.xml
@REM   )
@REM   if "%%a" == ":020000022000DC" (

@REM     echo   ^<MEM_BLOCKS^> >>sFlasher_config.xml
@REM     echo        ^<LOGICAL_BLOCK name="ASW"^> >>sFlasher_config.xml
@REM     echo            ^<PHY_BLOCK^> >>sFlasher_config.xml
@REM 	echo	            ^<BLOCK_NAME^>ASW3^</BLOCK_NAME^> >>sFlasher_config.xml
@REM 	echo	            ^<BLOCK_ID^>0xB103^</BLOCK_ID^> >>sFlasher_config.xml
@REM 	echo	            ^<BLOCK_STARTING_ADDRESS^>0x00020000^</BLOCK_STARTING_ADDRESS^> >>sFlasher_config.xml
@REM 	echo	            ^<BLOCK_SIZE^>0x00010000^</BLOCK_SIZE^> >>sFlasher_config.xml
@REM     echo            ^</PHY_BLOCK^> >>sFlasher_config.xml
@REM     echo        ^</LOGICAL_BLOCK^> >>sFlasher_config.xml
@REM     echo   ^</MEM_BLOCKS^> >>sFlasher_config.xml
@REM   )
@REM )
@REM echo ^</ECU_NAME^> >>sFlasher_config.xml
cd ..
PAUSE
@REM END...
@REM exit /b

















@REM for %%y in ("*.obj") do (
    @REM if "%%~nxy" NEQ  "r_fdl_user_if_init.obj" (
    @REM     if "%%~nxy" NEQ  "r_fdl_user_if.obj" (
    @REM         if "%%~nxy" NEQ  "r_fdl_hw_access.obj" (
    @REM             if "%%~nxy" NEQ  "fdl_descriptor.obj" (
    @REM                 if "%%~nxy" NEQ  "fdl_user.obj" (
                        @REM echo -input=Build/obj/%%y>> input_objFile.txt
    @REM     )
    @REM     )       
    @REM     )
    @REM     )
    @REM )
)
@REM for %%y in ("*.obj") do (
@REM     if "%%~nxy" EQU "r_fdl_user_if_init.obj" (
@REM         echo -input=Build/obj/%%y>> input_objFile.txt
@REM     ) else if "%%~nxy" EQU "r_fdl_user_if.obj" (
@REM         echo -input=Build/obj/%%y>> input_objFile.txt
@REM     ) else if "%%~nxy" EQU "r_fdl_hw_access.obj" (
@REM         echo -input=Build/obj/%%y>> input_objFile.txt
@REM     ) else if "%%~nxy" EQU "fdl_descriptor.obj" (
@REM         echo -input=Build/obj/%%y>> input_objFile.txt
@REM     ) else if "%%~nxy" EQU "fdl_user.obj" (
@REM         echo -input=Build/obj/%%y>> input_objFile.txt
@REM     )
@REM )    
