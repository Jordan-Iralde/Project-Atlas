#pragma once

#include "Window.hpp"
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

bool Window::Create(const char* title, int width, int height) {
	SDL_Init(SDL_INIT_VIDEO);
}

void Window::Destroy() {
	if (m_window) {
		SDL_DestroyWindow(m_window); //Destruye la venta
		m_window = nullptr;
	}
	SDL_Quit(); //Cierra SDL y libera los recursos asociados
}

bool Window::IsOpen() const {
	return m_isOpen;
}

void Window::PollEvents() {
	SDL_Event event; // Variable para almacenar eventos de SDL
	while (SDL_PollEvent(&event)) { //Mientras haya eventos en la cola (SDL_PollEvent devuelve 1 si hay eventos, 0 si no)
		if (event.type == SDL_QUIT) {
			m_isOpen = false; //Funcion para cerrar la ventana, el esta determinado por el usuario
		}
	}
}

void Window::GetSize(int& width, int& height) const { //Los punnteros que se pasan por referencia permiten modificar las variables originales en la función que llama a GetSize
	if (m_window) {
		SDL_GetWindowSize(m_window, &width, &height); //Obtiene el tamaño de la ventana
	}
}

void Window::SetTitle(const char* title) { //Puntero de char para tittle, que es el titulo de la ventana
	if (m_window) {
		SDL_SetWindowTitle(m_window, title); //Cambia el titulo de la ventana a partir del puntero de char que se pasa como argumento
	}
}