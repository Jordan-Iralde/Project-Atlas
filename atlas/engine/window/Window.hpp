class Window
{
public:
	bool Create(const char* title, int width, int height);
	void Destroy();
	bool IsOpen() const;
	void PollEvents();
	void GetSize(int& width, int& height) const;
	void SetTitle(const char* title);

private:
	SDL_Window* m_window = nullptr;  // El handle opaco de SDL. Solo Window lo toca.
	bool m_isOpen = false;           // Estado interno: ¿la ventana sigue abierta?
};

// TODO: Mover SDL_Init a Platform cuando haya más subsistemas.