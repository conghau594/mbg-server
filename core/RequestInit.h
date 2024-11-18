//Request.h
#ifndef _MBG_REQUEST_INIT_H
#define _MBG_REQUEST_INIT_H

#include "iRequest.h"
#include "UserData.h"
#include "SerializerBase.h"


namespace mbg {
  /**
   * @brief A class that represents a request and provides methods to manipulate and extract data from it.
   */
  class RequestInit : public iRequest {
    PathType        path_;      ///< The current path directing this request to travel across the server.
    SerializerBase* serializer_; ///< The data extractor to be used for extracting data from the request.
    UserData*       userData_;  ///< The user data associated with the request.

   public:  
    /**
     * @brief Constructs a Request object with the specified data extractor.
     * 
     * This constructor initializes the Request object with the given data extractor
     * and sets the path to 0.
     * 
     * @param extractor A pointer to the data extractor to be used.
     */
    RequestInit(SerializerBase* serializer)
      : serializer_(serializer), path_(0) {}

    /**
     * @brief Constructs a Request object with the specified data extractor and path.
     * 
     * This constructor initializes the Request object with the given data extractor
     * and sets the path to the specified value.
     * 
     * @param extractor A pointer to the data extractor to be used.
     * @param path The initial path value.
     */
    RequestInit(SerializerBase* serializer, PathType path)
      : serializer_(serializer), path_(path) {}

    /**
     * @brief Destructor for the Request class.
     * 
     * This destructor deletes the data extractor associated with the request.
     */
    ~RequestInit () { }

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

    
    DataObject* get(int type) override {
      switch (type)
      {
      case OBJ_USER_DATA:
        return userData_;

      case OBJ_SERIALIZER:
        return serializer_;

      default:
        return nullptr;
      }

    }

    void set(DataObject* dataPtr) override {
      switch (dataPtr->getType())
      {
      case OBJ_USER_DATA:
        userData_ = static_cast<UserData*>(dataPtr);
        break;

      case OBJ_SERIALIZER:
        serializer_ = static_cast<SerializerBase*>(dataPtr);
        break;

      default:
        assert(false);
        break;
      }
    }
    /**
     * @brief Makes a raw string representation of the request.
     * @return The raw string representation of the request.
     */
    String makeRaw() override {
      //TODO: Implement this method: Request::makeRaw
      return "extractor_->makeRaw();";
    }
    
  };
} // namespace mbg


#endif // !_MBG_REQUEST_INIT_H
