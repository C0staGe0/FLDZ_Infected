class InfectedSpawnManager
{
    private ref FLDZ_InfectedConfig m_Config;
    private bool m_IsSpawnEnabled;
    private int m_InfectedSpawnDelay;

    void Init()
    {
        m_Config = new FLDZ_InfectedConfig;
        m_Config.Load();

        m_IsSpawnEnabled = m_Config.EnableInfectedSpawn == 1;
        m_InfectedSpawnDelay = m_Config.InfectedSpawnDelayAfterStartInMinutes;

        if (m_IsSpawnEnabled)
        {
            Print("[FLDZ_InfectedSpawnManager] Infected spawn enabled.");

            if (m_InfectedSpawnDelay > 0)
            {
                // Implement delay logic here before calling SpawnInfectedEntities() function
                GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(SpawnInfectedEntities, m_InfectedSpawnDelay * 60 * 1000);
            }
            else
            {
                SpawnInfectedEntities();
            }
        }
        else
        {
            Print("[FLDZ_InfectedSpawnManager] Infected spawn disabled or config not found.");
        }
    }

    vector GetRandomSpawnPosition(float radius)
    {
        float xAdd = Math.RandomFloat(-radius, radius);
        float zAdd = Math.RandomFloat(-radius, radius);

        float xPos = Math.RandomFloat(0, 6000) + xAdd;
        float zPos = Math.RandomFloat(0, 8000) + zAdd;

        vector spawnPosition = Vector(xPos, GetGame().SurfaceY(xPos, zPos), zPos);

        // Print the spawn position
        Print("[FLDZ_InfectedSpawnManager] Spawn position: " + spawnPosition);

        return spawnPosition;
    }


    void SpawnInfectedEntities()
    {
        if (m_Config.InfectedClassNames_1.Count() == 0 && m_Config.InfectedClassNames_2.Count() == 0)
        {
            Print("[FLDZ_InfectedSpawnManager] Configuration error: Invalid config or empty InfectedClassNames arrays.");
            return;
        }

        int infectedSpawnAmount = m_Config.InfectedSpawnAmount;
        vector spawnPosition = GetRandomSpawnPosition(m_Config.SpawnRadius);

        // Spawn the first infected entity at the specified spawn position
        EntityAI firstInfectedEntity = EntityAI.Cast(GetGame().CreateObject(m_Config.InfectedClassNames_1.GetRandomElement(), spawnPosition, false, true));

        // Additional code for setting up the first infected entity, if needed

        // Keep track of the first infected entity's position
        vector firstEntityPosition = spawnPosition;

        // Spawn additional infected entities near the first entity
        for (int i = 1; i < infectedSpawnAmount; i++)
        {
            // Calculate a new spawn position near the first entity
            vector offset = Vector(Math.RandomFloat(-10, 10), 0, Math.RandomFloat(-10, 10));
            vector newSpawnPosition = firstEntityPosition + offset;

            // Determine which array of infected class names to use
            TStringArray infectedClassNames;
            if (i % 2 == 0)
            {
                infectedClassNames = m_Config.InfectedClassNames_1;
            }
            else
            {
                infectedClassNames = m_Config.InfectedClassNames_2;
            }

            // Spawn the infected entity at the new position
            EntityAI infectedEntity = EntityAI.Cast(GetGame().CreateObject(infectedClassNames.GetRandomElement(), newSpawnPosition, false, true));

            // Additional code for setting up the infected entity, if needed
        }
    }
}
