class IRunnable
{
	public : int Size;
	
	public : virtual bool Prepare(int size);
	public : virtual bool Run();
};