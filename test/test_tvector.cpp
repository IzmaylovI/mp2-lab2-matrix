#include "utmatrix.h"

#include <gtest.h>

TEST(TVector, can_create_vector_with_positive_length)
{
  ASSERT_NO_THROW(TVector<int> v(5));
}

TEST(TVector, cant_create_too_large_vector)
{
  ASSERT_ANY_THROW(TVector<int> v(MAX_VECTOR_SIZE + 1));
}

TEST(TVector, throws_when_create_vector_with_negative_length)
{
  ASSERT_ANY_THROW(TVector<int> v(-5));
}

TEST(TVector, throws_when_create_vector_with_negative_startindex)
{
  ASSERT_ANY_THROW(TVector<int> v(5, -2));
}

TEST(TVector, can_create_copied_vector)
{
  TVector<int> v(10);

  ASSERT_NO_THROW(TVector<int> v1(v));
}

TEST(TVector, copied_vector_is_equal_to_source_one)
{
	TVector<int> v(10, 5);
	v[5] = 100;
	v[6] = 20;
	// v: Size = 10 StartINdex = 5 pVector: 100 20 0 0 0 0 0 0 0 0 

	TVector<int> w(v);
	EXPECT_EQ(w, v);
}

TEST(TVector, copied_vector_has_its_own_memory)
{
	TVector<int> v(10);
	v[0] = 100;
	v[9] = 101;
	
	TVector<int> w(6, 1);
	w = v;

	EXPECT_EQ(v, w);
}

TEST(TVector, can_get_size)
{
    TVector<int> v(4);

    EXPECT_EQ(4, v.GetSize());
}

TEST(TVector, can_get_start_index)
{
    TVector<int> v(4, 2);

    EXPECT_EQ(2, v.GetStartIndex());
}

TEST(TVector, can_set_and_get_element)
{
	TVector<int> v(4);
    v[0] = 4;

    EXPECT_EQ(4, v[0]);
}

TEST(TVector, throws_when_set_element_with_negative_index)
{
	TVector<int> v(4);

	ASSERT_ANY_THROW(v[-1] = 2);
}

TEST(TVector, throws_when_set_element_with_too_large_index)
{
	TVector<int> v(4, 1);

	ASSERT_ANY_THROW(v[6] = 100);
}

TEST(TVector, can_assign_vector_to_itself)
{
	TVector<int> v(10);

	ASSERT_NO_THROW(v = v);
}

TEST(TVector, can_assign_vectors_of_equal_size)
{
	TVector<int> v(10);
	v[0] = 100;
	v[2] = 50;
	v[4] = 56;
	v[9] = 90;
	//v Size = 10 StartIndex = 0 pVector: 100 0 50 0 56 0 0 0 0 90

	TVector<int> w(10);
	w = v;
	EXPECT_EQ(w, v);
}

TEST(TVector, assign_operator_change_vector_size)
{
	TVector<int> v(10);
	TVector<int> w(3);
	
	w = v;

	EXPECT_EQ(w.GetSize(), v.GetSize());
}

TEST(TVector, can_assign_vectors_of_different_size)
{
	TVector<int> v(10);
	v[0] = 100;
	v[2] = 50;
	v[4] = 56;
	v[9] = 90;
	//v Size = 10 StartIndex = 0 pVector: 100 0 50 0 56 0 0 0 0 90

	TVector<int> w(3);
	w = v;
	EXPECT_EQ(w, v);
}

TEST(TVector, compare_equal_vectors_return_true)
{
	TVector<int> v(9, 1);
	v[1] = 10;
	v[2] = 20;
	v[4] = 45;
	v[7] = 37;
	v[8] = 67;
	//v Size = 9 StartIndex = 1 pVector: 10 20 0 45 0 0 37 67 0

	TVector<int> w = v;

	EXPECT_EQ(1, w == v);
}

TEST(TVector, compare_vector_with_itself_return_true)
{
	TVector<int> v(9, 1);
	v[1] = 10;
	v[2] = 20;
	v[4] = 45;
	v[7] = 37;
	v[8] = 67;
	//v Size = 9 StartIndex = 1 pVector: 10 20 0 45 0 0 37 67 0

	EXPECT_EQ(1, v == v);
}

