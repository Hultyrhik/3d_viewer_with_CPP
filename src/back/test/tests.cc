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

        model.set_path_of_file(path);

        int status = view.init_controller();

        EXPECT_EQ(status, 0);
        EXPECT_EQ(cube.countLines, 60);
        EXPECT_EQ(cube.countVertexes, 24);
        EXPECT_EQ(cube.countV, 8);
        EXPECT_EQ(cube.countL, 10);
        for (unsigned int i = 0; i < cube.countVertexes; i++) {
            EXPECT_NEAR(cube.vertexes[i],array[i], 1e-6);
        }

        model.s21_clearModelShape();

}

TEST(init_shape, test_init_tetrahedron) {
        Shape shape {};
        double array[114] = {0.000000, -0.230941, 0.669197, -0.078384, -0.185686, 0.509197, -0.058788, -0.264882, 0.573197, -0.741212, -0.658879, -0.541197, -0.721616, -0.557056, -0.541197, -0.800000, -0.692820, -0.637197, -0.741212, -0.590997, -0.637197, -0.078384, 0.557056, -0.541197, -0.058788, 0.590997, -0.637197, -0.000000, 0.692820, -0.637197, 0.800000, -0.692820, -0.637197, 0.078384, 0.557056, -0.541197, 0.721616, -0.557056, -0.541197, 0.078384, -0.185686, 0.509197, 0.000000, -0.163058, 0.573197, -0.000000, 0.624938, -0.541197, -0.643233, -0.602311, -0.669197, 0.000000, 0.511801, -0.669197, 0.041433, 0.493056, -0.541197, 0.647716, -0.557056, -0.541197, 0.041433, -0.207019, 0.448857, -0.000000, -0.230941, 0.533433, 0.689149, -0.628820, -0.591942, 0.000000, -0.278783, 0.448858, 0.606282, -0.628820, -0.541197, 0.643233, -0.692820, -0.541197, 0.000000, -0.321450, 0.509197, 0.000000, 0.564820, -0.591942, 0.606282, -0.580977, -0.608858, 0.643233, -0.602311, -0.669197, -0.606282, -0.580977, -0.608858, -0.689149, -0.628820, -0.591942, -0.041433, -0.207019, 0.448858, -0.041433, 0.493056, -0.541197, -0.647716, -0.557056, -0.541197, -0.606282, -0.628820, -0.541197, -0.643233, -0.692820, -0.541197, 0.000000, 0.469134, -0.608858};        
 
        std::string path = "obj/tetrahedron.obj";

        s21::Model model(&shape);
        s21::Controller controller(&model);
        s21::View view(&controller);

        model.set_path_of_file(path);

        int status = view.init_controller();

        EXPECT_EQ(status, 0);
        EXPECT_EQ(shape.countLines, 504);
        EXPECT_EQ(shape.countVertexes/3, 38);
        EXPECT_EQ(shape.countV, 38);
        EXPECT_EQ(shape.countL, 84);
        for (unsigned int i = 0; i < shape.countVertexes; i++) {
            EXPECT_NEAR(shape.vertexes[i],array[i], 1e-6);
        }
        
        model.s21_clearModelShape();

}


int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}