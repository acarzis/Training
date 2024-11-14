// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: proto/service.proto
// Protobuf C++ Version: 4.25.1

#ifndef GOOGLE_PROTOBUF_INCLUDED_proto_2fservice_2eproto_2epb_2eh
#define GOOGLE_PROTOBUF_INCLUDED_proto_2fservice_2eproto_2epb_2eh

#include <limits>
#include <string>
#include <type_traits>
#include <utility>

#include "google/protobuf/port_def.inc"
#if PROTOBUF_VERSION < 4025000
#error "This file was generated by a newer version of protoc which is"
#error "incompatible with your Protocol Buffer headers. Please update"
#error "your headers."
#endif  // PROTOBUF_VERSION

#if 4025001 < PROTOBUF_MIN_PROTOC_VERSION
#error "This file was generated by an older version of protoc which is"
#error "incompatible with your Protocol Buffer headers. Please"
#error "regenerate this file with a newer version of protoc."
#endif  // PROTOBUF_MIN_PROTOC_VERSION
#include "google/protobuf/port_undef.inc"
#include "google/protobuf/io/coded_stream.h"
#include "google/protobuf/arena.h"
#include "google/protobuf/arenastring.h"
#include "google/protobuf/generated_message_tctable_decl.h"
#include "google/protobuf/generated_message_util.h"
#include "google/protobuf/metadata_lite.h"
#include "google/protobuf/generated_message_reflection.h"
#include "google/protobuf/message.h"
#include "google/protobuf/repeated_field.h"  // IWYU pragma: export
#include "google/protobuf/extension_set.h"  // IWYU pragma: export
#include "google/protobuf/unknown_field_set.h"
// @@protoc_insertion_point(includes)

// Must be included last.
#include "google/protobuf/port_def.inc"

#define PROTOBUF_INTERNAL_EXPORT_proto_2fservice_2eproto

namespace google {
namespace protobuf {
namespace internal {
class AnyMetadata;
}  // namespace internal
}  // namespace protobuf
}  // namespace google

// Internal implementation detail -- do not use these members.
struct TableStruct_proto_2fservice_2eproto {
  static const ::uint32_t offsets[];
};
extern const ::google::protobuf::internal::DescriptorTable
    descriptor_table_proto_2fservice_2eproto;
class Numeric;
struct NumericDefaultTypeInternal;
extern NumericDefaultTypeInternal _Numeric_default_instance_;
class Point;
struct PointDefaultTypeInternal;
extern PointDefaultTypeInternal _Point_default_instance_;
namespace google {
namespace protobuf {
}  // namespace protobuf
}  // namespace google


// ===================================================================


// -------------------------------------------------------------------

