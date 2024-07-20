#include <gtest/gtest.h>

#include "../mvc/s21_3dparser.h"
#include "../mvc/s21_controller.h"
#include "../mvc/s21_model.h"
#include "../mvc/s21_view.h"

TEST(init_shape, test_init_cube) {
  s21::Shape cube{};
  double array[24] = {-0.800000, -0.800000, -0.800000, -0.800000, -0.800000,
                      0.800000,  -0.800000, 0.800000,  -0.800000, -0.800000,
                      0.800000,  0.800000,  0.800000,  -0.800000, -0.800000,
                      0.800000,  -0.800000, 0.800000,  0.800000,  0.800000,
                      -0.800000, 0.800000,  0.800000,  0.800000};

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
    EXPECT_NEAR(cube.vertexes[i], array[i], 1e-6);
  }

  model.s21_clearModelShape();
}

TEST(init_shape, test_init_tetrahedron) {
  s21::Shape shape{};
  double array[114] = {
      0.000000,  -0.230941, 0.669197,  -0.078384, -0.185686, 0.509197,
      -0.058788, -0.264882, 0.573197,  -0.741212, -0.658879, -0.541197,
      -0.721616, -0.557056, -0.541197, -0.800000, -0.692820, -0.637197,
      -0.741212, -0.590997, -0.637197, -0.078384, 0.557056,  -0.541197,
      -0.058788, 0.590997,  -0.637197, -0.000000, 0.692820,  -0.637197,
      0.800000,  -0.692820, -0.637197, 0.078384,  0.557056,  -0.541197,
      0.721616,  -0.557056, -0.541197, 0.078384,  -0.185686, 0.509197,
      0.000000,  -0.163058, 0.573197,  -0.000000, 0.624938,  -0.541197,
      -0.643233, -0.602311, -0.669197, 0.000000,  0.511801,  -0.669197,
      0.041433,  0.493056,  -0.541197, 0.647716,  -0.557056, -0.541197,
      0.041433,  -0.207019, 0.448857,  -0.000000, -0.230941, 0.533433,
      0.689149,  -0.628820, -0.591942, 0.000000,  -0.278783, 0.448858,
      0.606282,  -0.628820, -0.541197, 0.643233,  -0.692820, -0.541197,
      0.000000,  -0.321450, 0.509197,  0.000000,  0.564820,  -0.591942,
      0.606282,  -0.580977, -0.608858, 0.643233,  -0.602311, -0.669197,
      -0.606282, -0.580977, -0.608858, -0.689149, -0.628820, -0.591942,
      -0.041433, -0.207019, 0.448858,  -0.041433, 0.493056,  -0.541197,
      -0.647716, -0.557056, -0.541197, -0.606282, -0.628820, -0.541197,
      -0.643233, -0.692820, -0.541197, 0.000000,  0.469134,  -0.608858};

  std::string path = "obj/tetrahedron.obj";

  s21::Model model(&shape);
  s21::Controller controller(&model);
  s21::View view(&controller);

  model.set_path_of_file(path);

  int status = view.init_controller();

  EXPECT_EQ(status, 0);
  EXPECT_EQ(shape.countLines, 504);
  EXPECT_EQ(shape.countVertexes / 3, 38);
  EXPECT_EQ(shape.countV, 38);
  EXPECT_EQ(shape.countL, 84);
  for (unsigned int i = 0; i < shape.countVertexes; i++) {
    EXPECT_NEAR(shape.vertexes[i], array[i], 1e-6);
  }

  model.s21_clearModelShape();
}

TEST(init_shape, test_init_invalid_file_format) {
  s21::Shape shape{};
  std::string path = "obj/invalid.obj";

  s21::Model model(&shape);
  s21::Controller controller(&model);
  s21::View view(&controller);

  model.set_path_of_file(path);

  int status = view.init_controller();

  EXPECT_EQ(status, 1);
  model.s21_clearModelShape();
}

TEST(init_shape, test_init_file_missing1) {
  s21::Shape shape{};
  std::string path = "obj/file.obj";

  s21::Model model(&shape);
  s21::Controller controller(&model);
  s21::View view(&controller);

  model.set_path_of_file(path);

  int status = view.init_controller();

  EXPECT_EQ(status, 1);
  model.s21_clearModelShape();
}

