//iRequest.h

#ifndef _MBG_I_REQUEST_H
#define _MBG_I_REQUEST_H

#include "primitives.h"
#include "ExtendedType.h"
#include "iDataExtractor.h"

namespace mbg {
  /**
   * @brief Interface for request handling, inheriting from iSerializer.
   *        Provides methods for setting and extracting paths, and managing request lifecycle.
   */
  class iRequest : public iDataExtractor {
  public:
    virtual ~iRequest() = default;

    /**
     * @brief Pure virtual function to destroy the request object.
     *        Must be implemented by derived classes.
     */
    virtual void destroy() = 0;

    /**
     * @brief Pure virtual function to set the path for the request.
     *        Must be implemented by derived classes.
     * @param path The path to be set.
     */
    virtual void setPath(PathType path) = 0;

    /**
     * @brief Pure virtual function to extract the destination path.
     *        Must be implemented by derived classes.
     * @param n The number of bits for extraction.
     * @return The extracted destination path.
     */
    virtual PathType extractDestination(SizeType n) = 0;

    /**
     * @brief Pure virtual function to append a destination path.
     *        Must be implemented by derived classes.
     * @param dest The destination path to append.
     * @param n The number of bits for appending.
     */
    virtual void appendDestination(PathType dest, SizeType n) = 0;

    virtual String makeRaw() = 0;

  };
} // namespace mbg

#endif // !_MBG_I_REQUEST_H