TEST(TVector, vectors_with_different_size_are_not_equal)
{
	TVector<int> v(10);
	TVector<int> w(9);

	EXPECT_EQ(0, v == w);
}

TEST(TVector, can_add_scalar_to_vector)
{
	TVector<int> v(9, 1);
	v[1] = 10;
	v[2] = 20;
	v[4] = 45;
	v[7] = 37;
	v[8] = 67;
	//v Size = 9 StartIndex = 1 pVector:  x | 10 20 0 45 0 0 37 67 0
	
	
	v = v + 6;

	EXPECT_EQ(16, v[1]);
	EXPECT_EQ(26, v[2]);
	EXPECT_EQ(6, v[3]);
	EXPECT_EQ(51, v[4]);
	EXPECT_EQ(6, v[5]);
	EXPECT_EQ(6, v[6]);
	EXPECT_EQ(43, v[7]);
	EXPECT_EQ(73, v[8]);
	EXPECT_EQ(6, v[9]);
}

TEST(TVector, can_subtract_scalar_from_vector)
{
	TVector<int> v(9, 1);
	v[1] = 10;
	v[2] = 20;
	v[4] = 45;
	v[7] = 37;
	v[8] = 67;
	//v Size = 9 StartIndex = 1 pVector:  x | 10 20 0 45 0 0 37 67 0


	v = v - 6;

	EXPECT_EQ(4, v[1]);
	EXPECT_EQ(14, v[2]);
	EXPECT_EQ(-6, v[3]);
	EXPECT_EQ(39, v[4]);
	EXPECT_EQ(-6, v[5]);
	EXPECT_EQ(-6, v[6]);
	EXPECT_EQ(31, v[7]);
	EXPECT_EQ(61, v[8]);
	EXPECT_EQ(-6, v[9]);
}

TEST(TVector, can_multiply_scalar_by_vector)
{
	TVector<int> v(9, 1);
	v[1] = 10;
	v[2] = 20;
	v[4] = 45;
	v[7] = 37;
	v[8] = 67;
	//v Size = 9 StartIndex = 1 pVector:  x | 10 20 0 45 0 0 37 67 0


	v = v * 6;

	EXPECT_EQ(60, v[1]);
	EXPECT_EQ(120, v[2]);
	EXPECT_EQ(0, v[3]);
	EXPECT_EQ(270, v[4]);
	EXPECT_EQ(0, v[5]);
	EXPECT_EQ(0, v[6]);
	EXPECT_EQ(222, v[7]);
	EXPECT_EQ(402, v[8]);
	EXPECT_EQ(0, v[9]);
}

TEST(TVector, can_add_vectors_with_equal_size)
{
	TVector<int> first(9, 3);
	TVector<int> second(10, 2);

	first[3] = 10;
	first[4] = 11;
	first[7] = 9;
	first[11] = 78;
	// first Size = 9 StartIndex = 3 pVector: 10 11 0 0 9 0 0 0 78

	second[2] = 30;
	second[3] = 31;
	second[4] = 32;
	second[5] = 34;
	second[11] = 35;
	// second Size = 10 StartIndex = 2 pVector: 30 31 32 34 0 0 0 0 0 35

	TVector<int> result = first + second;

	EXPECT_EQ(30, result[2]);
	EXPECT_EQ(41, result[3]);
	EXPECT_EQ(43, result[4]);
	EXPECT_EQ(34, result[5]);
	EXPECT_EQ(0, result[6]);
	EXPECT_EQ(9, result[7]);
	EXPECT_EQ(0, result[8]);
	EXPECT_EQ(0, result[9]);
	EXPECT_EQ(0, result[10]);
	EXPECT_EQ(113, result[11]);
}

TEST(TVector, cant_add_vectors_with_not_equal_size)
{
	TVector<int> first(10, 1);
	TVector<int> second(5, 2);

	first[1] = 2;
	first[2] = 3;
	first[3] = 4;
	first[4] = 5;
	first[5] = 6;
	first[6] = 7;
	first[7] = 8;
	first[10] = 9;
	//first Size = 10 StartIndex = 1  pVector: 2 3 4 5 6 7 8 0 0 9

	second[2] = 10;
	second[3] = 10;
	second[4] = 10;
	second[5] = 10;
	second[6] = 10;
	//second Size = 5 StartIndex = 2  pVector: 10 10 10 10 10

	ASSERT_ANY_THROW(TVector<int> result = first + second);
}

