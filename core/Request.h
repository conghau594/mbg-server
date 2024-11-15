//Request.h
#ifndef _MBG_REQUEST_H
#define _MBG_REQUEST_H

#include "iRequest.h"

namespace mbg {
  /**
   * @brief A class that represents a request and provides methods to manipulate and extract data from it.
   */
  class Request final : public iRequest {
    PathType        path_;      ///< The current path directing this request to travel across the server.
    iDataExtractor* extractor_; ///< The data extractor to be used for extracting data from the request.

  public:  
    /**
     * @brief Constructs a Request object with the specified data extractor.
     * 
     * This constructor initializes the Request object with the given data extractor
     * and sets the path to 0.
     * 
     * @param extractor A pointer to the data extractor to be used.
     */
    Request(iDataExtractor* extractor)
      : extractor_(extractor), path_(0) {}

    /**
     * @brief Constructs a Request object with the specified data extractor and path.
     * 
     * This constructor initializes the Request object with the given data extractor
     * and sets the path to the specified value.
     * 
     * @param extractor A pointer to the data extractor to be used.
     * @param path The initial path value.
     */
    Request(iDataExtractor* extractor, PathType path)
      : extractor_(extractor), path_(path) {}

    /**
     * @brief Destructor for the Request class.
     * 
     * This destructor deletes the data extractor associated with the request.
     */
    ~Request() { delete extractor_; }

    /**
     * @brief Destroys the current object instance.
     */
    void destroy() override { delete this; }

 
    /**
     * @brief Sets the path for the request.
     * 
     * This method sets the path that directs the request to travel across the server.
     * 
     * @param path The new path value to be set.
     */
    void setPath(PathType path) override { path_ = path; }

    /**
     * @brief Extracts a destination from the path.
     * 
     * This method extracts a specified number of bits from the path and returns it as the destination.
     * The path is then right-shifted by the number of bits extracted.
     * 
     * @param n The number of bits to extract.
     * @return The extracted destination.
     */
    PathType extractDestination(SizeType n) override {
      PathType result = ((1 << (n + 1)) - 1) & path_;
      path_ = (path_ >> n);
      return result;
    }

    /**
     * @brief Appends a destination to the path.
     *
     * This method appends a specified number of bits from the destination to the path.
     * The path is left-shifted by the number of bits to make space for the new bits,
     * and then the destination bits are OR-ed into the path.
     *
     * @param dest The destination to append.
     * @param n The number of bits to append.
     */
    void appendDestination(PathType dest, SizeType n) override {
      path_ = (path_ << n) | dest;
    }

    /**
     * @brief Gets the value of the specified integer field.
     * @param field The integer field to get the value from.
     * @return The extracted integer value.
     */
    ExInt getValue(const IntField& field) override {
      return extractor_->getValue(field);
    }

    /**
     * @brief Gets the value of the specified string field.
     * @param field The string field to get the value from.
     * @return The extracted string value.
     */
    ExStr getValue(const StrField& field) override {
      return extractor_->getValue(field);
    }

    /**
     * @brief Gets the value of the specified float field.
     * @param field The float field to get the value from.
     * @return The extracted float value.
     */
    ExFloat getValue(const FloatField& field) override {
      return extractor_->getValue(field);
    }

    /**
     * @brief Gets the value of the specified path field.
     * @param field The path field to get the value from.
     * @return The extracted path value.
     */
    PathType getValue(const PathField& field) override {
      return extractor_->getValue(field);
    }

    /**
     * @brief Makes a raw string representation of the request.
     * @return The raw string representation of the request.
     */
    String makeRaw() override {
      return extractor_->makeRaw();
    }
    
  };
} // namespace mbg


#endif // !_MBG_REQUEST_H
