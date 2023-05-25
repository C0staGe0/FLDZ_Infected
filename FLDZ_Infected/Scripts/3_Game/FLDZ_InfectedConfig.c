class FLDZ_InfectedConfig
{
    private static const string CONFIG_VERSION = "0.0.1";
    private static const string FLDZ_InfectedModFolder = "$profile:\\FLDZ_Infected\\";
    private static const string FLDZ_InfectedConfigName = "FLDZ_InfectedConfig.json";

    string ConfigVersion = "";

    int EnableInfectedSpawn = 1; // 1 = Enabled, 0 = Disabled - Enables the infected spawn system on server start, without being set to 1 it will not work
    int InfectedSpawnDelayAfterStartInMinutes = 5; // Delay in minutes after server start to enable infected spawn system if EnableInfectedSpawn = 1
    int InfectedSpawnAmount = 10; // Amount of infected to spawn
    int SpawnRadius = 1000; // Radius in meters around the center of the map to spawn infected
    // int InfectedMovement = 1; // 1 = Enabled, 0 = Disabled - Enables infected movement towards nearest player
    autoptr TStringArray InfectedClassNames_1 = {
        "ZmbM_priestPopSkinny",
        "ZmbM_SkaterYoung_Grey",
        "ZmbM_SkaterYoung_Green",
        "ZmbM_SkaterYoung_Brown",
        "ZmbM_SkaterYoung_Blue",
		"ZmbM_MotobikerFat_Black",
        "ZmbM_MotobikerFat_Beige",
		"ZmbM_Jacket_stripes",
        "ZmbM_Jacket_magenta",
        "ZmbM_Jacket_khaki",
        "ZmbM_Jacket_grey",
        "ZmbM_Jacket_greenchecks",
        "ZmbM_Jacket_brown",
        "ZmbM_Jacket_bluechecks",
        "ZmbM_Jacket_blue",
        "ZmbM_Jacket_black",
        "ZmbM_Jacket_beige",
		"ZmbM_HikerSkinny_Yellow",
        "ZmbM_HikerSkinny_Green",
        "ZmbM_HikerSkinny_Blue",
        "ZmbM_HermitSkinny_Red",
        "ZmbM_HermitSkinny_Green",
        "ZmbM_HermitSkinny_Black",
        "ZmbM_HermitSkinny_Beige",
		"ZmbM_FarmerFat_Green",
        "ZmbM_FarmerFat_Brown",
        "ZmbM_FarmerFat_Blue",
        "ZmbM_FarmerFat_Beige",
		"ZmbM_ClerkFat_White",
        "ZmbM_ClerkFat_Khaki",
        "ZmbM_ClerkFat_Grey",
        "ZmbM_ClerkFat_Brown",
        "ZmbM_CitizenBFat_Red",
        "ZmbM_CitizenBFat_Green",
        "ZmbM_CitizenBFat_Blue",
        "ZmbM_CitizenASkinny_Red",
        "ZmbM_CitizenASkinny_Grey",
        "ZmbM_CitizenASkinny_Brown",
        "ZmbM_CitizenASkinny_Blue",
        "ZmbF_VillagerOld_White",
        "ZmbF_VillagerOld_Red",
        "ZmbF_VillagerOld_Green",
        "ZmbF_VillagerOld_Blue",
        "ZmbF_SurvivorNormal_White",
        "ZmbF_SurvivorNormal_Red",
        "ZmbF_SurvivorNormal_Orange",
        "ZmbF_SurvivorNormal_Blue",
        "ZmbF_SkaterYoung_Violet",
        "ZmbF_SkaterYoung_Striped",
        "ZmbF_SkaterYoung_Brown",
        "ZmbF_ShortSkirt_yellow",
        "ZmbF_ShortSkirt_white",
        "ZmbF_ShortSkirt_stripes",
        "ZmbF_ShortSkirt_red",
        "ZmbF_ShortSkirt_grey",
        "ZmbF_ShortSkirt_green",
        "ZmbF_ShortSkirt_checks",
        "ZmbF_ShortSkirt_brown",
        "ZmbF_ShortSkirt_black",
        "ZmbF_ShortSkirt_beige",
		"ZmbF_JoggerSkinny_Red",
        "ZmbF_JoggerSkinny_Green",
        "ZmbF_JoggerSkinny_Brown",
        "ZmbF_JoggerSkinny_Blue",
        "ZmbF_HikerSkinny_Red",
        "ZmbF_HikerSkinny_Grey",
        "ZmbF_HikerSkinny_Green",
        "ZmbF_HikerSkinny_Blue",
        "ZmbF_DoctorSkinny",
        "ZmbF_Clerk_Normal_White",
        "ZmbF_Clerk_Normal_Red",
        "ZmbF_Clerk_Normal_Green",
        "ZmbF_Clerk_Normal_Blue",
        "ZmbF_CitizenBSkinny",
        "ZmbF_CitizenANormal_Brown",
        "ZmbF_CitizenANormal_Blue",
        "ZmbF_CitizenANormal_Beige",
        "ZmbF_BlueCollarFat_White",
        "ZmbF_BlueCollarFat_Red",
        "ZmbF_BlueCollarFat_Green",
        "ZmbF_BlueCollarFat_Blue"
    };
    autoptr TStringArray InfectedClassNames_2 = {
        "ZmbM_PrisonerSkinny",
        "ZmbM_PolicemanSpecForce",
        "ZmbM_PolicemanFat",
        "ZmbM_PatientSkinny",
        "ZmbM_ParamedicNormal_Red",
        "ZmbM_ParamedicNormal_Green",
        "ZmbM_ParamedicNormal_Blue",
        "ZmbM_ParamedicNormal_Black",
        "ZmbM_OffshoreWorker_Yellow",
        "ZmbM_OffshoreWorker_Red",
        "ZmbM_OffshoreWorker_Orange",
        "ZmbM_OffshoreWorker_Green",        
        "ZmbM_MechanicSkinny_Red",
        "ZmbM_MechanicSkinny_Grey",
        "ZmbM_MechanicSkinny_Green",
        "ZmbM_MechanicSkinny_Blue",
        "ZmbM_JournalistSkinny",        
        "ZmbM_HunterOld_Winter",
        "ZmbM_HunterOld_Summer",
        "ZmbM_HunterOld_Spring",
        "ZmbM_HunterOld_Autumn",        
        "ZmbM_HeavyIndustryWorker",
        "ZmbM_HandymanNormal_White",
        "ZmbM_HandymanNormal_Grey",
        "ZmbM_HandymanNormal_Green",
        "ZmbM_HandymanNormal_Blue",
        "ZmbM_HandymanNormal_Beige",
        "ZmbM_FishermanOld_Red",
        "ZmbM_FishermanOld_Grey",
        "ZmbM_FishermanOld_Green",
        "ZmbM_FishermanOld_Blue",
        "ZmbM_FirefighterNormal",        
        "ZmbM_DoctorFat",
        "ZmbM_ConstrWorkerNormal_Grey",
        "ZmbM_ConstrWorkerNormal_Green",
        "ZmbM_ConstrWorkerNormal_Black",
        "ZmbM_ConstrWorkerNormal_Beige",
        "ZmbM_CommercialPilotOld_Olive",
        "ZmbM_CommercialPilotOld_Grey",
        "ZmbM_CommercialPilotOld_Brown",
        "ZmbM_CommercialPilotOld_Blue",        
        "ZmbF_PoliceWomanNormal",
        "ZmbF_PatientOld",
        "ZmbF_ParamedicNormal_Red",
        "ZmbF_ParamedicNormal_Green",
        "ZmbF_ParamedicNormal_Blue",
        "ZmbF_NurseFat",
        "ZmbF_MilkMaidOld_Grey",
        "ZmbF_MilkMaidOld_Green",
        "ZmbF_MilkMaidOld_Black",
        "ZmbF_MilkMaidOld_Beige",
        "ZmbF_MechanicNormal_Orange",
        "ZmbF_MechanicNormal_Grey",
        "ZmbF_MechanicNormal_Green",
        "ZmbF_MechanicNormal_Beige",
        "ZmbF_JournalistNormal_White",
        "ZmbF_JournalistNormal_Red",
        "ZmbF_JournalistNormal_Green",
        "ZmbF_JournalistNormal_Blue",        
        "ZmbM_SoldierNormal",
        "ZmbM_PatrolNormal_Autumn",
        "ZmbM_PatrolNormal_Flat",
        "ZmbM_PatrolNormal_PautRev",
        "ZmbM_PatrolNormal_Summer"
    };

    void Load()
    {
        Print("[FLDZ_InfectedConfig] Loading config file...");
        string configPath = FLDZ_InfectedModFolder + FLDZ_InfectedConfigName;

        if (FileExist(configPath))
        {
            JsonFileLoader<FLDZ_InfectedConfig>.JsonLoadFile(configPath, this);

            if (ConfigVersion != CONFIG_VERSION)
            {
                JsonFileLoader<FLDZ_InfectedConfig>.JsonSaveFile(configPath + "_old", this);
            }
            else
            {
                return;
            }
        }
        else
        {
            ConfigVersion = CONFIG_VERSION;
            Save();
        }
    }

    void Save()
    {
        Print("[FLDZ_InfectedConfig] Saving config file...");
        string configPath = FLDZ_InfectedModFolder + FLDZ_InfectedConfigName;

        if (!FileExist(FLDZ_InfectedModFolder))
        {
            if (!MakeDirectory(FLDZ_InfectedModFolder))
            {
                Print("[FLDZ_InfectedConfig] Error creating mod folder: " + FLDZ_InfectedModFolder);
                return;
            }
        }

        JsonFileLoader<FLDZ_InfectedConfig>.JsonSaveFile(configPath, this);
    }
};