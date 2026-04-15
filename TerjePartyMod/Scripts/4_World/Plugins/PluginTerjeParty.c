class PluginTerjeParty extends PluginBase
{	
	private string m_clientDataFilePath;
	private ref set<string> m_clientInvites;
	private ref set<string> m_clientPartyMembers;
	private ref TerjePartyModConfig m_config;
	
	override void OnInit()
	{
		GetRPCManager().AddRPC("TerjePartyMod", "OnSendInvite", this, SingleplayerExecutionType.Both);
		GetRPCManager().AddRPC("TerjePartyMod", "OnAcceptInvite", this, SingleplayerExecutionType.Both);
		GetRPCManager().AddRPC("TerjePartyMod", "OnRemoveFromParty", this, SingleplayerExecutionType.Both);
		GetRPCManager().AddRPC("TerjePartyMod", "RequestConfig", this, SingleplayerExecutionType.Both);
		
		if (g_Game.IsClient())
		{
			m_clientInvites = new set<string>;
			m_clientPartyMembers = new set<string>;
			m_clientDataFilePath = "$profile:TerjeParty.dat";
			if (FileExist(m_clientDataFilePath))
			{
				FileSerializer ctx = new FileSerializer();
				ctx.Open(m_clientDataFilePath, FileMode.READ);
				if (ctx.IsOpen())
				{
					int count;
					ctx.Read(count);			
					for (int i = 0; i < count; i++)
					{
						string guid;
						ctx.Read(guid);
						m_clientPartyMembers.Insert(guid);
					}
					
					ctx.Close();
				}
				else
				{
					Print("[TERJE PARTY]: Failed to read: " + m_clientDataFilePath);
				}
			}
		}
		
		if (g_Game.IsServer())
		{
			MakeDirectory("$profile:TerjePartyMod");
			
			m_config = new TerjePartyModConfig;
			string path = "$profile:TerjePartyMod\\Config.json";
			if (FileExist(path))
			{
				JsonFileLoader<ref TerjePartyModConfig>.JsonLoadFile(path, m_config);
			}
			else
			{
				JsonFileLoader<ref TerjePartyModConfig>.JsonSaveFile(path, m_config);
			}
		}
	}
	
	void RequestConfig(CallType type, ParamsReadContext ctx, PlayerIdentity sender, Object target)
	{		
		if (type == CallType.Server)
		{
			if (m_config)
			{
				GetRPCManager().SendRPC("TerjePartyMod", "RequestConfig", new Param1<ref TerjePartyModConfig>(m_config), true, sender);
			}
		}
		else if (type == CallType.Client)
		{
			Param1<ref TerjePartyModConfig> data;
			if (!ctx.Read(data)) return;
			
			m_config = new TerjePartyModConfig;
			m_config.m_showOnMap = data.param1.m_showOnMap;
			m_config.m_showOnHud = data.param1.m_showOnHud;
		}
	}
	
	void OnSendInvite(CallType type, ParamsReadContext ctx, PlayerIdentity sender, Object target)
	{		
		if (type == CallType.Client)
		{
			Param1<string> data;
			if (!ctx.Read(data)) return;
			
			m_clientInvites.Insert(data.param1);
		}
	}
	
	void OnAcceptInvite(CallType type, ParamsReadContext ctx, PlayerIdentity sender, Object target)
	{
		if (type == CallType.Client)
		{
			Param1<string> data;
			if (!ctx.Read(data)) return;

			if (m_clientInvites.Find(data.param1) != -1)
			{
				m_clientInvites.RemoveItem(data.param1);
			}
						
			m_clientPartyMembers.Insert(data.param1);			
			SavePartyData();
		}
	}
	
	void OnRemoveFromParty(CallType type, ParamsReadContext ctx, PlayerIdentity sender, Object target)
	{
		if (type == CallType.Client)
		{
			Param1<string> data;
			if (!ctx.Read(data)) return;
			
			m_clientPartyMembers.RemoveItem(data.param1);
			SavePartyData();
		}
	}
	
	void SavePartyData()
	{
		if (g_Game.IsClient())
		{
			FileSerializer ctx = new FileSerializer();
			ctx.Open(m_clientDataFilePath, FileMode.WRITE);
			if (ctx.IsOpen())
			{
				ctx.Write(m_clientPartyMembers.Count());
				foreach (string guid : m_clientPartyMembers)
				{
					ctx.Write(guid);
				}
				
				ctx.Close();
			}
		}
	}
	
	bool ContainsPlayerInParty(string guid)
	{
		if (g_Game.IsClient() && m_clientPartyMembers != null)
		{
			return m_clientPartyMembers.Find(guid) != -1;
		}
		else
		{
			return false;
		}
	}
	
	bool ContainsPlayerInInvites(string guid)
	{
		if (g_Game.IsClient() && m_clientInvites != null)
		{
			return m_clientInvites.Find(guid) != -1;
		}
		else
		{
			return false;
		}
	}
	
	bool IsReadyToSendInvite(string guid)
	{
		if (ContainsPlayerInParty(guid))
		{
			return false;
		}
		
		if (ContainsPlayerInInvites(guid))
		{
			return false;
		}
		
		return true;
	}
	
	bool IsReadyToAcceptInvite(string guid)
	{
		if (ContainsPlayerInParty(guid))
		{
			return false;
		}

		return ContainsPlayerInInvites(guid);
	}
	
	bool IsShowOnMap()
	{
		if (m_config)
		{
			return m_config.m_showOnMap;
		}
		
		return false;
	}
	
	bool IsShowOnHUD()
	{
		if (m_config)
		{
			return m_config.m_showOnHud;
		}
		
		return false;
	}
};

PluginTerjeParty GetTerjeParty() 
{
    return PluginTerjeParty.Cast(GetPlugin(PluginTerjeParty));
};

class TerjePartyModConfig
{
	int m_showOnMap = 1;
	int m_showOnHud = 1;
};