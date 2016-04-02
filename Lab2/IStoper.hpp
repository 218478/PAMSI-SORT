class IStoper
{
	public : virtual void Start();
	public : virtual void Stop();
	public : virtual long GetElapsedTime();
	public : virtual bool DumpToFile();
};