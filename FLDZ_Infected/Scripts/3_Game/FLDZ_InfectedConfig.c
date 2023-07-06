class FLDZ_InfectedConfig
{
    private static const string CONFIG_VERSION = "0.0.3";
    private static const string FLDZ_InfectedModFolder = "$profile:\\FLDZ_Infected\\";
    private static const string FLDZ_InfectedConfigName = "FLDZ_InfectedConfig.json";

    string ConfigVersion = "";

    int EnableInfectedSpawn = 1; // 1 = Enabled, 0 = Disabled - Enables the infected spawn system on server start, without being set to 1 it will not work
    int InfectedSpawnDelayAfterStartInMinutes = 1; // Delay in minutes after server start to enable infected spawn system if EnableInfectedSpawn = 1
    int InfectedSpawnAmount = 10; // Amount of infected to spawn
    int SpawnRadius = 1000; // Radius in meters around the center of the map to spawn infected
    bool CanSpawnContainer = 1; // 1 = Enabled, 0 = Disabled - If the loot container will be able to spawn with the horde
    bool CanSpawnWorldObject = 1; // 1 = Enabled, 0 = Disabled - If the world object will be able to spawn with the horde
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
        "ZmbM_HermitSkinny_Beige"
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
        "ZmbM_DoctorFat"
    };
    autoptr TStringArray ContainerObject = {
        "SeaChest",
        "Barrel_Blue",
        "Barrel_Green",
        "Barrel_Red",
        "Barrel_Yellow",
        "BarrelHoles_Blue",
        "BarrelHoles_Green",
        "BarrelHoles_Red",
        "BarrelHoles_Yellow"
    };
    autoptr TStringArray ContainerObjectLoot = {
        "M4A1_Green",
        "M4_RISHndgrd_Green",
        "M4_MPBttstck",
        "M4_Suppressor",
        "ACOGOptic",
        "Mag_STANAG_30Rnd",
        "Ammo_556x45",
        "Ammo_556x45",
        "HuntingKnife",
        "BakedBeansCan",
        "Canteen",
        "Battery9V"
        "WaterBottle",
        "SpaghettiCan",
        "UMP45",
        "M68Optic",
        "PistolSuppressor",
        "Mag_UMP_25Rnd",
        "Ammo_45ACP",
        "TunaCan",
        "RDG5Grenade"
    };
    autoptr TStringArray WorldObject = {
        "Land_Wreck_C130J",
        "Wreck_Mi8_Crashed",
        "Wreck_Mi8",
        "Wreck_UH1Y",
        "Land_Wreck_Caravan_MRust"
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
