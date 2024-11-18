//JsonSerializer.h
#ifndef _MBG_JSON_EXTRACTOR_H
#define _MBG_JSON_EXTRACTOR_H

#include "json.h"
#include "iSerializer.h"

namespace mbg {
  /**
   * @class JsonSerializer
   * @brief A class to extract data from JSON objects.
   *
   * This class implements the iSerializer interface to provide methods
   * for extracting integer, string, float, and path values from JSON objects.
   */
  class JsonSerializer final : public SerializerBase {
    Json json_; ///< JSON object to store the parsed JSON data.

  public:
    /**
     * @brief Constructs a new JsonSerializer object.
     * 
     * @param raw A string containing the raw JSON data to be parsed.
     */
    JsonSerializer(std::string raw) : json_{ raw } { }

    /**
     * @brief Extracts an integer value from the JSON object.
     * 
     * This method attempts to extract an integer value associated with the given field
     * from the JSON object. If the extraction fails, it returns NULL_INT.
     * 
     * @param field The field containing the name of the JSON key to extract the value from.
     * @return ExInt The extracted integer value or NULL_INT if extraction fails.
     * @see NULL_INT
     */
    ExInt getValue(const IntField& field) const override {
      ExInt result = NULL_INT;
      try {
        result = json_[field.getFieldName()].get<Int>();
      }
      catch (...) {}

      return result;
    }

    /**
     * @brief Extracts a string value from the JSON object.
     * 
     * This method attempts to extract a string value associated with the given field
     * from the JSON object. If the extraction fails, it returns an empty string.
     * 
     * @param field The field containing the name of the JSON key to extract the value from.
     * @return ExStr The extracted string value or an empty string if extraction fails.
     */
    ExStr getValue(const StrField& field) const override {
      ExStr result;
      try {
        result = json_[field.getFieldName()].get<String>();
      }
      catch (...) {}

      return result;
    }

    /**
     * @brief Extracts a float value from the JSON object.
     * 
     * This method attempts to extract a float value associated with the given field
     * from the JSON object. If the extraction fails, it returns NULL_FLOAT.
     * 
     * @param field The field containing the name of the JSON key to extract the value from.
     * @return ExFloat The extracted float value or NULL_FLOAT if extraction fails.
     * @see NULL_FLOAT
     */
    ExFloat getValue(const FloatField& field) const override {
      ExFloat result = NULL_FLOAT;
      try {
        result = json_[field.getFieldName()].get<Float>();
      }
      catch (...) {}

      return result;
    }

    /**
     * @brief Extracts a path value from the JSON object.
     * 
     * This method attempts to extract a path value associated with the given field
     * from the JSON object. If the extraction fails, it returns NULL_PATH.
     * 
     * @param field The field containing the name of the JSON key to extract the value from.
     * @return PathType The extracted path value or NULL_PATH if extraction fails.
     * @see NULL_PATH
     */
    PathType getValue(const PathField& field) const override {
      PathType result = NULL_PATH;
      try {
        result = json_[field.getFieldName()].get<Uint>();
      }
      catch (...) {}

      return result;
    }
 
  };
} // namespace mbg

#endif // !_MBG_JSON_EXTRACTOR_H
