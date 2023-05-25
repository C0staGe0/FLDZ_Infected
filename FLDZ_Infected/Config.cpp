class CfgPatches
{
	class FLDZ_Infected
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = 
		{
			"DZ_Scripts",
			"DZ_Data"
		};
	};
};
class CfgMods
{
	class FLDZ_Infected
	{
		dir = "FLDZ_Infected";
		picture = "";
		action = "";
		hideName = 1;
		hidePicture = 1;
		name = "FLDZ_Infected";
		credits = "CostaGeo";
		author = "";
		authorID = "0";
		version = "1.0";
		extra = 0;
		type = "mod";
		inputs="";
		dependencies[] = {"Game", "World", "Mission"};
		class defs
		{
			class gameScriptModule
			{
				value = "";
				files[] = 
				{
					"FLDZ_Infected/Scripts/Common",
					"FLDZ_Infected/Scripts/3_Game"
				};
			};
			class worldScriptModule
			{
				value = "";
				files[] = 
				{
					"FLDZ_Infected/Scripts/Common",
					"FLDZ_Infected/Scripts/4_World"
				};
			};
			class missionScriptModule
			{
				value = "";
				files[] = 
				{
					"FLDZ_Infected/Scripts/Common",
					"FLDZ_Infected/Scripts/5_Mission"
				};
			};
		};
	};
};