TEST(init_shape, test_init_file_missing2) {
  s21::Shape shape{};
  std::string path = "file.txt";

  s21::Model model(&shape);
  s21::Controller controller(&model);
  s21::View view(&controller);

  model.set_path_of_file(path);

  int status = view.init_controller();

  EXPECT_EQ(status, 1);
  model.s21_clearModelShape();
}

TEST(init_shape, test_init_empty_file) {
  s21::Shape shape{};
  std::string path = "obj/empty.obj";

  s21::Model model(&shape);
  s21::Controller controller(&model);
  s21::View view(&controller);

  model.set_path_of_file(path);

  int status = view.init_controller();

  EXPECT_EQ(status, 1);
  model.s21_clearModelShape();
}

TEST(init_shape, test_init_invalid_path) {
  s21::Shape shape{};
  std::string path = "obj/b/../obj/lobg/cube.obj";

  s21::Model model(&shape);
  s21::Controller controller(&model);
  s21::View view(&controller);

  model.set_path_of_file(path);

  int status = view.init_controller();

  EXPECT_EQ(status, 1);
  model.s21_clearModelShape();
}

TEST(rotate_shape, test_rotate_cube_x) {
  s21::Shape shape{};
  double array[24] = {-0.800000, -0.800000, -0.800000, -0.800000, -0.800000,
                      0.800000,  -0.800000, 0.800000,  -0.800000, -0.800000,
                      0.800000,  0.800000,  0.800000,  -0.800000, -0.800000,
                      0.800000,  -0.800000, 0.800000,  0.800000,  0.800000,
                      -0.800000, 0.800000,  0.800000,  0.800000};

  std::string path = "obj/cube.obj";

  s21::Model model(&shape);
  s21::Controller controller(&model);
  s21::View view(&controller);

  model.set_path_of_file(path);

  int status = view.init_controller();

  EXPECT_EQ(status, 0);
  EXPECT_EQ(shape.countLines, 60);
  EXPECT_EQ(shape.countVertexes, 24);
  EXPECT_EQ(shape.countV, 8);
  EXPECT_EQ(shape.countL, 10);
  for (unsigned int i = 0; i < shape.countVertexes; i++) {
    EXPECT_NEAR(shape.vertexes[i], array[i], 1e-6);
  }

  double array2[24] = {-0.800000, -0.000000, -1.131371, -0.800000, -1.131371,
                       0.000000,  -0.800000, 1.131371,  -0.000000, -0.800000,
                       0.000000,  1.131371,  0.800000,  -0.000000, -1.131371,
                       0.800000,  -1.131371, 0.000000,  0.800000,  1.131371,
                       -0.000000, 0.800000,  0.000000,  1.131371};

  s21::figure_rotation(&shape, 45.0, 0, 0);
  EXPECT_EQ(shape.countLines, 60);
  EXPECT_EQ(shape.countVertexes, 24);
  EXPECT_EQ(shape.countV, 8);
  EXPECT_EQ(shape.countL, 10);
  for (unsigned int i = 0; i < shape.countVertexes; i++) {
    EXPECT_NEAR(shape.vertexes[i], array2[i], 1e-6);
  }
  model.s21_clearModelShape();
}

TEST(rotate_shape, test_rotate_cube_y) {
  s21::Shape shape{};
  double array[24] = {-0.800000, -0.800000, -0.800000, -0.800000, -0.800000,
                      0.800000,  -0.800000, 0.800000,  -0.800000, -0.800000,
                      0.800000,  0.800000,  0.800000,  -0.800000, -0.800000,
                      0.800000,  -0.800000, 0.800000,  0.800000,  0.800000,
                      -0.800000, 0.800000,  0.800000,  0.800000};

  std::string path = "obj/cube.obj";

  s21::Model model(&shape);
  s21::Controller controller(&model);
  s21::View view(&controller);

  model.set_path_of_file(path);

  int status = view.init_controller();

  EXPECT_EQ(status, 0);
  EXPECT_EQ(shape.countLines, 60);
  EXPECT_EQ(shape.countVertexes, 24);
  EXPECT_EQ(shape.countV, 8);
  EXPECT_EQ(shape.countL, 10);
  for (unsigned int i = 0; i < shape.countVertexes; i++) {
    EXPECT_NEAR(shape.vertexes[i], array[i], 1e-6);
  }

  double array2[24] = {-0.800000, -0.800000, 0.800000,  0.800000,  -0.800000,
                       0.800000,  -0.800000, 0.800000,  0.800000,  0.800000,
                       0.800000,  0.800000,  -0.800000, -0.800000, -0.800000,
                       0.800000,  -0.800000, -0.800000, -0.800000, 0.800000,
                       -0.800000, 0.800000,  0.800000,  -0.800000};

  s21::figure_rotation(&shape, 0, 90.0, 0);
  EXPECT_EQ(shape.countLines, 60);
  EXPECT_EQ(shape.countVertexes, 24);
  EXPECT_EQ(shape.countV, 8);
  EXPECT_EQ(shape.countL, 10);
  for (unsigned int i = 0; i < shape.countVertexes; i++) {
    EXPECT_NEAR(shape.vertexes[i], array2[i], 1e-6);
  }
  model.s21_clearModelShape();
}

