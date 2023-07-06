class InfectedSpawnManager
{
    private ref FLDZ_InfectedConfig m_Config;
    private bool m_IsSpawnEnabled;
    private int m_InfectedSpawnDelay;
    private bool m_CanSpawnContainer
    private bool m_CanSpawnWorldObject;

    void Init()
    {
        m_Config = new FLDZ_InfectedConfig;
        m_Config.Load();

        m_IsSpawnEnabled = m_Config.EnableInfectedSpawn == 1;
        m_InfectedSpawnDelay = m_Config.InfectedSpawnDelayAfterStartInMinutes;
        m_CanSpawnContainer = m_Config.CanSpawnContainer == 1;
        m_CanSpawnWorldObject = m_Config.CanSpawnWorldObject == 1;

        if (m_IsSpawnEnabled)
        {
            Print("[FLDZ_InfectedSpawnManager] Infected spawn enabled.");

            if (m_InfectedSpawnDelay > 0)
            {
                // Implement delay logic here before calling SpawnInfectedEntitiesAndContainer() function
                GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(SpawnInfectedEntitiesAndContainer, m_InfectedSpawnDelay * 60 * 1000);
            }
            else
            {
                SpawnInfectedEntitiesAndContainer();
            }
        }
        else
        {
            Print("[FLDZ_InfectedSpawnManager] Infected spawn disabled or config not found.");
        }
    }

    vector GetRandomSpawnPosition(float radius)
    {
        vector spawnPosition;

        while (true)
        {
            float xAdd = Math.RandomFloat(-radius, radius);
            float zAdd = Math.RandomFloat(-radius, radius);

            float xPos = Math.RandomFloat(0, 6000) + xAdd;
            float zPos = Math.RandomFloat(0, 8000) + zAdd;

            spawnPosition = Vector(xPos, GetGame().SurfaceY(xPos, zPos), zPos);

            // Check if the spawn position is on land
            if (IsPositionOnLand(spawnPosition))
            {
                break;
            }
        }

        // Print the spawn position
        Print("[FLDZ_InfectedSpawnManager] Spawn position: " + spawnPosition);

        return spawnPosition;
    }

    bool IsPositionOnLand(vector position)
    {
        if (!GetGame().SurfaceIsSea(position[0], position[2]))
        {
            return true;
        }

        return false;
    }

    void SpawnInfectedEntitiesAndContainer()
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

        // Spawn the container if CanSpawnContainer is set to 1
        if (m_CanSpawnContainer)
        {
            SpawnContainer(firstEntityPosition);

            // Offset the first entity position for world object spawning
            firstEntityPosition = firstEntityPosition + Vector(10, 0, 10);
        }

        // Spawn the world object if CanSpawnWorldObject is set to 1
        if (m_CanSpawnWorldObject)
        {
            SpawnWorldObject(firstEntityPosition);
        }
    }

    void SpawnContainer(vector spawnPosition)
    {
        if (m_Config.ContainerObject.Count() == 0 || m_Config.ContainerObjectLoot.Count() == 0)
        {
            Print("[FLDZ_InfectedSpawnManager] Configuration error: Invalid config or empty ContainerObject or ContainerObjectLoot arrays.");
            return;
        }

        // Get a random container object and its corresponding loot
        string containerObject = m_Config.ContainerObject.GetRandomElement();
        string containerObjectLoot = m_Config.ContainerObjectLoot.GetRandomElement();

        // Spawn the container at the specified position
        EntityAI containerEntity = EntityAI.Cast(GetGame().CreateObject(containerObject, spawnPosition, false, true));

        // Attach random loot to the container's inventory
        ItemBase containerItem = ItemBase.Cast(containerEntity);
        for (int i = 0; i < 10; i++)
        {
            containerItem.GetInventory().CreateInInventory(GetRandomLootItem());
        }

        // Print a message indicating the container spawn
        Print("[FLDZ_InfectedSpawnManager] Container spawned at position: " + spawnPosition);
    }

    void SpawnWorldObject(vector spawnPosition)
    {
        if (m_Config.WorldObject.Count() == 0)
        {
            Print("[FLDZ_InfectedSpawnManager] Configuration error: Invalid config or empty WorldObject array.");
            return;
        }

        // Get a random world object from the configuration
        string worldObject = m_Config.WorldObject.GetRandomElement();

        // Offset the spawn position slightly above the ground
        float groundOffset = 2.0;
        spawnPosition = SnapToGround(spawnPosition) + Vector(0, groundOffset, 0);

        // Spawn the world object at the specified position
        EntityAI worldObjectEntity = EntityAI.Cast(GetGame().CreateObject(worldObject, spawnPosition, false, true));

        if (worldObjectEntity)
        {
            // Print a message indicating the world object spawn
            Print("[FLDZ_InfectedSpawnManager] World object spawned at position: " + spawnPosition);
        }
        else
        {
            Print("[FLDZ_InfectedSpawnManager] Error spawning world object: " + worldObject);
        }
    }

    vector SnapToGround(vector pos)
    {
        float pos_x = pos[0];
        float pos_z = pos[2];
        float pos_y = GetGame().SurfaceY(pos_x, pos_z);

        return Vector(pos_x, pos_y, pos_z);
    }

    string GetRandomLootItem()
    {
        if (m_Config.ContainerObjectLoot.Count() == 0)
        {
            return "";
        }

        int randomIndex = Math.RandomInt(0, m_Config.ContainerObjectLoot.Count());
        return m_Config.ContainerObjectLoot.Get(randomIndex);
    }
};
