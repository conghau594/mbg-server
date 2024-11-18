//SimpleSerializer.h

#ifndef _MBG_SIMPLE_SERIALIZER_H
#define _MBG_SIMPLE_SERIALIZER_H

#include "SerializerBase.h"

namespace mbg {
  class SimpleSerializer final : public SerializerBase {
    String content_;
  public:
    SimpleSerializer(const String& content) : content_{ content } {}

    ExInt getValue(const IntField& field) const override {
      return 0; // std::atoi(content_);
    }

    ExStr getValue(const StrField& field) const override {
      return ExStr(content_);
    }

    ExFloat getValue(const FloatField& field) const override {
      return std::atof(content_.data());
    }

    PathType getValue(const PathField& field) const override {
      return std::atoi(content_.data());
    }
  };
} // namespace mbg

#endif // !_MBG_SIMPLE_SERIALIZER_H