TEST(rotate_shape, test_rotate_cube_xyz) {
  s21::Shape shape{};
  double array[24] = {-0.800000, -0.800000, -0.800000, -0.800000, -0.800000,
                      0.800000,  -0.800000, 0.800000,  -0.800000, -0.800000,
                      0.800000,  0.800000,  0.800000,  -0.800000, -0.800000,
                      0.800000,  -0.800000, 0.800000,  0.800000,  0.800000,
                      -0.800000, 0.800000,  0.800000,  0.800000};

  std::string path = "obj/cube.obj";

  s21::Model model(&shape);
  s21::Controller controller(&model);
  s21::View view(&controller);

  model.set_path_of_file(path);

  int status = view.init_controller();

  EXPECT_EQ(status, 0);
  EXPECT_EQ(shape.countLines, 60);
  EXPECT_EQ(shape.countVertexes, 24);
  EXPECT_EQ(shape.countV, 8);
  EXPECT_EQ(shape.countL, 10);
  for (unsigned int i = 0; i < shape.countVertexes; i++) {
    EXPECT_NEAR(shape.vertexes[i], array[i], 1e-6);
  }

  double array2[24] = {-0.292820, -1.092820, -0.800000, -0.292820, -1.092820,
                       0.800000,  -1.092820, 0.292820,  -0.800000, -1.092820,
                       0.292820,  0.800000,  1.092820,  -0.292820, -0.800000,
                       1.092820,  -0.292820, 0.800000,  0.292820,  1.092820,
                       -0.800000, 0.292820,  1.092820,  0.800000};

  s21::figure_rotation(&shape, 0, 0.0, 30.0);
  EXPECT_EQ(shape.countLines, 60);
  EXPECT_EQ(shape.countVertexes, 24);
  EXPECT_EQ(shape.countV, 8);
  EXPECT_EQ(shape.countL, 10);
  for (unsigned int i = 0; i < shape.countVertexes; i++) {
    EXPECT_NEAR(shape.vertexes[i], array2[i], 1e-6);
  }
  model.s21_clearModelShape();
}

TEST(rotate_shape, test_rotate_cube_z) {
  s21::Shape shape{};
  double array[24] = {-0.800000, -0.800000, -0.800000, -0.800000, -0.800000,
                      0.800000,  -0.800000, 0.800000,  -0.800000, -0.800000,
                      0.800000,  0.800000,  0.800000,  -0.800000, -0.800000,
                      0.800000,  -0.800000, 0.800000,  0.800000,  0.800000,
                      -0.800000, 0.800000,  0.800000,  0.800000};

  std::string path = "obj/cube.obj";

  s21::Model model(&shape);
  s21::Controller controller(&model);
  s21::View view(&controller);

  model.set_path_of_file(path);

  int status = view.init_controller();

  EXPECT_EQ(status, 0);
  EXPECT_EQ(shape.countLines, 60);
  EXPECT_EQ(shape.countVertexes, 24);
  EXPECT_EQ(shape.countV, 8);
  EXPECT_EQ(shape.countL, 10);
  for (unsigned int i = 0; i < shape.countVertexes; i++) {
    EXPECT_NEAR(shape.vertexes[i], array[i], 1e-6);
  }

  double array2[24] = {0.000000,  -1.379796, 0.127135,  1.131371,  -0.400000,
                       0.692820,  -1.131371, -0.400000, 0.692820,  -0.000000,
                       0.579796,  1.258506,  0.000000,  -0.579796, -1.258506,
                       1.131371,  0.400000,  -0.692820, -1.131371, 0.400000,
                       -0.692820, -0.000000, 1.379796,  -0.127135};

  s21::figure_rotation(&shape, 45.0, 0.0, 0.0);
  s21::figure_rotation(&shape, 0, 60.0, 0.0);
  s21::figure_rotation(&shape, 0, 0.0, 90.0);
  EXPECT_EQ(shape.countLines, 60);
  EXPECT_EQ(shape.countVertexes, 24);
  EXPECT_EQ(shape.countV, 8);
  EXPECT_EQ(shape.countL, 10);
  for (unsigned int i = 0; i < shape.countVertexes; i++) {
    EXPECT_NEAR(shape.vertexes[i], array2[i], 1e-6);
  }
  model.s21_clearModelShape();
}

