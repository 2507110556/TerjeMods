class TerjeProgramBase
{
	protected TerjeGadgetBase m_gadget;
	
	TerjeGadgetBase GetGadget()
	{
		return m_gadget;
	}
	
	string GetWidgetClassname()
	{
		return string.Empty;
	}
	
	string GetName()
	{
		return string.Empty;
	}
	
	string GetIcon(int type)
	{
		return string.Empty;
	}
	
	void OnInit(TerjeGadgetBase gadget)
	{
		m_gadget = gadget;
	}
	
	void OnInstall()
	{
		
	}
	
	void OnStart()
	{
		
	}
	
	void OnUpdate(float deltaTime)
	{
		
	}
	
	void OnClose()
	{
		
	}
	
	void OnBack()
	{
		
	}
	
	void OnUninstall()
	{
		
	}
	
	void OnStoreLoad(TerjeStorageReadingContext ctx)
	{
		
	}
	
	void OnStoreSave(TerjeStorageWritingContext ctx)
	{
		
	}
	
	void OnSyncReceive(ParamsReadContext ctx)
	{
		
	}
	
	void OnSyncSend(ParamsWriteContext ctx)
	{
		
	}
	
	void OnRPC(string id, ParamsReadContext ctx)
	{
		
	}
	
	void SendRPC(string id, out TerjeStreamRpc stream)
	{
		if (GetGadget())
		{
			GetGadget().TerjeGadgetSendRPC("prg.rpc", stream);
			stream.Write(this.Type().ToString());
			stream.Write(id);
		}
	}
}