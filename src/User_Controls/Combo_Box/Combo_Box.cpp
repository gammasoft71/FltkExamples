#include "Fl_Combo_Box.h"
#include <FL/Fl.H>
#include <FL/Fl_Window.H>

namespace Examples {
  class Main_Window : public Fl_Window {
  public:
    Main_Window() : Fl_Window(200, 100, 300, 300, "Combo box example") {
      combo_box1.add_range({"Item1", "Item2", "Item3", "Item4", "Item5", "Item6", "Item7", "Item8", "Item9", "Item10"});
      combo_box1.callback([](Fl_Widget* sender, void* window) {
        auto index = reinterpret_cast<Fl_Combo_Box*>(sender)->find_index(reinterpret_cast<Fl_Combo_Box*>(sender)->value());
        if (index != -1) reinterpret_cast<Main_Window*>(window)->on_combo_box_click(index);
      }, this);
      
      combo_box2.style(Fl_Combo_Box_Style::simple);
      combo_box2.add_range({"Item1", "Item2", "Item3", "Item4", "Item5", "Item6", "Item7", "Item8", "Item9", "Item10"});
      combo_box2.callback([](Fl_Widget* sender, void* window) {
        reinterpret_cast<Main_Window*>(window)->on_combo_box_click(reinterpret_cast<Fl_Combo_Box*>(sender)->find_index(reinterpret_cast<Fl_Combo_Box*>(sender)->value()));
      }, this);
      
      combo_box3.style(Fl_Combo_Box_Style::drop_down_list);
      combo_box3.add_range({"Item1", "Item2", "Item3", "Item4", "Item5", "Item6", "Item7", "Item8", "Item9", "Item10"});
      combo_box3.callback([](Fl_Widget* sender, void* window) {
        reinterpret_cast<Main_Window*>(window)->on_combo_box_click(reinterpret_cast<Fl_Combo_Box*>(sender)->find_index(reinterpret_cast<Fl_Combo_Box*>(sender)->value()));
      }, this);
            
      on_combo_box_click(0);
    }
    
  private:
    void on_combo_box_click(int value) {
      combo_box1.value(value);
      combo_box2.value(value);
      combo_box3.value(value);
    }
    
    Fl_Combo_Box combo_box1 {10, 10, 120, 25};
    Fl_Combo_Box combo_box2 {10, 50, 120, 25};
    Fl_Combo_Box combo_box3 {10, 90, 120, 125};
  };
}

int main(int argc, char *argv[]) {
  Examples::Main_Window window;
  window.show(argc, argv);
  return Fl::run();
}
