#include <iostream>

#include "back/mvc/s21_3dparser.h"
#include "back/mvc/s21_model.h"
#include "back/mvc/s21_controller.h"
#include "back/mvc/s21_view.h"

int main() {

        Shape cube {};
        double array[24] = {-0.800000, -0.800000, -0.800000, -0.800000, -0.800000, 0.800000, -0.800000, 0.800000, -0.800000, -0.800000, 0.800000, 0.800000, 0.800000, -0.800000, -0.800000, 0.800000, -0.800000, 0.800000, 0.800000, 0.800000, -0.800000, 0.800000, 0.800000, 0.800000};       
        
        std::string path = "obj/cube.obj";

        s21::Model model(&cube);
        s21::Controller controller(&model);
        s21::View view(&controller);
        model.set_path_of_file(path);
        int status = view.init_controller();

        if (status == 0) {
            std::cout << "Right" << std::endl;
        }

        // EXPECT_EQ(cube.countLines, 60);
        // EXPECT_EQ(cube.countVertexes, 24);
        // EXPECT_EQ(cube.countV, 8);
        // EXPECT_EQ(cube.countL, 10);
        for (unsigned int i = 0; i < cube.countVertexes; i++) {
            if (cube.vertexes[i] != array[i]) {
                std::cout << i << " , " << "Wrong" << std::endl;
            }
        }
        
        model.s21_clearModelShape();

}
