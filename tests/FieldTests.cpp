#include <gtest/gtest.h>
#include <Field.h>

TEST(FieldTests, CreateField)
{
    ASSERT_NO_THROW(Field field({-2, 2, 2, -2}));
}

TEST(FieldTests, CreateFieldWithBadFieldSize)
{
    ASSERT_THROW(Field field({-2, -999, 2, -2}), std::invalid_argument);
}

TEST(FieldTests, RaiseExceptionWhenSpawnCellOutsideFieldWithNoBoundsMode)
{
    Field field({-2, 2, 2, -2});
    field.SetNoBounds(false);

    ASSERT_THROW(field.SpawnCell({-999, -999}), std::invalid_argument)
        << "Field didn't raise an exception when spawn a cell outside the field with disabled 'no bounds' mode";
}