TEST(TVector, can_subtract_vectors_with_equal_size)
{
	TVector<int> first(9, 3);
	TVector<int> second(10, 2);

	first[3] = 10;
	first[4] = 11;
	first[7] = 9;
	first[11] = 78;
	// first Size = 9 StartIndex = 3 pVector: 10 11 0 0 9 0 0 0 78

	second[2] = 30;
	second[3] = 31;
	second[4] = 32;
	second[5] = 34;
	second[11] = 35;
	// second Size = 10 StartIndex = 2 pVector: 30 31 32 34 0 0 0 0 0 35

	TVector<int> result = first - second;

	EXPECT_EQ(-30, result[2]);
	EXPECT_EQ(-21, result[3]);
	EXPECT_EQ(-21, result[4]);
	EXPECT_EQ(-34, result[5]);
	EXPECT_EQ(0, result[6]);
	EXPECT_EQ(9, result[7]);
	EXPECT_EQ(0, result[8]);
	EXPECT_EQ(0, result[9]);
	EXPECT_EQ(0, result[10]);
	EXPECT_EQ(43, result[11]);
}

TEST(TVector, cant_subtract_vectors_with_not_equal_size)
{
	TVector<int> first(10, 1);
	TVector<int> second(5, 2);

	first[1] = 2;
	first[2] = 3;
	first[3] = 4;
	first[4] = 5;
	first[5] = 6;
	first[6] = 7;
	first[7] = 8;
	first[10] = 9;
	//first Size = 10 StartIndex = 1  pVector: 2 3 4 5 6 7 8 0 0 9

	second[2] = 10;
	second[3] = 10;
	second[4] = 10;
	second[5] = 10;
	second[6] = 10;
	//second Size = 5 StartIndex = 2  pVector: 10 10 10 10 10

	ASSERT_ANY_THROW(TVector<int> result = first - second);
}

TEST(TVector, can_multiply_vectors_with_equal_size)
{
	TVector<int> first(9, 3);
	TVector<int> second(10, 2);

	first[3] = 10;
	first[4] = 11;
	first[7] = 9;
	first[11] = 78;
	// first Size = 9 StartIndex = 3 pVector: 10 11 0 0 9 0 0 0 78

	second[2] = 30;
	second[3] = 31;
	second[4] = 32;
	second[5] = 34;
	second[11] = 35;
	// second Size = 10 StartIndex = 2 pVector: 30 31 32 34 0 0 0 0 0 35

	EXPECT_EQ(3392, first * second);
}

TEST(TVector, cant_multiply_vectors_with_not_equal_size)
{
	TVector<int> first(10, 1);
	TVector<int> second(5, 2);

	first[1] = 2;
	first[2] = 3;
	first[3] = 4;
	first[4] = 5;
	first[5] = 6;
	first[6] = 7;
	first[7] = 8;
	first[10] = 9;
	//first Size = 10 StartIndex = 1  pVector: 2 3 4 5 6 7 8 0 0 9

	second[2] = 10;
	second[3] = 10;
	second[4] = 10;
	second[5] = 10;
	second[6] = 10;
	//second Size = 5 StartIndex = 2  pVector: 10 10 10 10 10

	ASSERT_ANY_THROW(first * second);
}

TEST(TVector, can_be_a_vector_sequentally_mutiplied_by_a_scalar_ad_by_a_vector)
{
	TVector<int> R(10);
	R[0] = 10;
	R[1] = 20;
	R[2] = 30;
	R[4] = 45;
	R[8] = 34;

	TVector<int> r(8,2);
	r[2] = 9;
	r[4] = 10;
	r[6] = 20;
	r[7] = 35;

	ASSERT_NO_THROW(R + r + 6);
}

TEST(TVector, the_sum_does_not_change_from_the_permutation_of_the_terms)
{
	TVector<int> t(5);
	TVector<int> k(5);

	t[0] = 1;
	t[1] = 3;
	t[2] = 5;
	t[3] = 7;
	t[4] = 9;

	k[0] = 4;
	k[1] = 9;
	k[2] = 10;
	k[3] = 6;
	k[4] = 3;

	EXPECT_EQ(t + k, k + t);
}