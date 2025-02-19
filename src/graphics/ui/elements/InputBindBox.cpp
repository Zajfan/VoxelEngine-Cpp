#include "InputBindBox.hpp"

#include "Label.hpp"
#include "graphics/core/DrawContext.hpp"
#include "graphics/core/Batch2D.hpp"
#include "util/stringutil.hpp"

using namespace gui;

InputBindBox::InputBindBox(Binding& binding, glm::vec4 padding) 
    : Panel(glm::vec2(100,32), padding, 0),
      binding(binding),
      label(std::make_shared<Label>(L"")) {
    add(label);
    setScrollable(false);
    hoverColor = glm::vec4(0.05f, 0.1f, 0.2f, 0.75f);
}

void InputBindBox::drawBackground(const DrawContext& pctx, const Assets&) {
    glm::vec2 pos = calcPos();
    auto batch = pctx.getBatch2D();
    batch->texture(nullptr);
    batch->setColor(isFocused() ? focusedColor : calcColor());
    batch->rect(pos.x, pos.y, size.x, size.y);
    label->setText(util::str2wstr_utf8(binding.text()));
}

void InputBindBox::clicked(GUI*, mousecode button) {
    if (isFocused()) {
        binding.reset(button);
        defocus();
    }
}

void InputBindBox::keyPressed(keycode key) {
    if (key != keycode::ESCAPE) {
        binding.reset(key);
    }
    defocus();
}
