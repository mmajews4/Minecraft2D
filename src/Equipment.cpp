#include "Equipment.h"

Equipment::Equipment()
{
    num_of_slots = 6;
    size = 90;
    outline = 5;
    left_offset = 0;
    top_offset = 0;
    text_offset = size*3/5;
    text_size = 20;
    text = "";

    Slot empty_slot = {
        Button(size, size, outline, left_offset, top_offset, text_offset, text_offset, text_size, text, 0),
        nullptr,
        0,
        false
    };
    for(int slots_placed = 0; slots_placed < num_of_slots; slots_placed++)
    {
        slots.push_back(empty_slot);
        slots[slots_placed].block = new Dirt();
    }
    slots[0].active = true;
}


// Adds given item to eq
void Equipment::pushItem(Block*)
{

}


// Pulls given item from eq
// - return 1 if item is in eq
// - return 0 if requested item is not in eq
bool Equipment::pullItem(Block*)
{
    return 1;
}


void Equipment::display(sf::RenderWindow &window)
{
    // Place slots in correct position
    sf::Vector2u window_size = window.getSize();
    left_offset = (window_size.x - (size + 2*outline) * num_of_slots)/2;
    top_offset = window_size.y - size - 20;

    // Create a text to display number of items in inventory
    sf::Text text_view;
    text_view.setFont(font.font);
    text_view.setStyle(sf::Text::Bold);
    text_view.setFillColor(sf::Color(255, 255, 255));
    text_view.setCharacterSize(text_size);

    for(int slots_updated = 0; slots_updated < num_of_slots;  slots_updated++)
    {
        int slot_offset = left_offset + slots_updated*(size+2*outline);
        slots[slots_updated].button.setPosition(slot_offset, top_offset);
        slots[slots_updated].block->setPosition(slot_offset, top_offset);
        slots[slots_updated].button.display(window);
        slots[slots_updated].block->drawInEq(window);
        text = to_string(slots[slots_updated].num_of_items);
        text_view.setString(text);
        text_view.setPosition(slot_offset + text_offset, top_offset + text_offset);
        window.draw(text_view);
    }


}