TEST(scale_shape, test_scale_cube_plus) {
  s21::Shape shape{};
  double array[24] = {-0.800000, -0.800000, -0.800000, -0.800000, -0.800000,
                      0.800000,  -0.800000, 0.800000,  -0.800000, -0.800000,
                      0.800000,  0.800000,  0.800000,  -0.800000, -0.800000,
                      0.800000,  -0.800000, 0.800000,  0.800000,  0.800000,
                      -0.800000, 0.800000,  0.800000,  0.800000};

  std::string path = "obj/cube.obj";

  s21::Model model(&shape);
  s21::Controller controller(&model);
  s21::View view(&controller);

  model.set_path_of_file(path);

  int status = view.init_controller();

  EXPECT_EQ(status, 0);
  EXPECT_EQ(shape.countLines, 60);
  EXPECT_EQ(shape.countVertexes, 24);
  EXPECT_EQ(shape.countV, 8);
  EXPECT_EQ(shape.countL, 10);
  for (unsigned int i = 0; i < shape.countVertexes; i++) {
    EXPECT_NEAR(shape.vertexes[i], array[i], 1e-6);
  }

  double array2[24] = {-2.400000, -2.400000, -2.400000, -2.400000, -2.400000,
                       2.400000,  -2.400000, 2.400000,  -2.400000, -2.400000,
                       2.400000,  2.400000,  2.400000,  -2.400000, -2.400000,
                       2.400000,  -2.400000, 2.400000,  2.400000,  2.400000,
                       -2.400000, 2.400000,  2.400000,  2.400000};
  s21::s21_setScale(&shape, 3);

  EXPECT_EQ(shape.countLines, 60);
  EXPECT_EQ(shape.countVertexes, 24);
  EXPECT_EQ(shape.countV, 8);
  EXPECT_EQ(shape.countL, 10);
  for (unsigned int i = 0; i < shape.countVertexes; i++) {
    EXPECT_NEAR(shape.vertexes[i], array2[i], 1e-6);
  }
  model.s21_clearModelShape();
}

TEST(scale_shape, test_scale_cube_plus2) {
  s21::Shape shape{};
  double array[24] = {-0.800000, -0.800000, -0.800000, -0.800000, -0.800000,
                      0.800000,  -0.800000, 0.800000,  -0.800000, -0.800000,
                      0.800000,  0.800000,  0.800000,  -0.800000, -0.800000,
                      0.800000,  -0.800000, 0.800000,  0.800000,  0.800000,
                      -0.800000, 0.800000,  0.800000,  0.800000};

  std::string path = "obj/cube.obj";

  s21::Model model(&shape);
  s21::Controller controller(&model);
  s21::View view(&controller);

  model.set_path_of_file(path);

  int status = view.init_controller();

  EXPECT_EQ(status, 0);
  EXPECT_EQ(shape.countLines, 60);
  EXPECT_EQ(shape.countVertexes, 24);
  EXPECT_EQ(shape.countV, 8);
  EXPECT_EQ(shape.countL, 10);
  for (unsigned int i = 0; i < shape.countVertexes; i++) {
    EXPECT_NEAR(shape.vertexes[i], array[i], 1e-6);
  }

  double array2[24] = {-8.080000, -8.080000, -8.080000, -8.080000, -8.080000,
                       8.080000,  -8.080000, 8.080000,  -8.080000, -8.080000,
                       8.080000,  8.080000,  8.080000,  -8.080000, -8.080000,
                       8.080000,  -8.080000, 8.080000,  8.080000,  8.080000,
                       -8.080000, 8.080000,  8.080000,  8.080000};
  s21::s21_setScale(&shape, 10.1);

  EXPECT_EQ(shape.countLines, 60);
  EXPECT_EQ(shape.countVertexes, 24);
  EXPECT_EQ(shape.countV, 8);
  EXPECT_EQ(shape.countL, 10);
  for (unsigned int i = 0; i < shape.countVertexes; i++) {
    EXPECT_NEAR(shape.vertexes[i], array2[i], 1e-6);
  }
  model.s21_clearModelShape();
}

