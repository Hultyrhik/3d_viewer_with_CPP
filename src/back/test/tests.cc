#include <gtest/gtest.h>

#include "../mvc/s21_3dparser.h"
#include "../mvc/s21_model.h"
#include "../mvc/s21_controller.h"
#include "../mvc/s21_view.h"

TEST(init_shape, test_init_cube) {
        Shape cube {};
        double array[24] = {-0.800000, -0.800000, -0.800000, -0.800000, -0.800000, 0.800000, -0.800000, 0.800000, -0.800000, -0.800000, 0.800000, 0.800000, 0.800000, -0.800000, -0.800000, 0.800000, -0.800000, 0.800000, 0.800000, 0.800000, -0.800000, 0.800000, 0.800000, 0.800000};       
        
        std::string path = "obj/cube.obj";

        s21::Model model(&cube);
        s21::Controller controller(&model);
        s21::View view(&controller);
                std::cout << "Before path" << std::endl;
        model.set_path_of_file(path);
                std::cout << "Before init" << std::endl;
        int status = view.init_controller();
                std::cout << "After init" << std::endl;



        EXPECT_EQ(status, 0);
        EXPECT_EQ(cube.countLines, 60);
        EXPECT_EQ(cube.countVertexes, 24);
        EXPECT_EQ(cube.countV, 8);
        EXPECT_EQ(cube.countL, 10);
        for (unsigned int i = 0; i < cube.countVertexes; i++) {
            EXPECT_NEAR(cube.vertexes[i],array[i], 1e-9);
        }
        
        std::cout << "Before clear" << std::endl;

        model.s21_clearModelShape();

}



int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}