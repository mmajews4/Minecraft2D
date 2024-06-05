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
    active_slot = 0;

    Slot empty_slot = {
        Button(size, size, outline, left_offset, top_offset, text_offset, text_offset, text_size, text, false),
        nullptr,
        0
    };
    for(int slots_placed = 0; slots_placed < num_of_slots; slots_placed++)
    {
        slots.push_back(empty_slot);
//        slots[slots_placed].block = new Dirt();
    }
    slots[active_slot].button.setActive(true);
    slots[2].block = new Grass();
}


// Adds given item to eq
// - go through whole eq to find if item is alerady in it
// - if not set position at first empty spot
// - add one item to this spot
void Equipment::pushItem(Block* block)
{
    cout << "Pushed " << block->getBlockSign() << endl;

    int slot_to_push = -1;

    for(int slot_nr = 0; slot_nr < num_of_slots; slot_nr++)
    {
        if(slots[slot_nr].block == nullptr)
        {
            continue;
        }
        if(slots[slot_nr].block->getBlockSign() == block->getBlockSign())
        {
            slot_to_push = slot_nr;        
        }
    }
    if(slot_to_push == -1)
    {
        for(int slot_nr = num_of_slots; slot_nr >= 0; slot_nr--)
        {
            if(slots[slot_nr].block == nullptr)
            {
                slot_to_push = slot_nr;        
            }
        }
    }
    if(slot_to_push != -1) slots[slot_to_push].num_of_items++;
}


// Pulls given item from eq
// - return 1 if item is in eq
// - return 0 if requested item is not in eq
bool Equipment::pullItem(Block*)
{
    return 1;
}


// Changes active slot in given direction
void Equipment::scroll(Dir dir)
{
    if(dir == RIGHT && active_slot < num_of_slots - 1)
    {
        slots[active_slot].button.setActive(false);
        active_slot++;
        slots[active_slot].button.setActive(true);
    }
    else if(dir == LEFT && active_slot > 0)
    {
        slots[active_slot].button.setActive(false);
        active_slot--;
        slots[active_slot].button.setActive(true);
    }
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
        slots[slots_updated].button.display(window);
        if(slots[slots_updated].num_of_items != 0)
        {
            slots[slots_updated].block->setPosition(slot_offset, top_offset);
            slots[slots_updated].block->drawInEq(window);
            text = to_string(slots[slots_updated].num_of_items);
            text_view.setString(text);
            text_view.setPosition(slot_offset + text_offset, top_offset + text_offset);
        }
        window.draw(text_view);
    }


}