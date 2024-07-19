#ifndef S21_VIEW_H
#define S21_VIEW_H

#include "s21_controller.h"

namespace s21 {
     class View{
        private:
            Controller* controller_;
        public:
            View(Controller* other): controller_{other}{}
            int init_controller(); 
    };
} // namespace s21


#endif