/*
 * This is an example unit test that doesn't really do anything useful.
 * It is here as a reference for you when creating additional unit tests.
 * For additional reference information, see the "test.h" header.
 */

#include "test.h" // Brings in the Catch framework

#include "Matrix.h"

TEST_CASE("Matrix size 1", "[Matrix]") {
  Matrix my_mat(1, 1, true);
  REQUIRE( my_mat.width() == 1 );
  REQUIRE( my_mat.height() == 1 );
}

TEST_CASE("Matrix size 2", "[Matrix]") {
  Matrix my_mat(3, 4, true);
  REQUIRE( my_mat.width() == 3 );
  REQUIRE( my_mat.height() == 4 );
}

TEST_CASE("Matrix size 3", "[Matrix]") {
  Matrix my_mat(4, 3, true);
  REQUIRE( my_mat.width() == 4 );
  REQUIRE( my_mat.height() == 3 );
}

TEST_CASE("Matrix size 4", "[Matrix]") {
  Matrix my_mat(1, 1, false);
  REQUIRE( my_mat.width() == 1 );
  REQUIRE( my_mat.height() == 1 );
}

TEST_CASE("Matrix size 5", "[Matrix]") {
  Matrix my_mat(3, 4, false);
  REQUIRE( my_mat.width() == 3 );
  REQUIRE( my_mat.height() == 4 );
}

TEST_CASE("Matrix size 6", "[Matrix]") {
  Matrix my_mat(4, 3, false);
  REQUIRE( my_mat.width() == 4 );
  REQUIRE( my_mat.height() == 3 );
}

TEST_CASE("Matrix copy 1", "[Matrix]") {
  Matrix mat1(4, 5, true);
  Matrix mat2 = mat1;
  REQUIRE( mat2.width() == 4 );
  REQUIRE( mat2.height() == 5 );
}

TEST_CASE("Matrix copy 2", "[Matrix]") {
  Matrix mat1(4, 5, true);
  for (int i = 0; i < 5; ++i) {
    for (int j = 0; j < 4; ++j) {
      mat1.get_uint8(i, j) = static_cast<uint8_t>(i + j);
    }
  }
  Matrix mat2 = mat1;
  bool eq = true;
  for (int i = 0; i < 5; ++i) {
    for (int j = 0; j < 4; ++j) {
      if (mat1.get_uint8(i, j) != mat2.get_uint8(i, j)) {
	eq = false;
      }
    }
  }
  REQUIRE( eq == true );
}

TEST_CASE("Matrix copy 3", "[Matrix]") {
  Matrix mat1(4, 5, false);
  Matrix mat2 = mat1;
  REQUIRE( mat2.width() == 4 );
  REQUIRE( mat2.height() == 5 );
}

TEST_CASE("Matrix copy 4", "[Matrix]") {
  Matrix mat1(4, 5, false);
  for (int i = 0; i < 5; ++i) {
    for (int j = 0; j < 4; ++j) {
      mat1.get_float(i, j) = static_cast<float>(i + j);
    }
  }
  Matrix mat2 = mat1;
  bool eq = true;
  for (int i = 0; i < 5; ++i) {
    for (int j = 0; j < 4; ++j) {
      if (mat1.get_float(i, j) != mat2.get_float(i, j)) {
	eq = false;
      }
    }
  }
  REQUIRE( eq == true );
}

TEST_CASE("Matrix copy assignment 1", "[Matrix]") {
  Matrix mat1(4, 5, true), mat2(4, 5, true);
  mat2 = mat1;
  REQUIRE( mat2.width() == 4 );
  REQUIRE( mat2.height() == 5 );
}

TEST_CASE("Matrix copy assignment 2", "[Matrix]") {
  Matrix mat1(4, 5, true), mat2(4, 5, true);
  for (int i = 0; i < 5; ++i) {
    for (int j = 0; j < 4; ++j) {
      mat1.get_uint8(i, j) = static_cast<uint8_t>(i + j);
    }
  }
  mat2 = mat1;
  bool eq = true;
  for (int i = 0; i < 5; ++i) {
    for (int j = 0; j < 4; ++j) {
      if (mat1.get_uint8(i, j) != mat2.get_uint8(i, j)) {
	eq = false;
      }
    }
  }
  REQUIRE( eq == true );
}

TEST_CASE("Matrix copy assignment 3", "[Matrix]") {
  Matrix mat1(4, 5, false), mat2(4, 5, false);
  mat2 = mat1;
  REQUIRE( mat2.width() == 4 );
  REQUIRE( mat2.height() == 5 );
}

TEST_CASE("Matrix copy assignment 4", "[Matrix]") {
  Matrix mat1(4, 5, false), mat2(4, 5, false);
  for (int i = 0; i < 5; ++i) {
    for (int j = 0; j < 4; ++j) {
      mat1.get_float(i, j) = static_cast<float>(i + j);
    }
  }
  mat2 = mat1;
  bool eq = true;
  for (int i = 0; i < 5; ++i) {
    for (int j = 0; j < 4; ++j) {
      if (mat1.get_float(i, j) != mat2.get_float(i, j)) {
	eq = false;
      }
    }
  }
  REQUIRE( eq == true );
}

