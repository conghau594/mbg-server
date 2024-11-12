#include "JsonExtractor.h"
#include "gtest/gtest.h"

using namespace mbg;

class JsonExtractorTest : public ::testing::Test {
protected:
    nlohmann::json json;
    JsonExtractor* extractor;

    void SetUp() override {
        json = R"({
            "intField": 42,
            "strField": "test",
            "floatField": 3.14,
            "pathField": 12345
        })"_json;
        extractor = new JsonExtractor(json.dump());
    }

    void TearDown() override {
        delete extractor;
    }
};

TEST_F(JsonExtractorTest, GetIntValue) {
    IntField intField("intField");
    ExInt result = extractor->getValue(intField);
    EXPECT_EQ(result, 42);
}

TEST_F(JsonExtractorTest, GetStrValue) {
    StrField strField("strField");
    ExStr result = extractor->getValue(strField);
    EXPECT_EQ(result, "test");
}

TEST_F(JsonExtractorTest, GetFloatValue) {
    FloatField floatField("floatField");
    ExFloat result = extractor->getValue(floatField);
    EXPECT_FLOAT_EQ(result, 3.14);
}

TEST_F(JsonExtractorTest, GetPathValue) {
    PathField pathField("pathField");
    PathType result = extractor->getValue(pathField);
    EXPECT_EQ(result, 12345);
}

TEST_F(JsonExtractorTest, GetNonExistentIntValue) {
    IntField intField("nonExistentField");
    ExInt result = extractor->getValue(intField);
    EXPECT_EQ(result, NULL_INT);
}

TEST_F(JsonExtractorTest, GetNonExistentStrValue) {
    StrField strField("nonExistentField");
    ExStr result = extractor->getValue(strField);
    EXPECT_TRUE(result.isNull());
}

TEST_F(JsonExtractorTest, GetNonExistentFloatValue) {
    FloatField floatField("nonExistentField");
    ExFloat result = extractor->getValue(floatField);
    EXPECT_EQ(result, NULL_FLOAT);
}

TEST_F(JsonExtractorTest, GetNonExistentPathValue) {
    PathField pathField("nonExistentField");
    PathType result = extractor->getValue(pathField);
    EXPECT_EQ(result, NULL_PATH);
}


TEST_F(JsonExtractorTest, GetEmptyIntValue) {
  IntField intField("");
  ExInt result = extractor->getValue(intField);
  EXPECT_EQ(result, NULL_INT);
}

TEST_F(JsonExtractorTest, GetEmptyStrValue) {
  StrField strField("");
  ExStr result = extractor->getValue(strField);
  EXPECT_TRUE(result.isNull());
}

TEST_F(JsonExtractorTest, GetEmptyFloatValue) {
  FloatField floatField("");
  ExFloat result = extractor->getValue(floatField);
  EXPECT_EQ(result, NULL_FLOAT);
}

TEST_F(JsonExtractorTest, GetEmptyPathValue) {
  PathField pathField("");
  PathType result = extractor->getValue(pathField);
  EXPECT_EQ(result, NULL_PATH);
}

//
//
//int main(int argc, char **argv) {
//    ::testing::InitGoogleTest(&argc, argv);
//    return RUN_ALL_TESTS();
//}
