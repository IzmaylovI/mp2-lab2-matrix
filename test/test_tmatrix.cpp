#include "utmatrix.h"

#include <gtest.h>

TEST(TMatrix, can_create_matrix_with_positive_length)
{
  ASSERT_NO_THROW(TMatrix<int> Neo(5));
}

TEST(TMatrix, cant_create_too_large_matrix)
{
  ASSERT_ANY_THROW(TMatrix<int> Neo(MAX_MATRIX_SIZE + 1));
}

TEST(TMatrix, throws_when_create_matrix_with_negative_length)
{
  ASSERT_ANY_THROW(TMatrix<int> Neo(-5));
}

TEST(TMatrix, can_create_copied_matrix)
{
  TMatrix<int> Neo(5);

  ASSERT_NO_THROW(TMatrix<int> K_Reeves(Neo));
}

TEST(TMatrix, copied_matrix_is_equal_to_source_one)
{
	TMatrix<int> Neo(5);

	TMatrix<int> K_Reeves(Neo);

	EXPECT_EQ(Neo, K_Reeves);
}

TEST(TMatrix, copied_matrix_has_its_own_memory)
{
	TMatrix<int> Neo(5);
	TMatrix<int> K_Reeves(Neo);

	EXPECT_NE(&Neo, &K_Reeves);
}

TEST(TMatrix, can_get_size)
{
	TMatrix<int> Neo(5);

	EXPECT_EQ(5, Neo.GetSize());
}

TEST(TMatrix, can_set_and_get_element)
{
	TMatrix<int> Neo(5);

	Neo[0][0] = 10;
	Neo[1][1] = 20;
	Neo[4][4] = 30;

	EXPECT_EQ(10, Neo[0][0]);
	EXPECT_EQ(20, Neo[1][1]);
	EXPECT_EQ(30, Neo[4][4]);
}

TEST(TMatrix, throws_when_set_element_with_negative_index)
{
	TMatrix<int> Neo(5);

	ASSERT_ANY_THROW(Neo[-1][0] = 10);
}

TEST(TMatrix, throws_when_set_element_with_too_large_index)
{
	TMatrix<int> Neo(5);

	ASSERT_ANY_THROW(Neo[5][0] = 10);
}

TEST(TMatrix, can_assign_matrix_to_itself)
{
	TMatrix<int> Neo(5);

	ASSERT_NO_THROW(Neo = Neo);
}

TEST(TMatrix, can_assign_matrices_of_equal_size)
{
	TMatrix<int> Neo(5);
	TMatrix<int> K_Reeves(5);

	ASSERT_NO_THROW(Neo, K_Reeves);
}

TEST(TMatrix, assign_operator_change_matrix_size)
{
	TMatrix<int> Neo(5);
	TMatrix<int> K_Reeves(6);

	Neo = K_Reeves;
	EXPECT_EQ(6, Neo.GetSize());
}

TEST(TMatrix, can_assign_matrices_of_different_size)
{
	TMatrix<int> Neo(5);
	TMatrix<int> K_Reeves(6);

	ASSERT_NO_THROW(Neo == K_Reeves);
}

TEST(TMatrix, compare_equal_matrices_return_true)
{
	TMatrix<int> Neo(5);
	TMatrix<int> K_Reeves(5);

	Neo[0][0] = 1; K_Reeves[0][0] = 1;
	Neo[1][1] = 2; K_Reeves[1][1] = 2;

	EXPECT_EQ(Neo, K_Reeves);
}

TEST(TMatrix, compare_matrix_with_itself_return_true)
{
	TMatrix<int> Neo(5);

	EXPECT_EQ(Neo, Neo);
}

TEST(TMatrix, matrices_with_different_size_are_not_equal)
{
	TMatrix<int> Neo(5);
	TMatrix<int> K_Reeves(6);

	EXPECT_NE(Neo, K_Reeves);
}

TEST(TMatrix, can_add_matrices_with_equal_size)
{
	TMatrix<int> Neo(5);
	TMatrix<int> K_Reeves(5);

	ASSERT_NO_THROW(Neo + K_Reeves);
}

TEST(TMatrix, cant_add_matrices_with_not_equal_size)
{
	TMatrix<int> Neo(5);
	TMatrix<int> K_Reeves(6);

	ASSERT_ANY_THROW(Neo + K_Reeves);
}

TEST(TMatrix, can_subtract_matrices_with_equal_size)
{
	TMatrix<int> Neo(5);
	TMatrix<int> K_Reeves(6);

	ASSERT_NO_THROW(Neo - K_Reeves);
}

TEST(TMatrix, cant_subtract_matrixes_with_not_equal_size)
{
  ADD_FAILURE();
}