class Point final :
    public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:Point) */ {
 public:
  inline Point() : Point(nullptr) {}
  ~Point() override;
  template<typename = void>
  explicit PROTOBUF_CONSTEXPR Point(::google::protobuf::internal::ConstantInitialized);

  inline Point(const Point& from)
      : Point(nullptr, from) {}
  Point(Point&& from) noexcept
    : Point() {
    *this = ::std::move(from);
  }

  inline Point& operator=(const Point& from) {
    CopyFrom(from);
    return *this;
  }
  inline Point& operator=(Point&& from) noexcept {
    if (this == &from) return *this;
    if (GetArena() == from.GetArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const
      ABSL_ATTRIBUTE_LIFETIME_BOUND {
    return _internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance);
  }
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields()
      ABSL_ATTRIBUTE_LIFETIME_BOUND {
    return _internal_metadata_.mutable_unknown_fields<::google::protobuf::UnknownFieldSet>();
  }

  static const ::google::protobuf::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::google::protobuf::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::google::protobuf::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const Point& default_instance() {
    return *internal_default_instance();
  }
  static inline const Point* internal_default_instance() {
    return reinterpret_cast<const Point*>(
               &_Point_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(Point& a, Point& b) {
    a.Swap(&b);
  }
  inline void Swap(Point* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetArena() != nullptr &&
        GetArena() == other->GetArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetArena() == other->GetArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::google::protobuf::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(Point* other) {
    if (other == this) return;
    ABSL_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  Point* New(::google::protobuf::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<Point>(arena);
  }
  using ::google::protobuf::Message::CopyFrom;
  void CopyFrom(const Point& from);
  using ::google::protobuf::Message::MergeFrom;
  void MergeFrom( const Point& from) {
    Point::MergeImpl(*this, from);
  }
  private:
  static void MergeImpl(::google::protobuf::Message& to_msg, const ::google::protobuf::Message& from_msg);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  ::size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::google::protobuf::internal::ParseContext* ctx) final;
  ::uint8_t* _InternalSerialize(
      ::uint8_t* target, ::google::protobuf::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const { return _impl_._cached_size_.Get(); }

  private:
  ::google::protobuf::internal::CachedSize* AccessCachedSize() const final;
  void SharedCtor(::google::protobuf::Arena* arena);
  void SharedDtor();
  void InternalSwap(Point* other);

  private:
  friend class ::google::protobuf::internal::AnyMetadata;
  static ::absl::string_view FullMessageName() {
    return "Point";
  }
  protected:
  explicit Point(::google::protobuf::Arena* arena);
  Point(::google::protobuf::Arena* arena, const Point& from);
  public:

  static const ClassData _class_data_;
  const ::google::protobuf::Message::ClassData*GetClassData() const final;

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kXFieldNumber = 1,
    kYFieldNumber = 2,
    kZFieldNumber = 3,
  };
  // float x = 1;
  void clear_x() ;
  float x() const;
  void set_x(float value);

  private:
  float _internal_x() const;
  void _internal_set_x(float value);

  public:
  // float y = 2;
  void clear_y() ;
  float y() const;
  void set_y(float value);

  private:
  float _internal_y() const;
  void _internal_set_y(float value);

  public:
  // float z = 3;
  void clear_z() ;
  float z() const;
  void set_z(float value);

  private:
  float _internal_z() const;
  void _internal_set_z(float value);

  public:
  // @@protoc_insertion_point(class_scope:Point)
 private:
  class _Internal;

  friend class ::google::protobuf::internal::TcParser;
  static const ::google::protobuf::internal::TcParseTable<
      2, 3, 0,
      0, 2>
      _table_;
  friend class ::google::protobuf::MessageLite;
  friend class ::google::protobuf::Arena;
  template <typename T>
  friend class ::google::protobuf::Arena::InternalHelper;
  using InternalArenaConstructable_ = void;
  using DestructorSkippable_ = void;
  struct Impl_ {

        inline explicit constexpr Impl_(
            ::google::protobuf::internal::ConstantInitialized) noexcept;
        inline explicit Impl_(::google::protobuf::internal::InternalVisibility visibility,
                              ::google::protobuf::Arena* arena);
        inline explicit Impl_(::google::protobuf::internal::InternalVisibility visibility,
                              ::google::protobuf::Arena* arena, const Impl_& from);
    float x_;
    float y_;
    float z_;
    mutable ::google::protobuf::internal::CachedSize _cached_size_;
    PROTOBUF_TSAN_DECLARE_MEMBER
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_proto_2fservice_2eproto;
};// -------------------------------------------------------------------

class Numeric final :
    public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:Numeric) */ {
 public:
  inline Numeric() : Numeric(nullptr) {}
  ~Numeric() override;
  template<typename = void>
  explicit PROTOBUF_CONSTEXPR Numeric(::google::protobuf::internal::ConstantInitialized);

  inline Numeric(const Numeric& from)
      : Numeric(nullptr, from) {}
  Numeric(Numeric&& from) noexcept
    : Numeric() {
    *this = ::std::move(from);
  }

  inline Numeric& operator=(const Numeric& from) {
    CopyFrom(from);
    return *this;
  }
  inline Numeric& operator=(Numeric&& from) noexcept {
    if (this == &from) return *this;
    if (GetArena() == from.GetArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const
      ABSL_ATTRIBUTE_LIFETIME_BOUND {
    return _internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance);
  }
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields()
      ABSL_ATTRIBUTE_LIFETIME_BOUND {
    return _internal_metadata_.mutable_unknown_fields<::google::protobuf::UnknownFieldSet>();
  }

  static const ::google::protobuf::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::google::protobuf::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::google::protobuf::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const Numeric& default_instance() {
    return *internal_default_instance();
  }
  static inline const Numeric* internal_default_instance() {
    return reinterpret_cast<const Numeric*>(
               &_Numeric_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  friend void swap(Numeric& a, Numeric& b) {
    a.Swap(&b);
  }
  inline void Swap(Numeric* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetArena() != nullptr &&
        GetArena() == other->GetArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetArena() == other->GetArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::google::protobuf::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(Numeric* other) {
    if (other == this) return;
    ABSL_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  Numeric* New(::google::protobuf::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<Numeric>(arena);
  }
  using ::google::protobuf::Message::CopyFrom;
  void CopyFrom(const Numeric& from);
  using ::google::protobuf::Message::MergeFrom;
  void MergeFrom( const Numeric& from) {
    Numeric::MergeImpl(*this, from);
  }
  private:
  static void MergeImpl(::google::protobuf::Message& to_msg, const ::google::protobuf::Message& from_msg);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  ::size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::google::protobuf::internal::ParseContext* ctx) final;
  ::uint8_t* _InternalSerialize(
      ::uint8_t* target, ::google::protobuf::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const { return _impl_._cached_size_.Get(); }

  private:
  ::google::protobuf::internal::CachedSize* AccessCachedSize() const final;
  void SharedCtor(::google::protobuf::Arena* arena);
  void SharedDtor();
  void InternalSwap(Numeric* other);

  private:
  friend class ::google::protobuf::internal::AnyMetadata;
  static ::absl::string_view FullMessageName() {
    return "Numeric";
  }
  protected:
  explicit Numeric(::google::protobuf::Arena* arena);
  Numeric(::google::protobuf::Arena* arena, const Numeric& from);
  public:

  static const ClassData _class_data_;
  const ::google::protobuf::Message::ClassData*GetClassData() const final;

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kValueFieldNumber = 1,
  };
  // float value = 1;
  void clear_value() ;
  float value() const;
  void set_value(float value);

  private:
  float _internal_value() const;
  void _internal_set_value(float value);

  public:
  // @@protoc_insertion_point(class_scope:Numeric)
 private:
  class _Internal;

  friend class ::google::protobuf::internal::TcParser;
  static const ::google::protobuf::internal::TcParseTable<
      0, 1, 0,
      0, 2>
      _table_;
  friend class ::google::protobuf::MessageLite;
  friend class ::google::protobuf::Arena;
  template <typename T>
  friend class ::google::protobuf::Arena::InternalHelper;
  using InternalArenaConstructable_ = void;
  using DestructorSkippable_ = void;
  struct Impl_ {

        inline explicit constexpr Impl_(
            ::google::protobuf::internal::ConstantInitialized) noexcept;
        inline explicit Impl_(::google::protobuf::internal::InternalVisibility visibility,
                              ::google::protobuf::Arena* arena);
        inline explicit Impl_(::google::protobuf::internal::InternalVisibility visibility,
                              ::google::protobuf::Arena* arena, const Impl_& from);
    float value_;
    mutable ::google::protobuf::internal::CachedSize _cached_size_;
    PROTOBUF_TSAN_DECLARE_MEMBER
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_proto_2fservice_2eproto;
};

// ===================================================================




// ===================================================================


#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// -------------------------------------------------------------------

// Point

// float x = 1;
inline void Point::clear_x() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.x_ = 0;
}
inline float Point::x() const {
  // @@protoc_insertion_point(field_get:Point.x)
  return _internal_x();
}
inline void Point::set_x(float value) {
  _internal_set_x(value);
  // @@protoc_insertion_point(field_set:Point.x)
}
inline float Point::_internal_x() const {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  return _impl_.x_;
}
inline void Point::_internal_set_x(float value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  ;
  _impl_.x_ = value;
}

// float y = 2;
inline void Point::clear_y() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.y_ = 0;
}
inline float Point::y() const {
  // @@protoc_insertion_point(field_get:Point.y)
  return _internal_y();
}
inline void Point::set_y(float value) {
  _internal_set_y(value);
  // @@protoc_insertion_point(field_set:Point.y)
}
inline float Point::_internal_y() const {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  return _impl_.y_;
}
inline void Point::_internal_set_y(float value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  ;
  _impl_.y_ = value;
}

// float z = 3;
inline void Point::clear_z() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.z_ = 0;
}
inline float Point::z() const {
  // @@protoc_insertion_point(field_get:Point.z)
  return _internal_z();
}
inline void Point::set_z(float value) {
  _internal_set_z(value);
  // @@protoc_insertion_point(field_set:Point.z)
}
inline float Point::_internal_z() const {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  return _impl_.z_;
}
inline void Point::_internal_set_z(float value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  ;
  _impl_.z_ = value;
}

// -------------------------------------------------------------------

// Numeric

// float value = 1;
inline void Numeric::clear_value() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.value_ = 0;
}
inline float Numeric::value() const {
  // @@protoc_insertion_point(field_get:Numeric.value)
  return _internal_value();
}
inline void Numeric::set_value(float value) {
  _internal_set_value(value);
  // @@protoc_insertion_point(field_set:Numeric.value)
}
inline float Numeric::_internal_value() const {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  return _impl_.value_;
}
inline void Numeric::_internal_set_value(float value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  ;
  _impl_.value_ = value;
}

#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)


// @@protoc_insertion_point(global_scope)

#include "google/protobuf/port_undef.inc"

#endif  // GOOGLE_PROTOBUF_INCLUDED_proto_2fservice_2eproto_2epb_2eh