TEST(scale_shape, test_scale_cube_plus3) {
  s21::Shape shape{};
  double array[24] = {-0.800000, -0.800000, -0.800000, -0.800000, -0.800000,
                      0.800000,  -0.800000, 0.800000,  -0.800000, -0.800000,
                      0.800000,  0.800000,  0.800000,  -0.800000, -0.800000,
                      0.800000,  -0.800000, 0.800000,  0.800000,  0.800000,
                      -0.800000, 0.800000,  0.800000,  0.800000};

  std::string path = "obj/cube.obj";

  s21::Model model(&shape);
  s21::Controller controller(&model);
  s21::View view(&controller);

  model.set_path_of_file(path);

  int status = view.init_controller();

  EXPECT_EQ(status, 0);
  EXPECT_EQ(shape.countLines, 60);
  EXPECT_EQ(shape.countVertexes, 24);
  EXPECT_EQ(shape.countV, 8);
  EXPECT_EQ(shape.countL, 10);
  for (unsigned int i = 0; i < shape.countVertexes; i++) {
    EXPECT_NEAR(shape.vertexes[i], array[i], 1e-6);
  }

  double array2[24] = {-0.800080, -0.800080, -0.800080, -0.800080, -0.800080,
                       0.800080,  -0.800080, 0.800080,  -0.800080, -0.800080,
                       0.800080,  0.800080,  0.800080,  -0.800080, -0.800080,
                       0.800080,  -0.800080, 0.800080,  0.800080,  0.800080,
                       -0.800080, 0.800080,  0.800080,  0.800080};
  s21::s21_setScale(&shape, 1.0001);

  EXPECT_EQ(shape.countLines, 60);
  EXPECT_EQ(shape.countVertexes, 24);
  EXPECT_EQ(shape.countV, 8);
  EXPECT_EQ(shape.countL, 10);
  for (unsigned int i = 0; i < shape.countVertexes; i++) {
    EXPECT_NEAR(shape.vertexes[i], array2[i], 1e-6);
  }
  model.s21_clearModelShape();
}

TEST(drifting_shape, test_drifting_cube_plus_x) {
  s21::Shape shape{};
  double array[24] = {-0.800000, -0.800000, -0.800000, -0.800000, -0.800000,
                      0.800000,  -0.800000, 0.800000,  -0.800000, -0.800000,
                      0.800000,  0.800000,  0.800000,  -0.800000, -0.800000,
                      0.800000,  -0.800000, 0.800000,  0.800000,  0.800000,
                      -0.800000, 0.800000,  0.800000,  0.800000};

  std::string path = "obj/cube.obj";

  s21::Model model(&shape);
  s21::Controller controller(&model);
  s21::View view(&controller);

  model.set_path_of_file(path);

  int status = view.init_controller();

  EXPECT_EQ(status, 0);
  EXPECT_EQ(shape.countLines, 60);
  EXPECT_EQ(shape.countVertexes, 24);
  EXPECT_EQ(shape.countV, 8);
  EXPECT_EQ(shape.countL, 10);
  for (unsigned int i = 0; i < shape.countVertexes; i++) {
    EXPECT_NEAR(shape.vertexes[i], array[i], 1e-6);
  }

  double array2[24] = {1.200000,  -0.800000, -0.800000, 1.200000,  -0.800000,
                       0.800000,  1.200000,  0.800000,  -0.800000, 1.200000,
                       0.800000,  0.800000,  2.800000,  -0.800000, -0.800000,
                       2.800000,  -0.800000, 0.800000,  2.800000,  0.800000,
                       -0.800000, 2.800000,  0.800000,  0.800000};
  s21::s21_shifting(&shape, 2, s21::AXIS_X);

  EXPECT_EQ(shape.countLines, 60);
  EXPECT_EQ(shape.countVertexes, 24);
  EXPECT_EQ(shape.countV, 8);
  EXPECT_EQ(shape.countL, 10);
  for (unsigned int i = 0; i < shape.countVertexes; i++) {
    EXPECT_NEAR(shape.vertexes[i], array2[i], 1e-6);
  }
  model.s21_clearModelShape();
}

