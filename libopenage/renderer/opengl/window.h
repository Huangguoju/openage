// Copyright 2018-2018 the openage authors. See copying.md for legal info.

#pragma once

#include "../window.h"

#include <optional>

#include "context.h"


namespace openage {
namespace renderer {
namespace opengl {

class GlWindow final : public Window {
public:
	/// Create a shiny window with the given title.
	GlWindow(const char *title, size_t width, size_t height);
	~GlWindow();

	void set_size(size_t width, size_t height) override;

	void update() override;

	std::unique_ptr<Renderer> make_renderer() override;

	/// Make this window's context the current rendering context of the current thread.
	/// Only use this and most other GL functions on a dedicated window thread.
	void make_context_current();

	/// Return a pointer to this window's GL context.
	opengl::GlContext *get_context();

private:
	/// The SDL struct representing this window.
	SDL_Window *window;

	/// The window's OpenGL context. It's optional because it can't be constructed immediately,
	/// but after the constructor runs it's guaranteed to be available.
	std::optional<opengl::GlContext> context;
};

}}} // namespace openage::renderer::opengl
