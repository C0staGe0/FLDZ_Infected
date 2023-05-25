modded class MissionServer extends MissionBase 
{
    private ref InfectedSpawnManager m_InfectedSpawnManager;

    override void OnInit() 
    {
        super.OnInit();
        
        m_InfectedSpawnManager = new InfectedSpawnManager();
        m_InfectedSpawnManager.Init();
    }
}