TEST(drifting_shape, test_drifting_cube_plus_y) {
  s21::Shape shape{};
  double array[24] = {-0.800000, -0.800000, -0.800000, -0.800000, -0.800000,
                      0.800000,  -0.800000, 0.800000,  -0.800000, -0.800000,
                      0.800000,  0.800000,  0.800000,  -0.800000, -0.800000,
                      0.800000,  -0.800000, 0.800000,  0.800000,  0.800000,
                      -0.800000, 0.800000,  0.800000,  0.800000};

  std::string path = "obj/cube.obj";

  s21::Model model(&shape);
  s21::Controller controller(&model);
  s21::View view(&controller);

  model.set_path_of_file(path);

  int status = view.init_controller();

  EXPECT_EQ(status, 0);
  EXPECT_EQ(shape.countLines, 60);
  EXPECT_EQ(shape.countVertexes, 24);
  EXPECT_EQ(shape.countV, 8);
  EXPECT_EQ(shape.countL, 10);
  for (unsigned int i = 0; i < shape.countVertexes; i++) {
    EXPECT_NEAR(shape.vertexes[i], array[i], 1e-6);
  }

  double array2[24] = {-0.800000, 9.200600,  -0.800000, -0.800000, 9.200600,
                       0.800000,  -0.800000, 10.800600, -0.800000, -0.800000,
                       10.800600, 0.800000,  0.800000,  9.200600,  -0.800000,
                       0.800000,  9.200600,  0.800000,  0.800000,  10.800600,
                       -0.800000, 0.800000,  10.800600, 0.800000};
  s21::s21_shifting(&shape, 10.0006, s21::AXIS_Y);

  EXPECT_EQ(shape.countLines, 60);
  EXPECT_EQ(shape.countVertexes, 24);
  EXPECT_EQ(shape.countV, 8);
  EXPECT_EQ(shape.countL, 10);
  for (unsigned int i = 0; i < shape.countVertexes; i++) {
    EXPECT_NEAR(shape.vertexes[i], array2[i], 1e-6);
  }
  model.s21_clearModelShape();
}

TEST(drifting_shape, test_drifting_cube_plus_z) {
  s21::Shape shape{};
  double array[24] = {-0.800000, -0.800000, -0.800000, -0.800000, -0.800000,
                      0.800000,  -0.800000, 0.800000,  -0.800000, -0.800000,
                      0.800000,  0.800000,  0.800000,  -0.800000, -0.800000,
                      0.800000,  -0.800000, 0.800000,  0.800000,  0.800000,
                      -0.800000, 0.800000,  0.800000,  0.800000};

  std::string path = "obj/cube.obj";

  s21::Model model(&shape);
  s21::Controller controller(&model);
  s21::View view(&controller);

  model.set_path_of_file(path);

  int status = view.init_controller();

  EXPECT_EQ(status, 0);
  EXPECT_EQ(shape.countLines, 60);
  EXPECT_EQ(shape.countVertexes, 24);
  EXPECT_EQ(shape.countV, 8);
  EXPECT_EQ(shape.countL, 10);
  for (unsigned int i = 0; i < shape.countVertexes; i++) {
    EXPECT_NEAR(shape.vertexes[i], array[i], 1e-6);
  }

  double array2[24] = {
      -0.800000, -0.799900, -0.800000, -0.800000, -0.799900, 0.800000,
      -0.800000, 0.800100,  -0.800000, -0.800000, 0.800100,  0.800000,
      0.800000,  -0.799900, -0.800000, 0.800000,  -0.799900, 0.800000,
      0.800000,  0.800100,  -0.800000, 0.800000,  0.800100,  0.800000,
  };
  s21::s21_shifting(&shape, 0.0001, s21::AXIS_Y);

  EXPECT_EQ(shape.countLines, 60);
  EXPECT_EQ(shape.countVertexes, 24);
  EXPECT_EQ(shape.countV, 8);
  EXPECT_EQ(shape.countL, 10);
  for (unsigned int i = 0; i < shape.countVertexes; i++) {
    EXPECT_NEAR(shape.vertexes[i], array2[i], 1e-6);
  }
  model.s21_clearModelShape();
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}